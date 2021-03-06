/*
TODO :
------
1)  to comply closure and others , when defining function store it's scope
	and jump to that scope when calling the function (CHECK IF THIS SUFFICIENT)

2)  Lists , still very much problematic

3)  I/O module to develop real sample scripts

4)  LLVM ?

5)  libffi ?

*/

#include "stdafx.h"
#include "yatgLexer.h"
#include "yatgParser.h"
#include "yatgFW.h"
#include "ZInterp.h"

enum ERROR_TYPE{UN_Wanted_Token_EXCEPTION,MISSING_TOKEN_EXCEPTION,RECOGNITION_EXCEPTION,MISMATCHED_TOKEN_EXCEPTION,NO_VIABLE_ALT_EXCEPTION,MISMATCHED_SET_EXCEPTION,EARLY_EXIT_EXCEPTION};
struct ERROR_DATA
{
	int count;
	string fileName;
	string text;
	int line;
	int column;
	int type;
	ERROR_TYPE Name;
};
vector< ERROR_DATA > error;
static void                        
myDisplayError (pANTLR3_BASE_RECOGNIZER recognizer, pANTLR3_UINT8 * tokenNames)
{
	ERROR_DATA ee;
	pANTLR3_PARSER			parser;
	pANTLR3_TREE_PARSER	    tparser;
	pANTLR3_INT_STREAM	    is;
	pANTLR3_STRING			ttext;
	pANTLR3_EXCEPTION	    ex;
	pANTLR3_COMMON_TOKEN    theToken;
	pANTLR3_BASE_TREE	    theBaseTree;
	pANTLR3_COMMON_TREE	    theCommonTree;
	ex	    =		recognizer->state->exception;
	ee.fileName.append( (char*)ex->streamName->to8(ex->streamName)->chars);
	ee.line=recognizer->state->exception->line;
	ee.type= recognizer->state->exception->type;
	switch	(recognizer->type)
	{
	case	ANTLR3_TYPE_PARSER:
	case	ANTLR3_TYPE_TREE_PARSER:	
		parser	    = (pANTLR3_PARSER) (recognizer->super);
		tparser	    = NULL;
		is			= parser->tstream->istream;
		theToken    = (pANTLR3_COMMON_TOKEN)(recognizer->state->exception->token);
		ttext	    = theToken->toString(theToken);
		ee.text.append((char*)ttext->chars);
		ee.column=recognizer->state->exception->charPositionInLine;
		break;
	default:

		cout<<"Not Support Error Ocurred"<<endl;
		return;
		break;
	}
	switch  (ex->type)
	{
	case	ANTLR3_UNWANTED_TOKEN_EXCEPTION:
		ee.Name= UN_Wanted_Token_EXCEPTION;
		if	(tokenNames == NULL)
		{
			//ANTLR3_FPRINTF(stderr, " : Extraneous input...");
		}
		else
		{
			if	(ex->expecting == ANTLR3_TOKEN_EOF)
			{
				//ANTLR3_FPRINTF(stderr, " : Extraneous input - expected <EOF>\n");
			}
			else
			{
				//ANTLR3_FPRINTF(stderr, " : Extraneous input - expected %s ...\n", tokenNames[ex->expecting]);
			}
		}
		break;

	case	ANTLR3_MISSING_TOKEN_EXCEPTION:
		ee.Name= MISSING_TOKEN_EXCEPTION;
		if	(tokenNames == NULL)
		{
			//ANTLR3_FPRINTF(stderr, " : Missing token (%d)...\n", ex->expecting);
		}
		else
		{
			if	(ex->expecting == ANTLR3_TOKEN_EOF)
			{
				//ANTLR3_FPRINTF(stderr, " : Missing <EOF>\n");
			}
			else
			{
				//ANTLR3_FPRINTF(stderr, " : Missing %s \n", tokenNames[ex->expecting]);
			}
		}
		break;

	case	ANTLR3_RECOGNITION_EXCEPTION:
		ee.Name= RECOGNITION_EXCEPTION;
		//ANTLR3_FPRINTF(stderr, " : syntax error...\n");    
		break;

	case    ANTLR3_MISMATCHED_TOKEN_EXCEPTION:
		ee.Name=MISMATCHED_TOKEN_EXCEPTION;
		if	(tokenNames == NULL)
		{
			//ANTLR3_FPRINTF(stderr, " : syntax error...\n");
		}
		else
		{
			if	(ex->expecting == ANTLR3_TOKEN_EOF)
			{
				//ANTLR3_FPRINTF(stderr, " : expected <EOF>\n");
			}
			else
			{
				//ANTLR3_FPRINTF(stderr, " : expected %s ...\n", tokenNames[ex->expecting]);
			}
		}
		break;

	case	ANTLR3_NO_VIABLE_ALT_EXCEPTION:
		ee.Name=NO_VIABLE_ALT_EXCEPTION;
		//ANTLR3_FPRINTF(stderr, " : cannot match to any predicted input...\n");

		break;

	case	ANTLR3_MISMATCHED_SET_EXCEPTION:
		ee.Name=MISMATCHED_SET_EXCEPTION;
		{
			ANTLR3_UINT32	  count;
			ANTLR3_UINT32	  bit;
			ANTLR3_UINT32	  size;
			ANTLR3_UINT32	  numbits;
			pANTLR3_BITSET	  errBits;
			ANTLR3_FPRINTF(stderr, " : unexpected input...\n  expected one of : ");
			count   = 0;
			errBits = antlr3BitsetLoad		(ex->expectingSet);
			numbits = errBits->numBits		(errBits);
			size    = errBits->size			(errBits);

			if  (size > 0)
			{
				for	(bit = 1; bit < numbits && count < 8 && count < size; bit++)
				{
					if  (tokenNames[bit])
					{
						//ANTLR3_FPRINTF(stderr, "%s%s", count > 0 ? ", " : "", tokenNames[bit]); 
						count++;
					}
				}
				ANTLR3_FPRINTF(stderr, "\n");
			}
			else
			{
				//ANTLR3_FPRINTF(stderr, "Actually dude, we didn't seem to be expecting anything here, or at least\n");
				//ANTLR3_FPRINTF(stderr, "I could not work out what I was expecting, like so many of us these days!\n");
			}
		}
		break;

	case	ANTLR3_EARLY_EXIT_EXCEPTION:
		ee.Name=EARLY_EXIT_EXCEPTION;
		//ANTLR3_FPRINTF(stderr, " : missing elements...\n");
		break;

	default:
	//	ANTLR3_FPRINTF(stderr, " : syntax not recognized...\n");
		break;
	}
	error.push_back(ee);
}

