/** \file
 *  This C header file was generated by $ANTLR version 3.2 Sep 23, 2009 12:02:23
 *
 *     -  From the grammar source file : C:\\Zlang\\src\\Zzparser\\Grammar\\yatg.g
 *     -                            On : 2010-06-26 17:43:25
 *     -                for the parser : yatgParserParser *
 * Editing it, at least manually, is not wise. 
 *
 * C language generator and runtime by Jim Idle, jimi|hereisanat|idle|dotgoeshere|ws.
 *
 *
 * The parser yatgParser has the callable functions (rules) shown below,
 * which will invoke the code for the associated rule in the source grammar
 * assuming that the input stream is pointing to a token/text stream that could begin
 * this rule.
 * 
 * For instance if you call the first (topmost) rule in a parser grammar, you will
 * get the results of a full parse, but calling a rule half way through the grammar will
 * allow you to pass part of a full token stream to the parser, such as for syntax checking
 * in editors and so on.
 *
 * The parser entry points are called indirectly (by function pointer to function) via
 * a parser context typedef pyatgParser, which is returned from a call to yatgParserNew().
 *
 * The methods in pyatgParser are  as follows:
 *
 *  - yatgParser_program_return      pyatgParser->program(pyatgParser)
 *  - yatgParser_expr_return      pyatgParser->expr(pyatgParser)
 *  - yatgParser_variable_decls_return      pyatgParser->variable_decls(pyatgParser)
 *  - yatgParser_type_decl_return      pyatgParser->type_decl(pyatgParser)
 *  - yatgParser_decl_return      pyatgParser->decl(pyatgParser)
 *  - yatgParser_if_expr_return      pyatgParser->if_expr(pyatgParser)
 *  - yatgParser_while_loop_return      pyatgParser->while_loop(pyatgParser)
 *  - yatgParser_do_loop_return      pyatgParser->do_loop(pyatgParser)
 *  - yatgParser_for_loop_return      pyatgParser->for_loop(pyatgParser)
 *  - yatgParser_source_return      pyatgParser->source(pyatgParser)
 *  - yatgParser_loop_exit_return      pyatgParser->loop_exit(pyatgParser)
 *  - yatgParser_loop_continue_return      pyatgParser->loop_continue(pyatgParser)
 *  - yatgParser_case_expr_return      pyatgParser->case_expr(pyatgParser)
 *  - yatgParser_case_item_return      pyatgParser->case_item(pyatgParser)
 *  - yatgParser_struct_def_return      pyatgParser->struct_def(pyatgParser)
 *  - yatgParser_member_return      pyatgParser->member(pyatgParser)
 *  - yatgParser_try_expr_return      pyatgParser->try_expr(pyatgParser)
 *  - yatgParser_function_def_return      pyatgParser->function_def(pyatgParser)
 *  - yatgParser_fun_return      pyatgParser->fun(pyatgParser)
 *  - yatgParser_function_return_return      pyatgParser->function_return(pyatgParser)
 *  - yatgParser_context_expr_return      pyatgParser->context_expr(pyatgParser)
 *  - yatgParser_context_return      pyatgParser->context(pyatgParser)
 *  - yatgParser_set_context_return      pyatgParser->set_context(pyatgParser)
 *  - yatgParser_math_expression_return      pyatgParser->math_expression(pyatgParser)
 *  - yatgParser_additive_expression_return      pyatgParser->additive_expression(pyatgParser)
 *  - yatgParser_multiplicative_expression_return      pyatgParser->multiplicative_expression(pyatgParser)
 *  - yatgParser_argT_return      pyatgParser->argT(pyatgParser)
 *  - yatgParser_argument_decl_list_return      pyatgParser->argument_decl_list(pyatgParser)
 *  - yatgParser_argument_expression_list_return      pyatgParser->argument_expression_list(pyatgParser)
 *  - yatgParser_unary_expression_return      pyatgParser->unary_expression(pyatgParser)
 *  - yatgParser_operand_return      pyatgParser->operand(pyatgParser)
 *  - yatgParser_operand_op_return      pyatgParser->operand_op(pyatgParser)
 *  - yatgParser_constant_return      pyatgParser->constant(pyatgParser)
 *  - yatgParser_number_return      pyatgParser->number(pyatgParser)
 *  - yatgParser_constant_expression_return      pyatgParser->constant_expression(pyatgParser)
 *  - yatgParser_assignment_expression_return      pyatgParser->assignment_expression(pyatgParser)
 *  - yatgParser_lvalue_return      pyatgParser->lvalue(pyatgParser)
 *  - yatgParser_assignment_operator_return      pyatgParser->assignment_operator(pyatgParser)
 *  - yatgParser_logical_expression_return      pyatgParser->logical_expression(pyatgParser)
 *  - yatgParser_logical_or_expression_return      pyatgParser->logical_or_expression(pyatgParser)
 *  - yatgParser_logical_and_expression_return      pyatgParser->logical_and_expression(pyatgParser)
 *  - yatgParser_equality_expression_return      pyatgParser->equality_expression(pyatgParser)
 *  - yatgParser_relational_expression_return      pyatgParser->relational_expression(pyatgParser)
 *  - yatgParser_expr_seq_return      pyatgParser->expr_seq(pyatgParser)
 *  - yatgParser_expr_g_return      pyatgParser->expr_g(pyatgParser)
 *  - yatgParser_box2_return      pyatgParser->box2(pyatgParser)
 *  - yatgParser_point3_return      pyatgParser->point3(pyatgParser)
 *  - yatgParser_point2_return      pyatgParser->point2(pyatgParser)
 *  - yatgParser_array_return      pyatgParser->array(pyatgParser)
 *  - yatgParser_bitarray_return      pyatgParser->bitarray(pyatgParser)
 *  - yatgParser_arrrange_return      pyatgParser->arrrange(pyatgParser)
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 *
 * The return type for any particular rule is of course determined by the source
 * grammar file.
 */
