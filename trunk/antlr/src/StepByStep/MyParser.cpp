/* $ANTLR 2.7.7 (20060906): "grammer.g" -> "MyParser.cpp"$ */
#include "MyParser.hpp"
#include <antlr/NoViableAltException.hpp>
#include <antlr/SemanticException.hpp>
#include <antlr/ASTFactory.hpp>
#line 19 "grammer.g"

// My code section

// Activate inherited ASTNodeFactory
_PNodeFactory PNodeFactory;

extern _PNodeFactory PNodeFactory;

#line 16 "MyParser.cpp"
MyParser::MyParser(ANTLR_USE_NAMESPACE(antlr)TokenBuffer& tokenBuf, int k)
: ANTLR_USE_NAMESPACE(antlr)LLkParser(tokenBuf,k)
{
}

MyParser::MyParser(ANTLR_USE_NAMESPACE(antlr)TokenBuffer& tokenBuf)
: ANTLR_USE_NAMESPACE(antlr)LLkParser(tokenBuf,2)
{
}

MyParser::MyParser(ANTLR_USE_NAMESPACE(antlr)TokenStream& lexer, int k)
: ANTLR_USE_NAMESPACE(antlr)LLkParser(lexer,k)
{
}

MyParser::MyParser(ANTLR_USE_NAMESPACE(antlr)TokenStream& lexer)
: ANTLR_USE_NAMESPACE(antlr)LLkParser(lexer,2)
{
}

MyParser::MyParser(const ANTLR_USE_NAMESPACE(antlr)ParserSharedInputState& state)
: ANTLR_USE_NAMESPACE(antlr)LLkParser(state,2)
{
}

void MyParser::interpretation_unit() {
	returnAST = RefPNode(ANTLR_USE_NAMESPACE(antlr)nullAST);
	ANTLR_USE_NAMESPACE(antlr)ASTPair currentAST;
	RefPNode interpretation_unit_AST = RefPNode(ANTLR_USE_NAMESPACE(antlr)nullAST);
#line 42 "grammer.g"
	
			// theContext=context; 
		
#line 50 "MyParser.cpp"
	
	try {      // for error handling
		{
		switch ( LA(1)) {
		case ID:
		case CHAR:
		case INT:
		case BOOL:
		case DOUBLE:
		case STRING:
		{
			start_condition();
			astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(returnAST));
			break;
		}
		case ANTLR_USE_NAMESPACE(antlr)Token::EOF_TYPE:
		{
			break;
		}
		default:
		{
			throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
		}
		}
		}
		match(ANTLR_USE_NAMESPACE(antlr)Token::EOF_TYPE);
		interpretation_unit_AST = RefPNode(currentAST.root);
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		reportError(ex);
		recover(ex,_tokenSet_0);
	}
	returnAST = interpretation_unit_AST;
}

void MyParser::start_condition() {
	returnAST = RefPNode(ANTLR_USE_NAMESPACE(antlr)nullAST);
	ANTLR_USE_NAMESPACE(antlr)ASTPair currentAST;
	RefPNode start_condition_AST = RefPNode(ANTLR_USE_NAMESPACE(antlr)nullAST);
	
	try {      // for error handling
		{
		if ((_tokenSet_1.member(LA(1))) && (LA(2) == ID)) {
			declaration_list();
			astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(returnAST));
		}
		else if ((LA(1) == ID) && (LA(2) == LPAREN)) {
		}
		else {
			throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
		}
		
		}
		match(ID);
		match(LPAREN);
		match(RPAREN);
		compound_statement();
		astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(returnAST));
		start_condition_AST = RefPNode(currentAST.root);
#line 56 "grammer.g"
		start_condition_AST = RefPNode(astFactory->make((new ANTLR_USE_NAMESPACE(antlr)ASTArray(2))->add(ANTLR_USE_NAMESPACE(antlr)RefAST(astFactory->create(NStartCondition,"NStartCondition")))->add(ANTLR_USE_NAMESPACE(antlr)RefAST(start_condition_AST))));
#line 112 "MyParser.cpp"
		currentAST.root = start_condition_AST;
		if ( start_condition_AST!=RefPNode(ANTLR_USE_NAMESPACE(antlr)nullAST) &&
			start_condition_AST->getFirstChild() != RefPNode(ANTLR_USE_NAMESPACE(antlr)nullAST) )
			  currentAST.child = start_condition_AST->getFirstChild();
		else
			currentAST.child = start_condition_AST;
		currentAST.advanceChildToEnd();
		start_condition_AST = RefPNode(currentAST.root);
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		reportError(ex);
		recover(ex,_tokenSet_0);
	}
	returnAST = start_condition_AST;
}

void MyParser::declaration_list() {
	returnAST = RefPNode(ANTLR_USE_NAMESPACE(antlr)nullAST);
	ANTLR_USE_NAMESPACE(antlr)ASTPair currentAST;
	RefPNode declaration_list_AST = RefPNode(ANTLR_USE_NAMESPACE(antlr)nullAST);
	
	try {      // for error handling
		{ // ( ... )+
		int _cnt78=0;
		for (;;) {
			if ((_tokenSet_1.member(LA(1))) && (LA(2) == ID)) {
				declaration();
				astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(returnAST));
			}
			else {
				if ( _cnt78>=1 ) { goto _loop78; } else {throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());}
			}
			
			_cnt78++;
		}
		_loop78:;
		}  // ( ... )+
		declaration_list_AST = RefPNode(currentAST.root);
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		reportError(ex);
		recover(ex,_tokenSet_2);
	}
	returnAST = declaration_list_AST;
}

void MyParser::compound_statement() {
	returnAST = RefPNode(ANTLR_USE_NAMESPACE(antlr)nullAST);
	ANTLR_USE_NAMESPACE(antlr)ASTPair currentAST;
	RefPNode compound_statement_AST = RefPNode(ANTLR_USE_NAMESPACE(antlr)nullAST);
	
	try {      // for error handling
		RefPNode tmp5_AST = RefPNode(ANTLR_USE_NAMESPACE(antlr)nullAST);
		tmp5_AST = astFactory->create(LT(1));
		astFactory->makeASTRoot(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(tmp5_AST));
		match(LCURLY);
		{
		if ((_tokenSet_1.member(LA(1))) && (LA(2) == ID)) {
			declaration_list();
			astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(returnAST));
			{
			switch ( LA(1)) {
			case ID:
			case LCURLY:
			case SEMI:
			case SWITCH:
			case IF:
			case WHILE:
			case DO:
			case FOR:
			case COUT:
			{
				statement_list();
				astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(returnAST));
				break;
			}
			case RCURLY:
			{
				break;
			}
			default:
			{
				throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
			}
			}
			}
		}
		else if ((_tokenSet_3.member(LA(1))) && (_tokenSet_4.member(LA(2)))) {
			statement_list();
			astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(returnAST));
		}
		else if ((LA(1) == RCURLY)) {
		}
		else {
			throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
		}
		
		}
		match(RCURLY);
		compound_statement_AST = RefPNode(currentAST.root);
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		reportError(ex);
		recover(ex,_tokenSet_5);
	}
	returnAST = compound_statement_AST;
}

void MyParser::statement() {
	returnAST = RefPNode(ANTLR_USE_NAMESPACE(antlr)nullAST);
	ANTLR_USE_NAMESPACE(antlr)ASTPair currentAST;
	RefPNode statement_AST = RefPNode(ANTLR_USE_NAMESPACE(antlr)nullAST);
	
	try {      // for error handling
		switch ( LA(1)) {
		case LCURLY:
		{
			compound_statement();
			astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(returnAST));
			statement_AST = RefPNode(currentAST.root);
			break;
		}
		case ID:
		{
			assign_statement();
			astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(returnAST));
			statement_AST = RefPNode(currentAST.root);
			break;
		}
		case SEMI:
		case SWITCH:
		case IF:
		{
			selection_statement();
			astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(returnAST));
			statement_AST = RefPNode(currentAST.root);
			break;
		}
		case WHILE:
		case DO:
		case FOR:
		{
			iteration_statement();
			astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(returnAST));
			statement_AST = RefPNode(currentAST.root);
			break;
		}
		case COUT:
		{
			stream_statement();
			astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(returnAST));
			statement_AST = RefPNode(currentAST.root);
			break;
		}
		default:
		{
			throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
		}
		}
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		reportError(ex);
		recover(ex,_tokenSet_6);
	}
	returnAST = statement_AST;
}

void MyParser::assign_statement() {
	returnAST = RefPNode(ANTLR_USE_NAMESPACE(antlr)nullAST);
	ANTLR_USE_NAMESPACE(antlr)ASTPair currentAST;
	RefPNode assign_statement_AST = RefPNode(ANTLR_USE_NAMESPACE(antlr)nullAST);
	
	try {      // for error handling
		assign_expression();
		astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(returnAST));
		match(SEMI);
		assign_statement_AST = RefPNode(currentAST.root);
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		reportError(ex);
		recover(ex,_tokenSet_6);
	}
	returnAST = assign_statement_AST;
}

void MyParser::selection_statement() {
	returnAST = RefPNode(ANTLR_USE_NAMESPACE(antlr)nullAST);
	ANTLR_USE_NAMESPACE(antlr)ASTPair currentAST;
	RefPNode selection_statement_AST = RefPNode(ANTLR_USE_NAMESPACE(antlr)nullAST);
	
	try {      // for error handling
		switch ( LA(1)) {
		case SEMI:
		{
			match(SEMI);
			selection_statement_AST = RefPNode(currentAST.root);
			break;
		}
		case SWITCH:
		{
			switchBlock();
			astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(returnAST));
			selection_statement_AST = RefPNode(currentAST.root);
			break;
		}
		case IF:
		{
			ifThenBlock();
			astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(returnAST));
			selection_statement_AST = RefPNode(currentAST.root);
			break;
		}
		default:
		{
			throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
		}
		}
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		reportError(ex);
		recover(ex,_tokenSet_6);
	}
	returnAST = selection_statement_AST;
}

void MyParser::iteration_statement() {
	returnAST = RefPNode(ANTLR_USE_NAMESPACE(antlr)nullAST);
	ANTLR_USE_NAMESPACE(antlr)ASTPair currentAST;
	RefPNode iteration_statement_AST = RefPNode(ANTLR_USE_NAMESPACE(antlr)nullAST);
	
	try {      // for error handling
		switch ( LA(1)) {
		case WHILE:
		{
			RefPNode tmp9_AST = RefPNode(ANTLR_USE_NAMESPACE(antlr)nullAST);
			tmp9_AST = astFactory->create(LT(1));
			astFactory->makeASTRoot(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(tmp9_AST));
			match(WHILE);
			match(LPAREN);
			condition();
			astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(returnAST));
			match(RPAREN);
			codeBlock();
			astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(returnAST));
			iteration_statement_AST = RefPNode(currentAST.root);
			break;
		}
		case DO:
		{
			RefPNode tmp12_AST = RefPNode(ANTLR_USE_NAMESPACE(antlr)nullAST);
			tmp12_AST = astFactory->create(LT(1));
			astFactory->makeASTRoot(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(tmp12_AST));
			match(DO);
			codeBlock();
			astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(returnAST));
			match(WHILE);
			match(LPAREN);
			condition();
			astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(returnAST));
			match(RPAREN);
			match(SEMI);
			iteration_statement_AST = RefPNode(currentAST.root);
			break;
		}
		case FOR:
		{
			for_loop();
			astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(returnAST));
			iteration_statement_AST = RefPNode(currentAST.root);
			break;
		}
		default:
		{
			throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
		}
		}
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		reportError(ex);
		recover(ex,_tokenSet_6);
	}
	returnAST = iteration_statement_AST;
}

