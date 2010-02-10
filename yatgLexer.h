/** \file
 *  This C header file was generated by $ANTLR version 3.2 Sep 23, 2009 12:02:23
 *
 *     -  From the grammar source file : yatg.g
 *     -                            On : 2010-01-08 22:55:39
 *     -                 for the lexer : yatgLexerLexer *
 * Editing it, at least manually, is not wise. 
 *
 * C language generator and runtime by Jim Idle, jimi|hereisanat|idle|dotgoeshere|ws.
 *
 *
 * The lexer yatgLexer has the callable functions (rules) shown below,
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
 * a parser context typedef pyatgLexer, which is returned from a call to yatgLexerNew().
 *
 * As this is a generated lexer, it is unlikely you will call it 'manually'. However
 * the methods are provided anyway.
 * * The methods in pyatgLexer are  as follows:
 *
 *  -  void      pyatgLexer->STRING_LITERIAL(pyatgLexer)
 *  -  void      pyatgLexer->EscapeSequence(pyatgLexer)
 *  -  void      pyatgLexer->SS_COMMA(pyatgLexer)
 *  -  void      pyatgLexer->KW_LOCAL(pyatgLexer)
 *  -  void      pyatgLexer->KW_GLOBAL(pyatgLexer)
 *  -  void      pyatgLexer->SS_EQUAL(pyatgLexer)
 *  -  void      pyatgLexer->KW_IF(pyatgLexer)
 *  -  void      pyatgLexer->KW_THEN(pyatgLexer)
 *  -  void      pyatgLexer->KW_DO(pyatgLexer)
 *  -  void      pyatgLexer->KW_ELSE(pyatgLexer)
 *  -  void      pyatgLexer->KW_WHILE(pyatgLexer)
 *  -  void      pyatgLexer->KW_FOR(pyatgLexer)
 *  -  void      pyatgLexer->KW_IN(pyatgLexer)
 *  -  void      pyatgLexer->KW_COLLECT(pyatgLexer)
 *  -  void      pyatgLexer->KW_TO(pyatgLexer)
 *  -  void      pyatgLexer->KW_BY(pyatgLexer)
 *  -  void      pyatgLexer->KW_WHERE(pyatgLexer)
 *  -  void      pyatgLexer->KW_EXIT(pyatgLexer)
 *  -  void      pyatgLexer->KW_WITH(pyatgLexer)
 *  -  void      pyatgLexer->KW_CASE(pyatgLexer)
 *  -  void      pyatgLexer->KW_OF(pyatgLexer)
 *  -  void      pyatgLexer->SS_OPAREN(pyatgLexer)
 *  -  void      pyatgLexer->SS_CPAREN(pyatgLexer)
 *  -  void      pyatgLexer->SS_COLON(pyatgLexer)
 *  -  void      pyatgLexer->KW_DEFAULT(pyatgLexer)
 *  -  void      pyatgLexer->KW_STRUCT(pyatgLexer)
 *  -  void      pyatgLexer->KW_TRY(pyatgLexer)
 *  -  void      pyatgLexer->KW_MAPPED(pyatgLexer)
 *  -  void      pyatgLexer->KW_FUNCTION(pyatgLexer)
 *  -  void      pyatgLexer->KW_FN(pyatgLexer)
 *  -  void      pyatgLexer->KW_RETURN(pyatgLexer)
 *  -  void      pyatgLexer->KW_ANIMATE(pyatgLexer)
 *  -  void      pyatgLexer->KW_AT(pyatgLexer)
 *  -  void      pyatgLexer->KW_LEVEL(pyatgLexer)
 *  -  void      pyatgLexer->KW_TIME(pyatgLexer)
 *  -  void      pyatgLexer->KW_COORDSYS(pyatgLexer)
 *  -  void      pyatgLexer->KW_WORLD(pyatgLexer)
 *  -  void      pyatgLexer->KW_PARENT(pyatgLexer)
 *  -  void      pyatgLexer->KW_ABOUT(pyatgLexer)
 *  -  void      pyatgLexer->KW_PIVOT(pyatgLexer)
 *  -  void      pyatgLexer->KW_SELECTION(pyatgLexer)
 *  -  void      pyatgLexer->KW_UNDO(pyatgLexer)
 *  -  void      pyatgLexer->KW_SET(pyatgLexer)
 *  -  void      pyatgLexer->SS_PLUS(pyatgLexer)
 *  -  void      pyatgLexer->SS_MINUS(pyatgLexer)
 *  -  void      pyatgLexer->SS_STAR(pyatgLexer)
 *  -  void      pyatgLexer->SS_FSLASH(pyatgLexer)
 *  -  void      pyatgLexer->SS_PERCENT(pyatgLexer)
 *  -  void      pyatgLexer->SS_OBRACKET(pyatgLexer)
 *  -  void      pyatgLexer->SS_CBRACKET(pyatgLexer)
 *  -  void      pyatgLexer->SS_HASH(pyatgLexer)
 *  -  void      pyatgLexer->KW_TRUE(pyatgLexer)
 *  -  void      pyatgLexer->KW_FALSE(pyatgLexer)
 *  -  void      pyatgLexer->KW_ON(pyatgLexer)
 *  -  void      pyatgLexer->KW_OFF(pyatgLexer)
 *  -  void      pyatgLexer->KW_OK(pyatgLexer)
 *  -  void      pyatgLexer->KW_UNDEFINED(pyatgLexer)
 *  -  void      pyatgLexer->KW_UNSUPPLIED(pyatgLexer)
 *  -  void      pyatgLexer->SS_D_BAR(pyatgLexer)
 *  -  void      pyatgLexer->SS_D_AMP(pyatgLexer)
 *  -  void      pyatgLexer->SS_D_EQUAL(pyatgLexer)
 *  -  void      pyatgLexer->SS_EXC_EQUAL(pyatgLexer)
 *  -  void      pyatgLexer->SS_LT(pyatgLexer)
 *  -  void      pyatgLexer->SS_GT(pyatgLexer)
 *  -  void      pyatgLexer->SS_LT_EQUAL(pyatgLexer)
 *  -  void      pyatgLexer->SS_GT_EQUAL(pyatgLexer)
 *  -  void      pyatgLexer->SS_STAR_EQUAL(pyatgLexer)
 *  -  void      pyatgLexer->SS_FSLASH_EQUAL(pyatgLexer)
 *  -  void      pyatgLexer->SS_PERCENT_EQUAL(pyatgLexer)
 *  -  void      pyatgLexer->SS_PLUS_EQUAL(pyatgLexer)
 *  -  void      pyatgLexer->SS_MINUS_EQUAL(pyatgLexer)
 *  -  void      pyatgLexer->SS_DQUOTE(pyatgLexer)
 *  -  void      pyatgLexer->ESQ_FSLASH_SQUOTE(pyatgLexer)
 *  -  void      pyatgLexer->SS_OCBRACKET(pyatgLexer)
 *  -  void      pyatgLexer->SS_CCBRACKET(pyatgLexer)
 *  -  void      pyatgLexer->SS_D_DOT(pyatgLexer)
 *  -  void      pyatgLexer->KW_CONTINUE(pyatgLexer)
 *  -  void      pyatgLexer->KW_CATCH(pyatgLexer)
 *  -  void      pyatgLexer->SS_DOT(pyatgLexer)
 *  -  void      pyatgLexer->IDENTIFIER(pyatgLexer)
 *  -  void      pyatgLexer->LETTER(pyatgLexer)
 *  -  void      pyatgLexer->DIGIT(pyatgLexer)
 *  -  void      pyatgLexer->HEX_LITERAL(pyatgLexer)
 *  -  void      pyatgLexer->HexDigit(pyatgLexer)
 *  -  void      pyatgLexer->WS(pyatgLexer)
 *  -  void      pyatgLexer->EOL(pyatgLexer)
 *  -  void      pyatgLexer->COMMENT(pyatgLexer)
 *  -  void      pyatgLexer->LINE_COMMENT(pyatgLexer)
 *  -  void      pyatgLexer->Tokens(pyatgLexer)
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

#ifndef	_yatgLexer_H
#define _yatgLexer_H
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
typedef struct yatgLexer_Ctx_struct yatgLexer, * pyatgLexer;



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

/** Context tracking structure for yatgLexer
 */
