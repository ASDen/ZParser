grammar yatg;

options 
{
	output=AST;
	//language=C;
	backtrack=true;
    	memoize=true;
    	k=2;
    	//ASTLabelType    = pANTLR3_BASE_TREE;
}


tokens {
	//declaration related
	VDECL;
	VDEF;
	VVAL;
	//Expression sequences
	ESEQ;
	//if-related
	EIF;
	EIF_COND;
	EIF_THEN;
	EIF_ELSE;
	EIF_END;
	//While-Related
	EWHILE;
	EWHILE_CON;
	EWHILE_EXP;
	EWHILE_END;
	//Do-Related
	EDO;
	EDO_CON;
	EDO_EXP;
	EDO_END;
	//for-related
	EFOR;
	EFOR_SRC;
	EFOR_EXP;
	EFOR_END;
	//source-related
	ESRC_START;
	ESRC_TO;
	ESRC_BY;
	ESRC_WHERE;
	//Points
	P_BOX2;
	P_P2;
	P_P3;
	//Arrays
	ARR_A;
	ARR_BIT;
	ARR_BIT_RANGE;
	ARR_IND;
	//loop exit
	LP_EXIT;
	LP_EXIT_WITH;
	//contine
	LP_CONT;
	//case
	CASE;
	CASE_Exp;
	CASE_Item;
	DEFAULT;
	ECASE_END;
	//structure
	STRUCT;
	//member
	MEMBER;
	//ty
	ETRY;
	ETRY_EXP;
	ECATCH_EXP;
	//function
	RETURN;
	FUN_DEF;
	FUN_NAME;
	BODY;
	FUN;
	MAPPED;
	FUN_DEF_END;
	//string
	STRING;
	//context
	CONTEXT;
	COORDSYS;
	SELECTION;
	PIVOT;
	ABOUT;
	LOCAL;
	WORLD;
	PARENT;
	LEVEL;
	ANIMATE;
	TIME;
	WITH;
	UNDO;
	EIN;
	AT;
	//external
	OPERAND;
	DOT;
	ARG_EXPR_L;
	ID_MORE;
	SET;
	PRIM_EXP;
	// NUMBER
	NUMBER;
	//Matrix
	MATRIX; 
	ROW;
}



program
	: ( expr )*
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
	: type_decl  decl (SS_COMMA decl )*
	
	->  ^( VDECL type_decl decl+  )
	;

type_decl
	:  KW_LOCAL | KW_GLOBAL
	;
decl
	: IDENTIFIER ( SS_EQUAL expr_g )? 
	
	-> ^( VDEF IDENTIFIER ^(VVAL expr_g)?)
	;

if_expr
	:KW_IF cond=expr_g  ( KW_THEN | KW_DO )  then=expr_g  (KW_ELSE relse=expr_g)?
	
	-> ^(EIF ^(EIF_COND $cond) ^(EIF_THEN $then) ^(EIF_ELSE ($relse)?) EIF_END )
	
	;

while_loop 
	: KW_WHILE cond=expr_g KW_DO exp=expr_g
	-> ^( EWHILE ^(EWHILE_CON $cond) ^(EWHILE_EXP $exp) EWHILE_END )
	;

do_loop 
	: KW_DO exp=expr_g KW_WHILE cond=expr_g
	-> ^( EDO  ^(EDO_CON $cond) ^(EDO_EXP $exp) EDO_END )
	;

for_loop 
	: KW_FOR  IDENTIFIER  ( KW_IN | SS_EQUAL ) source (KW_DO | KW_COLLECT) expr_g 
	-> ^( EFOR IDENTIFIER ^(EFOR_SRC source ) ^(EFOR_EXP expr_g) EFOR_END )
	;
	
source
	: sstart=expr_g (KW_TO sto=expr_g ( KW_BY sby=expr_g )?)? ( KW_WHERE swhere=expr_g )?
	-> ^(ESRC_START $sstart) ^(ESRC_TO $sto)? ^(ESRC_BY $sby)? ^(ESRC_WHERE $swhere)? 
	;

loop_exit 
	: KW_EXIT ( ( KW_WITH )=> KW_WITH expr_g )?
	-> ^(LP_EXIT ^(LP_EXIT_WITH expr_g)?)
	;

loop_continue
	 : KW_CONTINUE
	 -> ^(LP_CONT)
	 ;

case_expr
	 : KW_CASE ( expr_g )? KW_OF SS_OPAREN ( case_item )* SS_CPAREN
	 ->^(CASE ^(CASE_Exp expr_g)? ^( case_item)*  ECASE_END )
	 ;

