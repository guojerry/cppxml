#ifndef INC_MyLexer_hpp_
#define INC_MyLexer_hpp_

#include <antlr/config.hpp>
/* $ANTLR 2.7.7 (20060906): "grammer.g" -> "MyLexer.hpp"$ */
#include <antlr/CommonToken.hpp>
#include <antlr/InputBuffer.hpp>
#include <antlr/BitSet.hpp>
#include "ssci_TokenTypes.hpp"
#include <antlr/CharScanner.hpp>
#line 1 "grammer.g"


#include <iostream>
#include "PNode.hpp"
#include "PNodeFactory.hpp"

#pragma warning(disable:4101)

ANTLR_USING_NAMESPACE(std)
ANTLR_USING_NAMESPACE(antlr)


#line 25 "MyLexer.hpp"
class CUSTOM_API MyLexer : public ANTLR_USE_NAMESPACE(antlr)CharScanner, public ssci_TokenTypes
{
#line 1 "grammer.g"
#line 29 "MyLexer.hpp"
private:
	void initLiterals();
public:
	bool getCaseSensitiveLiterals() const
	{
		return true;
	}
public:
	MyLexer(ANTLR_USE_NAMESPACE(std)istream& in);
	MyLexer(ANTLR_USE_NAMESPACE(antlr)InputBuffer& ib);
	MyLexer(const ANTLR_USE_NAMESPACE(antlr)LexerSharedInputState& state);
	ANTLR_USE_NAMESPACE(antlr)RefToken nextToken();
	public: void mWhitespace(bool _createToken);
	public: void mCpp_Comment(bool _createToken);
	public: void mComment(bool _createToken);
	public: void mASSIGN(bool _createToken);
	public: void mCOLON(bool _createToken);
	public: void mCOMMA(bool _createToken);
	public: void mSEMI(bool _createToken);
	public: void mDOT(bool _createToken);
	public: void mLPAREN(bool _createToken);
	public: void mRPAREN(bool _createToken);
	public: void mLBRACKET(bool _createToken);
	public: void mRBRACKET(bool _createToken);
	public: void mLCURLY(bool _createToken);
	public: void mRCURLY(bool _createToken);
	public: void mEQUAL(bool _createToken);
	public: void mNOT_EQUAL(bool _createToken);
	public: void mLTE(bool _createToken);
	public: void mLT_OP(bool _createToken);
	public: void mGTE(bool _createToken);
	public: void mGT(bool _createToken);
	public: void mMOD(bool _createToken);
	public: void mDIV(bool _createToken);
	public: void mPLUS(bool _createToken);
	public: void mDIV_ASSIGN(bool _createToken);
	public: void mSTAR_ASSIGN(bool _createToken);
	public: void mMOD_ASSIGN(bool _createToken);
	public: void mADD_ASSIGN(bool _createToken);
	public: void mINC_OP(bool _createToken);
	public: void mMINUS(bool _createToken);
	public: void mSUB_ASSIGN(bool _createToken);
	public: void mDEC_OP(bool _createToken);
	public: void mSTAR(bool _createToken);
	public: void mLSHIFT(bool _createToken);
	public: void mLAND(bool _createToken);
	public: void mLNOT(bool _createToken);
	public: void mLOR(bool _createToken);
	public: void mCHAR_LITERAL(bool _createToken);
	protected: void mEscape(bool _createToken);
	public: void mSTRING_LITERAL(bool _createToken);
	protected: void mDIGIT(bool _createToken);
	protected: void mDOUBLE_CONST(bool _createToken);
	protected: void mINT_CONST(bool _createToken);
	public: void mNUMBER(bool _createToken);
	public: void mID(bool _createToken);
private:
	
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
};

#endif /*INC_MyLexer_hpp_*/