struct yatgLexer_Ctx_struct
{
    /** Built in ANTLR3 context tracker contains all the generic elements
     *  required for context tracking.
     */
    pANTLR3_LEXER    pLexer;


     void (*mSTRING_LITERIAL)	(struct yatgLexer_Ctx_struct * ctx);
     void (*mEscapeSequence)	(struct yatgLexer_Ctx_struct * ctx);
     void (*mSS_COMMA)	(struct yatgLexer_Ctx_struct * ctx);
     void (*mKW_LOCAL)	(struct yatgLexer_Ctx_struct * ctx);
     void (*mKW_GLOBAL)	(struct yatgLexer_Ctx_struct * ctx);
     void (*mSS_EQUAL)	(struct yatgLexer_Ctx_struct * ctx);
     void (*mKW_IF)	(struct yatgLexer_Ctx_struct * ctx);
     void (*mKW_THEN)	(struct yatgLexer_Ctx_struct * ctx);
     void (*mKW_DO)	(struct yatgLexer_Ctx_struct * ctx);
     void (*mKW_ELSE)	(struct yatgLexer_Ctx_struct * ctx);
     void (*mKW_WHILE)	(struct yatgLexer_Ctx_struct * ctx);
     void (*mKW_FOR)	(struct yatgLexer_Ctx_struct * ctx);
     void (*mKW_IN)	(struct yatgLexer_Ctx_struct * ctx);
     void (*mKW_COLLECT)	(struct yatgLexer_Ctx_struct * ctx);
     void (*mKW_TO)	(struct yatgLexer_Ctx_struct * ctx);
     void (*mKW_BY)	(struct yatgLexer_Ctx_struct * ctx);
     void (*mKW_WHERE)	(struct yatgLexer_Ctx_struct * ctx);
     void (*mKW_EXIT)	(struct yatgLexer_Ctx_struct * ctx);
     void (*mKW_WITH)	(struct yatgLexer_Ctx_struct * ctx);
     void (*mKW_CASE)	(struct yatgLexer_Ctx_struct * ctx);
     void (*mKW_OF)	(struct yatgLexer_Ctx_struct * ctx);
     void (*mSS_OPAREN)	(struct yatgLexer_Ctx_struct * ctx);
     void (*mSS_CPAREN)	(struct yatgLexer_Ctx_struct * ctx);
     void (*mSS_COLON)	(struct yatgLexer_Ctx_struct * ctx);
     void (*mKW_DEFAULT)	(struct yatgLexer_Ctx_struct * ctx);
     void (*mKW_STRUCT)	(struct yatgLexer_Ctx_struct * ctx);
     void (*mKW_TRY)	(struct yatgLexer_Ctx_struct * ctx);
     void (*mKW_MAPPED)	(struct yatgLexer_Ctx_struct * ctx);
     void (*mKW_FUNCTION)	(struct yatgLexer_Ctx_struct * ctx);
     void (*mKW_FN)	(struct yatgLexer_Ctx_struct * ctx);
     void (*mKW_RETURN)	(struct yatgLexer_Ctx_struct * ctx);
     void (*mKW_ANIMATE)	(struct yatgLexer_Ctx_struct * ctx);
     void (*mKW_AT)	(struct yatgLexer_Ctx_struct * ctx);
     void (*mKW_LEVEL)	(struct yatgLexer_Ctx_struct * ctx);
     void (*mKW_TIME)	(struct yatgLexer_Ctx_struct * ctx);
     void (*mKW_COORDSYS)	(struct yatgLexer_Ctx_struct * ctx);
     void (*mKW_WORLD)	(struct yatgLexer_Ctx_struct * ctx);
     void (*mKW_PARENT)	(struct yatgLexer_Ctx_struct * ctx);
     void (*mKW_ABOUT)	(struct yatgLexer_Ctx_struct * ctx);
     void (*mKW_PIVOT)	(struct yatgLexer_Ctx_struct * ctx);
     void (*mKW_SELECTION)	(struct yatgLexer_Ctx_struct * ctx);
     void (*mKW_UNDO)	(struct yatgLexer_Ctx_struct * ctx);
     void (*mKW_SET)	(struct yatgLexer_Ctx_struct * ctx);
     void (*mSS_PLUS)	(struct yatgLexer_Ctx_struct * ctx);
     void (*mSS_MINUS)	(struct yatgLexer_Ctx_struct * ctx);
     void (*mSS_STAR)	(struct yatgLexer_Ctx_struct * ctx);
     void (*mSS_FSLASH)	(struct yatgLexer_Ctx_struct * ctx);
     void (*mSS_PERCENT)	(struct yatgLexer_Ctx_struct * ctx);
     void (*mSS_OBRACKET)	(struct yatgLexer_Ctx_struct * ctx);
     void (*mSS_CBRACKET)	(struct yatgLexer_Ctx_struct * ctx);
     void (*mSS_HASH)	(struct yatgLexer_Ctx_struct * ctx);
     void (*mKW_TRUE)	(struct yatgLexer_Ctx_struct * ctx);
     void (*mKW_FALSE)	(struct yatgLexer_Ctx_struct * ctx);
     void (*mKW_ON)	(struct yatgLexer_Ctx_struct * ctx);
     void (*mKW_OFF)	(struct yatgLexer_Ctx_struct * ctx);
     void (*mKW_OK)	(struct yatgLexer_Ctx_struct * ctx);
     void (*mKW_UNDEFINED)	(struct yatgLexer_Ctx_struct * ctx);
     void (*mKW_UNSUPPLIED)	(struct yatgLexer_Ctx_struct * ctx);
     void (*mSS_D_BAR)	(struct yatgLexer_Ctx_struct * ctx);
     void (*mSS_D_AMP)	(struct yatgLexer_Ctx_struct * ctx);
     void (*mSS_D_EQUAL)	(struct yatgLexer_Ctx_struct * ctx);
     void (*mSS_EXC_EQUAL)	(struct yatgLexer_Ctx_struct * ctx);
     void (*mSS_LT)	(struct yatgLexer_Ctx_struct * ctx);
     void (*mSS_GT)	(struct yatgLexer_Ctx_struct * ctx);
     void (*mSS_LT_EQUAL)	(struct yatgLexer_Ctx_struct * ctx);
     void (*mSS_GT_EQUAL)	(struct yatgLexer_Ctx_struct * ctx);
     void (*mSS_STAR_EQUAL)	(struct yatgLexer_Ctx_struct * ctx);
     void (*mSS_FSLASH_EQUAL)	(struct yatgLexer_Ctx_struct * ctx);
     void (*mSS_PERCENT_EQUAL)	(struct yatgLexer_Ctx_struct * ctx);
     void (*mSS_PLUS_EQUAL)	(struct yatgLexer_Ctx_struct * ctx);
     void (*mSS_MINUS_EQUAL)	(struct yatgLexer_Ctx_struct * ctx);
     void (*mSS_DQUOTE)	(struct yatgLexer_Ctx_struct * ctx);
     void (*mESQ_FSLASH_SQUOTE)	(struct yatgLexer_Ctx_struct * ctx);
     void (*mSS_OCBRACKET)	(struct yatgLexer_Ctx_struct * ctx);
     void (*mSS_CCBRACKET)	(struct yatgLexer_Ctx_struct * ctx);
     void (*mSS_D_DOT)	(struct yatgLexer_Ctx_struct * ctx);
     void (*mKW_CONTINUE)	(struct yatgLexer_Ctx_struct * ctx);
     void (*mKW_CATCH)	(struct yatgLexer_Ctx_struct * ctx);
     void (*mSS_DOT)	(struct yatgLexer_Ctx_struct * ctx);
     void (*mIDENTIFIER)	(struct yatgLexer_Ctx_struct * ctx);
     void (*mLETTER)	(struct yatgLexer_Ctx_struct * ctx);
     void (*mDIGIT)	(struct yatgLexer_Ctx_struct * ctx);
     void (*mHEX_LITERAL)	(struct yatgLexer_Ctx_struct * ctx);
     void (*mHexDigit)	(struct yatgLexer_Ctx_struct * ctx);
     void (*mWS)	(struct yatgLexer_Ctx_struct * ctx);
     void (*mEOL)	(struct yatgLexer_Ctx_struct * ctx);
     void (*mCOMMENT)	(struct yatgLexer_Ctx_struct * ctx);
     void (*mLINE_COMMENT)	(struct yatgLexer_Ctx_struct * ctx);
     void (*mTokens)	(struct yatgLexer_Ctx_struct * ctx);    const char * (*getGrammarFileName)();
    void	    (*free)   (struct yatgLexer_Ctx_struct * ctx);
        
};

