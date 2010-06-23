
#include "stdafx.h"
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
	pANTLR3_BASE_TREE x = (pANTLR3_BASE_TREE)(ZInterp::cxtr->pTreeParser->rec->getCurrentInputSymbol(ZInterp::cxtr->pTreeParser->rec, ZInterp::cxtr->pTreeParser->ctnstream->tnstream->istream));
	return x->getToken(x)->line;
}