// [The "BSD licence"]
// Copyright (c) 2005-2009 Jim Idle, Temporal Wave LLC
// http://www.temporal-wave.com
// http://www.linkedin.com/in/jimidle
//
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions
// are met:
// 1. Redistributions of source code must retain the above copyright
//    notice, this list of conditions and the following disclaimer.
// 2. Redistributions in binary form must reproduce the above copyright
//    notice, this list of conditions and the following disclaimer in the
//    documentation and/or other materials provided with the distribution.
// 3. The name of the author may not be used to endorse or promote products
//    derived from this software without specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR
// IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
// OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
// IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,
// INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT
// NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
// DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
// THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
// (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
// THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

#ifndef	_yatgParser_H
#define _yatgParser_H
/* =============================================================================
 * Standard antlr3 C runtime definitions
 */
#include    <antlr3.h>

/* End of standard antlr 3 runtime definitions
 * =============================================================================
 */
 
#ifdef __cplusplus
extern "C" {
#endif

// Forward declare the context typedef so that we can use it before it is
// properly defined. Delegators and delegates (from import statements) are
// interdependent and their context structures contain pointers to each other
// C only allows such things to be declared if you pre-declare the typedef.
//
typedef struct yatgParser_Ctx_struct yatgParser, * pyatgParser;



#ifdef	ANTLR3_WINDOWS
// Disable: Unreferenced parameter,							- Rules with parameters that are not used
//          constant conditional,							- ANTLR realizes that a prediction is always true (synpred usually)
//          initialized but unused variable					- tree rewrite variables declared but not needed
//          Unreferenced local variable						- lexer rule declares but does not always use _type
//          potentially unitialized variable used			- retval always returned from a rule 
//			unreferenced local function has been removed	- susually getTokenNames or freeScope, they can go without warnigns
//
// These are only really displayed at warning level /W4 but that is the code ideal I am aiming at
// and the codegen must generate some of these warnings by necessity, apart from 4100, which is
// usually generated when a parser rule is given a parameter that it does not use. Mostly though
// this is a matter of orthogonality hence I disable that one.
//
#pragma warning( disable : 4100 )
#pragma warning( disable : 4101 )
#pragma warning( disable : 4127 )
#pragma warning( disable : 4189 )
#pragma warning( disable : 4505 )
#pragma warning( disable : 4701 )
#endif

/* ========================
 * BACKTRACKING IS ENABLED
 * ========================
 */
typedef struct yatgParser_program_return_struct
{
    /** Generic return elements for ANTLR3 rules that are not in tree parsers or returning trees
     */
    pANTLR3_COMMON_TOKEN    start;
    pANTLR3_COMMON_TOKEN    stop;
    pANTLR3_BASE_TREE	tree;
   
}
    yatgParser_program_return;

typedef struct yatgParser_expr_return_struct
{
    /** Generic return elements for ANTLR3 rules that are not in tree parsers or returning trees
     */
    pANTLR3_COMMON_TOKEN    start;
    pANTLR3_COMMON_TOKEN    stop;
    pANTLR3_BASE_TREE	tree;
   
}
    yatgParser_expr_return;

typedef struct yatgParser_variable_decls_return_struct
{
    /** Generic return elements for ANTLR3 rules that are not in tree parsers or returning trees
     */
    pANTLR3_COMMON_TOKEN    start;
    pANTLR3_COMMON_TOKEN    stop;
    pANTLR3_BASE_TREE	tree;
   
}
    yatgParser_variable_decls_return;

typedef struct yatgParser_type_decl_return_struct
{
    /** Generic return elements for ANTLR3 rules that are not in tree parsers or returning trees
     */
    pANTLR3_COMMON_TOKEN    start;
    pANTLR3_COMMON_TOKEN    stop;
    pANTLR3_BASE_TREE	tree;
   
}
    yatgParser_type_decl_return;

typedef struct yatgParser_decl_return_struct
{
    /** Generic return elements for ANTLR3 rules that are not in tree parsers or returning trees
     */
    pANTLR3_COMMON_TOKEN    start;
    pANTLR3_COMMON_TOKEN    stop;
    pANTLR3_BASE_TREE	tree;
   
}
    yatgParser_decl_return;

typedef struct yatgParser_if_expr_return_struct
{
    /** Generic return elements for ANTLR3 rules that are not in tree parsers or returning trees
     */
    pANTLR3_COMMON_TOKEN    start;
    pANTLR3_COMMON_TOKEN    stop;
    pANTLR3_BASE_TREE	tree;
   
}
    yatgParser_if_expr_return;

typedef struct yatgParser_while_loop_return_struct
{
    /** Generic return elements for ANTLR3 rules that are not in tree parsers or returning trees
     */
    pANTLR3_COMMON_TOKEN    start;
    pANTLR3_COMMON_TOKEN    stop;
    pANTLR3_BASE_TREE	tree;
   
}
    yatgParser_while_loop_return;

typedef struct yatgParser_do_loop_return_struct
{
    /** Generic return elements for ANTLR3 rules that are not in tree parsers or returning trees
     */
    pANTLR3_COMMON_TOKEN    start;
    pANTLR3_COMMON_TOKEN    stop;
    pANTLR3_BASE_TREE	tree;
   
}
    yatgParser_do_loop_return;

typedef struct yatgParser_for_loop_return_struct
{
    /** Generic return elements for ANTLR3 rules that are not in tree parsers or returning trees
     */
    pANTLR3_COMMON_TOKEN    start;
    pANTLR3_COMMON_TOKEN    stop;
    pANTLR3_BASE_TREE	tree;
   
}
    yatgParser_for_loop_return;

typedef struct yatgParser_source_return_struct
{
    /** Generic return elements for ANTLR3 rules that are not in tree parsers or returning trees
     */
    pANTLR3_COMMON_TOKEN    start;
    pANTLR3_COMMON_TOKEN    stop;
    pANTLR3_BASE_TREE	tree;
   
}
    yatgParser_source_return;

typedef struct yatgParser_loop_exit_return_struct
{
    /** Generic return elements for ANTLR3 rules that are not in tree parsers or returning trees
     */
    pANTLR3_COMMON_TOKEN    start;
    pANTLR3_COMMON_TOKEN    stop;
    pANTLR3_BASE_TREE	tree;
   
}
    yatgParser_loop_exit_return;

typedef struct yatgParser_loop_continue_return_struct
{
    /** Generic return elements for ANTLR3 rules that are not in tree parsers or returning trees
     */
    pANTLR3_COMMON_TOKEN    start;
    pANTLR3_COMMON_TOKEN    stop;
    pANTLR3_BASE_TREE	tree;
   
}
    yatgParser_loop_continue_return;

typedef struct yatgParser_case_expr_return_struct
{
    /** Generic return elements for ANTLR3 rules that are not in tree parsers or returning trees
     */
    pANTLR3_COMMON_TOKEN    start;
    pANTLR3_COMMON_TOKEN    stop;
    pANTLR3_BASE_TREE	tree;
   
}
    yatgParser_case_expr_return;

typedef struct yatgParser_case_item_return_struct
{
    /** Generic return elements for ANTLR3 rules that are not in tree parsers or returning trees
     */
    pANTLR3_COMMON_TOKEN    start;
    pANTLR3_COMMON_TOKEN    stop;
    pANTLR3_BASE_TREE	tree;
   
}
    yatgParser_case_item_return;

typedef struct yatgParser_struct_def_return_struct
{
    /** Generic return elements for ANTLR3 rules that are not in tree parsers or returning trees
     */
    pANTLR3_COMMON_TOKEN    start;
    pANTLR3_COMMON_TOKEN    stop;
    pANTLR3_BASE_TREE	tree;
   
}
    yatgParser_struct_def_return;

typedef struct yatgParser_member_return_struct
{
    /** Generic return elements for ANTLR3 rules that are not in tree parsers or returning trees
     */
    pANTLR3_COMMON_TOKEN    start;
    pANTLR3_COMMON_TOKEN    stop;
    pANTLR3_BASE_TREE	tree;
   
}
    yatgParser_member_return;

typedef struct yatgParser_try_expr_return_struct
{
    /** Generic return elements for ANTLR3 rules that are not in tree parsers or returning trees
     */
    pANTLR3_COMMON_TOKEN    start;
    pANTLR3_COMMON_TOKEN    stop;
    pANTLR3_BASE_TREE	tree;
   
}
    yatgParser_try_expr_return;

typedef struct yatgParser_function_def_return_struct
{
    /** Generic return elements for ANTLR3 rules that are not in tree parsers or returning trees
     */
    pANTLR3_COMMON_TOKEN    start;
    pANTLR3_COMMON_TOKEN    stop;
    pANTLR3_BASE_TREE	tree;
   
}
    yatgParser_function_def_return;

typedef struct yatgParser_fun_return_struct
{
    /** Generic return elements for ANTLR3 rules that are not in tree parsers or returning trees
     */
    pANTLR3_COMMON_TOKEN    start;
    pANTLR3_COMMON_TOKEN    stop;
    pANTLR3_BASE_TREE	tree;
   
}
    yatgParser_fun_return;

typedef struct yatgParser_function_return_return_struct
{
    /** Generic return elements for ANTLR3 rules that are not in tree parsers or returning trees
     */
    pANTLR3_COMMON_TOKEN    start;
    pANTLR3_COMMON_TOKEN    stop;
    pANTLR3_BASE_TREE	tree;
   
}
    yatgParser_function_return_return;

typedef struct yatgParser_context_expr_return_struct
{
    /** Generic return elements for ANTLR3 rules that are not in tree parsers or returning trees
     */
    pANTLR3_COMMON_TOKEN    start;
    pANTLR3_COMMON_TOKEN    stop;
    pANTLR3_BASE_TREE	tree;
   
}
    yatgParser_context_expr_return;

typedef struct yatgParser_context_return_struct
{
    /** Generic return elements for ANTLR3 rules that are not in tree parsers or returning trees
     */
    pANTLR3_COMMON_TOKEN    start;
    pANTLR3_COMMON_TOKEN    stop;
    pANTLR3_BASE_TREE	tree;
   
}
    yatgParser_context_return;

typedef struct yatgParser_set_context_return_struct
{
    /** Generic return elements for ANTLR3 rules that are not in tree parsers or returning trees
     */
    pANTLR3_COMMON_TOKEN    start;
    pANTLR3_COMMON_TOKEN    stop;
    pANTLR3_BASE_TREE	tree;
   
}
    yatgParser_set_context_return;

typedef struct yatgParser_math_expression_return_struct
{
    /** Generic return elements for ANTLR3 rules that are not in tree parsers or returning trees
     */
    pANTLR3_COMMON_TOKEN    start;
    pANTLR3_COMMON_TOKEN    stop;
    pANTLR3_BASE_TREE	tree;
   
}
    yatgParser_math_expression_return;

typedef struct yatgParser_additive_expression_return_struct
{
    /** Generic return elements for ANTLR3 rules that are not in tree parsers or returning trees
     */
    pANTLR3_COMMON_TOKEN    start;
    pANTLR3_COMMON_TOKEN    stop;
    pANTLR3_BASE_TREE	tree;
   
}
    yatgParser_additive_expression_return;

typedef struct yatgParser_multiplicative_expression_return_struct
{
    /** Generic return elements for ANTLR3 rules that are not in tree parsers or returning trees
     */
    pANTLR3_COMMON_TOKEN    start;
    pANTLR3_COMMON_TOKEN    stop;
    pANTLR3_BASE_TREE	tree;
   
}
    yatgParser_multiplicative_expression_return;

typedef struct yatgParser_argT_return_struct
{
    /** Generic return elements for ANTLR3 rules that are not in tree parsers or returning trees
     */
    pANTLR3_COMMON_TOKEN    start;
    pANTLR3_COMMON_TOKEN    stop;
    pANTLR3_BASE_TREE	tree;
   
}
    yatgParser_argT_return;

typedef struct yatgParser_argument_decl_list_return_struct
{
    /** Generic return elements for ANTLR3 rules that are not in tree parsers or returning trees
     */
    pANTLR3_COMMON_TOKEN    start;
    pANTLR3_COMMON_TOKEN    stop;
    pANTLR3_BASE_TREE	tree;
   
}
    yatgParser_argument_decl_list_return;

typedef struct yatgParser_argument_expression_list_return_struct
{
    /** Generic return elements for ANTLR3 rules that are not in tree parsers or returning trees
     */
    pANTLR3_COMMON_TOKEN    start;
    pANTLR3_COMMON_TOKEN    stop;
    pANTLR3_BASE_TREE	tree;
   
}
    yatgParser_argument_expression_list_return;

typedef struct yatgParser_unary_expression_return_struct
{
    /** Generic return elements for ANTLR3 rules that are not in tree parsers or returning trees
     */
    pANTLR3_COMMON_TOKEN    start;
    pANTLR3_COMMON_TOKEN    stop;
    pANTLR3_BASE_TREE	tree;
   
}
    yatgParser_unary_expression_return;

typedef struct yatgParser_operand_return_struct
{
    /** Generic return elements for ANTLR3 rules that are not in tree parsers or returning trees
     */
    pANTLR3_COMMON_TOKEN    start;
    pANTLR3_COMMON_TOKEN    stop;
    pANTLR3_BASE_TREE	tree;
   
}
    yatgParser_operand_return;

typedef struct yatgParser_operand_op_return_struct
{
    /** Generic return elements for ANTLR3 rules that are not in tree parsers or returning trees
     */
    pANTLR3_COMMON_TOKEN    start;
    pANTLR3_COMMON_TOKEN    stop;
    pANTLR3_BASE_TREE	tree;
   
}
    yatgParser_operand_op_return;

typedef struct yatgParser_constant_return_struct
{
    /** Generic return elements for ANTLR3 rules that are not in tree parsers or returning trees
     */
    pANTLR3_COMMON_TOKEN    start;
    pANTLR3_COMMON_TOKEN    stop;
    pANTLR3_BASE_TREE	tree;
   
}
    yatgParser_constant_return;

typedef struct yatgParser_number_return_struct
{
    /** Generic return elements for ANTLR3 rules that are not in tree parsers or returning trees
     */
    pANTLR3_COMMON_TOKEN    start;
    pANTLR3_COMMON_TOKEN    stop;
    pANTLR3_BASE_TREE	tree;
   
}
    yatgParser_number_return;

typedef struct yatgParser_constant_expression_return_struct
{
    /** Generic return elements for ANTLR3 rules that are not in tree parsers or returning trees
     */
    pANTLR3_COMMON_TOKEN    start;
    pANTLR3_COMMON_TOKEN    stop;
    pANTLR3_BASE_TREE	tree;
   
}
    yatgParser_constant_expression_return;

typedef struct yatgParser_assignment_expression_return_struct
{
    /** Generic return elements for ANTLR3 rules that are not in tree parsers or returning trees
     */
    pANTLR3_COMMON_TOKEN    start;
    pANTLR3_COMMON_TOKEN    stop;
    pANTLR3_BASE_TREE	tree;
   
}
    yatgParser_assignment_expression_return;

typedef struct yatgParser_lvalue_return_struct
{
    /** Generic return elements for ANTLR3 rules that are not in tree parsers or returning trees
     */
    pANTLR3_COMMON_TOKEN    start;
    pANTLR3_COMMON_TOKEN    stop;
    pANTLR3_BASE_TREE	tree;
   
}
    yatgParser_lvalue_return;

typedef struct yatgParser_assignment_operator_return_struct
{
    /** Generic return elements for ANTLR3 rules that are not in tree parsers or returning trees
     */
    pANTLR3_COMMON_TOKEN    start;
    pANTLR3_COMMON_TOKEN    stop;
    pANTLR3_BASE_TREE	tree;
   
}
    yatgParser_assignment_operator_return;

typedef struct yatgParser_logical_expression_return_struct
{
    /** Generic return elements for ANTLR3 rules that are not in tree parsers or returning trees
     */
    pANTLR3_COMMON_TOKEN    start;
    pANTLR3_COMMON_TOKEN    stop;
    pANTLR3_BASE_TREE	tree;
   
}
    yatgParser_logical_expression_return;

typedef struct yatgParser_logical_or_expression_return_struct
{
    /** Generic return elements for ANTLR3 rules that are not in tree parsers or returning trees
     */
    pANTLR3_COMMON_TOKEN    start;
    pANTLR3_COMMON_TOKEN    stop;
    pANTLR3_BASE_TREE	tree;
   
}
    yatgParser_logical_or_expression_return;

typedef struct yatgParser_logical_and_expression_return_struct
{
    /** Generic return elements for ANTLR3 rules that are not in tree parsers or returning trees
     */
    pANTLR3_COMMON_TOKEN    start;
    pANTLR3_COMMON_TOKEN    stop;
    pANTLR3_BASE_TREE	tree;
   
}
    yatgParser_logical_and_expression_return;

typedef struct yatgParser_equality_expression_return_struct
{
    /** Generic return elements for ANTLR3 rules that are not in tree parsers or returning trees
     */
    pANTLR3_COMMON_TOKEN    start;
    pANTLR3_COMMON_TOKEN    stop;
    pANTLR3_BASE_TREE	tree;
   
}
    yatgParser_equality_expression_return;

typedef struct yatgParser_relational_expression_return_struct
{
    /** Generic return elements for ANTLR3 rules that are not in tree parsers or returning trees
     */
    pANTLR3_COMMON_TOKEN    start;
    pANTLR3_COMMON_TOKEN    stop;
    pANTLR3_BASE_TREE	tree;
   
}
    yatgParser_relational_expression_return;

typedef struct yatgParser_expr_seq_return_struct
{
    /** Generic return elements for ANTLR3 rules that are not in tree parsers or returning trees
     */
    pANTLR3_COMMON_TOKEN    start;
    pANTLR3_COMMON_TOKEN    stop;
    pANTLR3_BASE_TREE	tree;
   
}
    yatgParser_expr_seq_return;

typedef struct yatgParser_expr_g_return_struct
{
    /** Generic return elements for ANTLR3 rules that are not in tree parsers or returning trees
     */
    pANTLR3_COMMON_TOKEN    start;
    pANTLR3_COMMON_TOKEN    stop;
    pANTLR3_BASE_TREE	tree;
   
}
    yatgParser_expr_g_return;

typedef struct yatgParser_box2_return_struct
{
    /** Generic return elements for ANTLR3 rules that are not in tree parsers or returning trees
     */
    pANTLR3_COMMON_TOKEN    start;
    pANTLR3_COMMON_TOKEN    stop;
    pANTLR3_BASE_TREE	tree;
   
}
    yatgParser_box2_return;

typedef struct yatgParser_point3_return_struct
{
    /** Generic return elements for ANTLR3 rules that are not in tree parsers or returning trees
     */
    pANTLR3_COMMON_TOKEN    start;
    pANTLR3_COMMON_TOKEN    stop;
    pANTLR3_BASE_TREE	tree;
   
}
    yatgParser_point3_return;

typedef struct yatgParser_point2_return_struct
{
    /** Generic return elements for ANTLR3 rules that are not in tree parsers or returning trees
     */
    pANTLR3_COMMON_TOKEN    start;
    pANTLR3_COMMON_TOKEN    stop;
    pANTLR3_BASE_TREE	tree;
   
}
    yatgParser_point2_return;

typedef struct yatgParser_array_return_struct
{
    /** Generic return elements for ANTLR3 rules that are not in tree parsers or returning trees
     */
    pANTLR3_COMMON_TOKEN    start;
    pANTLR3_COMMON_TOKEN    stop;
    pANTLR3_BASE_TREE	tree;
   
}
    yatgParser_array_return;

typedef struct yatgParser_bitarray_return_struct
{
    /** Generic return elements for ANTLR3 rules that are not in tree parsers or returning trees
     */
    pANTLR3_COMMON_TOKEN    start;
    pANTLR3_COMMON_TOKEN    stop;
    pANTLR3_BASE_TREE	tree;
   
}
    yatgParser_bitarray_return;

typedef struct yatgParser_arrrange_return_struct
{
    /** Generic return elements for ANTLR3 rules that are not in tree parsers or returning trees
     */
    pANTLR3_COMMON_TOKEN    start;
    pANTLR3_COMMON_TOKEN    stop;
    pANTLR3_BASE_TREE	tree;
   
}
    yatgParser_arrrange_return;



/** Context tracking structure for yatgParser
 */
struct yatgParser_Ctx_struct
{
    /** Built in ANTLR3 context tracker contains all the generic elements
     *  required for context tracking.
     */
    pANTLR3_PARSER   pParser;


     yatgParser_program_return (*program)	(struct yatgParser_Ctx_struct * ctx);
     yatgParser_expr_return (*expr)	(struct yatgParser_Ctx_struct * ctx);
     yatgParser_variable_decls_return (*variable_decls)	(struct yatgParser_Ctx_struct * ctx);
     yatgParser_type_decl_return (*type_decl)	(struct yatgParser_Ctx_struct * ctx);
     yatgParser_decl_return (*decl)	(struct yatgParser_Ctx_struct * ctx);
     yatgParser_if_expr_return (*if_expr)	(struct yatgParser_Ctx_struct * ctx);
     yatgParser_while_loop_return (*while_loop)	(struct yatgParser_Ctx_struct * ctx);
     yatgParser_do_loop_return (*do_loop)	(struct yatgParser_Ctx_struct * ctx);
     yatgParser_for_loop_return (*for_loop)	(struct yatgParser_Ctx_struct * ctx);
     yatgParser_source_return (*source)	(struct yatgParser_Ctx_struct * ctx);
     yatgParser_loop_exit_return (*loop_exit)	(struct yatgParser_Ctx_struct * ctx);
     yatgParser_loop_continue_return (*loop_continue)	(struct yatgParser_Ctx_struct * ctx);
     yatgParser_case_expr_return (*case_expr)	(struct yatgParser_Ctx_struct * ctx);
     yatgParser_case_item_return (*case_item)	(struct yatgParser_Ctx_struct * ctx);
     yatgParser_struct_def_return (*struct_def)	(struct yatgParser_Ctx_struct * ctx);
     yatgParser_member_return (*member)	(struct yatgParser_Ctx_struct * ctx);
     yatgParser_try_expr_return (*try_expr)	(struct yatgParser_Ctx_struct * ctx);
     yatgParser_function_def_return (*function_def)	(struct yatgParser_Ctx_struct * ctx);
     yatgParser_fun_return (*fun)	(struct yatgParser_Ctx_struct * ctx);
     yatgParser_function_return_return (*function_return)	(struct yatgParser_Ctx_struct * ctx);
     yatgParser_context_expr_return (*context_expr)	(struct yatgParser_Ctx_struct * ctx);
     yatgParser_context_return (*context)	(struct yatgParser_Ctx_struct * ctx);
     yatgParser_set_context_return (*set_context)	(struct yatgParser_Ctx_struct * ctx);
     yatgParser_math_expression_return (*math_expression)	(struct yatgParser_Ctx_struct * ctx);
     yatgParser_additive_expression_return (*additive_expression)	(struct yatgParser_Ctx_struct * ctx);
     yatgParser_multiplicative_expression_return (*multiplicative_expression)	(struct yatgParser_Ctx_struct * ctx);
     yatgParser_argT_return (*argT)	(struct yatgParser_Ctx_struct * ctx);
     yatgParser_argument_decl_list_return (*argument_decl_list)	(struct yatgParser_Ctx_struct * ctx);
     yatgParser_argument_expression_list_return (*argument_expression_list)	(struct yatgParser_Ctx_struct * ctx);
     yatgParser_unary_expression_return (*unary_expression)	(struct yatgParser_Ctx_struct * ctx);
     yatgParser_operand_return (*operand)	(struct yatgParser_Ctx_struct * ctx);
     yatgParser_operand_op_return (*operand_op)	(struct yatgParser_Ctx_struct * ctx);
     yatgParser_constant_return (*constant)	(struct yatgParser_Ctx_struct * ctx);
     yatgParser_number_return (*number)	(struct yatgParser_Ctx_struct * ctx);
     yatgParser_constant_expression_return (*constant_expression)	(struct yatgParser_Ctx_struct * ctx);
     yatgParser_assignment_expression_return (*assignment_expression)	(struct yatgParser_Ctx_struct * ctx);
     yatgParser_lvalue_return (*lvalue)	(struct yatgParser_Ctx_struct * ctx);
     yatgParser_assignment_operator_return (*assignment_operator)	(struct yatgParser_Ctx_struct * ctx);
     yatgParser_logical_expression_return (*logical_expression)	(struct yatgParser_Ctx_struct * ctx);
     yatgParser_logical_or_expression_return (*logical_or_expression)	(struct yatgParser_Ctx_struct * ctx);
     yatgParser_logical_and_expression_return (*logical_and_expression)	(struct yatgParser_Ctx_struct * ctx);
     yatgParser_equality_expression_return (*equality_expression)	(struct yatgParser_Ctx_struct * ctx);
     yatgParser_relational_expression_return (*relational_expression)	(struct yatgParser_Ctx_struct * ctx);
     yatgParser_expr_seq_return (*expr_seq)	(struct yatgParser_Ctx_struct * ctx);
     yatgParser_expr_g_return (*expr_g)	(struct yatgParser_Ctx_struct * ctx);
     yatgParser_box2_return (*box2)	(struct yatgParser_Ctx_struct * ctx);
     yatgParser_point3_return (*point3)	(struct yatgParser_Ctx_struct * ctx);
     yatgParser_point2_return (*point2)	(struct yatgParser_Ctx_struct * ctx);
     yatgParser_array_return (*array)	(struct yatgParser_Ctx_struct * ctx);
     yatgParser_bitarray_return (*bitarray)	(struct yatgParser_Ctx_struct * ctx);
     yatgParser_arrrange_return (*arrrange)	(struct yatgParser_Ctx_struct * ctx);
     ANTLR3_BOOLEAN (*synpred2_yatg)	(struct yatgParser_Ctx_struct * ctx);
     ANTLR3_BOOLEAN (*synpred16_yatg)	(struct yatgParser_Ctx_struct * ctx);
     ANTLR3_BOOLEAN (*synpred20_yatg)	(struct yatgParser_Ctx_struct * ctx);
     ANTLR3_BOOLEAN (*synpred26_yatg)	(struct yatgParser_Ctx_struct * ctx);
     ANTLR3_BOOLEAN (*synpred53_yatg)	(struct yatgParser_Ctx_struct * ctx);
     ANTLR3_BOOLEAN (*synpred60_yatg)	(struct yatgParser_Ctx_struct * ctx);
     ANTLR3_BOOLEAN (*synpred69_yatg)	(struct yatgParser_Ctx_struct * ctx);
     ANTLR3_BOOLEAN (*synpred71_yatg)	(struct yatgParser_Ctx_struct * ctx);
     ANTLR3_BOOLEAN (*synpred72_yatg)	(struct yatgParser_Ctx_struct * ctx);
     ANTLR3_BOOLEAN (*synpred73_yatg)	(struct yatgParser_Ctx_struct * ctx);
     ANTLR3_BOOLEAN (*synpred83_yatg)	(struct yatgParser_Ctx_struct * ctx);
     ANTLR3_BOOLEAN (*synpred98_yatg)	(struct yatgParser_Ctx_struct * ctx);
     ANTLR3_BOOLEAN (*synpred101_yatg)	(struct yatgParser_Ctx_struct * ctx);
    // Delegated rules
    const char * (*getGrammarFileName)();
    void	    (*free)   (struct yatgParser_Ctx_struct * ctx);
    /* @headerFile.members() */
    pANTLR3_BASE_TREE_ADAPTOR	adaptor;
    pANTLR3_VECTOR_FACTORY		vectors;
    /* End @headerFile.members() */
};

// Function protoypes for the constructor functions that external translation units
// such as delegators and delegates may wish to call.
//
ANTLR3_API pyatgParser yatgParserNew         (pANTLR3_COMMON_TOKEN_STREAM instream);
ANTLR3_API pyatgParser yatgParserNewSSD      (pANTLR3_COMMON_TOKEN_STREAM instream, pANTLR3_RECOGNIZER_SHARED_STATE state);

/** Symbolic definitions of all the tokens that the parser will work with.
 * \{
 *
 * Antlr will define EOF, but we can't use that as it it is too common in
 * in C header files and that would be confusing. There is no way to filter this out at the moment
 * so we just undef it here for now. That isn't the value we get back from C recognizers
 * anyway. We are looking for ANTLR3_TOKEN_EOF.
 */
#ifdef	EOF
#undef	EOF
#endif
#ifdef	Tokens
#undef	Tokens
#endif 
#define PIVOT      60
#define SS_PLUS_EQUAL      145
#define SS_D_DOT      157
#define SS_CCBRACKET      156
#define LETTER      161
#define EWHILE_EXP      15
#define SS_FSLASH      126
#define EIF_ELSE      11
#define CASE      39
#define KW_DEFAULT      103
#define ESEQ      7
#define P_P2      30
#define P_P3      31
#define UNDO      69
#define KW_WHERE      94
#define STRING_LITERIAL      132
#define KW_FN      109
#define EOF      -1
#define SS_PERCENT      127
#define KW_GLOBAL      81
#define EOL      164
#define KW_UNDEFINED      139
#define EIF_COND      9
#define KW_LEVEL      113
#define EWHILE_CON      14
#define KW_PARENT      117
#define LP_EXIT      36
#define SS_D_BAR      147
#define LP_EXIT_WITH      37
#define EDO      17
#define RETURN      49
#define KW_THEN      85
#define SS_LT_EQUAL      153
#define COORDSYS      58
#define BODY      52
#define KW_COORDSYS      115
#define SS_STAR      125
#define COMMENT      165
#define ARR_BIT      33
#define SS_GT      152
#define KW_EXIT      95
#define SS_COLON      102
#define ABOUT      61
#define KW_FUNCTION      108
#define ESRC_WHERE      28
#define EDO_CON      18
#define SS_COMMA      79
#define LINE_COMMENT      166
#define SS_DOT      128
#define ECATCH_EXP      48
#define KW_CATCH      106
#define NUMBER      78
#define P_BOX2      29
#define SS_D_EQUAL      149
#define LOCAL      62
#define KW_DO      86
#define SS_MINUS_EQUAL      146
#define SS_STAR_EQUAL      142
#define EWHILE      13
#define KW_ANIMATE      111
#define KW_ABOUT      118
#define EFOR      21
#define FUN_DEF      50
#define PRIM_EXP      77
#define SS_D_AMP      148
#define SS_CBRACKET      130
#define WS      163
#define SS_GT_EQUAL      154
#define SS_MINUS      124
#define LEVEL      65
#define SS_DQUOTE      159
#define KW_TO      92
#define EFOR_END      24
#define KW_BY      93
#define ETRY      46
#define ESRC_START      25
#define FUN      53
#define KW_LOCAL      80
#define EscapeSequence      158
#define SS_EQUAL      83
#define KW_ELSE      87
#define SS_EXC_EQUAL      150
#define MEMBER      45
#define MAPPED      54
#define ID_MORE      75
#define ARR_IND      35
#define SS_OPAREN      100
#define EDO_END      20
#define KW_UNSUPPLIED      140
#define KW_SELECTION      120
#define SS_CPAREN      101
#define KW_TRUE      134
#define HexDigit      162
#define KW_PIVOT      119
#define KW_WITH      96
#define CONTEXT      57
#define SELECTION      59
#define REF_OP      167
#define VDECL      4
#define AT      71
#define ECASE_END      43
#define TIME      67
#define KW_MAPPED      107
#define VDEF      5
#define PARENT      64
#define SS_PLUS      123
#define KW_TIME      114
#define EFOR_SRC      22
#define KW_STRUCT      104
#define EWHILE_END      16
#define VVAL      6
#define KW_WHILE      88
#define KW_FOR      89
#define IDENTIFIER      82
#define CASE_Exp      40
#define LP_CONT      38
#define OPERAND      72
#define KW_SET      122
#define KW_RETURN      110
#define EFOR_EXP      23
#define KW_IN      90
#define HEX_LITERAL      131
#define ESRC_BY      27
#define DIGIT      141
#define KW_TRY      105
#define ARR_A      32
#define DOT      73
#define KW_UNDO      121
#define KW_IF      84
#define ARR_BIT_RANGE      34
#define WITH      68
#define CASE_Item      41
#define EIF_END      12
#define ETRY_EXP      47
#define SS_OCBRACKET      155
#define WORLD      63
#define KW_FALSE      135
#define KW_OFF      137
#define DEFAULT      42
#define KW_CONTINUE      97
#define FUN_NAME      51
#define STRUCT      44
#define ARG_EXPR_L      74
#define SET      76
#define SS_LT      151
#define EDO_EXP      19
#define KW_CASE      98
#define FUN_DEF_END      55
#define KW_COLLECT      91
#define SS_PERCENT_EQUAL      144
#define EIN      70
#define EIF      8
#define KW_WORLD      116
#define KW_ON      136
#define ESQ_FSLASH_SQUOTE      160
#define SS_HASH      133
#define KW_OK      138
#define KW_AT      112
#define EIF_THEN      10
#define KW_OF      99
#define SS_OBRACKET      129
#define ANIMATE      66
#define ESRC_TO      26
#define SS_FSLASH_EQUAL      143
#define STRING      56
#ifdef	EOF
#undef	EOF
#define	EOF	ANTLR3_TOKEN_EOF
#endif

#ifndef TOKENSOURCE
#define TOKENSOURCE(lxr) lxr->pLexer->rec->state->tokSource
#endif

/* End of token definitions for yatgParser
 * =============================================================================
 */
/** \} */

#ifdef __cplusplus
}
#endif

#endif

/* END - Note:Keep extra line feed to satisfy UNIX systems */