int ANTLR3_CDECL _tmain(int argc, _TCHAR* argv[])
{
	
	pANTLR3_UINT8	    fName;

    pANTLR3_INPUT_STREAM    input;

	pyatgLexer		    lxr;
    
    pANTLR3_COMMON_TOKEN_STREAM	    tstream;

	pyatgParser				psr;

	yatgParser_program_return yatgAST;

	pANTLR3_COMMON_TREE_NODE_STREAM	nodes;

	pyatgFW		    treePsr;

	fName	=(pANTLR3_UINT8)"input.txt";
    
	input	= antlr3AsciiFileStreamNew(fName);

	

    if ( input == NULL)
    {
	    fprintf(stderr, "Failed to open file %s\n", (char *)fName);
		exit(1);
	}

   
	lxr	    = yatgLexerNew(input);	
    if ( lxr == NULL )
    {

	    fprintf(stderr, "Unable to create the lexer due to malloc() failure1\n");
	    exit(1);

    }

    
	tstream = antlr3CommonTokenStreamSourceNew(ANTLR3_SIZE_HINT, TOKENSOURCE(lxr));

    if (tstream == NULL)
    {
	fprintf(stderr, "Out of memory trying to allocate token stream\n");
	exit(1);
    }
	psr	    = yatgParserNew(tstream); 

    if (psr == NULL)
    {
		fprintf(stderr, "Out of memory trying to allocate parser\n");
		exit(ANTLR3_ERR_NOMEM);
    }
	psr->pParser->rec->displayRecognitionError=myDisplayError;
   	yatgAST=psr->program(psr);
   
	if (psr->pParser->rec->state->errorCount > 0)
	{
		
		//error=new ERROR_DATA[psr->pParser->rec->state->errorCount];
		fprintf(stderr, "The parser returned %d errors, tree walking aborted.\n", psr->pParser->rec->state->errorCount);
		for(int i=0;i<error.size();i++)
		{
			cout<<"-------------------------------------------------------------------"<<endl;
			cout<<"Error occured in \t"<<error[i].fileName<<endl
				<<"Error: \t"<<error[i].type<<"\t Name\t"<<error[i].Name<<endl
				<<"at line\t"<<error[i].line<<"\toffset: "<<error[i].column<<endl
				<<"Error text: "<<error[i].text<<endl;
			//cout<<"-------------------------------------------------------------------"<<endl;
		}
		exit(5);
	}
	else
	{
		if(yatgAST.tree!=NULL)
		{
			nodes	= antlr3CommonTreeNodeStreamNewTree(yatgAST.tree, ANTLR3_SIZE_HINT);
		}
		else
		{
			nodes  =  NULL;
			exit(2);
		}
		pANTLR3_BASE_TREE p;
		int ln=0,cpos=0;
		while(true)
		{
			p =nodes -> tnstream -> _LT ( nodes -> tnstream , 1 ) ;
			p->savedIndex=nodes->tnstream->istream->index(nodes->tnstream->istream);
			if( p->getToken(p)->line != 0 )
			{
				ln = p->getToken(p)->line;
			}
			p->getToken(p)->line = ln;
			
			if( p->getCharPositionInLine(p) != 0 )
			{
				cpos = p->getCharPositionInLine(p);
			}
			p->getToken(p)->charPosition = cpos;
			if(p->getType(p)==nodes->EOF_NODE.token->getType(nodes->EOF_NODE.token))break;
			nodes->tnstream->istream->consume(nodes->tnstream->istream);
		}
		ZTObject::Init();
		ZInterp::global::InitBuiltinMods();
		treePsr	= yatgFWNew(nodes);
		ZInterp::cxtr = treePsr;
		
		treePsr->program(treePsr);
		

		//ZInterp::ZSym.currentScope->VarTable.PrintAll();

		nodes->free(nodes); nodes = NULL;
		treePsr ->free  (treePsr);	    treePsr	= NULL;

	}
    psr	    ->free  (psr);	    psr = NULL;
    tstream ->free  (tstream);	    tstream = NULL;
    lxr	    ->free  (lxr);	    lxr = NULL;
    input   ->close (input);	    input = NULL;
	
	return 0;
}