header {

#include <iostream>
#include "PNode.hpp"
#include "PNodeFactory.hpp"

#pragma warning(disable:4101)

ANTLR_USING_NAMESPACE(std)
ANTLR_USING_NAMESPACE(antlr)

} 


options {
	language="Cpp";
}

{
// My code section

// Activate inherited ASTNodeFactory
_PNodeFactory PNodeFactory;

extern _PNodeFactory PNodeFactory;
}
                     
class MyParser extends Parser;
options {
        k = 2;
		buildAST=true;
		exportVocab = ssci_;
		ASTLabelType = "RefPNode";

		// Effektiv errorhandler	
		defaultErrorHandler=true ;

		codeGenMakeSwitchThreshold = 2;
		codeGenBitsetTestThreshold = 3;
}

interpretation_unit	
	{
		// theContext=context; 
	}
	:
		(	start_condition
		|	/* nothing */
		)

		EOF!
	;

start_condition
	:	(declaration_list)? ID!  LPAREN! RPAREN! compound_statement 
		{ #start_condition = #(#[NStartCondition,"NStartCondition"],#start_condition); }
	;

statement
	: 	compound_statement
	|	assign_statement
		//	|	call_statement
	|	selection_statement
	|	iteration_statement
	|	stream_statement
	;

compound_statement
	:	LCURLY^		
	(	declaration_list (statement_list)? 
	|	statement_list)? RCURLY!  
	;
	
statement_list
	:	( statement )+
	;

selection_statement
	:	SEMI! 
	|	switchBlock
	|	ifThenBlock
	;

switchBlock
	:	SWITCH! LPAREN! expression RPAREN! LCURLY!
		(
				options {
					warnWhenFollowAmbig = false;
				}
				:
				case_statement
			)*
		(
				options {
					warnWhenFollowAmbig = false;
				}
				:
				default_statement 
			)? RCURLY!
		{ #switchBlock = #(#[NSwitchBlock,"NSwitchBlock"],#switchBlock);}
	;

case_statement
	:	CASE! condition COLON! codeBlock
	  { #case_statement = #(#[NCaseStatement,"NCaseStatement"],#case_statement);}
	;

default_statement
	: DEFAULT! COLON! codeBlock
	{ #default_statement = #(#[NDefaultStatement,"NDefaultStatement"],#default_statement);}
	;

ifThenBlock
	:
		ifBlock
		(
				options {
					warnWhenFollowAmbig = false;
				}
				:
				elseBlock 
			)?
		{ #ifThenBlock = #(#[NIfThenBlock,"NIfThenBlock"],#ifThenBlock);}
	;

ifBlock
	:
		IF! LPAREN! condition RPAREN! codeBlock
		{ #ifBlock = #(#[NIfBlock,"NIfBlock"],#ifBlock);}
	;

elseBlock
	:
		ELSE! codeBlock
		{ #elseBlock = #(#[NElseBlock,"NElseBlock"],#elseBlock);}
	;

condition
	:
		expression
		{ #condition = #(#[NCondition,"NCondition"],#condition);}
	;

codeBlock
	:
		(
			options {
				warnWhenFollowAmbig = false;
			}
			:
			statement
		)
		{#codeBlock = #(#[NCodeBlock,"NCodeBlock"],#codeBlock);}
	;

iteration_statement
	:	WHILE^ LPAREN! condition RPAREN! codeBlock
	|	DO^ codeBlock  WHILE! LPAREN! condition RPAREN! SEMI!
	|	for_loop
	;

for_loop
	: FOR^ LPAREN! for_expression SEMI! loop_cntrl 
	;

for_expression
	: assign_expression
	| for_declaration 
	;

for_declaration
	: type_specifier declarator ASSIGN! expression
	{#for_declaration = #(#[NForDeclaration,"NForDeclaration"],#for_declaration);}
	;

loop_cntrl
	:  condition SEMI! forBlock 
	;

forBlock
	:!
		(
			options {
				warnWhenFollowAmbig = false;
			}
			:
			ax:assign_expression RPAREN! st:statement
		)
		{## = #( #[NForBlock,"NForBlock"], #st, #ax );}
	;

assign_statement
	:	assign_expression SEMI!
	;

assign_expression
	:	assign_ID 
	(	INC_OP^	// '++'
	|	DEC_OP^	// '--'
	|	a:assignment_operator! expression	{ ## = #( #a, ## );}
	)
	;

assign_ID
	:	ID 
		( LBRACKET! expression RBRACKET! { #assign_ID = #([NAssignList, "NAssignList"], #assign_ID); } )?			
	;

assignment_operator
	: 
	(	ASSIGN
	|	ADD_ASSIGN	
	|	SUB_ASSIGN
	|	DIV_ASSIGN
	|	STAR_ASSIGN
	|	MOD_ASSIGN	
	)
	;

//call_statement	// externe metoder i C++ uden returtype
//	:	call_expression SEMI
//	;

//call_expression
//	:	ID 
//		( DOT ID 
//		(	LPAREN ( argument_expression_list )? RPAREN
//		|   LBRACKET ( argument_expression_list )? RBRACKET
//		)? 
//		)+
//	;

argument_expression_list
	:	expression ( COMMA expression )*	
	;

stream_statement
	:	COUT^ stream  SEMI!
	;

stream 
	: ( LSHIFT! (expression | ENDL) )+
	;

expression
	:	logical_and_expression ( LOR^ logical_and_expression )*	
	;

logical_and_expression
	:	equality_expression ( LAND^ equality_expression )*		
	;

equality_expression
	:	relational_expression
	(	( EQUAL^ | NOT_EQUAL^ ) relational_expression )*			
	;

relational_expression	
	:	additive_expression
	(	( LT_OP^ | GT^ | LTE^ | GTE^ ) additive_expression )*
	;
	
additive_expression	
	:	multiplicative_expression
	(	( PLUS^ | MINUS^ ) multiplicative_expression )*
	;
	
multiplicative_expression	
	:	unary_expression
	(	( STAR^ | DIV^ | MOD^) unary_expression )*
	;
	
unary_expression	
	: 
	(	primary_expression
	|	u:unary_operator primary_expression
		{ ## = #( #[NUnary,"NUnary"], ## ); }
	)
	;
	
unary_operator
	:	PLUS
	|	MINUS
	|	LNOT
	;

primary_expression
	:
	(	ID 
	( 	LBRACKET! expression RBRACKET!
	{ 	#primary_expression = #([NListDeclaration, "NListDeclaration"], #primary_expression); }
	)?			
		//|	call_expression	// eksisterende metoder i C++ med returtype
	|	STRING_LITERAL
	|	CHAR_LITERAL
	|   	DOUBLE_CONST
	|  	 INT_CONST
	|	LPAREN^ expression RPAREN!
	|	TRUE
	|	FALSE
	)
	;

declaration_list
	:	 ( declaration )+	 	
	;
  
declaration
		{ /* RefAST d1; */
			RefPNode d1;
		 }
	:	t:type_specifier declarator_list ( ASSIGN! initializer_list )? SEMI!				
		{  
		
		d1 = PNodeFactory.dup(#t);
		int i;
		i = d1->getType();

		if (i==ID){
			#declaration = #([NExterntype, "NExterntype"], #declaration);		
		}
		else{
			#declaration = #([NDeclaration, "NDeclaration"], #declaration);
		}
	
		} // end-ACTION
	;

declarator_list 
	:	declarator ( COMMA! declarator )*		
		
	;

declarator
	:	ID 
	( LBRACKET! expression RBRACKET! 
	{ #declarator = #([NDeclareList, "NDeclareList"], #declarator); }
	)?
	;

initializer_list
	:	
	(	expression 
		
	|	LCURLY! (expression (COMMA! expression)* ) RCURLY!
	)
		{ #initializer_list = #([NInitializer, "NInitializer"], #initializer_list); }
	;

type_specifier
 	 : 
	 (	 CHAR			
 	 |	 INT
 	 |	 BOOL
 	 |	 DOUBLE
 	 |	 STRING				
	 |	 ID	 
		// supertype, maaske skal saettes _ttype til noget
	 )		
 	 ;

imaginary_token
	: NRootAST
	| NDeclaration
	| NUnionDeclaration
	| NUnary
	| NEmptyStatement
	| NInitializer
	| NExterntype
	| NCondition
	| NCodeBlock
	| NIfThenBlock
	| NIfBlock
	| NElseBlock
	| NForBlock
	| NCaseStatement
	| NDefaultStatement
	| NSwitchBlock
	| NCaseCondition
	| NForDeclaration
	| NDeclareList
	| NListDeclaration
	| NAssignList
	| NStartCondition
	;


/* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */


class MyLexer extends Lexer;

options
        {
		
        k = 3;
  		charVocabulary = '\3'..'\377';
        		
        }

tokens {
// token keywords

    	IF		= "if"; 
	ELSE		= "else";

	SWITCH		= "switch";
	CASE		= "case";
	DEFAULT		= "default";

	WHILE		= "while";
	DO		= "do";

	FOR		= "for";

	COUT		= "cout";
	ENDL		= "endl";

	TRUE		= "true";
	FALSE		= "false";

	INT		= "int";
	DOUBLE		= "double";
	CHAR		= "char";
	BOOL		= "bool";
	STRING		= "string";

}
 
Whitespace
        :       ( ( '\003'..'\010' | '\t' | '\013' | '\f' | '\016'.. '\037' | '\177'..'\377' | ' ' )
                | "\r\n"		{newline();}           
                | ( '\n' | '\r' )       {newline();}  
                )                       { _ttype = ANTLR_USE_NAMESPACE(antlr)Token::SKIP;  }
        ;

Cpp_Comment
	:	"//" 
		(~'\n')* '\n'	//match alt andet end newline
					{ _ttype = ANTLR_USE_NAMESPACE(antlr)Token::SKIP; newline(); }
	;

Comment
        :       
		"/*"
 		( { LA(2) != '/' }? '*'
		| "\r\n"			{newline();}
                | ( '\r' | '\n' )		{newline();}
                | ~( '*'| '\r' | '\n' )			
                )*
                "*/"                    
				
				{ _ttype = ANTLR_USE_NAMESPACE(antlr)Token::SKIP;}
        ;

/* Operators: */

ASSIGN          : '=' ;
COLON           options {
						paraphrase = "':'";
						}	: ':' ;
COMMA           : ',' ;
SEMI			options {
						paraphrase = "';'";
						}	: ';' ;

DOT  :			'.' ;

LPAREN			options {
						paraphrase = "'('";
						}   : '(' ;
RPAREN          options {
						paraphrase = "')'";
						}	: ')' ;
LBRACKET		options {
						paraphrase = "'['";
						}	: '[' ;
RBRACKET		options {
						paraphrase = "']'";
						}   : ']' ;
LCURLY			options {
						paraphrase = "'{'";
						}   : '{' ;
RCURLY			options {
						paraphrase = "'}'";
						}   : '}' ;

EQUAL           : "==" ;
NOT_EQUAL       : "!=" ;
LTE             : "<=" ;
LT_OP           : "<" ;
GTE             : ">=" ;
GT              : ">" ;

MOD		: '%' ;
DIV             : '/' ;
PLUS            : '+' ;
DIV_ASSIGN	: "/=";
STAR_ASSIGN	: "*=";
MOD_ASSIGN	: "%=";
ADD_ASSIGN	: "+=" ;
INC_OP          : "++" ;
MINUS           : '-' ;
SUB_ASSIGN	: "-=" ;
DEC_OP          : "--" ;
STAR            : '*' ;

LSHIFT		options {
			paraphrase = "'<<'";
			}	: "<<" ;

LAND            : "&&" ;
LNOT            : '!' ;
LOR             : "||" ;


CHAR_LITERAL
	:	'\'' ( Escape | ~( '\'' ) ) '\''
	;

STRING_LITERAL
	:	'"' (Escape|~'"')* '"'
	;

protected
Escape  
        :       '\\'
                ( options{warnWhenFollowAmbig=false;}:
                  'a'	
                | 'b'	{ $setText("\b"); }
                | 'f'	{ $setText("\f"); }
                | 'n'	{ $setText("\n"); }
                | 'r'	{ $setText("\r"); }
                | 't'	{ $setText("\t"); }
                | 'v'	
                | '"'	{ $setText("\""); }
                | '\''	{ $setText("\'"); }
                | '\\'	{ $setText("\\"); }
                | '?'	
                | ('0'..'3') ( options{warnWhenFollowAmbig=false;}: DIGIT ( options{warnWhenFollowAmbig=false;}: DIGIT )? )?
                | ('4'..'7') ( options{warnWhenFollowAmbig=false;}: DIGIT )?
                | 'x' ( options{warnWhenFollowAmbig=false;}: DIGIT | 'a'..'f' | 'A'..'F' )+
                )
        ;

/* Numeric Constants: */

protected
DOUBLE_CONST:;

protected
INT_CONST:;

protected
DIGIT
        :       '0'..'9'
        ;

NUMBER
		options
				{
				paraphrase = "a number";
				}


        : 
		(   
		( ( DIGIT )+  DOT  )=> ( ( DIGIT )+  DOT ( DIGIT )* )                       
		{_ttype = DOUBLE_CONST;   }   

		| ( DIGIT )+     {  _ttype = INT_CONST;         }
			
        )
        ;

ID
        options 
                {
                testLiterals = true; 
				paraphrase = "an identifier";
                }
        :       ( 'a'..'z' | 'A'..'Z' | '_' )
                ( 'a'..'z' | 'A'..'Z' | '_' | '0'..'9' )*
				
        ;