void MyParser::stream_statement() {
	returnAST = RefPNode(ANTLR_USE_NAMESPACE(antlr)nullAST);
	ANTLR_USE_NAMESPACE(antlr)ASTPair currentAST;
	RefPNode stream_statement_AST = RefPNode(ANTLR_USE_NAMESPACE(antlr)nullAST);
	
	try {      // for error handling
		RefPNode tmp17_AST = RefPNode(ANTLR_USE_NAMESPACE(antlr)nullAST);
		tmp17_AST = astFactory->create(LT(1));
		astFactory->makeASTRoot(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(tmp17_AST));
		match(COUT);
		stream();
		astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(returnAST));
		match(SEMI);
		stream_statement_AST = RefPNode(currentAST.root);
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		reportError(ex);
		recover(ex,_tokenSet_6);
	}
	returnAST = stream_statement_AST;
}

void MyParser::statement_list() {
	returnAST = RefPNode(ANTLR_USE_NAMESPACE(antlr)nullAST);
	ANTLR_USE_NAMESPACE(antlr)ASTPair currentAST;
	RefPNode statement_list_AST = RefPNode(ANTLR_USE_NAMESPACE(antlr)nullAST);
	
	try {      // for error handling
		{ // ( ... )+
		int _cnt11=0;
		for (;;) {
			if ((_tokenSet_3.member(LA(1)))) {
				statement();
				astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(returnAST));
			}
			else {
				if ( _cnt11>=1 ) { goto _loop11; } else {throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());}
			}
			
			_cnt11++;
		}
		_loop11:;
		}  // ( ... )+
		statement_list_AST = RefPNode(currentAST.root);
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		reportError(ex);
		recover(ex,_tokenSet_7);
	}
	returnAST = statement_list_AST;
}

void MyParser::switchBlock() {
	returnAST = RefPNode(ANTLR_USE_NAMESPACE(antlr)nullAST);
	ANTLR_USE_NAMESPACE(antlr)ASTPair currentAST;
	RefPNode switchBlock_AST = RefPNode(ANTLR_USE_NAMESPACE(antlr)nullAST);
	
	try {      // for error handling
		match(SWITCH);
		match(LPAREN);
		expression();
		astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(returnAST));
		match(RPAREN);
		match(LCURLY);
		{ // ( ... )*
		for (;;) {
			if ((LA(1) == CASE)) {
				case_statement();
				astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(returnAST));
			}
			else {
				goto _loop15;
			}
			
		}
		_loop15:;
		} // ( ... )*
		{
		switch ( LA(1)) {
		case DEFAULT:
		{
			default_statement();
			astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(returnAST));
			break;
		}
		case RCURLY:
		{
			break;
		}
		default:
		{
			throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
		}
		}
		}
		match(RCURLY);
		switchBlock_AST = RefPNode(currentAST.root);
#line 100 "grammer.g"
		switchBlock_AST = RefPNode(astFactory->make((new ANTLR_USE_NAMESPACE(antlr)ASTArray(2))->add(ANTLR_USE_NAMESPACE(antlr)RefAST(astFactory->create(NSwitchBlock,"NSwitchBlock")))->add(ANTLR_USE_NAMESPACE(antlr)RefAST(switchBlock_AST))));
#line 496 "MyParser.cpp"
		currentAST.root = switchBlock_AST;
		if ( switchBlock_AST!=RefPNode(ANTLR_USE_NAMESPACE(antlr)nullAST) &&
			switchBlock_AST->getFirstChild() != RefPNode(ANTLR_USE_NAMESPACE(antlr)nullAST) )
			  currentAST.child = switchBlock_AST->getFirstChild();
		else
			currentAST.child = switchBlock_AST;
		currentAST.advanceChildToEnd();
		switchBlock_AST = RefPNode(currentAST.root);
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		reportError(ex);
		recover(ex,_tokenSet_6);
	}
	returnAST = switchBlock_AST;
}

void MyParser::ifThenBlock() {
	returnAST = RefPNode(ANTLR_USE_NAMESPACE(antlr)nullAST);
	ANTLR_USE_NAMESPACE(antlr)ASTPair currentAST;
	RefPNode ifThenBlock_AST = RefPNode(ANTLR_USE_NAMESPACE(antlr)nullAST);
	
	try {      // for error handling
		ifBlock();
		astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(returnAST));
		{
		if ((LA(1) == ELSE) && (_tokenSet_3.member(LA(2)))) {
			elseBlock();
			astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(returnAST));
		}
		else if ((_tokenSet_6.member(LA(1))) && (_tokenSet_8.member(LA(2)))) {
		}
		else {
			throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
		}
		
		}
		ifThenBlock_AST = RefPNode(currentAST.root);
#line 123 "grammer.g"
		ifThenBlock_AST = RefPNode(astFactory->make((new ANTLR_USE_NAMESPACE(antlr)ASTArray(2))->add(ANTLR_USE_NAMESPACE(antlr)RefAST(astFactory->create(NIfThenBlock,"NIfThenBlock")))->add(ANTLR_USE_NAMESPACE(antlr)RefAST(ifThenBlock_AST))));
#line 536 "MyParser.cpp"
		currentAST.root = ifThenBlock_AST;
		if ( ifThenBlock_AST!=RefPNode(ANTLR_USE_NAMESPACE(antlr)nullAST) &&
			ifThenBlock_AST->getFirstChild() != RefPNode(ANTLR_USE_NAMESPACE(antlr)nullAST) )
			  currentAST.child = ifThenBlock_AST->getFirstChild();
		else
			currentAST.child = ifThenBlock_AST;
		currentAST.advanceChildToEnd();
		ifThenBlock_AST = RefPNode(currentAST.root);
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		reportError(ex);
		recover(ex,_tokenSet_6);
	}
	returnAST = ifThenBlock_AST;
}

void MyParser::expression() {
	returnAST = RefPNode(ANTLR_USE_NAMESPACE(antlr)nullAST);
	ANTLR_USE_NAMESPACE(antlr)ASTPair currentAST;
	RefPNode expression_AST = RefPNode(ANTLR_USE_NAMESPACE(antlr)nullAST);
	
	try {      // for error handling
		logical_and_expression();
		astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(returnAST));
		{ // ( ... )*
		for (;;) {
			if ((LA(1) == LOR)) {
				RefPNode tmp24_AST = RefPNode(ANTLR_USE_NAMESPACE(antlr)nullAST);
				tmp24_AST = astFactory->create(LT(1));
				astFactory->makeASTRoot(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(tmp24_AST));
				match(LOR);
				logical_and_expression();
				astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(returnAST));
			}
			else {
				goto _loop50;
			}
			
		}
		_loop50:;
		} // ( ... )*
		expression_AST = RefPNode(currentAST.root);
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		reportError(ex);
		recover(ex,_tokenSet_9);
	}
	returnAST = expression_AST;
}

void MyParser::case_statement() {
	returnAST = RefPNode(ANTLR_USE_NAMESPACE(antlr)nullAST);
	ANTLR_USE_NAMESPACE(antlr)ASTPair currentAST;
	RefPNode case_statement_AST = RefPNode(ANTLR_USE_NAMESPACE(antlr)nullAST);
	
	try {      // for error handling
		match(CASE);
		condition();
		astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(returnAST));
		match(COLON);
		codeBlock();
		astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(returnAST));
		case_statement_AST = RefPNode(currentAST.root);
#line 105 "grammer.g"
		case_statement_AST = RefPNode(astFactory->make((new ANTLR_USE_NAMESPACE(antlr)ASTArray(2))->add(ANTLR_USE_NAMESPACE(antlr)RefAST(astFactory->create(NCaseStatement,"NCaseStatement")))->add(ANTLR_USE_NAMESPACE(antlr)RefAST(case_statement_AST))));
#line 602 "MyParser.cpp"
		currentAST.root = case_statement_AST;
		if ( case_statement_AST!=RefPNode(ANTLR_USE_NAMESPACE(antlr)nullAST) &&
			case_statement_AST->getFirstChild() != RefPNode(ANTLR_USE_NAMESPACE(antlr)nullAST) )
			  currentAST.child = case_statement_AST->getFirstChild();
		else
			currentAST.child = case_statement_AST;
		currentAST.advanceChildToEnd();
		case_statement_AST = RefPNode(currentAST.root);
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		reportError(ex);
		recover(ex,_tokenSet_10);
	}
	returnAST = case_statement_AST;
}

void MyParser::default_statement() {
	returnAST = RefPNode(ANTLR_USE_NAMESPACE(antlr)nullAST);
	ANTLR_USE_NAMESPACE(antlr)ASTPair currentAST;
	RefPNode default_statement_AST = RefPNode(ANTLR_USE_NAMESPACE(antlr)nullAST);
	
	try {      // for error handling
		match(DEFAULT);
		match(COLON);
		codeBlock();
		astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(returnAST));
		default_statement_AST = RefPNode(currentAST.root);
#line 110 "grammer.g"
		default_statement_AST = RefPNode(astFactory->make((new ANTLR_USE_NAMESPACE(antlr)ASTArray(2))->add(ANTLR_USE_NAMESPACE(antlr)RefAST(astFactory->create(NDefaultStatement,"NDefaultStatement")))->add(ANTLR_USE_NAMESPACE(antlr)RefAST(default_statement_AST))));
#line 632 "MyParser.cpp"
		currentAST.root = default_statement_AST;
		if ( default_statement_AST!=RefPNode(ANTLR_USE_NAMESPACE(antlr)nullAST) &&
			default_statement_AST->getFirstChild() != RefPNode(ANTLR_USE_NAMESPACE(antlr)nullAST) )
			  currentAST.child = default_statement_AST->getFirstChild();
		else
			currentAST.child = default_statement_AST;
		currentAST.advanceChildToEnd();
		default_statement_AST = RefPNode(currentAST.root);
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		reportError(ex);
		recover(ex,_tokenSet_7);
	}
	returnAST = default_statement_AST;
}

void MyParser::condition() {
	returnAST = RefPNode(ANTLR_USE_NAMESPACE(antlr)nullAST);
	ANTLR_USE_NAMESPACE(antlr)ASTPair currentAST;
	RefPNode condition_AST = RefPNode(ANTLR_USE_NAMESPACE(antlr)nullAST);
	
	try {      // for error handling
		expression();
		astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(returnAST));
		condition_AST = RefPNode(currentAST.root);
#line 141 "grammer.g"
		condition_AST = RefPNode(astFactory->make((new ANTLR_USE_NAMESPACE(antlr)ASTArray(2))->add(ANTLR_USE_NAMESPACE(antlr)RefAST(astFactory->create(NCondition,"NCondition")))->add(ANTLR_USE_NAMESPACE(antlr)RefAST(condition_AST))));
#line 660 "MyParser.cpp"
		currentAST.root = condition_AST;
		if ( condition_AST!=RefPNode(ANTLR_USE_NAMESPACE(antlr)nullAST) &&
			condition_AST->getFirstChild() != RefPNode(ANTLR_USE_NAMESPACE(antlr)nullAST) )
			  currentAST.child = condition_AST->getFirstChild();
		else
			currentAST.child = condition_AST;
		currentAST.advanceChildToEnd();
		condition_AST = RefPNode(currentAST.root);
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		reportError(ex);
		recover(ex,_tokenSet_11);
	}
	returnAST = condition_AST;
}