// Function protoypes for the constructor functions that external translation units
// such as delegators and delegates may wish to call.
//
ANTLR3_API pyatgLexer yatgLexerNew         (pANTLR3_INPUT_STREAM instream);
ANTLR3_API pyatgLexer yatgLexerNewSSD      (pANTLR3_INPUT_STREAM instream, pANTLR3_RECOGNIZER_SHARED_STATE state);

/** Symbolic definitions of all the tokens that the lexer will work with.
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
#define SS_CCBRACKET      154
#define SS_D_DOT      155
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
#define KW_FN      107
#define EOF      -1
#define STRING_LITERIAL      131
#define SS_PERCENT      125
#define KW_GLOBAL      79
#define EOL      162
#define EIF_COND      9
#define KW_UNDEFINED      138
#define EWHILE_CON      14
#define KW_LEVEL      111
#define KW_PARENT      115
#define LP_EXIT      36
#define RETURN      48
#define EDO      17
#define LP_EXIT_WITH      37
#define SS_D_BAR      145
#define KW_THEN      83
#define COORDSYS      57
#define SS_LT_EQUAL      151
#define BODY      51
#define KW_COORDSYS      113
#define SS_STAR      123
#define COMMENT      163
#define ARR_BIT      33
#define KW_EXIT      93
#define SS_GT      150
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
#define KW_WITH      94
#define KW_PIVOT      117
#define CONTEXT      56
#define SELECTION      58
#define AT      70
#define VDECL      4
#define TIME      66
#define PARENT      63
#define VDEF      5
#define KW_MAPPED      105
#define SS_PLUS      121
#define KW_TIME      112
#define EFOR_SRC      22
#define KW_STRUCT      102
#define EWHILE_END      16
#define VVAL      6
#define KW_FOR      87
#define KW_WHILE      86
#define IDENTIFIER      80
#define OPERAND      71
#define LP_CONT      38
#define CASE_Exp      40
#define KW_RETURN      108
#define KW_SET      120
#define EFOR_EXP      23
#define KW_IN      88
#define HEX_LITERAL      130
#define ESRC_BY      27
#define ARR_A      32
#define KW_TRY      103
#define DIGIT      129
#define DOT      72
#define KW_IF      82
#define KW_UNDO      119
#define ARR_BIT_RANGE      34
#define WITH      67
#define ETRY_EXP      46
#define EIF_END      12
#define CASE_Item      41
#define WORLD      62
#define SS_OCBRACKET      153
#define KW_FALSE      134
#define KW_OFF      136
#define DEFAULT      42
#define FUN_NAME      50
#define KW_CONTINUE      95
#define SET      75
#define ARG_EXPR_L      73
#define STRUCT      43
#define SS_LT      149
#define EDO_EXP      19
#define KW_CASE      96
#define FUN_DEF_END      54
#define KW_COLLECT      89
#define EIN      69
#define SS_PERCENT_EQUAL      142
#define EIF      8
#define KW_WORLD      114
#define KW_ON      135
#define SS_HASH      132
#define ESQ_FSLASH_SQUOTE      158
#define KW_OK      137
#define EIF_THEN      10
#define KW_AT      110
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

/* End of token definitions for yatgLexer
 * =============================================================================
 */
/** \} */

#ifdef __cplusplus
}
#endif

#endif

/* END - Note:Keep extra line feed to satisfy UNIX systems */
