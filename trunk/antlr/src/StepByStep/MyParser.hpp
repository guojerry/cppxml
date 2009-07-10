#ifndef INC_MyParser_hpp_
#define INC_MyParser_hpp_

#include <antlr/config.hpp>
/* $ANTLR 2.7.7 (20060906): "grammer.g" -> "MyParser.hpp"$ */
#include <antlr/TokenStream.hpp>
#include <antlr/TokenBuffer.hpp>
#include "ssci_TokenTypes.hpp"
#include <antlr/LLkParser.hpp>

#line 1 "grammer.g"


#include <iostream>
#include "PNode.hpp"
#include "PNodeFactory.hpp"

#pragma warning(disable:4101)

ANTLR_USING_NAMESPACE(std)
ANTLR_USING_NAMESPACE(antlr)


#line 25 "MyParser.hpp"
class CUSTOM_API MyParser : public ANTLR_USE_NAMESPACE(antlr)LLkParser, public ssci_TokenTypes
{
#line 1 "grammer.g"
#line 29 "MyParser.hpp"
public:
	void initializeASTFactory( ANTLR_USE_NAMESPACE(antlr)ASTFactory& factory );
protected:
	MyParser(ANTLR_USE_NAMESPACE(antlr)TokenBuffer& tokenBuf, int k);
public:
	MyParser(ANTLR_USE_NAMESPACE(antlr)TokenBuffer& tokenBuf);
protected:
	MyParser(ANTLR_USE_NAMESPACE(antlr)TokenStream& lexer, int k);
public:
	MyParser(ANTLR_USE_NAMESPACE(antlr)TokenStream& lexer);
	MyParser(const ANTLR_USE_NAMESPACE(antlr)ParserSharedInputState& state);
	int getNumTokens() const
	{
		return MyParser::NUM_TOKENS;
	}
	const char* getTokenName( int type ) const
	{
		if( type > getNumTokens() ) return 0;
		return MyParser::tokenNames[type];
	}
	const char* const* getTokenNames() const
	{
		return MyParser::tokenNames;
	}
	public: void interpretation_unit();
	public: void start_condition();
	public: void declaration_list();
	public: void compound_statement();
	public: void statement();
	public: void assign_statement();
	public: void selection_statement();
	public: void iteration_statement();
	public: void stream_statement();
	public: void statement_list();
	public: void switchBlock();
	public: void ifThenBlock();
	public: void expression();
	public: void case_statement();
	public: void default_statement();
	public: void condition();
	public: void codeBlock();
	public: void ifBlock();
	public: void elseBlock();
	public: void for_loop();
	public: void for_expression();
	public: void loop_cntrl();
	public: void assign_expression();
	public: void for_declaration();
	public: void type_specifier();
	public: void declarator();
	public: void forBlock();
	public: void assign_ID();
	public: void assignment_operator();
	public: void argument_expression_list();
	public: void stream();
	public: void logical_and_expression();
	public: void equality_expression();
	public: void relational_expression();
	public: void additive_expression();
	public: void multiplicative_expression();
	public: void unary_expression();
	public: void primary_expression();
	public: void unary_operator();
	public: void declaration();
	public: void declarator_list();
	public: void initializer_list();
	public: void imaginary_token();
public:
	ANTLR_USE_NAMESPACE(antlr)RefAST getAST()
	{
		return ANTLR_USE_NAMESPACE(antlr)RefAST(returnAST);
	}
	
protected:
	RefPNode returnAST;
private:
	static const char* tokenNames[];
#ifndef NO_STATIC_CONSTS
	static const int NUM_TOKENS = 87;
#else
	enum {
		NUM_TOKENS = 87
	};
#endif
	