void MyParser::codeBlock() {
	returnAST = RefPNode(ANTLR_USE_NAMESPACE(antlr)nullAST);
	ANTLR_USE_NAMESPACE(antlr)ASTPair currentAST;
	RefPNode codeBlock_AST = RefPNode(ANTLR_USE_NAMESPACE(antlr)nullAST);
	
	try {      // for error handling
		{
		statement();
		astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(returnAST));
		}
		codeBlock_AST = RefPNode(currentAST.root);
#line 153 "grammer.g"
		codeBlock_AST = RefPNode(astFactory->make((new ANTLR_USE_NAMESPACE(antlr)ASTArray(2))->add(ANTLR_USE_NAMESPACE(antlr)RefAST(astFactory->create(NCodeBlock,"NCodeBlock")))->add(ANTLR_USE_NAMESPACE(antlr)RefAST(codeBlock_AST))));
#line 690 "MyParser.cpp"
		currentAST.root = codeBlock_AST;
		if ( codeBlock_AST!=RefPNode(ANTLR_USE_NAMESPACE(antlr)nullAST) &&
			codeBlock_AST->getFirstChild() != RefPNode(ANTLR_USE_NAMESPACE(antlr)nullAST) )
			  currentAST.child = codeBlock_AST->getFirstChild();
		else
			currentAST.child = codeBlock_AST;
		currentAST.advanceChildToEnd();
		codeBlock_AST = RefPNode(currentAST.root);
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		reportError(ex);
		recover(ex,_tokenSet_6);
	}
	returnAST = codeBlock_AST;
}

void MyParser::ifBlock() {
	returnAST = RefPNode(ANTLR_USE_NAMESPACE(antlr)nullAST);
	ANTLR_USE_NAMESPACE(antlr)ASTPair currentAST;
	RefPNode ifBlock_AST = RefPNode(ANTLR_USE_NAMESPACE(antlr)nullAST);
	
	try {      // for error handling
		match(IF);
		match(LPAREN);
		condition();
		astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(returnAST));
		match(RPAREN);
		codeBlock();
		astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(returnAST));
		ifBlock_AST = RefPNode(currentAST.root);
#line 129 "grammer.g"
		ifBlock_AST = RefPNode(astFactory->make((new ANTLR_USE_NAMESPACE(antlr)ASTArray(2))->add(ANTLR_USE_NAMESPACE(antlr)RefAST(astFactory->create(NIfBlock,"NIfBlock")))->add(ANTLR_USE_NAMESPACE(antlr)RefAST(ifBlock_AST))));
#line 723 "MyParser.cpp"
		currentAST.root = ifBlock_AST;
		if ( ifBlock_AST!=RefPNode(ANTLR_USE_NAMESPACE(antlr)nullAST) &&
			ifBlock_AST->getFirstChild() != RefPNode(ANTLR_USE_NAMESPACE(antlr)nullAST) )
			  currentAST.child = ifBlock_AST->getFirstChild();
		else
			currentAST.child = ifBlock_AST;
		currentAST.advanceChildToEnd();
		ifBlock_AST = RefPNode(currentAST.root);
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		reportError(ex);
		recover(ex,_tokenSet_6);
	}
	returnAST = ifBlock_AST;
}

void MyParser::elseBlock() {
	returnAST = RefPNode(ANTLR_USE_NAMESPACE(antlr)nullAST);
	ANTLR_USE_NAMESPACE(antlr)ASTPair currentAST;
	RefPNode elseBlock_AST = RefPNode(ANTLR_USE_NAMESPACE(antlr)nullAST);
	
	try {      // for error handling
		match(ELSE);
		codeBlock();
		astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(returnAST));
		elseBlock_AST = RefPNode(currentAST.root);
#line 135 "grammer.g"
		elseBlock_AST = RefPNode(astFactory->make((new ANTLR_USE_NAMESPACE(antlr)ASTArray(2))->add(ANTLR_USE_NAMESPACE(antlr)RefAST(astFactory->create(NElseBlock,"NElseBlock")))->add(ANTLR_USE_NAMESPACE(antlr)RefAST(elseBlock_AST))));
#line 752 "MyParser.cpp"
		currentAST.root = elseBlock_AST;
		if ( elseBlock_AST!=RefPNode(ANTLR_USE_NAMESPACE(antlr)nullAST) &&
			elseBlock_AST->getFirstChild() != RefPNode(ANTLR_USE_NAMESPACE(antlr)nullAST) )
			  currentAST.child = elseBlock_AST->getFirstChild();
		else
			currentAST.child = elseBlock_AST;
		currentAST.advanceChildToEnd();
		elseBlock_AST = RefPNode(currentAST.root);
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		reportError(ex);
		recover(ex,_tokenSet_6);
	}
	returnAST = elseBlock_AST;
}

void MyParser::for_loop() {
	returnAST = RefPNode(ANTLR_USE_NAMESPACE(antlr)nullAST);
	ANTLR_USE_NAMESPACE(antlr)ASTPair currentAST;
	RefPNode for_loop_AST = RefPNode(ANTLR_USE_NAMESPACE(antlr)nullAST);
	
	try {      // for error handling
		RefPNode tmp33_AST = RefPNode(ANTLR_USE_NAMESPACE(antlr)nullAST);
		tmp33_AST = astFactory->create(LT(1));
		astFactory->makeASTRoot(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(tmp33_AST));
		match(FOR);
		match(LPAREN);
		for_expression();
		astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(returnAST));
		match(SEMI);
		loop_cntrl();
		astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(returnAST));
		for_loop_AST = RefPNode(currentAST.root);
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		reportError(ex);
		recover(ex,_tokenSet_6);
	}
	returnAST = for_loop_AST;
}

void MyParser::for_expression() {
	returnAST = RefPNode(ANTLR_USE_NAMESPACE(antlr)nullAST);
	ANTLR_USE_NAMESPACE(antlr)ASTPair currentAST;
	RefPNode for_expression_AST = RefPNode(ANTLR_USE_NAMESPACE(antlr)nullAST);
	
	try {      // for error handling
		if ((LA(1) == ID) && (_tokenSet_12.member(LA(2)))) {
			assign_expression();
			astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(returnAST));
			for_expression_AST = RefPNode(currentAST.root);
		}
		else if ((_tokenSet_1.member(LA(1))) && (LA(2) == ID)) {
			for_declaration();
			astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(returnAST));
			for_expression_AST = RefPNode(currentAST.root);
		}
		else {
			throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
		}
		
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		reportError(ex);
		recover(ex,_tokenSet_13);
	}
	returnAST = for_expression_AST;
}

void MyParser::loop_cntrl() {
	returnAST = RefPNode(ANTLR_USE_NAMESPACE(antlr)nullAST);
	ANTLR_USE_NAMESPACE(antlr)ASTPair currentAST;
	RefPNode loop_cntrl_AST = RefPNode(ANTLR_USE_NAMESPACE(antlr)nullAST);
	
	try {      // for error handling
		condition();
		astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(returnAST));
		match(SEMI);
		forBlock();
		astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(returnAST));
		loop_cntrl_AST = RefPNode(currentAST.root);
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		reportError(ex);
		recover(ex,_tokenSet_6);
	}
	returnAST = loop_cntrl_AST;
}

void MyParser::assign_expression() {
	returnAST = RefPNode(ANTLR_USE_NAMESPACE(antlr)nullAST);
	ANTLR_USE_NAMESPACE(antlr)ASTPair currentAST;
	RefPNode assign_expression_AST = RefPNode(ANTLR_USE_NAMESPACE(antlr)nullAST);
	RefPNode a_AST = RefPNode(ANTLR_USE_NAMESPACE(antlr)nullAST);
	
	try {      // for error handling
		assign_ID();
		astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(returnAST));
		{
		switch ( LA(1)) {
		case INC_OP:
		{
			RefPNode tmp37_AST = RefPNode(ANTLR_USE_NAMESPACE(antlr)nullAST);
			tmp37_AST = astFactory->create(LT(1));
			astFactory->makeASTRoot(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(tmp37_AST));
			match(INC_OP);
			break;
		}
		case DEC_OP:
		{
			RefPNode tmp38_AST = RefPNode(ANTLR_USE_NAMESPACE(antlr)nullAST);
			tmp38_AST = astFactory->create(LT(1));
			astFactory->makeASTRoot(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(tmp38_AST));
			match(DEC_OP);
			break;
		}
		case ASSIGN:
		case ADD_ASSIGN:
		case SUB_ASSIGN:
		case DIV_ASSIGN:
		case STAR_ASSIGN:
		case MOD_ASSIGN:
		{
			assignment_operator();
			a_AST = returnAST;
			expression();
			astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(returnAST));
			assign_expression_AST = RefPNode(currentAST.root);
#line 200 "grammer.g"
			assign_expression_AST = RefPNode(astFactory->make((new ANTLR_USE_NAMESPACE(antlr)ASTArray(2))->add(ANTLR_USE_NAMESPACE(antlr)RefAST(a_AST))->add(ANTLR_USE_NAMESPACE(antlr)RefAST(assign_expression_AST))));
#line 883 "MyParser.cpp"
			currentAST.root = assign_expression_AST;
			if ( assign_expression_AST!=RefPNode(ANTLR_USE_NAMESPACE(antlr)nullAST) &&
				assign_expression_AST->getFirstChild() != RefPNode(ANTLR_USE_NAMESPACE(antlr)nullAST) )
				  currentAST.child = assign_expression_AST->getFirstChild();
			else
				currentAST.child = assign_expression_AST;
			currentAST.advanceChildToEnd();
			break;
		}
		default:
		{
			throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
		}
		}
		}
		assign_expression_AST = RefPNode(currentAST.root);
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		reportError(ex);
		recover(ex,_tokenSet_14);
	}
	returnAST = assign_expression_AST;
}

void MyParser::for_declaration() {
	returnAST = RefPNode(ANTLR_USE_NAMESPACE(antlr)nullAST);
	ANTLR_USE_NAMESPACE(antlr)ASTPair currentAST;
	RefPNode for_declaration_AST = RefPNode(ANTLR_USE_NAMESPACE(antlr)nullAST);
	
	try {      // for error handling
		type_specifier();
		astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(returnAST));
		declarator();
		astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(returnAST));
		match(ASSIGN);
		expression();
		astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(returnAST));
		for_declaration_AST = RefPNode(currentAST.root);
#line 173 "grammer.g"
		for_declaration_AST = RefPNode(astFactory->make((new ANTLR_USE_NAMESPACE(antlr)ASTArray(2))->add(ANTLR_USE_NAMESPACE(antlr)RefAST(astFactory->create(NForDeclaration,"NForDeclaration")))->add(ANTLR_USE_NAMESPACE(antlr)RefAST(for_declaration_AST))));
#line 924 "MyParser.cpp"
		currentAST.root = for_declaration_AST;
		if ( for_declaration_AST!=RefPNode(ANTLR_USE_NAMESPACE(antlr)nullAST) &&
			for_declaration_AST->getFirstChild() != RefPNode(ANTLR_USE_NAMESPACE(antlr)nullAST) )
			  currentAST.child = for_declaration_AST->getFirstChild();
		else
			currentAST.child = for_declaration_AST;
		currentAST.advanceChildToEnd();
		for_declaration_AST = RefPNode(currentAST.root);
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		reportError(ex);
		recover(ex,_tokenSet_13);
	}
	returnAST = for_declaration_AST;
}