case_item 
	: expr_g SS_COLON expr_g ->^(CASE_Item  expr_g expr_g)
	| KW_DEFAULT SS_COLON expr_g ->^(CASE_Item   DEFAULT expr_g)
	;

struct_def 
	: KW_STRUCT SS_OPAREN member ( SS_COMMA member )* SS_CPAREN
	->^(STRUCT member+)
	;

member 
	: IDENTIFIER ( SS_EQUAL expr_g )? ->^( MEMBER IDENTIFIER expr_g) 
	| function_def ->^(function_def)
	;
	
try_expr 
	: KW_TRY t_exp=expr_g KW_CATCH c_exp= expr_g
	->^(ETRY ^(ETRY_EXP $t_exp)^(ECATCH_EXP $c_exp))
	;
function_def 
	: ( KW_MAPPED )? fun IDENTIFIER ( argument_decl_list )*  SS_EQUAL expr_g
	->^( FUN_DEF ^(FUN_NAME IDENTIFIER) ^( ARG_EXPR_L ( argument_decl_list )*)  ^(BODY expr_g) FUN_DEF_END )
	;
	
fun	
	: KW_FUNCTION | KW_FN
	;
	
function_return 
	: KW_RETURN expr_g
	->^(RETURN expr_g)
	;

context_expr 
	: context  (SS_COMMA context )* expr_g
	->^(CONTEXT context+ expr_g)
	;

context 
	: (KW_WITH)? KW_ANIMATE logical_expression ->^(CONTEXT  ANIMATE logical_expression)
	| KW_AT KW_LEVEL operand ->^(CONTEXT AT LEVEL operand)
	| KW_AT KW_TIME operand ->^(CONTEXT AT TIME operand)
	| KW_IN operand ->^(CONTEXT EIN operand)
	| (KW_IN)? KW_COORDSYS 
		(
		 KW_LOCAL  ->^(CONTEXT  COORDSYS LOCAL)
		 | KW_WORLD ->^(CONTEXT  COORDSYS WORLD)
		 | KW_PARENT  ->^(CONTEXT COORDSYS PARENT)
		 | operand  ->^(CONTEXT COORDSYS operand) 
		 )
	| KW_ABOUT 
		( KW_PIVOT ->^(CONTEXT ABOUT PIVOT) 
		| KW_SELECTION  ->^(CONTEXT ABOUT SELECTION)
		| KW_COORDSYS  ->^(CONTEXT ABOUT COORDSYS)
		| operand  ->^(CONTEXT ABOUT operand)
		)
	| ( KW_WITH )? KW_UNDO logical_expression ->^(CONTEXT  UNDO  logical_expression)
	;

set_context 
	: KW_SET context
	->^(SET context)
	;
	
/// Begin Rev


math_expression
	: additive_expression
	;

additive_expression
	: (multiplicative_expression) ((SS_PLUS|SS_MINUS)^ multiplicative_expression)* 
	;

multiplicative_expression
	: (unary_expression) ((SS_STAR|SS_FSLASH|SS_PERCENT)^ unary_expression )*
	;

argT	:IDENTIFIER (SS_COLON operand)? 
	->^( IDENTIFIER (operand)? )
	;

argument_decl_list
	:  argT ( SS_COMMA argT)*	
	-> argT+	
	;

argument_expression_list
	: expr_g ( SS_COMMA expr_g)*	
	-> expr_g+
	;

unary_expression
	: operand
	;
operand
	: IDENTIFIER (operand_op )* ->^(OPERAND IDENTIFIER (operand_op)* ID_MORE)
        | constant 
        ;
	
operand_op
	: SS_DOT IDENTIFIER ->^(DOT IDENTIFIER)
        | SS_OBRACKET expr_g SS_CBRACKET ->^(ARR_IND expr_g)
        | SS_OPAREN argument_expression_list? SS_CPAREN -> ^(ARG_EXPR_L argument_expression_list?)
        ;

constant
    	:
    	  number
    	| HEX_LITERAL
    	| STRING_LITERIAL
    	| SS_HASH IDENTIFIER
   	| array
   	| matrix
    	| bitarray
    	| box2
   	| point3
   	| point2
    	| KW_TRUE
    	| KW_FALSE
    	| KW_ON
    	| KW_OFF
    	| KW_OK
    	| KW_UNDEFINED
    	| KW_UNSUPPLIED
    	| SS_MINUS expr_seq
   	| expr_seq
    	;