	static const unsigned long _tokenSet_0_data_[];
	static const ANTLR_USE_NAMESPACE(antlr)BitSet _tokenSet_0;
	static const unsigned long _tokenSet_1_data_[];
	static const ANTLR_USE_NAMESPACE(antlr)BitSet _tokenSet_1;
	static const unsigned long _tokenSet_2_data_[];
	static const ANTLR_USE_NAMESPACE(antlr)BitSet _tokenSet_2;
	static const unsigned long _tokenSet_3_data_[];
	static const ANTLR_USE_NAMESPACE(antlr)BitSet _tokenSet_3;
	static const unsigned long _tokenSet_4_data_[];
	static const ANTLR_USE_NAMESPACE(antlr)BitSet _tokenSet_4;
	static const unsigned long _tokenSet_5_data_[];
	static const ANTLR_USE_NAMESPACE(antlr)BitSet _tokenSet_5;
	static const unsigned long _tokenSet_6_data_[];
	static const ANTLR_USE_NAMESPACE(antlr)BitSet _tokenSet_6;
	static const unsigned long _tokenSet_7_data_[];
	static const ANTLR_USE_NAMESPACE(antlr)BitSet _tokenSet_7;
	static const unsigned long _tokenSet_8_data_[];
	static const ANTLR_USE_NAMESPACE(antlr)BitSet _tokenSet_8;
	static const unsigned long _tokenSet_9_data_[];
	static const ANTLR_USE_NAMESPACE(antlr)BitSet _tokenSet_9;
	static const unsigned long _tokenSet_10_data_[];
	static const ANTLR_USE_NAMESPACE(antlr)BitSet _tokenSet_10;
	static const unsigned long _tokenSet_11_data_[];
	static const ANTLR_USE_NAMESPACE(antlr)BitSet _tokenSet_11;
	static const unsigned long _tokenSet_12_data_[];
	static const ANTLR_USE_NAMESPACE(antlr)BitSet _tokenSet_12;
	static const unsigned long _tokenSet_13_data_[];
	static const ANTLR_USE_NAMESPACE(antlr)BitSet _tokenSet_13;
	static const unsigned long _tokenSet_14_data_[];
	static const ANTLR_USE_NAMESPACE(antlr)BitSet _tokenSet_14;
	static const unsigned long _tokenSet_15_data_[];
	static const ANTLR_USE_NAMESPACE(antlr)BitSet _tokenSet_15;
	static const unsigned long _tokenSet_16_data_[];
	static const ANTLR_USE_NAMESPACE(antlr)BitSet _tokenSet_16;
	static const unsigned long _tokenSet_17_data_[];
	static const ANTLR_USE_NAMESPACE(antlr)BitSet _tokenSet_17;
	static const unsigned long _tokenSet_18_data_[];
	static const ANTLR_USE_NAMESPACE(antlr)BitSet _tokenSet_18;
	static const unsigned long _tokenSet_19_data_[];
	static const ANTLR_USE_NAMESPACE(antlr)BitSet _tokenSet_19;
	static const unsigned long _tokenSet_20_data_[];
	static const ANTLR_USE_NAMESPACE(antlr)BitSet _tokenSet_20;
	static const unsigned long _tokenSet_21_data_[];
	static const ANTLR_USE_NAMESPACE(antlr)BitSet _tokenSet_21;
	static const unsigned long _tokenSet_22_data_[];
	static const ANTLR_USE_NAMESPACE(antlr)BitSet _tokenSet_22;
	static const unsigned long _tokenSet_23_data_[];
	static const ANTLR_USE_NAMESPACE(antlr)BitSet _tokenSet_23;
	static const unsigned long _tokenSet_24_data_[];
	static const ANTLR_USE_NAMESPACE(antlr)BitSet _tokenSet_24;
	static const unsigned long _tokenSet_25_data_[];
	static const ANTLR_USE_NAMESPACE(antlr)BitSet _tokenSet_25;
	static const unsigned long _tokenSet_26_data_[];
	static const ANTLR_USE_NAMESPACE(antlr)BitSet _tokenSet_26;
	static const unsigned long _tokenSet_27_data_[];
	static const ANTLR_USE_NAMESPACE(antlr)BitSet _tokenSet_27;
};

#endif /*INC_MyParser_hpp_*/