void MyParser::type_specifier() {
	returnAST = RefPNode(ANTLR_USE_NAMESPACE(antlr)nullAST);
	ANTLR_USE_NAMESPACE(antlr)ASTPair currentAST;
	RefPNode type_specifier_AST = RefPNode(ANTLR_USE_NAMESPACE(antlr)nullAST);
	
	try {      // for error handling
		{
		switch ( LA(1)) {
		case CHAR:
		{
			RefPNode tmp40_AST = RefPNode(ANTLR_USE_NAMESPACE(antlr)nullAST);
			tmp40_AST = astFactory->create(LT(1));
			astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(tmp40_AST));
			match(CHAR);
			break;
		}
		case INT:
		{
			RefPNode tmp41_AST = RefPNode(ANTLR_USE_NAMESPACE(antlr)nullAST);
			tmp41_AST = astFactory->create(LT(1));
			astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(tmp41_AST));
			match(INT);
			break;
		}
		case BOOL:
		{
			RefPNode tmp42_AST = RefPNode(ANTLR_USE_NAMESPACE(antlr)nullAST);
			tmp42_AST = astFactory->create(LT(1));
			astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(tmp42_AST));
			match(BOOL);
			break;
		}
		case DOUBLE:
		{
			RefPNode tmp43_AST = RefPNode(ANTLR_USE_NAMESPACE(antlr)nullAST);
			tmp43_AST = astFactory->create(LT(1));
			astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(tmp43_AST));
			match(DOUBLE);
			break;
		}
		case STRING:
		{
			RefPNode tmp44_AST = RefPNode(ANTLR_USE_NAMESPACE(antlr)nullAST);
			tmp44_AST = astFactory->create(LT(1));
			astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(tmp44_AST));
			match(STRING);
			break;
		}
		case ID:
		{
			RefPNode tmp45_AST = RefPNode(ANTLR_USE_NAMESPACE(antlr)nullAST);
			tmp45_AST = astFactory->create(LT(1));
			astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(tmp45_AST));
			match(ID);
			break;
		}
		default:
		{
			throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
		}
		}
		}
		type_specifier_AST = RefPNode(currentAST.root);
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		reportError(ex);
		recover(ex,_tokenSet_15);
	}
	returnAST = type_specifier_AST;
}

void MyParser::declarator() {
	returnAST = RefPNode(ANTLR_USE_NAMESPACE(antlr)nullAST);
	ANTLR_USE_NAMESPACE(antlr)ASTPair currentAST;
	RefPNode declarator_AST = RefPNode(ANTLR_USE_NAMESPACE(antlr)nullAST);
	
	try {      // for error handling
		RefPNode tmp46_AST = RefPNode(ANTLR_USE_NAMESPACE(antlr)nullAST);
		tmp46_AST = astFactory->create(LT(1));
		astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(tmp46_AST));
		match(ID);
		{
		switch ( LA(1)) {
		case LBRACKET:
		{
			match(LBRACKET);
			expression();
			astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(returnAST));
			match(RBRACKET);
			declarator_AST = RefPNode(currentAST.root);
#line 337 "grammer.g"
			declarator_AST = RefPNode(astFactory->make((new ANTLR_USE_NAMESPACE(antlr)ASTArray(2))->add(ANTLR_USE_NAMESPACE(antlr)RefAST(astFactory->create(NDeclareList,"NDeclareList")))->add(ANTLR_USE_NAMESPACE(antlr)RefAST(declarator_AST))));
#line 1033 "MyParser.cpp"
			currentAST.root = declarator_AST;
			if ( declarator_AST!=RefPNode(ANTLR_USE_NAMESPACE(antlr)nullAST) &&
				declarator_AST->getFirstChild() != RefPNode(ANTLR_USE_NAMESPACE(antlr)nullAST) )
				  currentAST.child = declarator_AST->getFirstChild();
			else
				currentAST.child = declarator_AST;
			currentAST.advanceChildToEnd();
			break;
		}
		case SEMI:
		case ASSIGN:
		case COMMA:
		{
			break;
		}
		default:
		{
			throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
		}
		}
		}
		declarator_AST = RefPNode(currentAST.root);
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		reportError(ex);
		recover(ex,_tokenSet_16);
	}
	returnAST = declarator_AST;
}

void MyParser::forBlock() {
	returnAST = RefPNode(ANTLR_USE_NAMESPACE(antlr)nullAST);
	ANTLR_USE_NAMESPACE(antlr)ASTPair currentAST;
	RefPNode forBlock_AST = RefPNode(ANTLR_USE_NAMESPACE(antlr)nullAST);
	RefPNode ax_AST = RefPNode(ANTLR_USE_NAMESPACE(antlr)nullAST);
	RefPNode st_AST = RefPNode(ANTLR_USE_NAMESPACE(antlr)nullAST);
	
	try {      // for error handling
		{
		assign_expression();
		ax_AST = returnAST;
		match(RPAREN);
		statement();
		st_AST = returnAST;
		}
		forBlock_AST = RefPNode(currentAST.root);
#line 189 "grammer.g"
		forBlock_AST = RefPNode(astFactory->make((new ANTLR_USE_NAMESPACE(antlr)ASTArray(3))->add(ANTLR_USE_NAMESPACE(antlr)RefAST(astFactory->create(NForBlock,"NForBlock")))->add(ANTLR_USE_NAMESPACE(antlr)RefAST(st_AST))->add(ANTLR_USE_NAMESPACE(antlr)RefAST(ax_AST))));
#line 1082 "MyParser.cpp"
		currentAST.root = forBlock_AST;
		if ( forBlock_AST!=RefPNode(ANTLR_USE_NAMESPACE(antlr)nullAST) &&
			forBlock_AST->getFirstChild() != RefPNode(ANTLR_USE_NAMESPACE(antlr)nullAST) )
			  currentAST.child = forBlock_AST->getFirstChild();
		else
			currentAST.child = forBlock_AST;
		currentAST.advanceChildToEnd();
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		reportError(ex);
		recover(ex,_tokenSet_6);
	}
	returnAST = forBlock_AST;
}

void MyParser::assign_ID() {
	returnAST = RefPNode(ANTLR_USE_NAMESPACE(antlr)nullAST);
	ANTLR_USE_NAMESPACE(antlr)ASTPair currentAST;
	RefPNode assign_ID_AST = RefPNode(ANTLR_USE_NAMESPACE(antlr)nullAST);
	
	try {      // for error handling
		RefPNode tmp50_AST = RefPNode(ANTLR_USE_NAMESPACE(antlr)nullAST);
		tmp50_AST = astFactory->create(LT(1));
		astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(tmp50_AST));
		match(ID);
		{
		switch ( LA(1)) {
		case LBRACKET:
		{
			match(LBRACKET);
			expression();
			astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(returnAST));
			match(RBRACKET);
			assign_ID_AST = RefPNode(currentAST.root);
#line 206 "grammer.g"
			assign_ID_AST = RefPNode(astFactory->make((new ANTLR_USE_NAMESPACE(antlr)ASTArray(2))->add(ANTLR_USE_NAMESPACE(antlr)RefAST(astFactory->create(NAssignList,"NAssignList")))->add(ANTLR_USE_NAMESPACE(antlr)RefAST(assign_ID_AST))));
#line 1119 "MyParser.cpp"
			currentAST.root = assign_ID_AST;
			if ( assign_ID_AST!=RefPNode(ANTLR_USE_NAMESPACE(antlr)nullAST) &&
				assign_ID_AST->getFirstChild() != RefPNode(ANTLR_USE_NAMESPACE(antlr)nullAST) )
				  currentAST.child = assign_ID_AST->getFirstChild();
			else
				currentAST.child = assign_ID_AST;
			currentAST.advanceChildToEnd();
			break;
		}
		case ASSIGN:
		case INC_OP:
		case DEC_OP:
		case ADD_ASSIGN:
		case SUB_ASSIGN:
		case DIV_ASSIGN:
		case STAR_ASSIGN:
		case MOD_ASSIGN:
		{
			break;
		}
		default:
		{
			throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
		}
		}
		}
		assign_ID_AST = RefPNode(currentAST.root);
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		reportError(ex);
		recover(ex,_tokenSet_17);
	}
	returnAST = assign_ID_AST;
}

void MyParser::assignment_operator() {
	returnAST = RefPNode(ANTLR_USE_NAMESPACE(antlr)nullAST);
	ANTLR_USE_NAMESPACE(antlr)ASTPair currentAST;
	RefPNode assignment_operator_AST = RefPNode(ANTLR_USE_NAMESPACE(antlr)nullAST);
	
	try {      // for error handling
		{
		switch ( LA(1)) {
		case ASSIGN:
		{
			RefPNode tmp53_AST = RefPNode(ANTLR_USE_NAMESPACE(antlr)nullAST);
			tmp53_AST = astFactory->create(LT(1));
			astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(tmp53_AST));
			match(ASSIGN);
			break;
		}
		case ADD_ASSIGN:
		{
			RefPNode tmp54_AST = RefPNode(ANTLR_USE_NAMESPACE(antlr)nullAST);
			tmp54_AST = astFactory->create(LT(1));
			astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(tmp54_AST));
			match(ADD_ASSIGN);
			break;
		}
		case SUB_ASSIGN:
		{
			RefPNode tmp55_AST = RefPNode(ANTLR_USE_NAMESPACE(antlr)nullAST);
			tmp55_AST = astFactory->create(LT(1));
			astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(tmp55_AST));
			match(SUB_ASSIGN);
			break;
		}
		case DIV_ASSIGN:
		{
			RefPNode tmp56_AST = RefPNode(ANTLR_USE_NAMESPACE(antlr)nullAST);
			tmp56_AST = astFactory->create(LT(1));
			astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(tmp56_AST));
			match(DIV_ASSIGN);
			break;
		}
		case STAR_ASSIGN:
		{
			RefPNode tmp57_AST = RefPNode(ANTLR_USE_NAMESPACE(antlr)nullAST);
			tmp57_AST = astFactory->create(LT(1));
			astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(tmp57_AST));
			match(STAR_ASSIGN);
			break;
		}
		case MOD_ASSIGN:
		{
			RefPNode tmp58_AST = RefPNode(ANTLR_USE_NAMESPACE(antlr)nullAST);
			tmp58_AST = astFactory->create(LT(1));
			astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(tmp58_AST));
			match(MOD_ASSIGN);
			break;
		}
		default:
		{
			throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
		}
		}
		}
		assignment_operator_AST = RefPNode(currentAST.root);
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		reportError(ex);
		recover(ex,_tokenSet_18);
	}
	returnAST = assignment_operator_AST;
}

