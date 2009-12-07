tree grammar yatgFW;

options
{
    tokenVocab	    = yatg;
    ASTLabelType   = pANTLR3_BASE_TREE;
    language	    = C;
    backtrack	    = true;
}

@includes
{
	#include "stdafx.h"
}

@postinclude
{
	#include "ZInterp.h"
}


program
	:
	 ( expr )+
	;

expr
	: assignment_expression
	| variable_decls
    	| if_expr
    	| while_loop
    	| do_loop
    	| for_loop
    	| loop_exit
    	| loop_continue
    	| case_expr
    	| struct_def
    	| try_expr
    	| function_def
    	| function_return
    	| context_expr
    	| expr_seq
    	;
    	
variable_decls
	: 
	   ^( VDECL type_decl decl+ )
	;

type_decl
	:  KW_LOCAL | KW_GLOBAL
	;
decl
	:
	    ^( VDEF k=IDENTIFIER (^(VVAL y=expr_g)))
	  | ^( VDEF IDENTIFIER)
	;

if_expr
	:
	  ^( j= EIF ^(EIF_COND c =expr_g) {ZInterp::IfExpr::Exec($j,$c.start,ctx);}  )
	  
	;

while_loop 
	: 
	  ^( j= EWHILE ^(EWHILE_CON c =expr_g) {ZInterp::WhileExpr::Exec($j,$c.start,ctx);})
	;

do_loop 
	: 
	 ^( j= EDO ^(EDO_CON  c =expr_g) { ZInterp::DoExpr::Exec($j,$c.start,ctx);})
	;

for_loop 
	: 
	  ^( j= EFOR IDENTIFIER ^(EFOR_SRC c =source ) {ZInterp::ForExpr::Exec($j,$c.start,ctx); } )
	;
	
source
	: 
	  ^(ESRC_START expr_g) (^(ESRC_TO expr_g))? (^(ESRC_BY expr_g))? (^(ESRC_WHERE expr_g))? 
	;

loop_exit 
	: 
	  ^( LP_EXIT ( ^(LP_EXIT_WITH expr_g ) )? )
	;

loop_continue
	 : 
	   LP_CONT
	 ;

case_expr
	 : 
	  ^(j =CASE (^(CASE_Exp expr_g))?{ZInterp::CaseExpr::Exec( $j , ctx );})
	 ;

case_item 
	:   ^(CASE_Item  constant expr_g)
	|   ^(CASE_Item   DEFAULT expr_g)
	;

struct_def 
	: 
	 ^( STRUCT member+ )
	 
	;

member 
	:   ^( MEMBER IDENTIFIER expr_g) 
	|    function_def 
	;
	
try_expr 
	: 
	 ^(ETRY (^(ETRY_EXP expr_g))(^(ECATCH_EXP  expr_g)))
	;
	
function_def
	: 
	^( t =FUN_DEF ^(FUN_NAME IDENTIFIER) ( argument_expression_list )*  { ZInterp::Function::Defination($t,ctx); })
	;
	
fun	
	: KW_FUNCTION | KW_FN
	;
	
function_return 
	: 
	 ^(RETURN expr_g)
	;

context_expr 
	: 
	 ^(CONTEXT context+ expr_g)
	;

context 
	:  ^(CONTEXT  ANIMATE cexprx)
	|   ^(CONTEXT AT LEVEL operand)
	|  ^(CONTEXT AT TIME operand)
	|  ^(CONTEXT EIN operand)
	| (KW_IN)? KW_COORDSYS 
		(
		    ^(CONTEXT  COORDSYS LOCAL)
		 |  ^(CONTEXT  COORDSYS WORLD)
		 |  ^(CONTEXT COORDSYS PARENT)
		 |  ^(CONTEXT COORDSYS operand) 
		 )
	| KW_ABOUT 
		(  ^(CONTEXT ABOUT PIVOT) 
		|    ^(CONTEXT ABOUT SELECTION)
		|   ^(CONTEXT ABOUT COORDSYS)
		|  ^(CONTEXT ABOUT operand)
		)
	|  ^(CONTEXT  UNDO  cexprx  )
	;

