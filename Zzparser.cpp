// Zzparser.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "yatgLexer.h"
#include "yatgParser.h"
#include "yatgFW.h"
#include "ZInterp.h"

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

    fName	=(pANTLR3_UINT8)"input.txt"; // Note in VS2005 debug, working directory must be configured
    
	input	= antlr3AsciiFileStreamNew(fName);

    if ( input == NULL)
    {
	    fprintf(stderr, "Failed to open file %s\n", (char *)fName);
		exit(1);
	}

   
	lxr	    = yatgLexerNew(input);	    // CLexerNew is generated by ANTLR

    // Need to check for errors
    //
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
	// Finally, now that we have our lexer constructed, we can create the parser
    //
	psr	    = yatgParserNew(tstream);  // CParserNew is generated by ANTLR3

    if (psr == NULL)
    {
		fprintf(stderr, "Out of memory trying to allocate parser\n");
		exit(ANTLR3_ERR_NOMEM);
    }
	
   	yatgAST=psr->program(psr);
   
	if (psr->pParser->rec->state->errorCount > 0)
	{
		fprintf(stderr, "The parser returned %d errors, tree walking aborted.\n", psr->pParser->rec->state->errorCount);
		exit(5);
	}
	else
	{
		//printf("Tree : %s\n", yatgAST.tree->toStringTree(yatgAST.tree)->chars);
		nodes	= antlr3CommonTreeNodeStreamNewTree(yatgAST.tree, ANTLR3_SIZE_HINT); // sIZE HINT WILL SOON BE DEPRECATED!!
		// Tree parsers are given a common tree node stream (or your override)
		//
		pANTLR3_BASE_TREE p;
		while(true)
		{
			p=nodes->tnstream->_LT(nodes->tnstream,1);
			p->savedIndex=nodes->tnstream->istream->index(nodes->tnstream->istream);
			if(p->getType(p)==nodes->EOF_NODE.token->getType(nodes->EOF_NODE.token))break;
			nodes->tnstream->istream->consume(nodes->tnstream->istream);
		}
		ZInterp::global::Init();
		treePsr	= yatgFWNew(nodes);
		treePsr->program(treePsr);

		ZInterp::ZSym.currentScope->VarTable.PrintAll();
		
		nodes->free(nodes); nodes = NULL;
		treePsr ->free  (treePsr);	    treePsr	= NULL;

	}
    psr	    ->free  (psr);	    psr = NULL;
    tstream ->free  (tstream);	    tstream = NULL;
    lxr	    ->free  (lxr);	    lxr = NULL;
    input   ->close (input);	    input = NULL;
	

	return 0;
}