void MyParser::argument_expression_list() {
	returnAST = RefPNode(ANTLR_USE_NAMESPACE(antlr)nullAST);
	ANTLR_USE_NAMESPACE(antlr)ASTPair currentAST;
	RefPNode argument_expression_list_AST = RefPNode(ANTLR_USE_NAMESPACE(antlr)nullAST);
	
	try {      // for error handling
		expression();
		astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(returnAST));
		{ // ( ... )*
		for (;;) {
			if ((LA(1) == COMMA)) {
				RefPNode tmp59_AST = RefPNode(ANTLR_USE_NAMESPACE(antlr)nullAST);
				tmp59_AST = astFactory->create(LT(1));
				astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(tmp59_AST));
				match(COMMA);
				expression();
				astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(returnAST));
			}
			else {
				goto _loop42;
			}
			
		}
		_loop42:;
		} // ( ... )*
		argument_expression_list_AST = RefPNode(currentAST.root);
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		reportError(ex);
		recover(ex,_tokenSet_0);
	}
	returnAST = argument_expression_list_AST;
}

void MyParser::stream() {
	returnAST = RefPNode(ANTLR_USE_NAMESPACE(antlr)nullAST);
	ANTLR_USE_NAMESPACE(antlr)ASTPair currentAST;
	RefPNode stream_AST = RefPNode(ANTLR_USE_NAMESPACE(antlr)nullAST);
	
	try {      // for error handling
		{ // ( ... )+
		int _cnt47=0;
		for (;;) {
			if ((LA(1) == LSHIFT)) {
				match(LSHIFT);
				{
				switch ( LA(1)) {
				case ID:
				case LPAREN:
				case PLUS:
				case MINUS:
				case LNOT:
				case STRING_LITERAL:
				case CHAR_LITERAL:
				case DOUBLE_CONST:
				case INT_CONST:
				case TRUE:
				case FALSE:
				{
					expression();
					astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(returnAST));
					break;
				}
				case ENDL:
				{
					RefPNode tmp61_AST = RefPNode(ANTLR_USE_NAMESPACE(antlr)nullAST);
					tmp61_AST = astFactory->create(LT(1));
					astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(tmp61_AST));
					match(ENDL);
					break;
				}
				default:
				{
					throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
				}
				}
				}
			}
			else {
				if ( _cnt47>=1 ) { goto _loop47; } else {throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());}
			}
			
			_cnt47++;
		}
		_loop47:;
		}  // ( ... )+
		stream_AST = RefPNode(currentAST.root);
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		reportError(ex);
		recover(ex,_tokenSet_13);
	}
	returnAST = stream_AST;
}

void MyParser::logical_and_expression() {
	returnAST = RefPNode(ANTLR_USE_NAMESPACE(antlr)nullAST);
	ANTLR_USE_NAMESPACE(antlr)ASTPair currentAST;
	RefPNode logical_and_expression_AST = RefPNode(ANTLR_USE_NAMESPACE(antlr)nullAST);
	
	try {      // for error handling
		equality_expression();
		astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(returnAST));
		{ // ( ... )*
		for (;;) {
			if ((LA(1) == LAND)) {
				RefPNode tmp62_AST = RefPNode(ANTLR_USE_NAMESPACE(antlr)nullAST);
				tmp62_AST = astFactory->create(LT(1));
				astFactory->makeASTRoot(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(tmp62_AST));
				match(LAND);
				equality_expression();
				astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(returnAST));
			}
			else {
				goto _loop53;
			}
			
		}
		_loop53:;
		} // ( ... )*
		logical_and_expression_AST = RefPNode(currentAST.root);
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		reportError(ex);
		recover(ex,_tokenSet_19);
	}
	returnAST = logical_and_expression_AST;
}

void MyParser::equality_expression() {
	returnAST = RefPNode(ANTLR_USE_NAMESPACE(antlr)nullAST);
	ANTLR_USE_NAMESPACE(antlr)ASTPair currentAST;
	RefPNode equality_expression_AST = RefPNode(ANTLR_USE_NAMESPACE(antlr)nullAST);
	
	try {      // for error handling
		relational_expression();
		astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(returnAST));
		{ // ( ... )*
		for (;;) {
			if ((LA(1) == EQUAL || LA(1) == NOT_EQUAL)) {
				{
				switch ( LA(1)) {
				case EQUAL:
				{
					RefPNode tmp63_AST = RefPNode(ANTLR_USE_NAMESPACE(antlr)nullAST);
					tmp63_AST = astFactory->create(LT(1));
					astFactory->makeASTRoot(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(tmp63_AST));
					match(EQUAL);
					break;
				}
				case NOT_EQUAL:
				{
					RefPNode tmp64_AST = RefPNode(ANTLR_USE_NAMESPACE(antlr)nullAST);
					tmp64_AST = astFactory->create(LT(1));
					astFactory->makeASTRoot(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(tmp64_AST));
					match(NOT_EQUAL);
					break;
				}
				default:
				{
					throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
				}
				}
				}
				relational_expression();
				astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(returnAST));
			}
			else {
				goto _loop57;
			}
			
		}
		_loop57:;
		} // ( ... )*
		equality_expression_AST = RefPNode(currentAST.root);
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		reportError(ex);
		recover(ex,_tokenSet_20);
	}
	returnAST = equality_expression_AST;
}

void MyParser::relational_expression() {
	returnAST = RefPNode(ANTLR_USE_NAMESPACE(antlr)nullAST);
	ANTLR_USE_NAMESPACE(antlr)ASTPair currentAST;
	RefPNode relational_expression_AST = RefPNode(ANTLR_USE_NAMESPACE(antlr)nullAST);
	
	try {      // for error handling
		additive_expression();
		astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(returnAST));
		{ // ( ... )*
		for (;;) {
			if (((LA(1) >= LT_OP && LA(1) <= GTE))) {
				{
				switch ( LA(1)) {
				case LT_OP:
				{
					RefPNode tmp65_AST = RefPNode(ANTLR_USE_NAMESPACE(antlr)nullAST);
					tmp65_AST = astFactory->create(LT(1));
					astFactory->makeASTRoot(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(tmp65_AST));
					match(LT_OP);
					break;
				}
				case GT:
				{
					RefPNode tmp66_AST = RefPNode(ANTLR_USE_NAMESPACE(antlr)nullAST);
					tmp66_AST = astFactory->create(LT(1));
					astFactory->makeASTRoot(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(tmp66_AST));
					match(GT);
					break;
				}
				case LTE:
				{
					RefPNode tmp67_AST = RefPNode(ANTLR_USE_NAMESPACE(antlr)nullAST);
					tmp67_AST = astFactory->create(LT(1));
					astFactory->makeASTRoot(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(tmp67_AST));
					match(LTE);
					break;
				}
				case GTE:
				{
					RefPNode tmp68_AST = RefPNode(ANTLR_USE_NAMESPACE(antlr)nullAST);
					tmp68_AST = astFactory->create(LT(1));
					astFactory->makeASTRoot(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(tmp68_AST));
					match(GTE);
					break;
				}
				default:
				{
					throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
				}
				}
				}
				additive_expression();
				astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(returnAST));
			}
			else {
				goto _loop61;
			}
			
		}
		_loop61:;
		} // ( ... )*
		relational_expression_AST = RefPNode(currentAST.root);
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		reportError(ex);
		recover(ex,_tokenSet_21);
	}
	returnAST = relational_expression_AST;
}

void MyParser::additive_expression() {
	returnAST = RefPNode(ANTLR_USE_NAMESPACE(antlr)nullAST);
	ANTLR_USE_NAMESPACE(antlr)ASTPair currentAST;
	RefPNode additive_expression_AST = RefPNode(ANTLR_USE_NAMESPACE(antlr)nullAST);
	
	try {      // for error handling
		multiplicative_expression();
		astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(returnAST));
		{ // ( ... )*
		for (;;) {
			if ((LA(1) == PLUS || LA(1) == MINUS)) {
				{
				switch ( LA(1)) {
				case PLUS:
				{
					RefPNode tmp69_AST = RefPNode(ANTLR_USE_NAMESPACE(antlr)nullAST);
					tmp69_AST = astFactory->create(LT(1));
					astFactory->makeASTRoot(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(tmp69_AST));
					match(PLUS);
					break;
				}
				case MINUS:
				{
					RefPNode tmp70_AST = RefPNode(ANTLR_USE_NAMESPACE(antlr)nullAST);
					tmp70_AST = astFactory->create(LT(1));
					astFactory->makeASTRoot(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(tmp70_AST));
					match(MINUS);
					break;
				}
				default:
				{
					throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
				}
				}
				}
				multiplicative_expression();
				astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(returnAST));
			}
			else {
				goto _loop65;
			}
			
		}
		_loop65:;
		} // ( ... )*
		additive_expression_AST = RefPNode(currentAST.root);
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		reportError(ex);
		recover(ex,_tokenSet_22);
	}
	returnAST = additive_expression_AST;
}

void MyParser::multiplicative_expression() {
	returnAST = RefPNode(ANTLR_USE_NAMESPACE(antlr)nullAST);
	ANTLR_USE_NAMESPACE(antlr)ASTPair currentAST;
	RefPNode multiplicative_expression_AST = RefPNode(ANTLR_USE_NAMESPACE(antlr)nullAST);
	
	try {      // for error handling
		unary_expression();
		astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(returnAST));
		{ // ( ... )*
		for (;;) {
			if (((LA(1) >= STAR && LA(1) <= MOD))) {
				{
				switch ( LA(1)) {
				case STAR:
				{
					RefPNode tmp71_AST = RefPNode(ANTLR_USE_NAMESPACE(antlr)nullAST);
					tmp71_AST = astFactory->create(LT(1));
					astFactory->makeASTRoot(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(tmp71_AST));
					match(STAR);
					break;
				}
				case DIV:
				{
					RefPNode tmp72_AST = RefPNode(ANTLR_USE_NAMESPACE(antlr)nullAST);
					tmp72_AST = astFactory->create(LT(1));
					astFactory->makeASTRoot(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(tmp72_AST));
					match(DIV);
					break;
				}
				case MOD:
				{
					RefPNode tmp73_AST = RefPNode(ANTLR_USE_NAMESPACE(antlr)nullAST);
					tmp73_AST = astFactory->create(LT(1));
					astFactory->makeASTRoot(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(tmp73_AST));
					match(MOD);
					break;
				}
				default:
				{
					throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
				}
				}
				}
				unary_expression();
				astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(returnAST));
			}
			else {
				goto _loop69;
			}
			
		}
		_loop69:;
		} // ( ... )*
		multiplicative_expression_AST = RefPNode(currentAST.root);
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		reportError(ex);
		recover(ex,_tokenSet_23);
	}
	returnAST = multiplicative_expression_AST;
}