set_context 
	: 
	 ^(SET context)
	;
	
/// Begin Rev


argT	:	
	 ^( IDENTIFIER (operand)? )
	;

argument_expression_list
	:  
	 ^(ARG_EXPR_L argT+)
	;

unary_expression
	: operand
	;
	
operand
	:    
	^(t1=OPERAND IDENTIFIER 
	( 
	  ID_MORE {ZInterp::Operand::_OPERAND($t1);}
	| ^(DOT IDENTIFIER ) ID_MORE
	| ^(ARR_IND expr_g ) ID_MORE
	| ^(arg =ARG_EXPR_L expr_g+ ) ID_MORE {ZInterp::Operand::FunCall($t1,$arg,ctx);}
	)
	)
        | constant
        ;
	
operand_op
	  : ^(DOT IDENTIFIER)
          | ^(ARR_IND expr_g)
          //| argument_expression_list?
          ;

constant
    	: 
    	(
    	  e = DIGIT		
    	| e = HEX_LITERAL
    	| e =  STRING_LITERIAL
    	| e = KW_TRUE
    	| e = KW_FALSE
    	| e = KW_ON
    	| e = KW_OFF
    	| e = KW_OK
    	| e = KW_UNDEFINED
    	| e = KW_UNSUPPLIED
    	)
    	{ ZInterp::Constant::Exec($e); }
    	
    	| SS_HASH IDENTIFIER
   	| array
    	| bitarray
    	| box2
   	| point3
   	| point2
    	| SS_MINUS expr_g
   	| expr_seq
    	;
    	
assignment_expression
	: 
	^(r=assignment_operator l=lvalue e=expr)
	{
	ZInterp::AssingmentExpr::Exec($r.start,$l.start,$e.start);
	}
	| cexprx
	;

cexprx	:
	( 
	  ^(r = SS_D_BAR t1=cexprx t2=cexprx)
	| ^(r = SS_D_AMP t1=cexprx t2=cexprx)
	| ^(r = SS_D_EQUAL t1=cexprx t2=cexprx)
	| ^(r = SS_EXC_EQUAL t1=cexprx t2=cexprx)
	| ^(r = SS_LT t1=cexprx t2=cexprx)
	| ^(r = SS_GT t1=cexprx t2=cexprx)
	| ^(r = SS_LT_EQUAL t1=cexprx t2=cexprx)
	| ^(r = SS_GT_EQUAL t1=cexprx t2=cexprx)
	| ^(r = SS_PLUS t1=cexprx t2=cexprx)	
	| ^(r = SS_MINUS t1=cexprx t2=cexprx)	
	| ^(r = SS_STAR t1=cexprx t2=cexprx)	
	| ^(r = SS_FSLASH t1=cexprx t2=cexprx)	
	| ^(r = SS_PERCENT t1=cexprx t2=cexprx)
	) 
	{ZInterp::Cexprx::Exec($r,$t1.start,$t2.start);}
	
	| unary_expression
	;



	
lvalue
	: 
	  unary_expression
	;

assignment_operator
	: SS_EQUAL
	| SS_STAR_EQUAL
	| SS_FSLASH_EQUAL
	| SS_PERCENT_EQUAL
	| SS_PLUS_EQUAL
	| SS_MINUS_EQUAL
	;

/// End Rev

expr_seq
	:
	^(e=ESEQ{ZInterp::global::IncScope();} expr+{ZInterp::global::DecScope();})
	{
	ZInterp::ExprSeq::_ESEQ($e);
	}
	;
expr_g
	:  expr_seq 
	|  expr	    
	;

	
box2
	:  
	  ^(P_BOX2  expr_g  expr_g  expr_g  expr_g)
	;

point3
	:  
	  ^(P_P3  expr_g  expr_g  expr_g)
	;

point2 
	:  
	  ^(P_P2  expr_g  expr_g)
	;

array 
	:  
	   ARR_A 
	| ^(ARR_A  expr_g+)
	;

bitarray 
	:  ARR_BIT  
	|  ^(ARR_BIT arrrange+ )
	;

arrrange
	: 
	  ^(ARR_BIT_RANGE  arrrange arrrange?)
	;		
