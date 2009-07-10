header "pre_include_hpp" 
{
    // gets inserted before antlr generated includes in the header file
}
header "post_include_hpp" 
{
    // gets inserted after antlr generated includes in the header file
    // outside any generated namespace specifications
}

header "pre_include_cpp" 
{
    // gets inserted before the antlr generated includes in the cpp file
}

header "post_include_cpp" 
{
    // gets inserted after the antlr generated includes in the cpp file
}

header 
{
    // gets inserted after generated namespace specifications in the header
    // file. But outside the generated class.
    #include <antlr/Token.hpp>
}

options 
{
	language="Cpp";
}

{
}

class MyParser extends Parser;

options 
{
	exportVocab=My;
    genHashLines = false;		// generated #line's or turn it off.
    buildAST = true;			// uses CommonAST by default
}

{
   // additional methods and members
}

expr:   
	mexpr (PLUS^ mexpr)* SEMI!
    ;

mexpr
    :   atom (STAR^ atom)*
    ;

atom:   INT
    ;

{
   // global stuff in the cpp file
}

class MyLexer extends Lexer;
options 
{
	exportVocab=My;
	genHashLines = false;		// generated #line's or turn it off.
}
{
   // additional methods and members
}
WS	:	(' '
	|	'\t'
	|	'\n'
	|	'\r')
		{ _ttype = ANTLR_USE_NAMESPACE(antlr)Token::SKIP; }
	;

LPAREN:	'('
	;

RPAREN:	')'
	;

STAR:	'*'
	;

PLUS:	'+'
	;

SEMI:	';'
	;

INT	:	('0'..'9')+
	;