void MyParser::unary_expression() {
	returnAST = RefPNode(ANTLR_USE_NAMESPACE(antlr)nullAST);
	ANTLR_USE_NAMESPACE(antlr)ASTPair currentAST;
	RefPNode unary_expression_AST = RefPNode(ANTLR_USE_NAMESPACE(antlr)nullAST);
	RefPNode u_AST = RefPNode(ANTLR_USE_NAMESPACE(antlr)nullAST);
	
	try {      // for error handling
		{
		switch ( LA(1)) {
		case ID:
		case LPAREN:
		case STRING_LITERAL:
		case CHAR_LITERAL:
		case DOUBLE_CONST:
		case INT_CONST:
		case TRUE:
		case FALSE:
		{
			primary_expression();
			astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(returnAST));
			break;
		}
		case PLUS:
		case MINUS:
		case LNOT:
		{
			unary_operator();
			u_AST = returnAST;
			astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(returnAST));
			primary_expression();
			astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(returnAST));
			unary_expression_AST = RefPNode(currentAST.root);
#line 277 "grammer.g"
			unary_expression_AST = RefPNode(astFactory->make((new ANTLR_USE_NAMESPACE(antlr)ASTArray(2))->add(ANTLR_USE_NAMESPACE(antlr)RefAST(astFactory->create(NUnary,"NUnary")))->add(ANTLR_USE_NAMESPACE(antlr)RefAST(unary_expression_AST))));
#line 1629 "MyParser.cpp"
			currentAST.root = unary_expression_AST;
			if ( unary_expression_AST!=RefPNode(ANTLR_USE_NAMESPACE(antlr)nullAST) &&
				unary_expression_AST->getFirstChild() != RefPNode(ANTLR_USE_NAMESPACE(antlr)nullAST) )
				  currentAST.child = unary_expression_AST->getFirstChild();
			else
				currentAST.child = unary_expression_AST;
			currentAST.advanceChildToEnd();
			break;
		}
		default:
		{
			throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
		}
		}
		}
		unary_expression_AST = RefPNode(currentAST.root);
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		reportError(ex);
		recover(ex,_tokenSet_24);
	}
	returnAST = unary_expression_AST;
}

void MyParser::primary_expression() {
	returnAST = RefPNode(ANTLR_USE_NAMESPACE(antlr)nullAST);
	ANTLR_USE_NAMESPACE(antlr)ASTPair currentAST;
	RefPNode primary_expression_AST = RefPNode(ANTLR_USE_NAMESPACE(antlr)nullAST);
	
	try {      // for error handling
		{
		switch ( LA(1)) {
		case ID:
		{
			RefPNode tmp74_AST = RefPNode(ANTLR_USE_NAMESPACE(antlr)nullAST);
			tmp74_AST = astFactory->create(LT(1));
			astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(tmp74_AST));
			match(ID);
			{
			switch ( LA(1)) {
			case LBRACKET:
			{
				match(LBRACKET);
				expression();
				astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(returnAST));
				match(RBRACKET);
				primary_expression_AST = RefPNode(currentAST.root);
#line 291 "grammer.g"
					primary_expression_AST = RefPNode(astFactory->make((new ANTLR_USE_NAMESPACE(antlr)ASTArray(2))->add(ANTLR_USE_NAMESPACE(antlr)RefAST(astFactory->create(NListDeclaration,"NListDeclaration")))->add(ANTLR_USE_NAMESPACE(antlr)RefAST(primary_expression_AST))));
#line 1679 "MyParser.cpp"
				currentAST.root = primary_expression_AST;
				if ( primary_expression_AST!=RefPNode(ANTLR_USE_NAMESPACE(antlr)nullAST) &&
					primary_expression_AST->getFirstChild() != RefPNode(ANTLR_USE_NAMESPACE(antlr)nullAST) )
					  currentAST.child = primary_expression_AST->getFirstChild();
				else
					currentAST.child = primary_expression_AST;
				currentAST.advanceChildToEnd();
				break;
			}
			case ANTLR_USE_NAMESPACE(antlr)Token::EOF_TYPE:
			case RPAREN:
			case RCURLY:
			case SEMI:
			case COLON:
			case RBRACKET:
			case COMMA:
			case LSHIFT:
			case LOR:
			case LAND:
			case EQUAL:
			case NOT_EQUAL:
			case LT_OP:
			case GT:
			case LTE:
			case GTE:
			case PLUS:
			case MINUS:
			case STAR:
			case DIV:
			case MOD:
			{
				break;
			}
			default:
			{
				throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
			}
			}
			}
			break;
		}
		case STRING_LITERAL:
		{
			RefPNode tmp77_AST = RefPNode(ANTLR_USE_NAMESPACE(antlr)nullAST);
			tmp77_AST = astFactory->create(LT(1));
			astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(tmp77_AST));
			match(STRING_LITERAL);
			break;
		}
		case CHAR_LITERAL:
		{
			RefPNode tmp78_AST = RefPNode(ANTLR_USE_NAMESPACE(antlr)nullAST);
			tmp78_AST = astFactory->create(LT(1));
			astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(tmp78_AST));
			match(CHAR_LITERAL);
			break;
		}
		case DOUBLE_CONST:
		{
			RefPNode tmp79_AST = RefPNode(ANTLR_USE_NAMESPACE(antlr)nullAST);
			tmp79_AST = astFactory->create(LT(1));
			astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(tmp79_AST));
			match(DOUBLE_CONST);
			break;
		}
		case INT_CONST:
		{
			RefPNode tmp80_AST = RefPNode(ANTLR_USE_NAMESPACE(antlr)nullAST);
			tmp80_AST = astFactory->create(LT(1));
			astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(tmp80_AST));
			match(INT_CONST);
			break;
		}
		case LPAREN:
		{
			RefPNode tmp81_AST = RefPNode(ANTLR_USE_NAMESPACE(antlr)nullAST);
			tmp81_AST = astFactory->create(LT(1));
			astFactory->makeASTRoot(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(tmp81_AST));
			match(LPAREN);
			expression();
			astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(returnAST));
			match(RPAREN);
			break;
		}
		case TRUE:
		{
			RefPNode tmp83_AST = RefPNode(ANTLR_USE_NAMESPACE(antlr)nullAST);
			tmp83_AST = astFactory->create(LT(1));
			astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(tmp83_AST));
			match(TRUE);
			break;
		}
		case FALSE:
		{
			RefPNode tmp84_AST = RefPNode(ANTLR_USE_NAMESPACE(antlr)nullAST);
			tmp84_AST = astFactory->create(LT(1));
			astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(tmp84_AST));
			match(FALSE);
			break;
		}
		default:
		{
			throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
		}
		}
		}
		primary_expression_AST = RefPNode(currentAST.root);
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		reportError(ex);
		recover(ex,_tokenSet_24);
	}
	returnAST = primary_expression_AST;
}

void MyParser::unary_operator() {
	returnAST = RefPNode(ANTLR_USE_NAMESPACE(antlr)nullAST);
	ANTLR_USE_NAMESPACE(antlr)ASTPair currentAST;
	RefPNode unary_operator_AST = RefPNode(ANTLR_USE_NAMESPACE(antlr)nullAST);
	
	try {      // for error handling
		switch ( LA(1)) {
		case PLUS:
		{
			RefPNode tmp85_AST = RefPNode(ANTLR_USE_NAMESPACE(antlr)nullAST);
			tmp85_AST = astFactory->create(LT(1));
			astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(tmp85_AST));
			match(PLUS);
			unary_operator_AST = RefPNode(currentAST.root);
			break;
		}
		case MINUS:
		{
			RefPNode tmp86_AST = RefPNode(ANTLR_USE_NAMESPACE(antlr)nullAST);
			tmp86_AST = astFactory->create(LT(1));
			astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(tmp86_AST));
			match(MINUS);
			unary_operator_AST = RefPNode(currentAST.root);
			break;
		}
		case LNOT:
		{
			RefPNode tmp87_AST = RefPNode(ANTLR_USE_NAMESPACE(antlr)nullAST);
			tmp87_AST = astFactory->create(LT(1));
			astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(tmp87_AST));
			match(LNOT);
			unary_operator_AST = RefPNode(currentAST.root);
			break;
		}
		default:
		{
			throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
		}
		}
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		reportError(ex);
		recover(ex,_tokenSet_25);
	}
	returnAST = unary_operator_AST;
}

void MyParser::declaration() {
	returnAST = RefPNode(ANTLR_USE_NAMESPACE(antlr)nullAST);
	ANTLR_USE_NAMESPACE(antlr)ASTPair currentAST;
	RefPNode declaration_AST = RefPNode(ANTLR_USE_NAMESPACE(antlr)nullAST);
	RefPNode t_AST = RefPNode(ANTLR_USE_NAMESPACE(antlr)nullAST);
#line 308 "grammer.g"
	/* RefAST d1; */
				RefPNode d1;
			
#line 1851 "MyParser.cpp"
	
	try {      // for error handling
		type_specifier();
		t_AST = returnAST;
		astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(returnAST));
		declarator_list();
		astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(returnAST));
		{
		switch ( LA(1)) {
		case ASSIGN:
		{
			match(ASSIGN);
			initializer_list();
			astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(returnAST));
			break;
		}
		case SEMI:
		{
			break;
		}
		default:
		{
			throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
		}
		}
		}
		match(SEMI);
		declaration_AST = RefPNode(currentAST.root);
#line 313 "grammer.g"
		
				
				d1 = PNodeFactory.dup(t_AST);
				int i;
				i = d1->getType();
		
				if (i==ID){
					declaration_AST = RefPNode(astFactory->make((new ANTLR_USE_NAMESPACE(antlr)ASTArray(2))->add(ANTLR_USE_NAMESPACE(antlr)RefAST(astFactory->create(NExterntype,"NExterntype")))->add(ANTLR_USE_NAMESPACE(antlr)RefAST(declaration_AST))));		
				}
				else{
					declaration_AST = RefPNode(astFactory->make((new ANTLR_USE_NAMESPACE(antlr)ASTArray(2))->add(ANTLR_USE_NAMESPACE(antlr)RefAST(astFactory->create(NDeclaration,"NDeclaration")))->add(ANTLR_USE_NAMESPACE(antlr)RefAST(declaration_AST))));
				}
			
				
#line 1895 "MyParser.cpp"
		currentAST.root = declaration_AST;
		if ( declaration_AST!=RefPNode(ANTLR_USE_NAMESPACE(antlr)nullAST) &&
			declaration_AST->getFirstChild() != RefPNode(ANTLR_USE_NAMESPACE(antlr)nullAST) )
			  currentAST.child = declaration_AST->getFirstChild();
		else
			currentAST.child = declaration_AST;
		currentAST.advanceChildToEnd();
		declaration_AST = RefPNode(currentAST.root);
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		reportError(ex);
		recover(ex,_tokenSet_26);
	}
	returnAST = declaration_AST;
}

void MyParser::declarator_list() {
	returnAST = RefPNode(ANTLR_USE_NAMESPACE(antlr)nullAST);
	ANTLR_USE_NAMESPACE(antlr)ASTPair currentAST;
	RefPNode declarator_list_AST = RefPNode(ANTLR_USE_NAMESPACE(antlr)nullAST);
	
	try {      // for error handling
		declarator();
		astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(returnAST));
		{ // ( ... )*
		for (;;) {
			if ((LA(1) == COMMA)) {
				match(COMMA);
				declarator();
				astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(returnAST));
			}
			else {
				goto _loop83;
			}
			
		}
		_loop83:;
		} // ( ... )*
		declarator_list_AST = RefPNode(currentAST.root);
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		reportError(ex);
		recover(ex,_tokenSet_27);
	}
	returnAST = declarator_list_AST;
}

void MyParser::initializer_list() {
	returnAST = RefPNode(ANTLR_USE_NAMESPACE(antlr)nullAST);
	ANTLR_USE_NAMESPACE(antlr)ASTPair currentAST;
	RefPNode initializer_list_AST = RefPNode(ANTLR_USE_NAMESPACE(antlr)nullAST);
	
	try {      // for error handling
		{
		switch ( LA(1)) {
		case ID:
		case LPAREN:
		case PLUS:
		case MINUS:
		case LNOT:
		case STRING_LITERAL:
		case CHAR_LITERAL:
		case DOUBLE_CONST:
		case INT_CONST:
		case TRUE:
		case FALSE:
		{
			expression();
			astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(returnAST));
			break;
		}
		case LCURLY:
		{
			match(LCURLY);
			{
			expression();
			astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(returnAST));
			{ // ( ... )*
			for (;;) {
				if ((LA(1) == COMMA)) {
					match(COMMA);
					expression();
					astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(returnAST));
				}
				else {
					goto _loop90;
				}
				
			}
			_loop90:;
			} // ( ... )*
			}
			match(RCURLY);
			break;
		}
		default:
		{
			throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
		}
		}
		}
		initializer_list_AST = RefPNode(currentAST.root);