///

number	:
	(SS_MINUS)? DIGIT
    	  ->^(NUMBER (SS_MINUS)? DIGIT )
    	  |
    	  (SS_MINUS)? DIGIT1
    	  ->^(NUMBER (SS_MINUS)? DIGIT1 )
	;
//
constant_expression
	: logical_expression
	;

assignment_expression
	: lvalue assignment_operator expr
	-> ^(assignment_operator lvalue expr)
	| constant_expression
	;
	
lvalue
	: unary_expression
	;

assignment_operator
	: SS_EQUAL
	| SS_STAR_EQUAL
	| SS_FSLASH_EQUAL
	| SS_PERCENT_EQUAL
	| SS_PLUS_EQUAL
	| SS_MINUS_EQUAL
	;

logical_expression
	: logical_or_expression
	;

logical_or_expression
	: logical_and_expression (SS_D_BAR^ logical_and_expression)*
	;

logical_and_expression
	: equality_expression (SS_D_AMP^ equality_expression)*
	;

equality_expression
	: relational_expression ((SS_D_EQUAL|SS_EXC_EQUAL)^ relational_expression)*
	;

relational_expression
	: math_expression ((SS_LT|SS_GT|SS_LT_EQUAL|SS_GT_EQUAL)^ math_expression)*
	;


/// End Rev


expr_seq
	: SS_OPAREN (expr )* SS_CPAREN
	-> ^(ESEQ expr*)
	;
expr_g
	:  expr_seq
	|  expr
	;

	
/*decimal_number
	: //('-')? (digit)* ( '.'(digit)* (( 'e' |'E' ) ('+' | '-')? (digit)+ )? )?
	digit
	;
*/	
	



/*time
	: ('-')? ( decimal_number ('m' | 's' | 'f' | 't')? )+
	| ('-')? (digit)* ':' (digit)* ( '.' (digit)* )?
	| ('-')? decimal_number 'n'
	;
*/
box2
	: SS_OBRACKET e1=expr_g SS_COMMA e2=expr_g SS_COMMA e3=expr_g SS_COMMA e4=expr_g SS_CBRACKET
	-> ^(P_BOX2 $e1 $e2 $e3 $e4)
	;

point3
	: SS_OBRACKET e1=expr_g SS_COMMA e2=expr_g SS_COMMA e3=expr_g SS_CBRACKET
	-> ^(P_P3 $e1 $e2 $e3)
	;

point2 
	: SS_OBRACKET e1=expr_g SS_COMMA e2=expr_g SS_CBRACKET
	-> ^(P_P2 $e1 $e2)
	;

array 
	: SS_OBRACKET SS_CBRACKET
	-> ^(ARR_A)
	| SS_OBRACKET ele+=expr_g ( SS_COMMA ele+=expr_g )* SS_CBRACKET
	-> ^(ARR_A $ele+)
	;
matrix
	: SS_OCBRACKET SS_CCBRACKET
	-> ^(MATRIX)
	| SS_OCBRACKET ele+= row ( SS_COMMA ele+= row )* SS_CCBRACKET
	-> ^(MATRIX $ele+)
	;

row	
	: SS_OCBRACKET SS_CCBRACKET
	-> ^(ROW)
	|  SS_OCBRACKET ele+=expr_g ( SS_COMMA ele+=expr_g )* SS_CCBRACKET
	-> ^(ROW $ele+)
	;
bitarray 
	: SS_HASH SS_OCBRACKET SS_CCBRACKET -> ^(ARR_BIT)
	| SS_HASH SS_OCBRACKET ele+=arrrange ( SS_COMMA ele+=arrrange )* SS_CCBRACKET -> ^(ARR_BIT $ele+)
	;

arrrange
	: (e1=expr_g ( SS_D_DOT e2=expr_g)?)
	-> ^(ARR_BIT_RANGE $e1 $e2?)
	;

/*---------------------------------
	Lexical Rules Begin	
-----------------------------------*/


STRING_LITERIAL
    	:  '"' ( EscapeSequence | ~('\\'|'"') )* '"'
    	;

fragment
EscapeSequence
    	:   '\\' ('b'|'t'|'n'|'f'|'r'|'\"'|'\''|'\\')
    	;

SS_COMMA
	:	','
	;

KW_LOCAL
	:	'local'
	;

KW_GLOBAL
	:	'global'
	;

SS_EQUAL
	:	'='
	;

KW_IF
	:	'if'
	;

KW_THEN
	:	'then'
	;

