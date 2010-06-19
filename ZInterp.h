#pragma once
#ifndef _ZINTERP_H_
#define _ZINTERP_H_

#include "yatgFW.h"


namespace ZInterp
{
	extern ZSymbolTable<ZTvar> ZSym;
    extern ZIBool isExit,isContinue;
    extern vector <ANTLR3_MARKER> lend,lCon;
    extern int loopNum,actual,currentFrame;

	class global
	{
	public:
		
		static void Init();

		static void InitBuiltinMods();

		static void IncScope();

		static void DecScope();
	};
	
	
	ZChar* getNodeText(pANTLR3_BASE_TREE n);

	
	void setCustomNodeField(pANTLR3_BASE_TREE t,ZTvarp v);

	class Operand
	{
	public:
		static void _OPERAND(pANTLR3_BASE_TREE t1);
		static void AccessListElement(pANTLR3_BASE_TREE t1,pANTLR3_BASE_TREE ind);
		static void AccessObjectField(pANTLR3_BASE_TREE t1,pANTLR3_BASE_TREE field);
		static void FunCall(pANTLR3_BASE_TREE t1,pANTLR3_BASE_TREE arg,yatgFW_Ctx_struct* xyz);
	};

	class Constant
	{
	public:
		static void Exec(pANTLR3_BASE_TREE c);
		static void ComplexExec(pANTLR3_BASE_TREE c);
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
	class ForExpr
	{
	public:
		static void Exec(pANTLR3_BASE_TREE fnode,pANTLR3_BASE_TREE cond,yatgFW_Ctx_struct* xyz);
	};
	class DoExpr
	{
	public:
		static void Exec (pANTLR3_BASE_TREE dnode,pANTLR3_BASE_TREE cond,yatgFW_Ctx_struct* xyz);
	};
	class CaseExpr
	{
	public:
		static void Exec(pANTLR3_BASE_TREE caseNode,yatgFW_Ctx_struct* );
	};
	class ContextExpr
	{
	public:
		static void Exec (pANTLR3_BASE_TREE timeNode,yatgFW_Ctx_struct* );
		static void Flush();
	};

	class Function
	{
	public:
		static void Defination(pANTLR3_BASE_TREE funNode,yatgFW_Ctx_struct* xyz);
	};
    class EXIT
	{
	public:
		static void Exec(pANTLR3_BASE_TREE exitNode,yatgFW_Ctx_struct* xyz);
	};
    class CONTINUE
	{
	public:
		static void Exec(pANTLR3_BASE_TREE conNode,yatgFW_Ctx_struct* xyz);
	};
};

#endif