#line 347 "grammer.g"
		initializer_list_AST = RefPNode(astFactory->make((new ANTLR_USE_NAMESPACE(antlr)ASTArray(2))->add(ANTLR_USE_NAMESPACE(antlr)RefAST(astFactory->create(NInitializer,"NInitializer")))->add(ANTLR_USE_NAMESPACE(antlr)RefAST(initializer_list_AST))));
#line 2000 "MyParser.cpp"
		currentAST.root = initializer_list_AST;
		if ( initializer_list_AST!=RefPNode(ANTLR_USE_NAMESPACE(antlr)nullAST) &&
			initializer_list_AST->getFirstChild() != RefPNode(ANTLR_USE_NAMESPACE(antlr)nullAST) )
			  currentAST.child = initializer_list_AST->getFirstChild();
		else
			currentAST.child = initializer_list_AST;
		currentAST.advanceChildToEnd();
		initializer_list_AST = RefPNode(currentAST.root);
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		reportError(ex);
		recover(ex,_tokenSet_13);
	}
	returnAST = initializer_list_AST;
}

void MyParser::imaginary_token() {
	returnAST = RefPNode(ANTLR_USE_NAMESPACE(antlr)nullAST);
	ANTLR_USE_NAMESPACE(antlr)ASTPair currentAST;
	RefPNode imaginary_token_AST = RefPNode(ANTLR_USE_NAMESPACE(antlr)nullAST);
	
	try {      // for error handling
		switch ( LA(1)) {
		case NRootAST:
		{
			RefPNode tmp94_AST = RefPNode(ANTLR_USE_NAMESPACE(antlr)nullAST);
			tmp94_AST = astFactory->create(LT(1));
			astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(tmp94_AST));
			match(NRootAST);
			imaginary_token_AST = RefPNode(currentAST.root);
			break;
		}
		case NDeclaration:
		{
			RefPNode tmp95_AST = RefPNode(ANTLR_USE_NAMESPACE(antlr)nullAST);
			tmp95_AST = astFactory->create(LT(1));
			astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(tmp95_AST));
			match(NDeclaration);
			imaginary_token_AST = RefPNode(currentAST.root);
			break;
		}
		case NUnionDeclaration:
		{
			RefPNode tmp96_AST = RefPNode(ANTLR_USE_NAMESPACE(antlr)nullAST);
			tmp96_AST = astFactory->create(LT(1));
			astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(tmp96_AST));
			match(NUnionDeclaration);
			imaginary_token_AST = RefPNode(currentAST.root);
			break;
		}
		case NUnary:
		{
			RefPNode tmp97_AST = RefPNode(ANTLR_USE_NAMESPACE(antlr)nullAST);
			tmp97_AST = astFactory->create(LT(1));
			astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(tmp97_AST));
			match(NUnary);
			imaginary_token_AST = RefPNode(currentAST.root);
			break;
		}
		case NEmptyStatement:
		{
			RefPNode tmp98_AST = RefPNode(ANTLR_USE_NAMESPACE(antlr)nullAST);
			tmp98_AST = astFactory->create(LT(1));
			astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(tmp98_AST));
			match(NEmptyStatement);
			imaginary_token_AST = RefPNode(currentAST.root);
			break;
		}
		case NInitializer:
		{
			RefPNode tmp99_AST = RefPNode(ANTLR_USE_NAMESPACE(antlr)nullAST);
			tmp99_AST = astFactory->create(LT(1));
			astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(tmp99_AST));
			match(NInitializer);
			imaginary_token_AST = RefPNode(currentAST.root);
			break;
		}
		case NExterntype:
		{
			RefPNode tmp100_AST = RefPNode(ANTLR_USE_NAMESPACE(antlr)nullAST);
			tmp100_AST = astFactory->create(LT(1));
			astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(tmp100_AST));
			match(NExterntype);
			imaginary_token_AST = RefPNode(currentAST.root);
			break;
		}
		case NCondition:
		{
			RefPNode tmp101_AST = RefPNode(ANTLR_USE_NAMESPACE(antlr)nullAST);
			tmp101_AST = astFactory->create(LT(1));
			astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(tmp101_AST));
			match(NCondition);
			imaginary_token_AST = RefPNode(currentAST.root);
			break;
		}
		case NCodeBlock:
		{
			RefPNode tmp102_AST = RefPNode(ANTLR_USE_NAMESPACE(antlr)nullAST);
			tmp102_AST = astFactory->create(LT(1));
			astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(tmp102_AST));
			match(NCodeBlock);
			imaginary_token_AST = RefPNode(currentAST.root);
			break;
		}
		case NIfThenBlock:
		{
			RefPNode tmp103_AST = RefPNode(ANTLR_USE_NAMESPACE(antlr)nullAST);
			tmp103_AST = astFactory->create(LT(1));
			astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(tmp103_AST));
			match(NIfThenBlock);
			imaginary_token_AST = RefPNode(currentAST.root);
			break;
		}
		case NIfBlock:
		{
			RefPNode tmp104_AST = RefPNode(ANTLR_USE_NAMESPACE(antlr)nullAST);
			tmp104_AST = astFactory->create(LT(1));
			astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(tmp104_AST));
			match(NIfBlock);
			imaginary_token_AST = RefPNode(currentAST.root);
			break;
		}
		case NElseBlock:
		{
			RefPNode tmp105_AST = RefPNode(ANTLR_USE_NAMESPACE(antlr)nullAST);
			tmp105_AST = astFactory->create(LT(1));
			astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(tmp105_AST));
			match(NElseBlock);
			imaginary_token_AST = RefPNode(currentAST.root);
			break;
		}
		case NForBlock:
		{
			RefPNode tmp106_AST = RefPNode(ANTLR_USE_NAMESPACE(antlr)nullAST);
			tmp106_AST = astFactory->create(LT(1));
			astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(tmp106_AST));
			match(NForBlock);
			imaginary_token_AST = RefPNode(currentAST.root);
			break;
		}
		case NCaseStatement:
		{
			RefPNode tmp107_AST = RefPNode(ANTLR_USE_NAMESPACE(antlr)nullAST);
			tmp107_AST = astFactory->create(LT(1));
			astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(tmp107_AST));
			match(NCaseStatement);
			imaginary_token_AST = RefPNode(currentAST.root);
			break;
		}
		case NDefaultStatement:
		{
			RefPNode tmp108_AST = RefPNode(ANTLR_USE_NAMESPACE(antlr)nullAST);
			tmp108_AST = astFactory->create(LT(1));
			astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(tmp108_AST));
			match(NDefaultStatement);
			imaginary_token_AST = RefPNode(currentAST.root);
			break;
		}
		case NSwitchBlock:
		{
			RefPNode tmp109_AST = RefPNode(ANTLR_USE_NAMESPACE(antlr)nullAST);
			tmp109_AST = astFactory->create(LT(1));
			astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(tmp109_AST));
			match(NSwitchBlock);
			imaginary_token_AST = RefPNode(currentAST.root);
			break;
		}
		case NCaseCondition:
		{
			RefPNode tmp110_AST = RefPNode(ANTLR_USE_NAMESPACE(antlr)nullAST);
			tmp110_AST = astFactory->create(LT(1));
			astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(tmp110_AST));
			match(NCaseCondition);
			imaginary_token_AST = RefPNode(currentAST.root);
			break;
		}
		case NForDeclaration:
		{
			RefPNode tmp111_AST = RefPNode(ANTLR_USE_NAMESPACE(antlr)nullAST);
			tmp111_AST = astFactory->create(LT(1));
			astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(tmp111_AST));
			match(NForDeclaration);
			imaginary_token_AST = RefPNode(currentAST.root);
			break;
		}
		case NDeclareList:
		{
			RefPNode tmp112_AST = RefPNode(ANTLR_USE_NAMESPACE(antlr)nullAST);
			tmp112_AST = astFactory->create(LT(1));
			astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(tmp112_AST));
			match(NDeclareList);
			imaginary_token_AST = RefPNode(currentAST.root);
			break;
		}
		case NListDeclaration:
		{
			RefPNode tmp113_AST = RefPNode(ANTLR_USE_NAMESPACE(antlr)nullAST);
			tmp113_AST = astFactory->create(LT(1));
			astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(tmp113_AST));
			match(NListDeclaration);
			imaginary_token_AST = RefPNode(currentAST.root);
			break;
		}
		case NAssignList:
		{
			RefPNode tmp114_AST = RefPNode(ANTLR_USE_NAMESPACE(antlr)nullAST);
			tmp114_AST = astFactory->create(LT(1));
			astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(tmp114_AST));
			match(NAssignList);
			imaginary_token_AST = RefPNode(currentAST.root);
			break;
		}
		case NStartCondition:
		{
			RefPNode tmp115_AST = RefPNode(ANTLR_USE_NAMESPACE(antlr)nullAST);
			tmp115_AST = astFactory->create(LT(1));
			astFactory->addASTChild(currentAST, ANTLR_USE_NAMESPACE(antlr)RefAST(tmp115_AST));
			match(NStartCondition);
			imaginary_token_AST = RefPNode(currentAST.root);
			break;
		}
		default:
		{
			throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
		}
		}
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		reportError(ex);
		recover(ex,_tokenSet_0);
	}
	returnAST = imaginary_token_AST;
}

void MyParser::initializeASTFactory( ANTLR_USE_NAMESPACE(antlr)ASTFactory& factory )
{
	factory.setMaxNodeType(86);
}
const char* MyParser::tokenNames[] = {
	"<0>",
	"EOF",
	"<2>",
	"NULL_TREE_LOOKAHEAD",
	"an identifier",
	"\'(\'",
	"\')\'",
	"\'{\'",
	"\'}\'",
	"\';\'",
	"\"switch\"",
	"\"case\"",
	"\':\'",
	"\"default\"",
	"\"if\"",
	"\"else\"",
	"\"while\"",
	"\"do\"",
	"\"for\"",
	"ASSIGN",
	"INC_OP",
	"DEC_OP",
	"\'[\'",
	"\']\'",
	"ADD_ASSIGN",
	"SUB_ASSIGN",
	"DIV_ASSIGN",
	"STAR_ASSIGN",
	"MOD_ASSIGN",
	"COMMA",
	"\"cout\"",
	"\'<<\'",
	"\"endl\"",
	"LOR",
	"LAND",
	"EQUAL",
	"NOT_EQUAL",
	"LT_OP",
	"GT",
	"LTE",
	"GTE",
	"PLUS",
	"MINUS",
	"STAR",
	"DIV",
	"MOD",
	"LNOT",
	"STRING_LITERAL",
	"CHAR_LITERAL",
	"DOUBLE_CONST",
	"INT_CONST",
	"\"true\"",
	"\"false\"",
	"\"char\"",
	"\"int\"",
	"\"bool\"",
	"\"double\"",
	"\"string\"",
	"NRootAST",
	"NDeclaration",
	"NUnionDeclaration",
	"NUnary",
	"NEmptyStatement",
	"NInitializer",
	"NExterntype",
	"NCondition",
	"NCodeBlock",
	"NIfThenBlock",
	"NIfBlock",
	"NElseBlock",
	"NForBlock",
	"NCaseStatement",
	"NDefaultStatement",
	"NSwitchBlock",
	"NCaseCondition",
	"NForDeclaration",
	"NDeclareList",
	"NListDeclaration",
	"NAssignList",
	"NStartCondition",
	"Whitespace",
	"Cpp_Comment",
	"Comment",
	"DOT",
	"Escape",
	"DIGIT",
	"a number",
	0
};

