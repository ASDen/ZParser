/** \file
 *  This C header file was generated by $ANTLR version 3.2 Sep 23, 2009 12:02:23
 *
 *     -  From the grammar source file : yatg.g
 *     -                            On : 2010-01-08 22:55:31
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
     ANTLR3_BOOLEAN (*synpred18_yatg)	(struct yatgParser_Ctx_struct * ctx);
     ANTLR3_BOOLEAN (*synpred20_yatg)	(struct yatgParser_Ctx_struct * ctx);
     ANTLR3_BOOLEAN (*synpred26_yatg)	(struct yatgParser_Ctx_struct * ctx);
     ANTLR3_BOOLEAN (*synpred53_yatg)	(struct yatgParser_Ctx_struct * ctx);
     ANTLR3_BOOLEAN (*synpred56_yatg)	(struct yatgParser_Ctx_struct * ctx);
     ANTLR3_BOOLEAN (*synpred60_yatg)	(struct yatgParser_Ctx_struct * ctx);
     ANTLR3_BOOLEAN (*synpred69_yatg)	(struct yatgParser_Ctx_struct * ctx);
     ANTLR3_BOOLEAN (*synpred71_yatg)	(struct yatgParser_Ctx_struct * ctx);
     ANTLR3_BOOLEAN (*synpred72_yatg)	(struct yatgParser_Ctx_struct * ctx);
     ANTLR3_BOOLEAN (*synpred73_yatg)	(struct yatgParser_Ctx_struct * ctx);
     ANTLR3_BOOLEAN (*synpred82_yatg)	(struct yatgParser_Ctx_struct * ctx);
     ANTLR3_BOOLEAN (*synpred88_yatg)	(struct yatgParser_Ctx_struct * ctx);
     ANTLR3_BOOLEAN (*synpred89_yatg)	(struct yatgParser_Ctx_struct * ctx);
     ANTLR3_BOOLEAN (*synpred91_yatg)	(struct yatgParser_Ctx_struct * ctx);
     ANTLR3_BOOLEAN (*synpred95_yatg)	(struct yatgParser_Ctx_struct * ctx);
     ANTLR3_BOOLEAN (*synpred97_yatg)	(struct yatgParser_Ctx_struct * ctx);
     ANTLR3_BOOLEAN (*synpred100_yatg)	(struct yatgParser_Ctx_struct * ctx);
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
#define PIVOT      59
#define SS_PLUS_EQUAL      143
#define SS_D_DOT      155
#define SS_CCBRACKET      154
#define LETTER      159
#define EWHILE_EXP      15
#define SS_FSLASH      124
#define EIF_ELSE      11
#define CASE      39
#define KW_DEFAULT      101
#define ESEQ      7
#define P_P2      30
#define P_P3      31
#define UNDO      68
#define KW_WHERE      92
#define STRING_LITERIAL      131
#define KW_FN      107
#define EOF      -1
#define SS_PERCENT      125
#define KW_GLOBAL      79
#define EOL      162
#define KW_UNDEFINED      138
#define EIF_COND      9
#define KW_LEVEL      111
#define EWHILE_CON      14
#define KW_PARENT      115
#define LP_EXIT      36
#define SS_D_BAR      145
#define LP_EXIT_WITH      37
#define EDO      17
#define RETURN      48
#define KW_THEN      83
#define SS_LT_EQUAL      151
#define COORDSYS      57
#define BODY      51
#define KW_COORDSYS      113
#define SS_STAR      123
#define COMMENT      163
#define ARR_BIT      33
#define SS_GT      150
#define KW_EXIT      93
#define SS_COLON      100
#define ABOUT      60
#define KW_FUNCTION      106
#define ESRC_WHERE      28
#define EDO_CON      18
#define SS_COMMA      77
#define LINE_COMMENT      164
#define SS_DOT      126
#define ECATCH_EXP      47
#define KW_CATCH      104
#define P_BOX2      29
#define SS_D_EQUAL      147
#define LOCAL      61
#define KW_DO      84
#define SS_MINUS_EQUAL      144
#define SS_STAR_EQUAL      140
#define EWHILE      13
#define KW_ANIMATE      109
#define KW_ABOUT      116
#define EFOR      21
#define FUN_DEF      49
#define PRIM_EXP      76
#define SS_D_AMP      146
#define SS_CBRACKET      128
#define WS      161
#define SS_GT_EQUAL      152
#define SS_MINUS      122
#define LEVEL      64
#define SS_DQUOTE      157
#define EFOR_END      24
#define KW_TO      90
#define ETRY      45
#define KW_BY      91
#define ESRC_START      25
#define FUN      52
#define KW_LOCAL      78
#define EscapeSequence      156
#define SS_EQUAL      81
#define KW_ELSE      85
#define SS_EXC_EQUAL      148
#define MEMBER      44
#define MAPPED      53
#define ID_MORE      74
#define ARR_IND      35
#define SS_OPAREN      98
#define EDO_END      20
#define KW_UNSUPPLIED      139
#define KW_SELECTION      118
#define SS_CPAREN      99
#define KW_TRUE      133
#define HexDigit      160
#define KW_PIVOT      117
#define KW_WITH      94
#define CONTEXT      56
#define SELECTION      58
#define VDECL      4
#define AT      70
#define TIME      66
#define KW_MAPPED      105
#define VDEF      5
#define PARENT      63
#define SS_PLUS      121
#define KW_TIME      112
#define EFOR_SRC      22
#define KW_STRUCT      102
#define EWHILE_END      16
#define VVAL      6
#define KW_WHILE      86
#define KW_FOR      87
#define IDENTIFIER      80
#define CASE_Exp      40
#define LP_CONT      38
#define OPERAND      71
#define KW_SET      120
#define KW_RETURN      108
#define EFOR_EXP      23
#define KW_IN      88
#define HEX_LITERAL      130
#define ESRC_BY      27
#define DIGIT      129
#define KW_TRY      103
#define ARR_A      32
#define DOT      72
#define KW_UNDO      119
#define KW_IF      82
#define ARR_BIT_RANGE      34
#define WITH      67
#define CASE_Item      41
#define EIF_END      12
#define ETRY_EXP      46
#define SS_OCBRACKET      153
#define WORLD      62
#define KW_FALSE      134
#define KW_OFF      136
#define DEFAULT      42
#define KW_CONTINUE      95
#define FUN_NAME      50
#define STRUCT      43
#define ARG_EXPR_L      73
#define SET      75
#define SS_LT      149
#define EDO_EXP      19
#define KW_CASE      96
#define FUN_DEF_END      54
#define KW_COLLECT      89
#define SS_PERCENT_EQUAL      142
#define EIN      69
#define EIF      8
#define KW_WORLD      114
#define KW_ON      135
#define ESQ_FSLASH_SQUOTE      158
#define SS_HASH      132
#define KW_OK      137
#define KW_AT      110
#define EIF_THEN      10
#define KW_OF      97
#define SS_OBRACKET      127
#define ANIMATE      65
#define ESRC_TO      26
#define SS_FSLASH_EQUAL      141
#define STRING      55
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