KW_DO
	:	'do'
	;

KW_ELSE
	:	'else'
	;

KW_WHILE
	:	'while'
	;

KW_FOR
	:	'for'
	;

KW_IN
	:	'in'
	;

KW_COLLECT
	:	'collect'
	;

KW_TO
	:	'to'
	;

KW_BY
	:	'by'
	;

KW_WHERE
	:	'where'
	;

KW_EXIT
	:	'exit'
	;

KW_WITH
	:	'with'
	;

KW_CASE
	:	'case'
	;

KW_OF
	:	'of'
	;

SS_OPAREN
	:	'('
	;

SS_CPAREN
	:	')'
	;

SS_COLON
	:	':'
	;

KW_DEFAULT
	:	'default'
	;

KW_STRUCT
	:	'struct'
	;

KW_TRY
	:	'try'
	;

KW_MAPPED
	:	'mapped'
	;

KW_FUNCTION
	:	'function'
	;

KW_FN
	:	'fn'
	;

KW_RETURN
	:	'return'
	;

KW_ANIMATE
	:	'animate'
	;

KW_AT
	:	'at'
	;

KW_LEVEL
	:	'level'
	;

KW_TIME
	:	'time'
	;

KW_COORDSYS
	:	'coordsys'
	;

KW_WORLD
	:	'world'
	;

KW_PARENT
	:	'parent'
	;

KW_ABOUT
	:	'about'
	;

KW_PIVOT
	:	'pivot'
	;

KW_SELECTION
	:	'selection'
	;

KW_UNDO
	:	'undo'
	;

KW_SET
	:	'set'
	;

SS_PLUS
	:	'+'
	;

SS_MINUS
	:	'-'
	;

SS_STAR
	:	'*'
	;

SS_FSLASH
	:	'/'
	;

SS_PERCENT
	:	'%'
	;

SS_OBRACKET
	:	'['
	;

SS_CBRACKET
	:	']'
	;

SS_HASH
	:	'#'
	;

KW_TRUE
	:	'true'
	;

KW_FALSE
	:	'false'
	;

KW_ON
	:	'on'
	;

KW_OFF
	:	'off'
	;

KW_OK
	:	'ok'
	;

KW_UNDEFINED
	:	'undefined'
	;

KW_UNSUPPLIED
	:	'unsupplied'
	;

SS_D_BAR
	:	'||'
	;

SS_D_AMP
	:	'&&'
	;

SS_D_EQUAL
	:	'=='
	;

SS_EXC_EQUAL
	:	'!='
	;

SS_LT
	:	'<'
	;

SS_GT
	:	'>'
	;

SS_LT_EQUAL
	:	'<='
	;

SS_GT_EQUAL
	:	'>='
	;

SS_STAR_EQUAL
	:	'*='
	;

SS_FSLASH_EQUAL
	:	'/='
	;

SS_PERCENT_EQUAL
	:	'%='
	;

SS_PLUS_EQUAL
	:	'+='
	;

SS_MINUS_EQUAL
	:	'-='
	;

SS_DQUOTE
	:	'"'
	;

ESQ_FSLASH_SQUOTE
	:	'\''
	;

SS_OCBRACKET
	:	'{'
	;

SS_CCBRACKET
	:	'}'
	;

SS_D_DOT
	:	'..'
	;

KW_CONTINUE
	:	'continue'
	;

KW_CATCH
	:	'catch'
	;

SS_DOT
	:	'.'
	;
	
IDENTIFIER
	: LETTER (LETTER|'0'..'9')*
	;
	
fragment
LETTER
	: '$'
	| 'A'..'Z'
	| 'a'..'z'
	| '_'
	;
	
DIGIT 	: ('0'..'9')+
	;

DIGIT1 	: ('0'..'9')* '.' ('0'..'9')+
	;

HEX_LITERAL 
	: '0' ('x'|'X') HexDigit+
	;

fragment
HexDigit
	: ( '0'..'9' | 'a'..'f' | 'A'..'F' )
	;
	
WS  
	:  (' '|'\t'|'\u000C') {$channel=HIDDEN;}
	;
	
EOL
	: (';' |  '\r'?'\n' )+ {$channel=HIDDEN;}
	;
	
COMMENT
	:  '/*' ( options {greedy=false;} : . )* '*/' {$channel=HIDDEN;}
	|
	'//'
    	;

LINE_COMMENT
    	: '--' ~('\n')* '\r'?'\n' {$channel=HIDDEN;}
    	;
REF_OP	
	:'&'
	;