const unsigned long MyParser::_tokenSet_0_data_[] = { 2UL, 0UL, 0UL, 0UL };
// EOF 
const ANTLR_USE_NAMESPACE(antlr)BitSet MyParser::_tokenSet_0(_tokenSet_0_data_,4);
const unsigned long MyParser::_tokenSet_1_data_[] = { 16UL, 65011712UL, 0UL, 0UL };
// ID "char" "int" "bool" "double" "string" 
const ANTLR_USE_NAMESPACE(antlr)BitSet MyParser::_tokenSet_1(_tokenSet_1_data_,4);
const unsigned long MyParser::_tokenSet_2_data_[] = { 1074218896UL, 0UL, 0UL, 0UL };
// ID LCURLY RCURLY SEMI "switch" "if" "while" "do" "for" "cout" 
const ANTLR_USE_NAMESPACE(antlr)BitSet MyParser::_tokenSet_2(_tokenSet_2_data_,4);
const unsigned long MyParser::_tokenSet_3_data_[] = { 1074218640UL, 0UL, 0UL, 0UL };
// ID LCURLY SEMI "switch" "if" "while" "do" "for" "cout" 
const ANTLR_USE_NAMESPACE(antlr)BitSet MyParser::_tokenSet_3(_tokenSet_3_data_,4);
const unsigned long MyParser::_tokenSet_4_data_[] = { 3749660592UL, 65011712UL, 0UL, 0UL };
// ID LPAREN LCURLY RCURLY SEMI "switch" "if" "while" "do" "for" ASSIGN 
// INC_OP DEC_OP LBRACKET ADD_ASSIGN SUB_ASSIGN DIV_ASSIGN STAR_ASSIGN 
// MOD_ASSIGN "cout" LSHIFT "char" "int" "bool" "double" "string" 
const ANTLR_USE_NAMESPACE(antlr)BitSet MyParser::_tokenSet_4(_tokenSet_4_data_,4);
const unsigned long MyParser::_tokenSet_5_data_[] = { 1074261906UL, 0UL, 0UL, 0UL };
// EOF ID LCURLY RCURLY SEMI "switch" "case" "default" "if" "else" "while" 
// "do" "for" "cout" 
const ANTLR_USE_NAMESPACE(antlr)BitSet MyParser::_tokenSet_5(_tokenSet_5_data_,4);
const unsigned long MyParser::_tokenSet_6_data_[] = { 1074261904UL, 0UL, 0UL, 0UL };
// ID LCURLY RCURLY SEMI "switch" "case" "default" "if" "else" "while" 
// "do" "for" "cout" 
const ANTLR_USE_NAMESPACE(antlr)BitSet MyParser::_tokenSet_6(_tokenSet_6_data_,4);
const unsigned long MyParser::_tokenSet_7_data_[] = { 256UL, 0UL, 0UL, 0UL };
// RCURLY 
const ANTLR_USE_NAMESPACE(antlr)BitSet MyParser::_tokenSet_7(_tokenSet_7_data_,4);
const unsigned long MyParser::_tokenSet_8_data_[] = { 3749707698UL, 67094016UL, 0UL, 0UL };
// EOF ID LPAREN LCURLY RCURLY SEMI "switch" "case" COLON "default" "if" 
// "else" "while" "do" "for" ASSIGN INC_OP DEC_OP LBRACKET ADD_ASSIGN SUB_ASSIGN 
// DIV_ASSIGN STAR_ASSIGN MOD_ASSIGN "cout" LSHIFT PLUS MINUS LNOT STRING_LITERAL 
// CHAR_LITERAL DOUBLE_CONST INT_CONST "true" "false" "char" "int" "bool" 
// "double" "string" 
const ANTLR_USE_NAMESPACE(antlr)BitSet MyParser::_tokenSet_8(_tokenSet_8_data_,4);
const unsigned long MyParser::_tokenSet_9_data_[] = { 2692748098UL, 0UL, 0UL, 0UL };
// EOF RPAREN RCURLY SEMI COLON RBRACKET COMMA LSHIFT 
const ANTLR_USE_NAMESPACE(antlr)BitSet MyParser::_tokenSet_9(_tokenSet_9_data_,4);
const unsigned long MyParser::_tokenSet_10_data_[] = { 10496UL, 0UL, 0UL, 0UL };
// RCURLY "case" "default" 
const ANTLR_USE_NAMESPACE(antlr)BitSet MyParser::_tokenSet_10(_tokenSet_10_data_,4);
const unsigned long MyParser::_tokenSet_11_data_[] = { 4672UL, 0UL, 0UL, 0UL };
// RPAREN SEMI COLON 
const ANTLR_USE_NAMESPACE(antlr)BitSet MyParser::_tokenSet_11(_tokenSet_11_data_,4);
const unsigned long MyParser::_tokenSet_12_data_[] = { 527958016UL, 0UL, 0UL, 0UL };
// ASSIGN INC_OP DEC_OP LBRACKET ADD_ASSIGN SUB_ASSIGN DIV_ASSIGN STAR_ASSIGN 
// MOD_ASSIGN 
const ANTLR_USE_NAMESPACE(antlr)BitSet MyParser::_tokenSet_12(_tokenSet_12_data_,4);
const unsigned long MyParser::_tokenSet_13_data_[] = { 512UL, 0UL, 0UL, 0UL };
// SEMI 
const ANTLR_USE_NAMESPACE(antlr)BitSet MyParser::_tokenSet_13(_tokenSet_13_data_,4);
const unsigned long MyParser::_tokenSet_14_data_[] = { 576UL, 0UL, 0UL, 0UL };
// RPAREN SEMI 
const ANTLR_USE_NAMESPACE(antlr)BitSet MyParser::_tokenSet_14(_tokenSet_14_data_,4);
const unsigned long MyParser::_tokenSet_15_data_[] = { 16UL, 0UL, 0UL, 0UL };
// ID 
const ANTLR_USE_NAMESPACE(antlr)BitSet MyParser::_tokenSet_15(_tokenSet_15_data_,4);
const unsigned long MyParser::_tokenSet_16_data_[] = { 537395712UL, 0UL, 0UL, 0UL };
// SEMI ASSIGN COMMA 
const ANTLR_USE_NAMESPACE(antlr)BitSet MyParser::_tokenSet_16(_tokenSet_16_data_,4);
const unsigned long MyParser::_tokenSet_17_data_[] = { 523763712UL, 0UL, 0UL, 0UL };
// ASSIGN INC_OP DEC_OP ADD_ASSIGN SUB_ASSIGN DIV_ASSIGN STAR_ASSIGN MOD_ASSIGN 
const ANTLR_USE_NAMESPACE(antlr)BitSet MyParser::_tokenSet_17(_tokenSet_17_data_,4);
const unsigned long MyParser::_tokenSet_18_data_[] = { 48UL, 2082304UL, 0UL, 0UL };
// ID LPAREN PLUS MINUS LNOT STRING_LITERAL CHAR_LITERAL DOUBLE_CONST INT_CONST 
// "true" "false" 
const ANTLR_USE_NAMESPACE(antlr)BitSet MyParser::_tokenSet_18(_tokenSet_18_data_,4);
const unsigned long MyParser::_tokenSet_19_data_[] = { 2692748098UL, 2UL, 0UL, 0UL };
// EOF RPAREN RCURLY SEMI COLON RBRACKET COMMA LSHIFT LOR 
const ANTLR_USE_NAMESPACE(antlr)BitSet MyParser::_tokenSet_19(_tokenSet_19_data_,4);
const unsigned long MyParser::_tokenSet_20_data_[] = { 2692748098UL, 6UL, 0UL, 0UL };
// EOF RPAREN RCURLY SEMI COLON RBRACKET COMMA LSHIFT LOR LAND 
const ANTLR_USE_NAMESPACE(antlr)BitSet MyParser::_tokenSet_20(_tokenSet_20_data_,4);
const unsigned long MyParser::_tokenSet_21_data_[] = { 2692748098UL, 30UL, 0UL, 0UL };
// EOF RPAREN RCURLY SEMI COLON RBRACKET COMMA LSHIFT LOR LAND EQUAL NOT_EQUAL 
const ANTLR_USE_NAMESPACE(antlr)BitSet MyParser::_tokenSet_21(_tokenSet_21_data_,4);
const unsigned long MyParser::_tokenSet_22_data_[] = { 2692748098UL, 510UL, 0UL, 0UL };
// EOF RPAREN RCURLY SEMI COLON RBRACKET COMMA LSHIFT LOR LAND EQUAL NOT_EQUAL 
// LT_OP GT LTE GTE 
const ANTLR_USE_NAMESPACE(antlr)BitSet MyParser::_tokenSet_22(_tokenSet_22_data_,4);
const unsigned long MyParser::_tokenSet_23_data_[] = { 2692748098UL, 2046UL, 0UL, 0UL };
// EOF RPAREN RCURLY SEMI COLON RBRACKET COMMA LSHIFT LOR LAND EQUAL NOT_EQUAL 
// LT_OP GT LTE GTE PLUS MINUS 
const ANTLR_USE_NAMESPACE(antlr)BitSet MyParser::_tokenSet_23(_tokenSet_23_data_,4);
const unsigned long MyParser::_tokenSet_24_data_[] = { 2692748098UL, 16382UL, 0UL, 0UL };
// EOF RPAREN RCURLY SEMI COLON RBRACKET COMMA LSHIFT LOR LAND EQUAL NOT_EQUAL 
// LT_OP GT LTE GTE PLUS MINUS STAR DIV MOD 
const ANTLR_USE_NAMESPACE(antlr)BitSet MyParser::_tokenSet_24(_tokenSet_24_data_,4);
const unsigned long MyParser::_tokenSet_25_data_[] = { 48UL, 2064384UL, 0UL, 0UL };
// ID LPAREN STRING_LITERAL CHAR_LITERAL DOUBLE_CONST INT_CONST "true" 
// "false" 
const ANTLR_USE_NAMESPACE(antlr)BitSet MyParser::_tokenSet_25(_tokenSet_25_data_,4);
const unsigned long MyParser::_tokenSet_26_data_[] = { 1074218896UL, 65011712UL, 0UL, 0UL };
// ID LCURLY RCURLY SEMI "switch" "if" "while" "do" "for" "cout" "char" 
// "int" "bool" "double" "string" 
const ANTLR_USE_NAMESPACE(antlr)BitSet MyParser::_tokenSet_26(_tokenSet_26_data_,4);
const unsigned long MyParser::_tokenSet_27_data_[] = { 524800UL, 0UL, 0UL, 0UL };
// SEMI ASSIGN 
const ANTLR_USE_NAMESPACE(antlr)BitSet MyParser::_tokenSet_27(_tokenSet_27_data_,4);


