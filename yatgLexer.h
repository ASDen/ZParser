/** \file
 *  This C header file was generated by $ANTLR version 3.2 Sep 23, 2009 12:02:23
 *
 *     -  From the grammar source file : C:\\Zlang\\src\\Zzparser\\Grammar\\yatg.g
 *     -                            On : 2010-07-07 05:42:00
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
 *  -  void      pyatgLexer->DIGIT1(pyatgLexer)
 *  -  void      pyatgLexer->HEX_LITERAL(pyatgLexer)
 *  -  void      pyatgLexer->HexDigit(pyatgLexer)
 *  -  void      pyatgLexer->WS(pyatgLexer)
 *  -  void      pyatgLexer->EOL(pyatgLexer)
 *  -  void      pyatgLexer->COMMENT(pyatgLexer)
 *  -  void      pyatgLexer->LINE_COMMENT(pyatgLexer)
 *  -  void      pyatgLexer->REF_OP(pyatgLexer)
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
     void (*mDIGIT1)	(struct yatgLexer_Ctx_struct * ctx);
     void (*mHEX_LITERAL)	(struct yatgLexer_Ctx_struct * ctx);
     void (*mHexDigit)	(struct yatgLexer_Ctx_struct * ctx);
     void (*mWS)	(struct yatgLexer_Ctx_struct * ctx);
     void (*mEOL)	(struct yatgLexer_Ctx_struct * ctx);
     void (*mCOMMENT)	(struct yatgLexer_Ctx_struct * ctx);
     void (*mLINE_COMMENT)	(struct yatgLexer_Ctx_struct * ctx);
     void (*mREF_OP)	(struct yatgLexer_Ctx_struct * ctx);
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
#define PIVOT      60
#define SS_PLUS_EQUAL      148
#define ROW      80
#define SS_D_DOT      160
#define SS_CCBRACKET      159
#define LETTER      164
#define EWHILE_EXP      15
#define SS_FSLASH      128
#define EIF_ELSE      11
#define CASE      39
#define KW_DEFAULT      105
#define ESEQ      7
#define P_P2      30
#define P_P3      31
#define UNDO      69
#define KW_WHERE      96
#define KW_FN      111
#define STRING_LITERIAL      134
#define EOF      -1
#define SS_PERCENT      129
#define KW_GLOBAL      83
#define EOL      167
#define EIF_COND      9
#define KW_UNDEFINED      141
#define EWHILE_CON      14
#define KW_LEVEL      115
#define KW_PARENT      119
#define LP_EXIT      36
#define RETURN      49
#define EDO      17
#define LP_EXIT_WITH      37
#define SS_D_BAR      150
#define KW_THEN      87
#define COORDSYS      58
#define SS_LT_EQUAL      156
#define BODY      52
#define KW_COORDSYS      117
#define SS_STAR      127
#define COMMENT      168
#define ARR_BIT      33
#define SS_GT      155
#define KW_EXIT      97
#define SS_COLON      104
#define ABOUT      61
#define KW_FUNCTION      110
#define ESRC_WHERE      28
#define MATRIX      79
#define EDO_CON      18
#define SS_COMMA      81
#define LINE_COMMENT      169
#define SS_DOT      130
#define ECATCH_EXP      48
#define KW_CATCH      108
#define NUMBER      78
#define P_BOX2      29
#define SS_D_EQUAL      152
#define LOCAL      62
#define KW_DO      88
#define SS_MINUS_EQUAL      149
#define SS_STAR_EQUAL      145
#define EWHILE      13
#define KW_ANIMATE      113
#define KW_ABOUT      120
#define EFOR      21
#define FUN_DEF      50
#define PRIM_EXP      77
#define SS_D_AMP      151
#define SS_CBRACKET      132
#define WS      166
#define SS_GT_EQUAL      157
#define SS_MINUS      126
#define LEVEL      65
#define SS_DQUOTE      162
#define KW_TO      94
#define EFOR_END      24
#define KW_BY      95
#define ETRY      46
#define ESRC_START      25
#define FUN      53
#define KW_LOCAL      82
#define EscapeSequence      161
#define SS_EQUAL      85
#define KW_ELSE      89
#define SS_EXC_EQUAL      153
#define MEMBER      45
#define MAPPED      54
#define ID_MORE      75
#define ARR_IND      35
#define SS_OPAREN      102
#define EDO_END      20
#define KW_UNSUPPLIED      142
#define KW_SELECTION      122
#define SS_CPAREN      103
#define KW_TRUE      136
#define HexDigit      165
#define KW_WITH      98
#define KW_PIVOT      121
#define CONTEXT      57
#define SELECTION      59
#define AT      71
#define VDECL      4
#define REF_OP      170
#define TIME      67
#define ECASE_END      43
#define PARENT      64
#define VDEF      5
#define KW_MAPPED      109
#define SS_PLUS      125
#define KW_TIME      116
#define EFOR_SRC      22
#define KW_STRUCT      106
#define EWHILE_END      16
#define VVAL      6
#define KW_FOR      91
#define KW_WHILE      90
#define IDENTIFIER      84
#define DIGIT1      144
#define OPERAND      72
#define LP_CONT      38
#define CASE_Exp      40
#define KW_RETURN      112
#define KW_SET      124
#define EFOR_EXP      23
#define KW_IN      92
#define HEX_LITERAL      133
#define ESRC_BY      27
#define ARR_A      32
#define KW_TRY      107
#define DIGIT      143
#define DOT      73
#define KW_IF      86
#define KW_UNDO      123
#define ARR_BIT_RANGE      34
#define WITH      68
#define ETRY_EXP      47
#define EIF_END      12
#define CASE_Item      41
#define WORLD      63
#define SS_OCBRACKET      158
#define KW_FALSE      137
#define KW_OFF      139
#define DEFAULT      42
#define FUN_NAME      51
#define KW_CONTINUE      99
#define SET      76
#define ARG_EXPR_L      74
#define STRUCT      44
#define SS_LT      154
#define EDO_EXP      19
#define KW_CASE      100
#define FUN_DEF_END      55
#define KW_COLLECT      93
#define EIN      70
#define SS_PERCENT_EQUAL      147
#define EIF      8
#define KW_WORLD      118
#define KW_ON      138
#define SS_HASH      135
#define ESQ_FSLASH_SQUOTE      163
#define KW_OK      140
#define EIF_THEN      10
#define KW_AT      114
#define KW_OF      101
#define SS_OBRACKET      131
#define ANIMATE      66
#define ESRC_TO      26
#define SS_FSLASH_EQUAL      146
#define STRING      56
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
