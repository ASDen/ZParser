#pragma once
#ifndef _ZINTERP_H_
#define _ZINTERP_H_

#include "yatgFW.h"


namespace ZInterp
{
	extern ZSymbolTable<ZTvar,ZTmfp> ZSym;

	class global
	{
	public:
		
		static void Init();

		static void IncScope();

		static void DecScope();
	};
	
	
	ZChar* getNodeText(pANTLR3_BASE_TREE n);

	
	void setCustomNodeField(pANTLR3_BASE_TREE t,ZTvarp v);

	class Operand
	{
	public:
		static void _OPERAND(pANTLR3_BASE_TREE t1);
	};

	class Constant
	{
	public:
		static void Exec(pANTLR3_BASE_TREE c);
	};

	class Cexprx
	{
	public:
		static void Exec(pANTLR3_BASE_TREE r,pANTLR3_BASE_TREE t1,pANTLR3_BASE_TREE t2);
	};

	class ExprSeq
	{
	public:
		static void _ESEQ(pANTLR3_BASE_TREE e);
	};

	class AssingmentExpr
	{
	public:
		static void Exec(pANTLR3_BASE_TREE r,pANTLR3_BASE_TREE l,pANTLR3_BASE_TREE e);
	};

	class IfExpr
	{		
	public:
		static void Exec(pANTLR3_BASE_TREE j,pANTLR3_BASE_TREE r,yatgFW_Ctx_struct* xyz);
	};

	class WhileExpr
	{
	public:
		static void Exec(pANTLR3_BASE_TREE wnode,pANTLR3_BASE_TREE cond,yatgFW_Ctx_struct* xyz);
	};
};

#endif