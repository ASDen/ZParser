
#include "stdafx.h"
#include "ZError.h"
#include "ZInterp.h"

#define	    PARSER							ZInterp::cxtr->pTreeParser  
#define	    RECOGNIZER						PARSER->rec
#define	    INPUT							PARSER->ctnstream
#define		ISTREAM							INPUT->tnstream->istream
#define	    MATCHT(t, fs)					RECOGNIZER->match(RECOGNIZER, t, fs)
#define	    MATCHANYT()						RECOGNIZER->matchAny(RECOGNIZER)
#define	    CONSUME()						ISTREAM->consume(ISTREAM)
#define	    LA(n)							ISTREAM->_LA(ISTREAM, n)
#define	    LT(n)							INPUT->tnstream->_LT(INPUT->tnstream, n)
#define		SEEK(n)							ISTREAM->seek(ISTREAM, n)

int ZError::Lnum()
{
	while(true)
	{
		pANTLR3_BASE_TREE x = (pANTLR3_BASE_TREE)(ZInterp::cxtr->pTreeParser->rec->getCurrentInputSymbol(ZInterp::cxtr->pTreeParser->rec, ZInterp::cxtr->pTreeParser->ctnstream->tnstream->istream));
		if((x->getType(x)!=ANTLR3_TOKEN_UP) && (x->getType(x)!=ANTLR3_TOKEN_DOWN))
		{
			return x->getToken(x)->user1;
		}
		MATCHANYT();
	}
}

int ZError::Cnum()
{
	while(true)
	{
		pANTLR3_BASE_TREE x = (pANTLR3_BASE_TREE)(ZInterp::cxtr->pTreeParser->rec->getCurrentInputSymbol(ZInterp::cxtr->pTreeParser->rec, ZInterp::cxtr->pTreeParser->ctnstream->tnstream->istream));
		if((x->getType(x)!=ANTLR3_TOKEN_UP) && (x->getType(x)!=ANTLR3_TOKEN_DOWN))
			//	if(x->getToken(x)->charPosition>0)
			return x->getToken(x)->user2;
		MATCHANYT();
	}
	pANTLR3_BASE_TREE x = (pANTLR3_BASE_TREE)(ZInterp::cxtr->pTreeParser->rec->getCurrentInputSymbol(ZInterp::cxtr->pTreeParser->rec, ZInterp::cxtr->pTreeParser->ctnstream->tnstream->istream));
	return x->getToken(x)->line;
}