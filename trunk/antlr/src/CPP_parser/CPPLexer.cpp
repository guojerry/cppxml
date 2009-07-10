/* $ANTLR 2.7.7 (20060906): "CPP_parser.g" -> "CPPLexer.cpp"$ */
#line 98 "CPP_parser.g"
// pre_include_cpp
	
#line 6 "CPPLexer.cpp"
#include "CPPLexer.hpp"
#include <antlr/CharBuffer.hpp>
#include <antlr/TokenStreamException.hpp>
#include <antlr/TokenStreamIOException.hpp>
#include <antlr/TokenStreamRecognitionException.hpp>
#include <antlr/CharStreamException.hpp>
#include <antlr/CharStreamIOException.hpp>
#include <antlr/NoViableAltForCharException.hpp>

#line 102 "CPP_parser.g"
// post_include_cpp
	
#line 19 "CPPLexer.cpp"
#line 2464 "CPP_parser.g"

// Possibility of global stuff in the lexer cpp file

bool in_user_file_deferred = false;	// used to record first detection of user file

int deferredLineCount = 0;	// Used to accumulate line numbers in comments etc.

char principal_file[128];	// Path and name of user file set on reading the first preprocessor #line directive
int principal_line = 0;		// principal file's line number
int principal_last_set = 0; // where principal file's line number was last set

char current_included_file[128];	// Path and name of current include file
int include_line = 0; // include file's line number
int include_last_set = 0; // where included file's line number was last set


#line 37 "CPPLexer.cpp"
CPPLexer::CPPLexer(ANTLR_USE_NAMESPACE(std)istream& in)
	: ANTLR_USE_NAMESPACE(antlr)CharScanner(new ANTLR_USE_NAMESPACE(antlr)CharBuffer(in),true)
{
	initLiterals();
}

CPPLexer::CPPLexer(ANTLR_USE_NAMESPACE(antlr)InputBuffer& ib)
	: ANTLR_USE_NAMESPACE(antlr)CharScanner(ib,true)
{
	initLiterals();
}

CPPLexer::CPPLexer(const ANTLR_USE_NAMESPACE(antlr)LexerSharedInputState& state)
	: ANTLR_USE_NAMESPACE(antlr)CharScanner(state,true)
{
	initLiterals();
}

void CPPLexer::initLiterals()
{
	literals["_cdecl"] = 140;
	literals["__stdcall"] = 151;
	literals["extern"] = 13;
	literals["public"] = 63;
	literals["namespace"] = 14;
	literals["case"] = 75;
	literals["short"] = 42;
	literals["break"] = 85;
	literals["while"] = 80;
	literals["__int8"] = 45;
	literals["delete"] = 152;
	literals["new"] = 139;
	literals["__declspec"] = 27;
	literals["_int32"] = 48;
	literals["__pascal"] = 149;
	literals["template"] = 4;
	literals["reinterpret_cast"] = 125;
	literals["inline"] = 12;
	literals["unsigned"] = 56;
	literals["const"] = 60;
	literals["float"] = 57;
	literals["_int8"] = 44;
	literals["__int16"] = 47;
	literals["static_cast"] = 124;
	literals["return"] = 86;
	literals["throw"] = 73;
	literals["typename"] = 38;
	literals["using"] = 74;
	literals["operator"] = 66;
	literals["__far"] = 145;
	literals["sizeof"] = 118;
	literals["protected"] = 64;
	literals["class"] = 25;
	literals["_stdcall"] = 150;
	literals["friend"] = 21;
	literals["do"] = 81;
	literals["__interrupt"] = 146;
	literals["_far"] = 144;
	literals["typeid"] = 127;
	literals["__alignof__"] = 119;
	literals["__cdecl"] = 141;
	literals["_int64"] = 50;
	literals["pascal"] = 147;
	literals["typedef"] = 7;
	literals["const_cast"] = 126;
	literals["explicit"] = 37;
	literals["if"] = 77;
	literals["__int32"] = 49;
	literals["double"] = 58;
	literals["volatile"] = 61;
	literals["catch"] = 88;
	literals["union"] = 24;
	literals["dynamic_cast"] = 123;
	literals["try"] = 87;
	literals["register"] = 31;
	literals["_inline"] = 34;
	literals["auto"] = 30;
	literals["goto"] = 83;
	literals["enum"] = 8;
	literals["int"] = 43;
	literals["for"] = 82;
	literals["char"] = 39;
	literals["__near"] = 143;
	literals["private"] = 65;
	literals["default"] = 76;
	literals["false"] = 137;
	literals["this"] = 128;
	literals["static"] = 32;
	literals["mutable"] = 33;
	literals["_int16"] = 46;
	literals["continue"] = 84;
	literals["bool"] = 41;
	literals["struct"] = 23;
	literals["_near"] = 142;
	literals["__int64"] = 51;
	literals["signed"] = 55;
	literals["else"] = 78;
	literals["_declspec"] = 26;
	literals["_pascal"] = 148;
	literals["__w64"] = 53;
	literals["antlrTrace_on"] = 15;
	literals["void"] = 59;
	literals["antlrTrace_off"] = 16;
	literals["wchar_t"] = 40;
	literals["switch"] = 79;
	literals["__inline"] = 35;
	literals["true"] = 136;
	literals["long"] = 54;
	literals["virtual"] = 36;
	literals["_w64"] = 52;
}

ANTLR_USE_NAMESPACE(antlr)RefToken CPPLexer::nextToken()
{
	ANTLR_USE_NAMESPACE(antlr)RefToken theRetToken;
	for (;;) {
		ANTLR_USE_NAMESPACE(antlr)RefToken theRetToken;
		int _ttype = ANTLR_USE_NAMESPACE(antlr)Token::INVALID_TYPE;
		resetText();
		try {   // for lexical and char stream error handling
			switch ( LA(1)) {
			case 0x2c /* ',' */ :
			{
				mCOMMA(true);
				theRetToken=_returnToken;
				break;
			}
			case 0x3f /* '?' */ :
			{
				mQUESTIONMARK(true);
				theRetToken=_returnToken;
				break;
			}
			case 0x3b /* ';' */ :
			{
				mSEMICOLON(true);
				theRetToken=_returnToken;
				break;
			}
			case 0x28 /* '(' */ :
			{
				mLPAREN(true);
				theRetToken=_returnToken;
				break;
			}
			case 0x29 /* ')' */ :
			{
				mRPAREN(true);
				theRetToken=_returnToken;
				break;
			}
			case 0x5b /* '[' */ :
			{
				mLSQUARE(true);
				theRetToken=_returnToken;
				break;
			}
			case 0x5d /* ']' */ :
			{
				mRSQUARE(true);
				theRetToken=_returnToken;
				break;
			}
			case 0x7b /* '{' */ :
			{
				mLCURLY(true);
				theRetToken=_returnToken;
				break;
			}
			case 0x7d /* '}' */ :
			{
				mRCURLY(true);
				theRetToken=_returnToken;
				break;
			}
			case 0x7e /* '~' */ :
			{
				mTILDE(true);
				theRetToken=_returnToken;
				break;
			}
			case 0x9 /* '\t' */ :
			case 0xa /* '\n' */ :
			case 0xc /* '\14' */ :
			case 0xd /* '\r' */ :
			case 0x20 /* ' ' */ :
			case 0x5c /* '\\' */ :
			{
				mWhitespace(true);
				theRetToken=_returnToken;
				break;
			}
			case 0x22 /* '\"' */ :
			{
				mStringLiteral(true);
				theRetToken=_returnToken;
				break;
			}
			case 0x27 /* '\'' */ :
			{
				mCharLiteral(true);
				theRetToken=_returnToken;
				break;
			}
			default:
				if ((LA(1) == 0x3e /* '>' */ ) && (LA(2) == 0x3e /* '>' */ ) && (LA(3) == 0x3d /* '=' */ )) {
					mSHIFTRIGHTEQUAL(true);
					theRetToken=_returnToken;
				}
				else if ((LA(1) == 0x3c /* '<' */ ) && (LA(2) == 0x3c /* '<' */ ) && (LA(3) == 0x3d /* '=' */ )) {
					mSHIFTLEFTEQUAL(true);
					theRetToken=_returnToken;
				}
				else if ((LA(1) == 0x2d /* '-' */ ) && (LA(2) == 0x3e /* '>' */ ) && (LA(3) == 0x2a /* '*' */ )) {
					mPOINTERTOMBR(true);
					theRetToken=_returnToken;
				}
				else if ((LA(1) == 0x2d /* '-' */ ) && (LA(2) == 0x3e /* '>' */ ) && (true)) {
					mPOINTERTO(true);
					theRetToken=_returnToken;
				}
				else if ((LA(1) == 0x3d /* '=' */ ) && (LA(2) == 0x3d /* '=' */ )) {
					mEQUAL(true);
					theRetToken=_returnToken;
				}
				else if ((LA(1) == 0x21 /* '!' */ ) && (LA(2) == 0x3d /* '=' */ )) {
					mNOTEQUAL(true);
					theRetToken=_returnToken;
				}
				else if ((LA(1) == 0x3c /* '<' */ ) && (LA(2) == 0x3d /* '=' */ )) {
					mLESSTHANOREQUALTO(true);
					theRetToken=_returnToken;
				}
				else if ((LA(1) == 0x3e /* '>' */ ) && (LA(2) == 0x3d /* '=' */ )) {
					mGREATERTHANOREQUALTO(true);
					theRetToken=_returnToken;
				}
				else if ((LA(1) == 0x2f /* '/' */ ) && (LA(2) == 0x3d /* '=' */ )) {
					mDIVIDEEQUAL(true);
					theRetToken=_returnToken;
				}
				else if ((LA(1) == 0x2b /* '+' */ ) && (LA(2) == 0x3d /* '=' */ )) {
					mPLUSEQUAL(true);
					theRetToken=_returnToken;
				}
				else if ((LA(1) == 0x2b /* '+' */ ) && (LA(2) == 0x2b /* '+' */ )) {
					mPLUSPLUS(true);
					theRetToken=_returnToken;
				}
				else if ((LA(1) == 0x2d /* '-' */ ) && (LA(2) == 0x3d /* '=' */ )) {
					mMINUSEQUAL(true);
					theRetToken=_returnToken;
				}
				else if ((LA(1) == 0x2d /* '-' */ ) && (LA(2) == 0x2d /* '-' */ )) {
					mMINUSMINUS(true);
					theRetToken=_returnToken;
				}
				else if ((LA(1) == 0x2a /* '*' */ ) && (LA(2) == 0x3d /* '=' */ )) {
					mTIMESEQUAL(true);
					theRetToken=_returnToken;
				}
				else if ((LA(1) == 0x25 /* '%' */ ) && (LA(2) == 0x3d /* '=' */ )) {
					mMODEQUAL(true);
					theRetToken=_returnToken;
				}
				else if ((LA(1) == 0x3e /* '>' */ ) && (LA(2) == 0x3e /* '>' */ ) && (true)) {
					mSHIFTRIGHT(true);
					theRetToken=_returnToken;
				}
				else if ((LA(1) == 0x3c /* '<' */ ) && (LA(2) == 0x3c /* '<' */ ) && (true)) {
					mSHIFTLEFT(true);
					theRetToken=_returnToken;
				}
				else if ((LA(1) == 0x26 /* '&' */ ) && (LA(2) == 0x26 /* '&' */ )) {
					mAND(true);
					theRetToken=_returnToken;
				}
				else if ((LA(1) == 0x7c /* '|' */ ) && (LA(2) == 0x7c /* '|' */ )) {
					mOR(true);
					theRetToken=_returnToken;
				}
				else if ((LA(1) == 0x26 /* '&' */ ) && (LA(2) == 0x3d /* '=' */ )) {
					mBITWISEANDEQUAL(true);
					theRetToken=_returnToken;
				}
				else if ((LA(1) == 0x7c /* '|' */ ) && (LA(2) == 0x3d /* '=' */ )) {
					mBITWISEOREQUAL(true);
					theRetToken=_returnToken;
				}
				else if ((LA(1) == 0x5e /* '^' */ ) && (LA(2) == 0x3d /* '=' */ )) {
					mBITWISEXOREQUAL(true);
					theRetToken=_returnToken;
				}
				else if ((LA(1) == 0x2e /* '.' */ ) && (LA(2) == 0x2a /* '*' */ )) {
					mDOTMBR(true);
					theRetToken=_returnToken;
				}
				else if ((LA(1) == 0x3a /* ':' */ ) && (LA(2) == 0x3a /* ':' */ )) {
					mSCOPE(true);
					theRetToken=_returnToken;
				}
				else if ((LA(1) == 0x2f /* '/' */ ) && (LA(2) == 0x2a /* '*' */ )) {
					mComment(true);
					theRetToken=_returnToken;
				}
				else if ((LA(1) == 0x2f /* '/' */ ) && (LA(2) == 0x2f /* '/' */ )) {
					mCPPComment(true);
					theRetToken=_returnToken;
				}
				else if ((LA(1) == 0x23 /* '#' */ ) && (_tokenSet_0.member(LA(2)))) {
					mPREPROC_DIRECTIVE(true);
					theRetToken=_returnToken;
				}
				else if ((LA(1) == 0x23 /* '#' */ ) && (LA(2) == 0x70 /* 'p' */ )) {
					mPragma(true);
					theRetToken=_returnToken;
				}
				else if ((LA(1) == 0x23 /* '#' */ ) && (LA(2) == 0x65 /* 'e' */ )) {
					mError(true);
					theRetToken=_returnToken;
				}
				else if ((LA(1) == 0x4c /* 'L' */ ) && (LA(2) == 0x27 /* '\'' */ )) {
					mWCharLiteral(true);
					theRetToken=_returnToken;
				}
				else if ((LA(1) == 0x4c /* 'L' */ ) && (LA(2) == 0x22 /* '\"' */ )) {
					mWStringLiteral(true);
					theRetToken=_returnToken;
				}
				else if ((LA(1) == 0x3d /* '=' */ ) && (true)) {
					mASSIGNEQUAL(true);
					theRetToken=_returnToken;
				}
				else if ((LA(1) == 0x3a /* ':' */ ) && (true)) {
					mCOLON(true);
					theRetToken=_returnToken;
				}
				else if ((LA(1) == 0x3c /* '<' */ ) && (true)) {
					mLESSTHAN(true);
					theRetToken=_returnToken;
				}
				else if ((LA(1) == 0x3e /* '>' */ ) && (true)) {
					mGREATERTHAN(true);
					theRetToken=_returnToken;
				}
				else if ((LA(1) == 0x2f /* '/' */ ) && (true)) {
					mDIVIDE(true);
					theRetToken=_returnToken;
				}
				else if ((LA(1) == 0x2b /* '+' */ ) && (true)) {
					mPLUS(true);
					theRetToken=_returnToken;
				}
				else if ((LA(1) == 0x2d /* '-' */ ) && (true)) {
					mMINUS(true);
					theRetToken=_returnToken;
				}
				else if ((LA(1) == 0x2a /* '*' */ ) && (true)) {
					mSTAR(true);
					theRetToken=_returnToken;
				}
				else if ((LA(1) == 0x25 /* '%' */ ) && (true)) {
					mMOD(true);
					theRetToken=_returnToken;
				}
				else if ((LA(1) == 0x21 /* '!' */ ) && (true)) {
					mNOT(true);
					theRetToken=_returnToken;
				}
				else if ((LA(1) == 0x26 /* '&' */ ) && (true)) {
					mAMPERSAND(true);
					theRetToken=_returnToken;
				}
				else if ((LA(1) == 0x7c /* '|' */ ) && (true)) {
					mBITWISEOR(true);
					theRetToken=_returnToken;
				}
				else if ((LA(1) == 0x5e /* '^' */ ) && (true)) {
					mBITWISEXOR(true);
					theRetToken=_returnToken;
				}
				else if ((_tokenSet_1.member(LA(1))) && (true)) {
					mNumber(true);
					theRetToken=_returnToken;
				}
				else if ((_tokenSet_2.member(LA(1))) && (true)) {
					mID(true);
					theRetToken=_returnToken;
				}
			else {
				if (LA(1)==EOF_CHAR)
				{
					uponEOF();
					_returnToken = makeToken(ANTLR_USE_NAMESPACE(antlr)Token::EOF_TYPE);
				}
				else {throw ANTLR_USE_NAMESPACE(antlr)NoViableAltForCharException(LA(1), getFilename(), getLine(), getColumn());}
			}
			}
			if ( !_returnToken )
				goto tryAgain; // found SKIP token

			_ttype = _returnToken->getType();
			_ttype = testLiteralsTable(_ttype);
			_returnToken->setType(_ttype);
			return _returnToken;
		}
		catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& e) {
				throw ANTLR_USE_NAMESPACE(antlr)TokenStreamRecognitionException(e);
		}
		catch (ANTLR_USE_NAMESPACE(antlr)CharStreamIOException& csie) {
			throw ANTLR_USE_NAMESPACE(antlr)TokenStreamIOException(csie.io);
		}
		catch (ANTLR_USE_NAMESPACE(antlr)CharStreamException& cse) {
			throw ANTLR_USE_NAMESPACE(antlr)TokenStreamException(cse.getMessage());
		}
tryAgain:;
	}
}

void CPPLexer::mASSIGNEQUAL(bool _createToken) {
	int _ttype; ANTLR_USE_NAMESPACE(antlr)RefToken _token; ANTLR_USE_NAMESPACE(std)string::size_type _begin = text.length();
	_ttype = ASSIGNEQUAL;
	ANTLR_USE_NAMESPACE(std)string::size_type _saveIndex;
	
	match('=' /* charlit */ );
	if ( _createToken && _token==ANTLR_USE_NAMESPACE(antlr)nullToken && _ttype!=ANTLR_USE_NAMESPACE(antlr)Token::SKIP ) {
	   _token = makeToken(_ttype);
	   _token->setText(text.substr(_begin, text.length()-_begin));
	}
	_returnToken = _token;
	_saveIndex=0;
}

void CPPLexer::mCOLON(bool _createToken) {
	int _ttype; ANTLR_USE_NAMESPACE(antlr)RefToken _token; ANTLR_USE_NAMESPACE(std)string::size_type _begin = text.length();
	_ttype = COLON;
	ANTLR_USE_NAMESPACE(std)string::size_type _saveIndex;
	
	match(':' /* charlit */ );
	if ( _createToken && _token==ANTLR_USE_NAMESPACE(antlr)nullToken && _ttype!=ANTLR_USE_NAMESPACE(antlr)Token::SKIP ) {
	   _token = makeToken(_ttype);
	   _token->setText(text.substr(_begin, text.length()-_begin));
	}
	_returnToken = _token;
	_saveIndex=0;
}

void CPPLexer::mCOMMA(bool _createToken) {
	int _ttype; ANTLR_USE_NAMESPACE(antlr)RefToken _token; ANTLR_USE_NAMESPACE(std)string::size_type _begin = text.length();
	_ttype = COMMA;
	ANTLR_USE_NAMESPACE(std)string::size_type _saveIndex;
	
	match(',' /* charlit */ );
	if ( _createToken && _token==ANTLR_USE_NAMESPACE(antlr)nullToken && _ttype!=ANTLR_USE_NAMESPACE(antlr)Token::SKIP ) {
	   _token = makeToken(_ttype);
	   _token->setText(text.substr(_begin, text.length()-_begin));
	}
	_returnToken = _token;
	_saveIndex=0;
}

void CPPLexer::mQUESTIONMARK(bool _createToken) {
	int _ttype; ANTLR_USE_NAMESPACE(antlr)RefToken _token; ANTLR_USE_NAMESPACE(std)string::size_type _begin = text.length();
	_ttype = QUESTIONMARK;
	ANTLR_USE_NAMESPACE(std)string::size_type _saveIndex;
	
	match('?' /* charlit */ );
	if ( _createToken && _token==ANTLR_USE_NAMESPACE(antlr)nullToken && _ttype!=ANTLR_USE_NAMESPACE(antlr)Token::SKIP ) {
	   _token = makeToken(_ttype);
	   _token->setText(text.substr(_begin, text.length()-_begin));
	}
	_returnToken = _token;
	_saveIndex=0;
}

void CPPLexer::mSEMICOLON(bool _createToken) {
	int _ttype; ANTLR_USE_NAMESPACE(antlr)RefToken _token; ANTLR_USE_NAMESPACE(std)string::size_type _begin = text.length();
	_ttype = SEMICOLON;
	ANTLR_USE_NAMESPACE(std)string::size_type _saveIndex;
	
	match(';' /* charlit */ );
	if ( _createToken && _token==ANTLR_USE_NAMESPACE(antlr)nullToken && _ttype!=ANTLR_USE_NAMESPACE(antlr)Token::SKIP ) {
	   _token = makeToken(_ttype);
	   _token->setText(text.substr(_begin, text.length()-_begin));
	}
	_returnToken = _token;
	_saveIndex=0;
}

void CPPLexer::mPOINTERTO(bool _createToken) {
	int _ttype; ANTLR_USE_NAMESPACE(antlr)RefToken _token; ANTLR_USE_NAMESPACE(std)string::size_type _begin = text.length();
	_ttype = POINTERTO;
	ANTLR_USE_NAMESPACE(std)string::size_type _saveIndex;
	
	match("->");
	if ( _createToken && _token==ANTLR_USE_NAMESPACE(antlr)nullToken && _ttype!=ANTLR_USE_NAMESPACE(antlr)Token::SKIP ) {
	   _token = makeToken(_ttype);
	   _token->setText(text.substr(_begin, text.length()-_begin));
	}
	_returnToken = _token;
	_saveIndex=0;
}

void CPPLexer::mLPAREN(bool _createToken) {
	int _ttype; ANTLR_USE_NAMESPACE(antlr)RefToken _token; ANTLR_USE_NAMESPACE(std)string::size_type _begin = text.length();
	_ttype = LPAREN;
	ANTLR_USE_NAMESPACE(std)string::size_type _saveIndex;
	
	match('(' /* charlit */ );
	if ( _createToken && _token==ANTLR_USE_NAMESPACE(antlr)nullToken && _ttype!=ANTLR_USE_NAMESPACE(antlr)Token::SKIP ) {
	   _token = makeToken(_ttype);
	   _token->setText(text.substr(_begin, text.length()-_begin));
	}
	_returnToken = _token;
	_saveIndex=0;
}

void CPPLexer::mRPAREN(bool _createToken) {
	int _ttype; ANTLR_USE_NAMESPACE(antlr)RefToken _token; ANTLR_USE_NAMESPACE(std)string::size_type _begin = text.length();
	_ttype = RPAREN;
	ANTLR_USE_NAMESPACE(std)string::size_type _saveIndex;
	
	match(')' /* charlit */ );
	if ( _createToken && _token==ANTLR_USE_NAMESPACE(antlr)nullToken && _ttype!=ANTLR_USE_NAMESPACE(antlr)Token::SKIP ) {
	   _token = makeToken(_ttype);
	   _token->setText(text.substr(_begin, text.length()-_begin));
	}
	_returnToken = _token;
	_saveIndex=0;
}

void CPPLexer::mLSQUARE(bool _createToken) {
	int _ttype; ANTLR_USE_NAMESPACE(antlr)RefToken _token; ANTLR_USE_NAMESPACE(std)string::size_type _begin = text.length();
	_ttype = LSQUARE;
	ANTLR_USE_NAMESPACE(std)string::size_type _saveIndex;
	
	match('[' /* charlit */ );
	if ( _createToken && _token==ANTLR_USE_NAMESPACE(antlr)nullToken && _ttype!=ANTLR_USE_NAMESPACE(antlr)Token::SKIP ) {
	   _token = makeToken(_ttype);
	   _token->setText(text.substr(_begin, text.length()-_begin));
	}
	_returnToken = _token;
	_saveIndex=0;
}

void CPPLexer::mRSQUARE(bool _createToken) {
	int _ttype; ANTLR_USE_NAMESPACE(antlr)RefToken _token; ANTLR_USE_NAMESPACE(std)string::size_type _begin = text.length();
	_ttype = RSQUARE;
	ANTLR_USE_NAMESPACE(std)string::size_type _saveIndex;
	
	match(']' /* charlit */ );
	if ( _createToken && _token==ANTLR_USE_NAMESPACE(antlr)nullToken && _ttype!=ANTLR_USE_NAMESPACE(antlr)Token::SKIP ) {
	   _token = makeToken(_ttype);
	   _token->setText(text.substr(_begin, text.length()-_begin));
	}
	_returnToken = _token;
	_saveIndex=0;
}

void CPPLexer::mLCURLY(bool _createToken) {
	int _ttype; ANTLR_USE_NAMESPACE(antlr)RefToken _token; ANTLR_USE_NAMESPACE(std)string::size_type _begin = text.length();
	_ttype = LCURLY;
	ANTLR_USE_NAMESPACE(std)string::size_type _saveIndex;
	
	match('{' /* charlit */ );
	if ( _createToken && _token==ANTLR_USE_NAMESPACE(antlr)nullToken && _ttype!=ANTLR_USE_NAMESPACE(antlr)Token::SKIP ) {
	   _token = makeToken(_ttype);
	   _token->setText(text.substr(_begin, text.length()-_begin));
	}
	_returnToken = _token;
	_saveIndex=0;
}

void CPPLexer::mRCURLY(bool _createToken) {
	int _ttype; ANTLR_USE_NAMESPACE(antlr)RefToken _token; ANTLR_USE_NAMESPACE(std)string::size_type _begin = text.length();
	_ttype = RCURLY;
	ANTLR_USE_NAMESPACE(std)string::size_type _saveIndex;
	
	match('}' /* charlit */ );
	if ( _createToken && _token==ANTLR_USE_NAMESPACE(antlr)nullToken && _ttype!=ANTLR_USE_NAMESPACE(antlr)Token::SKIP ) {
	   _token = makeToken(_ttype);
	   _token->setText(text.substr(_begin, text.length()-_begin));
	}
	_returnToken = _token;
	_saveIndex=0;
}

void CPPLexer::mEQUAL(bool _createToken) {
	int _ttype; ANTLR_USE_NAMESPACE(antlr)RefToken _token; ANTLR_USE_NAMESPACE(std)string::size_type _begin = text.length();
	_ttype = EQUAL;
	ANTLR_USE_NAMESPACE(std)string::size_type _saveIndex;
	
	match("==");
	if ( _createToken && _token==ANTLR_USE_NAMESPACE(antlr)nullToken && _ttype!=ANTLR_USE_NAMESPACE(antlr)Token::SKIP ) {
	   _token = makeToken(_ttype);
	   _token->setText(text.substr(_begin, text.length()-_begin));
	}
	_returnToken = _token;
	_saveIndex=0;
}

void CPPLexer::mNOTEQUAL(bool _createToken) {
	int _ttype; ANTLR_USE_NAMESPACE(antlr)RefToken _token; ANTLR_USE_NAMESPACE(std)string::size_type _begin = text.length();
	_ttype = NOTEQUAL;
	ANTLR_USE_NAMESPACE(std)string::size_type _saveIndex;
	
	match("!=");
	if ( _createToken && _token==ANTLR_USE_NAMESPACE(antlr)nullToken && _ttype!=ANTLR_USE_NAMESPACE(antlr)Token::SKIP ) {
	   _token = makeToken(_ttype);
	   _token->setText(text.substr(_begin, text.length()-_begin));
	}
	_returnToken = _token;
	_saveIndex=0;
}

void CPPLexer::mLESSTHANOREQUALTO(bool _createToken) {
	int _ttype; ANTLR_USE_NAMESPACE(antlr)RefToken _token; ANTLR_USE_NAMESPACE(std)string::size_type _begin = text.length();
	_ttype = LESSTHANOREQUALTO;
	ANTLR_USE_NAMESPACE(std)string::size_type _saveIndex;
	
	match("<=");
	if ( _createToken && _token==ANTLR_USE_NAMESPACE(antlr)nullToken && _ttype!=ANTLR_USE_NAMESPACE(antlr)Token::SKIP ) {
	   _token = makeToken(_ttype);
	   _token->setText(text.substr(_begin, text.length()-_begin));
	}
	_returnToken = _token;
	_saveIndex=0;
}

void CPPLexer::mLESSTHAN(bool _createToken) {
	int _ttype; ANTLR_USE_NAMESPACE(antlr)RefToken _token; ANTLR_USE_NAMESPACE(std)string::size_type _begin = text.length();
	_ttype = LESSTHAN;
	ANTLR_USE_NAMESPACE(std)string::size_type _saveIndex;
	
	match("<");
	if ( _createToken && _token==ANTLR_USE_NAMESPACE(antlr)nullToken && _ttype!=ANTLR_USE_NAMESPACE(antlr)Token::SKIP ) {
	   _token = makeToken(_ttype);
	   _token->setText(text.substr(_begin, text.length()-_begin));
	}
	_returnToken = _token;
	_saveIndex=0;
}

void CPPLexer::mGREATERTHANOREQUALTO(bool _createToken) {
	int _ttype; ANTLR_USE_NAMESPACE(antlr)RefToken _token; ANTLR_USE_NAMESPACE(std)string::size_type _begin = text.length();
	_ttype = GREATERTHANOREQUALTO;
	ANTLR_USE_NAMESPACE(std)string::size_type _saveIndex;
	
	match(">=");
	if ( _createToken && _token==ANTLR_USE_NAMESPACE(antlr)nullToken && _ttype!=ANTLR_USE_NAMESPACE(antlr)Token::SKIP ) {
	   _token = makeToken(_ttype);
	   _token->setText(text.substr(_begin, text.length()-_begin));
	}
	_returnToken = _token;
	_saveIndex=0;
}

void CPPLexer::mGREATERTHAN(bool _createToken) {
	int _ttype; ANTLR_USE_NAMESPACE(antlr)RefToken _token; ANTLR_USE_NAMESPACE(std)string::size_type _begin = text.length();
	_ttype = GREATERTHAN;
	ANTLR_USE_NAMESPACE(std)string::size_type _saveIndex;
	
	match(">");
	if ( _createToken && _token==ANTLR_USE_NAMESPACE(antlr)nullToken && _ttype!=ANTLR_USE_NAMESPACE(antlr)Token::SKIP ) {
	   _token = makeToken(_ttype);
	   _token->setText(text.substr(_begin, text.length()-_begin));
	}
	_returnToken = _token;
	_saveIndex=0;
}

void CPPLexer::mDIVIDE(bool _createToken) {
	int _ttype; ANTLR_USE_NAMESPACE(antlr)RefToken _token; ANTLR_USE_NAMESPACE(std)string::size_type _begin = text.length();
	_ttype = DIVIDE;
	ANTLR_USE_NAMESPACE(std)string::size_type _saveIndex;
	
	match('/' /* charlit */ );
	if ( _createToken && _token==ANTLR_USE_NAMESPACE(antlr)nullToken && _ttype!=ANTLR_USE_NAMESPACE(antlr)Token::SKIP ) {
	   _token = makeToken(_ttype);
	   _token->setText(text.substr(_begin, text.length()-_begin));
	}
	_returnToken = _token;
	_saveIndex=0;
}

void CPPLexer::mDIVIDEEQUAL(bool _createToken) {
	int _ttype; ANTLR_USE_NAMESPACE(antlr)RefToken _token; ANTLR_USE_NAMESPACE(std)string::size_type _begin = text.length();
	_ttype = DIVIDEEQUAL;
	ANTLR_USE_NAMESPACE(std)string::size_type _saveIndex;
	
	match("/=");
	if ( _createToken && _token==ANTLR_USE_NAMESPACE(antlr)nullToken && _ttype!=ANTLR_USE_NAMESPACE(antlr)Token::SKIP ) {
	   _token = makeToken(_ttype);
	   _token->setText(text.substr(_begin, text.length()-_begin));
	}
	_returnToken = _token;
	_saveIndex=0;
}

void CPPLexer::mPLUS(bool _createToken) {
	int _ttype; ANTLR_USE_NAMESPACE(antlr)RefToken _token; ANTLR_USE_NAMESPACE(std)string::size_type _begin = text.length();
	_ttype = PLUS;
	ANTLR_USE_NAMESPACE(std)string::size_type _saveIndex;
	
	match('+' /* charlit */ );
	if ( _createToken && _token==ANTLR_USE_NAMESPACE(antlr)nullToken && _ttype!=ANTLR_USE_NAMESPACE(antlr)Token::SKIP ) {
	   _token = makeToken(_ttype);
	   _token->setText(text.substr(_begin, text.length()-_begin));
	}
	_returnToken = _token;
	_saveIndex=0;
}

void CPPLexer::mPLUSEQUAL(bool _createToken) {
	int _ttype; ANTLR_USE_NAMESPACE(antlr)RefToken _token; ANTLR_USE_NAMESPACE(std)string::size_type _begin = text.length();
	_ttype = PLUSEQUAL;
	ANTLR_USE_NAMESPACE(std)string::size_type _saveIndex;
	
	match("+=");
	if ( _createToken && _token==ANTLR_USE_NAMESPACE(antlr)nullToken && _ttype!=ANTLR_USE_NAMESPACE(antlr)Token::SKIP ) {
	   _token = makeToken(_ttype);
	   _token->setText(text.substr(_begin, text.length()-_begin));
	}
	_returnToken = _token;
	_saveIndex=0;
}

void CPPLexer::mPLUSPLUS(bool _createToken) {
	int _ttype; ANTLR_USE_NAMESPACE(antlr)RefToken _token; ANTLR_USE_NAMESPACE(std)string::size_type _begin = text.length();
	_ttype = PLUSPLUS;
	ANTLR_USE_NAMESPACE(std)string::size_type _saveIndex;
	
	match("++");
	if ( _createToken && _token==ANTLR_USE_NAMESPACE(antlr)nullToken && _ttype!=ANTLR_USE_NAMESPACE(antlr)Token::SKIP ) {
	   _token = makeToken(_ttype);
	   _token->setText(text.substr(_begin, text.length()-_begin));
	}
	_returnToken = _token;
	_saveIndex=0;
}

void CPPLexer::mMINUS(bool _createToken) {
	int _ttype; ANTLR_USE_NAMESPACE(antlr)RefToken _token; ANTLR_USE_NAMESPACE(std)string::size_type _begin = text.length();
	_ttype = MINUS;
	ANTLR_USE_NAMESPACE(std)string::size_type _saveIndex;
	
	match('-' /* charlit */ );
	if ( _createToken && _token==ANTLR_USE_NAMESPACE(antlr)nullToken && _ttype!=ANTLR_USE_NAMESPACE(antlr)Token::SKIP ) {
	   _token = makeToken(_ttype);
	   _token->setText(text.substr(_begin, text.length()-_begin));
	}
	_returnToken = _token;
	_saveIndex=0;
}

void CPPLexer::mMINUSEQUAL(bool _createToken) {
	int _ttype; ANTLR_USE_NAMESPACE(antlr)RefToken _token; ANTLR_USE_NAMESPACE(std)string::size_type _begin = text.length();
	_ttype = MINUSEQUAL;
	ANTLR_USE_NAMESPACE(std)string::size_type _saveIndex;
	
	match("-=");
	if ( _createToken && _token==ANTLR_USE_NAMESPACE(antlr)nullToken && _ttype!=ANTLR_USE_NAMESPACE(antlr)Token::SKIP ) {
	   _token = makeToken(_ttype);
	   _token->setText(text.substr(_begin, text.length()-_begin));
	}
	_returnToken = _token;
	_saveIndex=0;
}

void CPPLexer::mMINUSMINUS(bool _createToken) {
	int _ttype; ANTLR_USE_NAMESPACE(antlr)RefToken _token; ANTLR_USE_NAMESPACE(std)string::size_type _begin = text.length();
	_ttype = MINUSMINUS;
	ANTLR_USE_NAMESPACE(std)string::size_type _saveIndex;
	
	match("--");
	if ( _createToken && _token==ANTLR_USE_NAMESPACE(antlr)nullToken && _ttype!=ANTLR_USE_NAMESPACE(antlr)Token::SKIP ) {
	   _token = makeToken(_ttype);
	   _token->setText(text.substr(_begin, text.length()-_begin));
	}
	_returnToken = _token;
	_saveIndex=0;
}

void CPPLexer::mSTAR(bool _createToken) {
	int _ttype; ANTLR_USE_NAMESPACE(antlr)RefToken _token; ANTLR_USE_NAMESPACE(std)string::size_type _begin = text.length();
	_ttype = STAR;
	ANTLR_USE_NAMESPACE(std)string::size_type _saveIndex;
	
	match('*' /* charlit */ );
	if ( _createToken && _token==ANTLR_USE_NAMESPACE(antlr)nullToken && _ttype!=ANTLR_USE_NAMESPACE(antlr)Token::SKIP ) {
	   _token = makeToken(_ttype);
	   _token->setText(text.substr(_begin, text.length()-_begin));
	}
	_returnToken = _token;
	_saveIndex=0;
}

void CPPLexer::mTIMESEQUAL(bool _createToken) {
	int _ttype; ANTLR_USE_NAMESPACE(antlr)RefToken _token; ANTLR_USE_NAMESPACE(std)string::size_type _begin = text.length();
	_ttype = TIMESEQUAL;
	ANTLR_USE_NAMESPACE(std)string::size_type _saveIndex;
	
	match("*=");
	if ( _createToken && _token==ANTLR_USE_NAMESPACE(antlr)nullToken && _ttype!=ANTLR_USE_NAMESPACE(antlr)Token::SKIP ) {
	   _token = makeToken(_ttype);
	   _token->setText(text.substr(_begin, text.length()-_begin));
	}
	_returnToken = _token;
	_saveIndex=0;
}

void CPPLexer::mMOD(bool _createToken) {
	int _ttype; ANTLR_USE_NAMESPACE(antlr)RefToken _token; ANTLR_USE_NAMESPACE(std)string::size_type _begin = text.length();
	_ttype = MOD;
	ANTLR_USE_NAMESPACE(std)string::size_type _saveIndex;
	
	match('%' /* charlit */ );
	if ( _createToken && _token==ANTLR_USE_NAMESPACE(antlr)nullToken && _ttype!=ANTLR_USE_NAMESPACE(antlr)Token::SKIP ) {
	   _token = makeToken(_ttype);
	   _token->setText(text.substr(_begin, text.length()-_begin));
	}
	_returnToken = _token;
	_saveIndex=0;
}

void CPPLexer::mMODEQUAL(bool _createToken) {
	int _ttype; ANTLR_USE_NAMESPACE(antlr)RefToken _token; ANTLR_USE_NAMESPACE(std)string::size_type _begin = text.length();
	_ttype = MODEQUAL;
	ANTLR_USE_NAMESPACE(std)string::size_type _saveIndex;
	
	match("%=");
	if ( _createToken && _token==ANTLR_USE_NAMESPACE(antlr)nullToken && _ttype!=ANTLR_USE_NAMESPACE(antlr)Token::SKIP ) {
	   _token = makeToken(_ttype);
	   _token->setText(text.substr(_begin, text.length()-_begin));
	}
	_returnToken = _token;
	_saveIndex=0;
}

void CPPLexer::mSHIFTRIGHT(bool _createToken) {
	int _ttype; ANTLR_USE_NAMESPACE(antlr)RefToken _token; ANTLR_USE_NAMESPACE(std)string::size_type _begin = text.length();
	_ttype = SHIFTRIGHT;
	ANTLR_USE_NAMESPACE(std)string::size_type _saveIndex;
	
	match(">>");
	if ( _createToken && _token==ANTLR_USE_NAMESPACE(antlr)nullToken && _ttype!=ANTLR_USE_NAMESPACE(antlr)Token::SKIP ) {
	   _token = makeToken(_ttype);
	   _token->setText(text.substr(_begin, text.length()-_begin));
	}
	_returnToken = _token;
	_saveIndex=0;
}

void CPPLexer::mSHIFTRIGHTEQUAL(bool _createToken) {
	int _ttype; ANTLR_USE_NAMESPACE(antlr)RefToken _token; ANTLR_USE_NAMESPACE(std)string::size_type _begin = text.length();
	_ttype = SHIFTRIGHTEQUAL;
	ANTLR_USE_NAMESPACE(std)string::size_type _saveIndex;
	
	match(">>=");
	if ( _createToken && _token==ANTLR_USE_NAMESPACE(antlr)nullToken && _ttype!=ANTLR_USE_NAMESPACE(antlr)Token::SKIP ) {
	   _token = makeToken(_ttype);
	   _token->setText(text.substr(_begin, text.length()-_begin));
	}
	_returnToken = _token;
	_saveIndex=0;
}

void CPPLexer::mSHIFTLEFT(bool _createToken) {
	int _ttype; ANTLR_USE_NAMESPACE(antlr)RefToken _token; ANTLR_USE_NAMESPACE(std)string::size_type _begin = text.length();
	_ttype = SHIFTLEFT;
	ANTLR_USE_NAMESPACE(std)string::size_type _saveIndex;
	
	match("<<");
	if ( _createToken && _token==ANTLR_USE_NAMESPACE(antlr)nullToken && _ttype!=ANTLR_USE_NAMESPACE(antlr)Token::SKIP ) {
	   _token = makeToken(_ttype);
	   _token->setText(text.substr(_begin, text.length()-_begin));
	}
	_returnToken = _token;
	_saveIndex=0;
}

void CPPLexer::mSHIFTLEFTEQUAL(bool _createToken) {
	int _ttype; ANTLR_USE_NAMESPACE(antlr)RefToken _token; ANTLR_USE_NAMESPACE(std)string::size_type _begin = text.length();
	_ttype = SHIFTLEFTEQUAL;
	ANTLR_USE_NAMESPACE(std)string::size_type _saveIndex;
	
	match("<<=");
	if ( _createToken && _token==ANTLR_USE_NAMESPACE(antlr)nullToken && _ttype!=ANTLR_USE_NAMESPACE(antlr)Token::SKIP ) {
	   _token = makeToken(_ttype);
	   _token->setText(text.substr(_begin, text.length()-_begin));
	}
	_returnToken = _token;
	_saveIndex=0;
}

void CPPLexer::mAND(bool _createToken) {
	int _ttype; ANTLR_USE_NAMESPACE(antlr)RefToken _token; ANTLR_USE_NAMESPACE(std)string::size_type _begin = text.length();
	_ttype = AND;
	ANTLR_USE_NAMESPACE(std)string::size_type _saveIndex;
	
	match("&&");
	if ( _createToken && _token==ANTLR_USE_NAMESPACE(antlr)nullToken && _ttype!=ANTLR_USE_NAMESPACE(antlr)Token::SKIP ) {
	   _token = makeToken(_ttype);
	   _token->setText(text.substr(_begin, text.length()-_begin));
	}
	_returnToken = _token;
	_saveIndex=0;
}

void CPPLexer::mNOT(bool _createToken) {
	int _ttype; ANTLR_USE_NAMESPACE(antlr)RefToken _token; ANTLR_USE_NAMESPACE(std)string::size_type _begin = text.length();
	_ttype = NOT;
	ANTLR_USE_NAMESPACE(std)string::size_type _saveIndex;
	
	match('!' /* charlit */ );
	if ( _createToken && _token==ANTLR_USE_NAMESPACE(antlr)nullToken && _ttype!=ANTLR_USE_NAMESPACE(antlr)Token::SKIP ) {
	   _token = makeToken(_ttype);
	   _token->setText(text.substr(_begin, text.length()-_begin));
	}
	_returnToken = _token;
	_saveIndex=0;
}

void CPPLexer::mOR(bool _createToken) {
	int _ttype; ANTLR_USE_NAMESPACE(antlr)RefToken _token; ANTLR_USE_NAMESPACE(std)string::size_type _begin = text.length();
	_ttype = OR;
	ANTLR_USE_NAMESPACE(std)string::size_type _saveIndex;
	
	match("||");
	if ( _createToken && _token==ANTLR_USE_NAMESPACE(antlr)nullToken && _ttype!=ANTLR_USE_NAMESPACE(antlr)Token::SKIP ) {
	   _token = makeToken(_ttype);
	   _token->setText(text.substr(_begin, text.length()-_begin));
	}
	_returnToken = _token;
	_saveIndex=0;
}

void CPPLexer::mAMPERSAND(bool _createToken) {
	int _ttype; ANTLR_USE_NAMESPACE(antlr)RefToken _token; ANTLR_USE_NAMESPACE(std)string::size_type _begin = text.length();
	_ttype = AMPERSAND;
	ANTLR_USE_NAMESPACE(std)string::size_type _saveIndex;
	
	match('&' /* charlit */ );
	if ( _createToken && _token==ANTLR_USE_NAMESPACE(antlr)nullToken && _ttype!=ANTLR_USE_NAMESPACE(antlr)Token::SKIP ) {
	   _token = makeToken(_ttype);
	   _token->setText(text.substr(_begin, text.length()-_begin));
	}
	_returnToken = _token;
	_saveIndex=0;
}

void CPPLexer::mBITWISEANDEQUAL(bool _createToken) {
	int _ttype; ANTLR_USE_NAMESPACE(antlr)RefToken _token; ANTLR_USE_NAMESPACE(std)string::size_type _begin = text.length();
	_ttype = BITWISEANDEQUAL;
	ANTLR_USE_NAMESPACE(std)string::size_type _saveIndex;
	
	match("&=");
	if ( _createToken && _token==ANTLR_USE_NAMESPACE(antlr)nullToken && _ttype!=ANTLR_USE_NAMESPACE(antlr)Token::SKIP ) {
	   _token = makeToken(_ttype);
	   _token->setText(text.substr(_begin, text.length()-_begin));
	}
	_returnToken = _token;
	_saveIndex=0;
}

void CPPLexer::mTILDE(bool _createToken) {
	int _ttype; ANTLR_USE_NAMESPACE(antlr)RefToken _token; ANTLR_USE_NAMESPACE(std)string::size_type _begin = text.length();
	_ttype = TILDE;
	ANTLR_USE_NAMESPACE(std)string::size_type _saveIndex;
	
	match('~' /* charlit */ );
	if ( _createToken && _token==ANTLR_USE_NAMESPACE(antlr)nullToken && _ttype!=ANTLR_USE_NAMESPACE(antlr)Token::SKIP ) {
	   _token = makeToken(_ttype);
	   _token->setText(text.substr(_begin, text.length()-_begin));
	}
	_returnToken = _token;
	_saveIndex=0;
}

void CPPLexer::mBITWISEOR(bool _createToken) {
	int _ttype; ANTLR_USE_NAMESPACE(antlr)RefToken _token; ANTLR_USE_NAMESPACE(std)string::size_type _begin = text.length();
	_ttype = BITWISEOR;
	ANTLR_USE_NAMESPACE(std)string::size_type _saveIndex;
	
	match('|' /* charlit */ );
	if ( _createToken && _token==ANTLR_USE_NAMESPACE(antlr)nullToken && _ttype!=ANTLR_USE_NAMESPACE(antlr)Token::SKIP ) {
	   _token = makeToken(_ttype);
	   _token->setText(text.substr(_begin, text.length()-_begin));
	}
	_returnToken = _token;
	_saveIndex=0;
}

void CPPLexer::mBITWISEOREQUAL(bool _createToken) {
	int _ttype; ANTLR_USE_NAMESPACE(antlr)RefToken _token; ANTLR_USE_NAMESPACE(std)string::size_type _begin = text.length();
	_ttype = BITWISEOREQUAL;
	ANTLR_USE_NAMESPACE(std)string::size_type _saveIndex;
	
	match("|=");
	if ( _createToken && _token==ANTLR_USE_NAMESPACE(antlr)nullToken && _ttype!=ANTLR_USE_NAMESPACE(antlr)Token::SKIP ) {
	   _token = makeToken(_ttype);
	   _token->setText(text.substr(_begin, text.length()-_begin));
	}
	_returnToken = _token;
	_saveIndex=0;
}

void CPPLexer::mBITWISEXOR(bool _createToken) {
	int _ttype; ANTLR_USE_NAMESPACE(antlr)RefToken _token; ANTLR_USE_NAMESPACE(std)string::size_type _begin = text.length();
	_ttype = BITWISEXOR;
	ANTLR_USE_NAMESPACE(std)string::size_type _saveIndex;
	
	match('^' /* charlit */ );
	if ( _createToken && _token==ANTLR_USE_NAMESPACE(antlr)nullToken && _ttype!=ANTLR_USE_NAMESPACE(antlr)Token::SKIP ) {
	   _token = makeToken(_ttype);
	   _token->setText(text.substr(_begin, text.length()-_begin));
	}
	_returnToken = _token;
	_saveIndex=0;
}

void CPPLexer::mBITWISEXOREQUAL(bool _createToken) {
	int _ttype; ANTLR_USE_NAMESPACE(antlr)RefToken _token; ANTLR_USE_NAMESPACE(std)string::size_type _begin = text.length();
	_ttype = BITWISEXOREQUAL;
	ANTLR_USE_NAMESPACE(std)string::size_type _saveIndex;
	
	match("^=");
	if ( _createToken && _token==ANTLR_USE_NAMESPACE(antlr)nullToken && _ttype!=ANTLR_USE_NAMESPACE(antlr)Token::SKIP ) {
	   _token = makeToken(_ttype);
	   _token->setText(text.substr(_begin, text.length()-_begin));
	}
	_returnToken = _token;
	_saveIndex=0;
}

void CPPLexer::mPOINTERTOMBR(bool _createToken) {
	int _ttype; ANTLR_USE_NAMESPACE(antlr)RefToken _token; ANTLR_USE_NAMESPACE(std)string::size_type _begin = text.length();
	_ttype = POINTERTOMBR;
	ANTLR_USE_NAMESPACE(std)string::size_type _saveIndex;
	
	match("->*");
	if ( _createToken && _token==ANTLR_USE_NAMESPACE(antlr)nullToken && _ttype!=ANTLR_USE_NAMESPACE(antlr)Token::SKIP ) {
	   _token = makeToken(_ttype);
	   _token->setText(text.substr(_begin, text.length()-_begin));
	}
	_returnToken = _token;
	_saveIndex=0;
}

void CPPLexer::mDOTMBR(bool _createToken) {
	int _ttype; ANTLR_USE_NAMESPACE(antlr)RefToken _token; ANTLR_USE_NAMESPACE(std)string::size_type _begin = text.length();
	_ttype = DOTMBR;
	ANTLR_USE_NAMESPACE(std)string::size_type _saveIndex;
	
	match(".*");
	if ( _createToken && _token==ANTLR_USE_NAMESPACE(antlr)nullToken && _ttype!=ANTLR_USE_NAMESPACE(antlr)Token::SKIP ) {
	   _token = makeToken(_ttype);
	   _token->setText(text.substr(_begin, text.length()-_begin));
	}
	_returnToken = _token;
	_saveIndex=0;
}

void CPPLexer::mSCOPE(bool _createToken) {
	int _ttype; ANTLR_USE_NAMESPACE(antlr)RefToken _token; ANTLR_USE_NAMESPACE(std)string::size_type _begin = text.length();
	_ttype = SCOPE;
	ANTLR_USE_NAMESPACE(std)string::size_type _saveIndex;
	
	match("::");
	if ( _createToken && _token==ANTLR_USE_NAMESPACE(antlr)nullToken && _ttype!=ANTLR_USE_NAMESPACE(antlr)Token::SKIP ) {
	   _token = makeToken(_ttype);
	   _token->setText(text.substr(_begin, text.length()-_begin));
	}
	_returnToken = _token;
	_saveIndex=0;
}

void CPPLexer::mWhitespace(bool _createToken) {
	int _ttype; ANTLR_USE_NAMESPACE(antlr)RefToken _token; ANTLR_USE_NAMESPACE(std)string::size_type _begin = text.length();
	_ttype = Whitespace;
	ANTLR_USE_NAMESPACE(std)string::size_type _saveIndex;
	
	{
	switch ( LA(1)) {
	case 0x9 /* '\t' */ :
	case 0xc /* '\14' */ :
	case 0x20 /* ' ' */ :
	{
		mSpace(false);
		break;
	}
	case 0xa /* '\n' */ :
	case 0xd /* '\r' */ :
	{
		{
		if ((LA(1) == 0xd /* '\r' */ ) && (LA(2) == 0xa /* '\n' */ )) {
			match('\r' /* charlit */ );
			match('\n' /* charlit */ );
		}
		else if ((LA(1) == 0xd /* '\r' */ ) && (true)) {
			match('\r' /* charlit */ );
		}
		else if ((LA(1) == 0xa /* '\n' */ )) {
			match('\n' /* charlit */ );
		}
		else {
			throw ANTLR_USE_NAMESPACE(antlr)NoViableAltForCharException(LA(1), getFilename(), getLine(), getColumn());
		}
		
		}
		if ( inputState->guessing==0 ) {
#line 2653 "CPP_parser.g"
			newline();
#line 1151 "CPPLexer.cpp"
		}
		break;
	}
	case 0x5c /* '\\' */ :
	{
		{
		if ((LA(1) == 0x5c /* '\\' */ ) && (LA(2) == 0xd /* '\r' */ ) && (LA(3) == 0xa /* '\n' */ )) {
			match('\\' /* charlit */ );
			match('\r' /* charlit */ );
			match('\n' /* charlit */ );
		}
		else if ((LA(1) == 0x5c /* '\\' */ ) && (LA(2) == 0xd /* '\r' */ ) && (true)) {
			match('\\' /* charlit */ );
			match('\r' /* charlit */ );
		}
		else if ((LA(1) == 0x5c /* '\\' */ ) && (LA(2) == 0xa /* '\n' */ )) {
			match('\\' /* charlit */ );
			match('\n' /* charlit */ );
		}
		else {
			throw ANTLR_USE_NAMESPACE(antlr)NoViableAltForCharException(LA(1), getFilename(), getLine(), getColumn());
		}
		
		}
		if ( inputState->guessing==0 ) {
#line 2658 "CPP_parser.g"
			printf("CPP_parser.g continuation line detected on line %d\n",lineNo);
							deferredNewline();
#line 1180 "CPPLexer.cpp"
		}
		break;
	}
	default:
	{
		throw ANTLR_USE_NAMESPACE(antlr)NoViableAltForCharException(LA(1), getFilename(), getLine(), getColumn());
	}
	}
	}
	if ( inputState->guessing==0 ) {
#line 2661 "CPP_parser.g"
		_ttype = ANTLR_USE_NAMESPACE(antlr)Token::SKIP;
#line 1193 "CPPLexer.cpp"
	}
	if ( _createToken && _token==ANTLR_USE_NAMESPACE(antlr)nullToken && _ttype!=ANTLR_USE_NAMESPACE(antlr)Token::SKIP ) {
	   _token = makeToken(_ttype);
	   _token->setText(text.substr(_begin, text.length()-_begin));
	}
	_returnToken = _token;
	_saveIndex=0;
}

void CPPLexer::mSpace(bool _createToken) {
	int _ttype; ANTLR_USE_NAMESPACE(antlr)RefToken _token; ANTLR_USE_NAMESPACE(std)string::size_type _begin = text.length();
	_ttype = Space;
	ANTLR_USE_NAMESPACE(std)string::size_type _saveIndex;
	
	{
	switch ( LA(1)) {
	case 0x20 /* ' ' */ :
	{
		match(' ' /* charlit */ );
		break;
	}
	case 0x9 /* '\t' */ :
	{
		match('\t' /* charlit */ );
		if ( inputState->guessing==0 ) {
#line 2705 "CPP_parser.g"
			tab();
#line 1221 "CPPLexer.cpp"
		}
		break;
	}
	case 0xc /* '\14' */ :
	{
		match('\14' /* charlit */ );
		break;
	}
	default:
	{
		throw ANTLR_USE_NAMESPACE(antlr)NoViableAltForCharException(LA(1), getFilename(), getLine(), getColumn());
	}
	}
	}
	if ( _createToken && _token==ANTLR_USE_NAMESPACE(antlr)nullToken && _ttype!=ANTLR_USE_NAMESPACE(antlr)Token::SKIP ) {
	   _token = makeToken(_ttype);
	   _token->setText(text.substr(_begin, text.length()-_begin));
	}
	_returnToken = _token;
	_saveIndex=0;
}

void CPPLexer::mComment(bool _createToken) {
	int _ttype; ANTLR_USE_NAMESPACE(antlr)RefToken _token; ANTLR_USE_NAMESPACE(std)string::size_type _begin = text.length();
	_ttype = Comment;
	ANTLR_USE_NAMESPACE(std)string::size_type _saveIndex;
	
	match("/*");
	{ // ( ... )*
	for (;;) {
		if (((LA(1) == 0x2a /* '*' */ ) && ((LA(2) >= 0x0 /* '\0' */  && LA(2) <= 0xff)) && ((LA(3) >= 0x0 /* '\0' */  && LA(3) <= 0xff)))&&(LA(2) != '/')) {
			match('*' /* charlit */ );
		}
		else if ((LA(1) == 0xa /* '\n' */  || LA(1) == 0xd /* '\r' */ )) {
			mEndOfLine(false);
			if ( inputState->guessing==0 ) {
#line 2668 "CPP_parser.g"
				deferredNewline();
#line 1260 "CPPLexer.cpp"
			}
		}
		else if ((_tokenSet_3.member(LA(1)))) {
			{
			match(_tokenSet_3);
			}
		}
		else {
			goto _loop660;
		}
		
	}
	_loop660:;
	} // ( ... )*
	match("*/");
	if ( inputState->guessing==0 ) {
#line 2671 "CPP_parser.g"
		_ttype = ANTLR_USE_NAMESPACE(antlr)Token::SKIP;
#line 1279 "CPPLexer.cpp"
	}
	if ( _createToken && _token==ANTLR_USE_NAMESPACE(antlr)nullToken && _ttype!=ANTLR_USE_NAMESPACE(antlr)Token::SKIP ) {
	   _token = makeToken(_ttype);
	   _token->setText(text.substr(_begin, text.length()-_begin));
	}
	_returnToken = _token;
	_saveIndex=0;
}

void CPPLexer::mEndOfLine(bool _createToken) {
	int _ttype; ANTLR_USE_NAMESPACE(antlr)RefToken _token; ANTLR_USE_NAMESPACE(std)string::size_type _begin = text.length();
	_ttype = EndOfLine;
	ANTLR_USE_NAMESPACE(std)string::size_type _saveIndex;
	
	{
	if ((LA(1) == 0xd /* '\r' */ ) && (LA(2) == 0xa /* '\n' */ ) && (true)) {
		match("\r\n");
	}
	else if ((LA(1) == 0xd /* '\r' */ ) && (true) && (true)) {
		match('\r' /* charlit */ );
	}
	else if ((LA(1) == 0xa /* '\n' */ )) {
		match('\n' /* charlit */ );
	}
	else {
		throw ANTLR_USE_NAMESPACE(antlr)NoViableAltForCharException(LA(1), getFilename(), getLine(), getColumn());
	}
	
	}
	if ( _createToken && _token==ANTLR_USE_NAMESPACE(antlr)nullToken && _ttype!=ANTLR_USE_NAMESPACE(antlr)Token::SKIP ) {
	   _token = makeToken(_ttype);
	   _token->setText(text.substr(_begin, text.length()-_begin));
	}
	_returnToken = _token;
	_saveIndex=0;
}

void CPPLexer::mCPPComment(bool _createToken) {
	int _ttype; ANTLR_USE_NAMESPACE(antlr)RefToken _token; ANTLR_USE_NAMESPACE(std)string::size_type _begin = text.length();
	_ttype = CPPComment;
	ANTLR_USE_NAMESPACE(std)string::size_type _saveIndex;
	
	match("//");
	{ // ( ... )*
	for (;;) {
		if ((_tokenSet_4.member(LA(1)))) {
			{
			match(_tokenSet_4);
			}
		}
		else {
			goto _loop664;
		}
		
	}
	_loop664:;
	} // ( ... )*
	mEndOfLine(false);
	if ( inputState->guessing==0 ) {
#line 2677 "CPP_parser.g"
		_ttype = ANTLR_USE_NAMESPACE(antlr)Token::SKIP; newline();
#line 1341 "CPPLexer.cpp"
	}
	if ( _createToken && _token==ANTLR_USE_NAMESPACE(antlr)nullToken && _ttype!=ANTLR_USE_NAMESPACE(antlr)Token::SKIP ) {
	   _token = makeToken(_ttype);
	   _token->setText(text.substr(_begin, text.length()-_begin));
	}
	_returnToken = _token;
	_saveIndex=0;
}

void CPPLexer::mPREPROC_DIRECTIVE(bool _createToken) {
	int _ttype; ANTLR_USE_NAMESPACE(antlr)RefToken _token; ANTLR_USE_NAMESPACE(std)string::size_type _begin = text.length();
	_ttype = PREPROC_DIRECTIVE;
	ANTLR_USE_NAMESPACE(std)string::size_type _saveIndex;
	
	match('#' /* charlit */ );
	mLineDirective(false);
	if ( inputState->guessing==0 ) {
#line 2684 "CPP_parser.g"
		_ttype = ANTLR_USE_NAMESPACE(antlr)Token::SKIP; newline();
#line 1361 "CPPLexer.cpp"
	}
	if ( _createToken && _token==ANTLR_USE_NAMESPACE(antlr)nullToken && _ttype!=ANTLR_USE_NAMESPACE(antlr)Token::SKIP ) {
	   _token = makeToken(_ttype);
	   _token->setText(text.substr(_begin, text.length()-_begin));
	}
	_returnToken = _token;
	_saveIndex=0;
}

void CPPLexer::mLineDirective(bool _createToken) {
	int _ttype; ANTLR_USE_NAMESPACE(antlr)RefToken _token; ANTLR_USE_NAMESPACE(std)string::size_type _begin = text.length();
	_ttype = LineDirective;
	ANTLR_USE_NAMESPACE(std)string::size_type _saveIndex;
	ANTLR_USE_NAMESPACE(antlr)RefToken n;
	ANTLR_USE_NAMESPACE(antlr)RefToken sl;
	
	{
	switch ( LA(1)) {
	case 0x6c /* 'l' */ :
	{
		match("line");
		break;
	}
	case 0x9 /* '\t' */ :
	case 0xc /* '\14' */ :
	case 0x20 /* ' ' */ :
	{
		break;
	}
	default:
	{
		throw ANTLR_USE_NAMESPACE(antlr)NoViableAltForCharException(LA(1), getFilename(), getLine(), getColumn());
	}
	}
	}
	{ // ( ... )+
	int _cnt669=0;
	for (;;) {
		if ((LA(1) == 0x9 /* '\t' */  || LA(1) == 0xc /* '\14' */  || LA(1) == 0x20 /* ' ' */ )) {
			mSpace(false);
		}
		else {
			if ( _cnt669>=1 ) { goto _loop669; } else {throw ANTLR_USE_NAMESPACE(antlr)NoViableAltForCharException(LA(1), getFilename(), getLine(), getColumn());}
		}
		
		_cnt669++;
	}
	_loop669:;
	}  // ( ... )+
	mDecimal(true);
	n=_returnToken;
	{ // ( ... )+
	int _cnt671=0;
	for (;;) {
		if ((LA(1) == 0x9 /* '\t' */  || LA(1) == 0xc /* '\14' */  || LA(1) == 0x20 /* ' ' */ )) {
			mSpace(false);
		}
		else {
			if ( _cnt671>=1 ) { goto _loop671; } else {throw ANTLR_USE_NAMESPACE(antlr)NoViableAltForCharException(LA(1), getFilename(), getLine(), getColumn());}
		}
		
		_cnt671++;
	}
	_loop671:;
	}  // ( ... )+
	{
	mStringLiteral(true);
	sl=_returnToken;
	}
	{ // ( ... )*
	for (;;) {
		if ((LA(1) == 0x9 /* '\t' */  || LA(1) == 0xc /* '\14' */  || LA(1) == 0x20 /* ' ' */ )) {
			{ // ( ... )+
			int _cnt675=0;
			for (;;) {
				if ((LA(1) == 0x9 /* '\t' */  || LA(1) == 0xc /* '\14' */  || LA(1) == 0x20 /* ' ' */ )) {
					mSpace(false);
				}
				else {
					if ( _cnt675>=1 ) { goto _loop675; } else {throw ANTLR_USE_NAMESPACE(antlr)NoViableAltForCharException(LA(1), getFilename(), getLine(), getColumn());}
				}
				
				_cnt675++;
			}
			_loop675:;
			}  // ( ... )+
			mDecimal(false);
		}
		else {
			goto _loop676;
		}
		
	}
	_loop676:;
	} // ( ... )*
	if ( inputState->guessing==0 ) {
#line 2696 "CPP_parser.g"
		
				process_line_directive((sl->getText()).data(), (n->getText()).data());  // see main()
				
#line 1462 "CPPLexer.cpp"
	}
	mEndOfLine(false);
	if ( _createToken && _token==ANTLR_USE_NAMESPACE(antlr)nullToken && _ttype!=ANTLR_USE_NAMESPACE(antlr)Token::SKIP ) {
	   _token = makeToken(_ttype);
	   _token->setText(text.substr(_begin, text.length()-_begin));
	}
	_returnToken = _token;
	_saveIndex=0;
}

void CPPLexer::mDecimal(bool _createToken) {
	int _ttype; ANTLR_USE_NAMESPACE(antlr)RefToken _token; ANTLR_USE_NAMESPACE(std)string::size_type _begin = text.length();
	_ttype = Decimal;
	ANTLR_USE_NAMESPACE(std)string::size_type _saveIndex;
	
	{ // ( ... )+
	int _cnt718=0;
	for (;;) {
		if (((LA(1) >= 0x30 /* '0' */  && LA(1) <= 0x39 /* '9' */ ))) {
			matchRange('0','9');
		}
		else {
			if ( _cnt718>=1 ) { goto _loop718; } else {throw ANTLR_USE_NAMESPACE(antlr)NoViableAltForCharException(LA(1), getFilename(), getLine(), getColumn());}
		}
		
		_cnt718++;
	}
	_loop718:;
	}  // ( ... )+
	if ( _createToken && _token==ANTLR_USE_NAMESPACE(antlr)nullToken && _ttype!=ANTLR_USE_NAMESPACE(antlr)Token::SKIP ) {
	   _token = makeToken(_ttype);
	   _token->setText(text.substr(_begin, text.length()-_begin));
	}
	_returnToken = _token;
	_saveIndex=0;
}

void CPPLexer::mStringLiteral(bool _createToken) {
	int _ttype; ANTLR_USE_NAMESPACE(antlr)RefToken _token; ANTLR_USE_NAMESPACE(std)string::size_type _begin = text.length();
	_ttype = StringLiteral;
	ANTLR_USE_NAMESPACE(std)string::size_type _saveIndex;
	
	match('\"' /* charlit */ );
	{ // ( ... )*
	for (;;) {
		if ((LA(1) == 0x5c /* '\\' */ ) && (_tokenSet_5.member(LA(2)))) {
			mEscape(false);
		}
		else if ((LA(1) == 0x5c /* '\\' */ ) && (LA(2) == 0x55 /* 'U' */  || LA(2) == 0x75 /* 'u' */ )) {
			mUniversalCharacterName(false);
		}
		else if ((_tokenSet_6.member(LA(1)))) {
			{
			match(_tokenSet_6);
			}
		}
		else {
			goto _loop700;
		}
		
	}
	_loop700:;
	} // ( ... )*
	match('\"' /* charlit */ );
	if ( _createToken && _token==ANTLR_USE_NAMESPACE(antlr)nullToken && _ttype!=ANTLR_USE_NAMESPACE(antlr)Token::SKIP ) {
	   _token = makeToken(_ttype);
	   _token->setText(text.substr(_begin, text.length()-_begin));
	}
	_returnToken = _token;
	_saveIndex=0;
}

void CPPLexer::mPragma(bool _createToken) {
	int _ttype; ANTLR_USE_NAMESPACE(antlr)RefToken _token; ANTLR_USE_NAMESPACE(std)string::size_type _begin = text.length();
	_ttype = Pragma;
	ANTLR_USE_NAMESPACE(std)string::size_type _saveIndex;
	
	{
	match('#' /* charlit */ );
	match("pragma");
	{ // ( ... )*
	for (;;) {
		bool synPredMatched683 = false;
		if (((LA(1) == 0x5c /* '\\' */ ) && (LA(2) == 0xa /* '\n' */  || LA(2) == 0xd /* '\r' */ ) && ((LA(3) >= 0x0 /* '\0' */  && LA(3) <= 0xff)))) {
			int _m683 = mark();
			synPredMatched683 = true;
			inputState->guessing++;
			try {
				{
				mEndOfContinuedLine(false);
				}
			}
			catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& pe) {
				synPredMatched683 = false;
			}
			rewind(_m683);
			inputState->guessing--;
		}
		if ( synPredMatched683 ) {
			mEndOfContinuedLine(false);
		}
		else if ((_tokenSet_4.member(LA(1))) && ((LA(2) >= 0x0 /* '\0' */  && LA(2) <= 0xff)) && (true)) {
			{
			match(_tokenSet_4);
			}
		}
		else {
			goto _loop685;
		}
		
	}
	_loop685:;
	} // ( ... )*
	mEndOfLine(false);
	}
	if ( inputState->guessing==0 ) {
#line 2714 "CPP_parser.g"
		_ttype = ANTLR_USE_NAMESPACE(antlr)Token::SKIP; newline();
#line 1581 "CPPLexer.cpp"
	}
	if ( _createToken && _token==ANTLR_USE_NAMESPACE(antlr)nullToken && _ttype!=ANTLR_USE_NAMESPACE(antlr)Token::SKIP ) {
	   _token = makeToken(_ttype);
	   _token->setText(text.substr(_begin, text.length()-_begin));
	}
	_returnToken = _token;
	_saveIndex=0;
}

void CPPLexer::mEndOfContinuedLine(bool _createToken) {
	int _ttype; ANTLR_USE_NAMESPACE(antlr)RefToken _token; ANTLR_USE_NAMESPACE(std)string::size_type _begin = text.length();
	_ttype = EndOfContinuedLine;
	ANTLR_USE_NAMESPACE(std)string::size_type _saveIndex;
	
	{
	if ((LA(1) == 0x5c /* '\\' */ ) && (LA(2) == 0xd /* '\r' */ ) && (LA(3) == 0xa /* '\n' */ )) {
		match('\\' /* charlit */ );
		match('\r' /* charlit */ );
		match('\n' /* charlit */ );
	}
	else if ((LA(1) == 0x5c /* '\\' */ ) && (LA(2) == 0xd /* '\r' */ ) && ((LA(3) >= 0x0 /* '\0' */  && LA(3) <= 0xff))) {
		match('\\' /* charlit */ );
		match('\r' /* charlit */ );
	}
	else if ((LA(1) == 0x5c /* '\\' */ ) && (LA(2) == 0xa /* '\n' */ )) {
		match('\\' /* charlit */ );
		match('\n' /* charlit */ );
	}
	else {
		throw ANTLR_USE_NAMESPACE(antlr)NoViableAltForCharException(LA(1), getFilename(), getLine(), getColumn());
	}
	
	}
	if ( inputState->guessing==0 ) {
#line 2773 "CPP_parser.g"
		deferredNewline();
#line 1618 "CPPLexer.cpp"
	}
	if ( _createToken && _token==ANTLR_USE_NAMESPACE(antlr)nullToken && _ttype!=ANTLR_USE_NAMESPACE(antlr)Token::SKIP ) {
	   _token = makeToken(_ttype);
	   _token->setText(text.substr(_begin, text.length()-_begin));
	}
	_returnToken = _token;
	_saveIndex=0;
}

void CPPLexer::mError(bool _createToken) {
	int _ttype; ANTLR_USE_NAMESPACE(antlr)RefToken _token; ANTLR_USE_NAMESPACE(std)string::size_type _begin = text.length();
	_ttype = Error;
	ANTLR_USE_NAMESPACE(std)string::size_type _saveIndex;
	
	{
	match('#' /* charlit */ );
	match("error");
	{ // ( ... )*
	for (;;) {
		bool synPredMatched690 = false;
		if (((LA(1) == 0x5c /* '\\' */ ) && (LA(2) == 0xa /* '\n' */  || LA(2) == 0xd /* '\r' */ ) && ((LA(3) >= 0x0 /* '\0' */  && LA(3) <= 0xff)))) {
			int _m690 = mark();
			synPredMatched690 = true;
			inputState->guessing++;
			try {
				{
				mEndOfContinuedLine(false);
				}
			}
			catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& pe) {
				synPredMatched690 = false;
			}
			rewind(_m690);
			inputState->guessing--;
		}
		if ( synPredMatched690 ) {
			mEndOfContinuedLine(false);
		}
		else if ((_tokenSet_4.member(LA(1))) && ((LA(2) >= 0x0 /* '\0' */  && LA(2) <= 0xff)) && (true)) {
			{
			match(_tokenSet_4);
			}
		}
		else {
			goto _loop692;
		}
		
	}
	_loop692:;
	} // ( ... )*
	mEndOfLine(false);
	}
	if ( inputState->guessing==0 ) {
#line 2723 "CPP_parser.g"
		_ttype = ANTLR_USE_NAMESPACE(antlr)Token::SKIP; newline();
#line 1674 "CPPLexer.cpp"
	}
	if ( _createToken && _token==ANTLR_USE_NAMESPACE(antlr)nullToken && _ttype!=ANTLR_USE_NAMESPACE(antlr)Token::SKIP ) {
	   _token = makeToken(_ttype);
	   _token->setText(text.substr(_begin, text.length()-_begin));
	}
	_returnToken = _token;
	_saveIndex=0;
}

void CPPLexer::mCharLiteral(bool _createToken) {
	int _ttype; ANTLR_USE_NAMESPACE(antlr)RefToken _token; ANTLR_USE_NAMESPACE(std)string::size_type _begin = text.length();
	_ttype = CharLiteral;
	ANTLR_USE_NAMESPACE(std)string::size_type _saveIndex;
	
	match('\'' /* charlit */ );
	{
	if ((LA(1) == 0x5c /* '\\' */ ) && (_tokenSet_5.member(LA(2)))) {
		mEscape(false);
	}
	else if ((LA(1) == 0x5c /* '\\' */ ) && (LA(2) == 0x55 /* 'U' */  || LA(2) == 0x75 /* 'u' */ )) {
		mUniversalCharacterName(false);
	}
	else if ((_tokenSet_7.member(LA(1)))) {
		{
		match(_tokenSet_7);
		}
	}
	else {
		throw ANTLR_USE_NAMESPACE(antlr)NoViableAltForCharException(LA(1), getFilename(), getLine(), getColumn());
	}
	
	}
	match('\'' /* charlit */ );
	if ( _createToken && _token==ANTLR_USE_NAMESPACE(antlr)nullToken && _ttype!=ANTLR_USE_NAMESPACE(antlr)Token::SKIP ) {
	   _token = makeToken(_ttype);
	   _token->setText(text.substr(_begin, text.length()-_begin));
	}
	_returnToken = _token;
	_saveIndex=0;
}

void CPPLexer::mEscape(bool _createToken) {
	int _ttype; ANTLR_USE_NAMESPACE(antlr)RefToken _token; ANTLR_USE_NAMESPACE(std)string::size_type _begin = text.length();
	_ttype = Escape;
	ANTLR_USE_NAMESPACE(std)string::size_type _saveIndex;
	
	match('\\' /* charlit */ );
	{
	switch ( LA(1)) {
	case 0x61 /* 'a' */ :
	{
		match('a' /* charlit */ );
		break;
	}
	case 0x62 /* 'b' */ :
	{
		match('b' /* charlit */ );
		break;
	}
	case 0x66 /* 'f' */ :
	{
		match('f' /* charlit */ );
		break;
	}
	case 0x6e /* 'n' */ :
	{
		match('n' /* charlit */ );
		break;
	}
	case 0x72 /* 'r' */ :
	{
		match('r' /* charlit */ );
		break;
	}
	case 0x74 /* 't' */ :
	{
		match('t' /* charlit */ );
		break;
	}
	case 0x76 /* 'v' */ :
	{
		match('v' /* charlit */ );
		break;
	}
	case 0x22 /* '\"' */ :
	{
		match('\"' /* charlit */ );
		break;
	}
	case 0x27 /* '\'' */ :
	{
		match('\'' /* charlit */ );
		break;
	}
	case 0x5c /* '\\' */ :
	{
		match('\\' /* charlit */ );
		break;
	}
	case 0x3f /* '?' */ :
	{
		match('?' /* charlit */ );
		break;
	}
	case 0x30 /* '0' */ :
	case 0x31 /* '1' */ :
	case 0x32 /* '2' */ :
	case 0x33 /* '3' */ :
	{
		{
		matchRange('0','3');
		}
		{
		if (((LA(1) >= 0x30 /* '0' */  && LA(1) <= 0x39 /* '9' */ )) && (_tokenSet_4.member(LA(2))) && (true)) {
			mDigit(false);
			{
			if (((LA(1) >= 0x30 /* '0' */  && LA(1) <= 0x39 /* '9' */ )) && (_tokenSet_4.member(LA(2))) && (true)) {
				mDigit(false);
			}
			else if ((_tokenSet_4.member(LA(1))) && (true) && (true)) {
			}
			else {
				throw ANTLR_USE_NAMESPACE(antlr)NoViableAltForCharException(LA(1), getFilename(), getLine(), getColumn());
			}
			
			}
		}
		else if ((_tokenSet_4.member(LA(1))) && (true) && (true)) {
		}
		else {
			throw ANTLR_USE_NAMESPACE(antlr)NoViableAltForCharException(LA(1), getFilename(), getLine(), getColumn());
		}
		
		}
		break;
	}
	case 0x34 /* '4' */ :
	case 0x35 /* '5' */ :
	case 0x36 /* '6' */ :
	case 0x37 /* '7' */ :
	{
		{
		matchRange('4','7');
		}
		{
		if (((LA(1) >= 0x30 /* '0' */  && LA(1) <= 0x39 /* '9' */ )) && (_tokenSet_4.member(LA(2))) && (true)) {
			mDigit(false);
		}
		else if ((_tokenSet_4.member(LA(1))) && (true) && (true)) {
		}
		else {
			throw ANTLR_USE_NAMESPACE(antlr)NoViableAltForCharException(LA(1), getFilename(), getLine(), getColumn());
		}
		
		}
		break;
	}
	case 0x78 /* 'x' */ :
	{
		match('x' /* charlit */ );
		{ // ( ... )+
		int _cnt714=0;
		for (;;) {
			if ((_tokenSet_8.member(LA(1))) && (_tokenSet_4.member(LA(2))) && (true)) {
				mHexadecimalDigit(false);
			}
			else {
				if ( _cnt714>=1 ) { goto _loop714; } else {throw ANTLR_USE_NAMESPACE(antlr)NoViableAltForCharException(LA(1), getFilename(), getLine(), getColumn());}
			}
			
			_cnt714++;
		}
		_loop714:;
		}  // ( ... )+
		break;
	}
	default:
	{
		throw ANTLR_USE_NAMESPACE(antlr)NoViableAltForCharException(LA(1), getFilename(), getLine(), getColumn());
	}
	}
	}
	if ( _createToken && _token==ANTLR_USE_NAMESPACE(antlr)nullToken && _ttype!=ANTLR_USE_NAMESPACE(antlr)Token::SKIP ) {
	   _token = makeToken(_ttype);
	   _token->setText(text.substr(_begin, text.length()-_begin));
	}
	_returnToken = _token;
	_saveIndex=0;
}

void CPPLexer::mUniversalCharacterName(bool _createToken) {
	int _ttype; ANTLR_USE_NAMESPACE(antlr)RefToken _token; ANTLR_USE_NAMESPACE(std)string::size_type _begin = text.length();
	_ttype = UniversalCharacterName;
	ANTLR_USE_NAMESPACE(std)string::size_type _saveIndex;
	
	if ((LA(1) == 0x5c /* '\\' */ ) && (LA(2) == 0x75 /* 'u' */ )) {
		match("\\u");
		mHexQuad(false);
	}
	else if ((LA(1) == 0x5c /* '\\' */ ) && (LA(2) == 0x55 /* 'U' */ )) {
		match("\\U");
		mHexQuad(false);
		mHexQuad(false);
	}
	else {
		throw ANTLR_USE_NAMESPACE(antlr)NoViableAltForCharException(LA(1), getFilename(), getLine(), getColumn());
	}
	
	if ( _createToken && _token==ANTLR_USE_NAMESPACE(antlr)nullToken && _ttype!=ANTLR_USE_NAMESPACE(antlr)Token::SKIP ) {
	   _token = makeToken(_ttype);
	   _token->setText(text.substr(_begin, text.length()-_begin));
	}
	_returnToken = _token;
	_saveIndex=0;
}

void CPPLexer::mWCharLiteral(bool _createToken) {
	int _ttype; ANTLR_USE_NAMESPACE(antlr)RefToken _token; ANTLR_USE_NAMESPACE(std)string::size_type _begin = text.length();
	_ttype = WCharLiteral;
	ANTLR_USE_NAMESPACE(std)string::size_type _saveIndex;
	
	match('L' /* charlit */ );
	mCharLiteral(false);
	if ( _createToken && _token==ANTLR_USE_NAMESPACE(antlr)nullToken && _ttype!=ANTLR_USE_NAMESPACE(antlr)Token::SKIP ) {
	   _token = makeToken(_ttype);
	   _token->setText(text.substr(_begin, text.length()-_begin));
	}
	_returnToken = _token;
	_saveIndex=0;
}

void CPPLexer::mWStringLiteral(bool _createToken) {
	int _ttype; ANTLR_USE_NAMESPACE(antlr)RefToken _token; ANTLR_USE_NAMESPACE(std)string::size_type _begin = text.length();
	_ttype = WStringLiteral;
	ANTLR_USE_NAMESPACE(std)string::size_type _saveIndex;
	
	match('L' /* charlit */ );
	mStringLiteral(false);
	if ( _createToken && _token==ANTLR_USE_NAMESPACE(antlr)nullToken && _ttype!=ANTLR_USE_NAMESPACE(antlr)Token::SKIP ) {
	   _token = makeToken(_ttype);
	   _token->setText(text.substr(_begin, text.length()-_begin));
	}
	_returnToken = _token;
	_saveIndex=0;
}

void CPPLexer::mDigit(bool _createToken) {
	int _ttype; ANTLR_USE_NAMESPACE(antlr)RefToken _token; ANTLR_USE_NAMESPACE(std)string::size_type _begin = text.length();
	_ttype = Digit;
	ANTLR_USE_NAMESPACE(std)string::size_type _saveIndex;
	
	matchRange('0','9');
	if ( _createToken && _token==ANTLR_USE_NAMESPACE(antlr)nullToken && _ttype!=ANTLR_USE_NAMESPACE(antlr)Token::SKIP ) {
	   _token = makeToken(_ttype);
	   _token->setText(text.substr(_begin, text.length()-_begin));
	}
	_returnToken = _token;
	_saveIndex=0;
}

void CPPLexer::mHexadecimalDigit(bool _createToken) {
	int _ttype; ANTLR_USE_NAMESPACE(antlr)RefToken _token; ANTLR_USE_NAMESPACE(std)string::size_type _begin = text.length();
	_ttype = HexadecimalDigit;
	ANTLR_USE_NAMESPACE(std)string::size_type _saveIndex;
	
	{
	switch ( LA(1)) {
	case 0x30 /* '0' */ :
	case 0x31 /* '1' */ :
	case 0x32 /* '2' */ :
	case 0x33 /* '3' */ :
	case 0x34 /* '4' */ :
	case 0x35 /* '5' */ :
	case 0x36 /* '6' */ :
	case 0x37 /* '7' */ :
	case 0x38 /* '8' */ :
	case 0x39 /* '9' */ :
	{
		matchRange('0','9');
		break;
	}
	case 0x61 /* 'a' */ :
	case 0x62 /* 'b' */ :
	case 0x63 /* 'c' */ :
	case 0x64 /* 'd' */ :
	case 0x65 /* 'e' */ :
	case 0x66 /* 'f' */ :
	{
		matchRange('a','f');
		break;
	}
	case 0x41 /* 'A' */ :
	case 0x42 /* 'B' */ :
	case 0x43 /* 'C' */ :
	case 0x44 /* 'D' */ :
	case 0x45 /* 'E' */ :
	case 0x46 /* 'F' */ :
	{
		matchRange('A','F');
		break;
	}
	default:
	{
		throw ANTLR_USE_NAMESPACE(antlr)NoViableAltForCharException(LA(1), getFilename(), getLine(), getColumn());
	}
	}
	}
	if ( _createToken && _token==ANTLR_USE_NAMESPACE(antlr)nullToken && _ttype!=ANTLR_USE_NAMESPACE(antlr)Token::SKIP ) {
	   _token = makeToken(_ttype);
	   _token->setText(text.substr(_begin, text.length()-_begin));
	}
	_returnToken = _token;
	_saveIndex=0;
}

void CPPLexer::mLongSuffix(bool _createToken) {
	int _ttype; ANTLR_USE_NAMESPACE(antlr)RefToken _token; ANTLR_USE_NAMESPACE(std)string::size_type _begin = text.length();
	_ttype = LongSuffix;
	ANTLR_USE_NAMESPACE(std)string::size_type _saveIndex;
	
	switch ( LA(1)) {
	case 0x6c /* 'l' */ :
	{
		match('l' /* charlit */ );
		break;
	}
	case 0x4c /* 'L' */ :
	{
		match('L' /* charlit */ );
		break;
	}
	default:
	{
		throw ANTLR_USE_NAMESPACE(antlr)NoViableAltForCharException(LA(1), getFilename(), getLine(), getColumn());
	}
	}
	if ( _createToken && _token==ANTLR_USE_NAMESPACE(antlr)nullToken && _ttype!=ANTLR_USE_NAMESPACE(antlr)Token::SKIP ) {
	   _token = makeToken(_ttype);
	   _token->setText(text.substr(_begin, text.length()-_begin));
	}
	_returnToken = _token;
	_saveIndex=0;
}

void CPPLexer::mUnsignedSuffix(bool _createToken) {
	int _ttype; ANTLR_USE_NAMESPACE(antlr)RefToken _token; ANTLR_USE_NAMESPACE(std)string::size_type _begin = text.length();
	_ttype = UnsignedSuffix;
	ANTLR_USE_NAMESPACE(std)string::size_type _saveIndex;
	
	switch ( LA(1)) {
	case 0x75 /* 'u' */ :
	{
		match('u' /* charlit */ );
		break;
	}
	case 0x55 /* 'U' */ :
	{
		match('U' /* charlit */ );
		break;
	}
	default:
	{
		throw ANTLR_USE_NAMESPACE(antlr)NoViableAltForCharException(LA(1), getFilename(), getLine(), getColumn());
	}
	}
	if ( _createToken && _token==ANTLR_USE_NAMESPACE(antlr)nullToken && _ttype!=ANTLR_USE_NAMESPACE(antlr)Token::SKIP ) {
	   _token = makeToken(_ttype);
	   _token->setText(text.substr(_begin, text.length()-_begin));
	}
	_returnToken = _token;
	_saveIndex=0;
}

void CPPLexer::mFloatSuffix(bool _createToken) {
	int _ttype; ANTLR_USE_NAMESPACE(antlr)RefToken _token; ANTLR_USE_NAMESPACE(std)string::size_type _begin = text.length();
	_ttype = FloatSuffix;
	ANTLR_USE_NAMESPACE(std)string::size_type _saveIndex;
	
	switch ( LA(1)) {
	case 0x66 /* 'f' */ :
	{
		match('f' /* charlit */ );
		break;
	}
	case 0x46 /* 'F' */ :
	{
		match('F' /* charlit */ );
		break;
	}
	default:
	{
		throw ANTLR_USE_NAMESPACE(antlr)NoViableAltForCharException(LA(1), getFilename(), getLine(), getColumn());
	}
	}
	if ( _createToken && _token==ANTLR_USE_NAMESPACE(antlr)nullToken && _ttype!=ANTLR_USE_NAMESPACE(antlr)Token::SKIP ) {
	   _token = makeToken(_ttype);
	   _token->setText(text.substr(_begin, text.length()-_begin));
	}
	_returnToken = _token;
	_saveIndex=0;
}

void CPPLexer::mExponent(bool _createToken) {
	int _ttype; ANTLR_USE_NAMESPACE(antlr)RefToken _token; ANTLR_USE_NAMESPACE(std)string::size_type _begin = text.length();
	_ttype = Exponent;
	ANTLR_USE_NAMESPACE(std)string::size_type _saveIndex;
	
	{
	switch ( LA(1)) {
	case 0x65 /* 'e' */ :
	{
		match('e' /* charlit */ );
		break;
	}
	case 0x45 /* 'E' */ :
	{
		match('E' /* charlit */ );
		break;
	}
	default:
	{
		throw ANTLR_USE_NAMESPACE(antlr)NoViableAltForCharException(LA(1), getFilename(), getLine(), getColumn());
	}
	}
	}
	{
	switch ( LA(1)) {
	case 0x2b /* '+' */ :
	{
		match('+' /* charlit */ );
		break;
	}
	case 0x2d /* '-' */ :
	{
		match('-' /* charlit */ );
		break;
	}
	case 0x30 /* '0' */ :
	case 0x31 /* '1' */ :
	case 0x32 /* '2' */ :
	case 0x33 /* '3' */ :
	case 0x34 /* '4' */ :
	case 0x35 /* '5' */ :
	case 0x36 /* '6' */ :
	case 0x37 /* '7' */ :
	case 0x38 /* '8' */ :
	case 0x39 /* '9' */ :
	{
		break;
	}
	default:
	{
		throw ANTLR_USE_NAMESPACE(antlr)NoViableAltForCharException(LA(1), getFilename(), getLine(), getColumn());
	}
	}
	}
	{ // ( ... )+
	int _cnt726=0;
	for (;;) {
		if (((LA(1) >= 0x30 /* '0' */  && LA(1) <= 0x39 /* '9' */ ))) {
			mDigit(false);
		}
		else {
			if ( _cnt726>=1 ) { goto _loop726; } else {throw ANTLR_USE_NAMESPACE(antlr)NoViableAltForCharException(LA(1), getFilename(), getLine(), getColumn());}
		}
		
		_cnt726++;
	}
	_loop726:;
	}  // ( ... )+
	if ( _createToken && _token==ANTLR_USE_NAMESPACE(antlr)nullToken && _ttype!=ANTLR_USE_NAMESPACE(antlr)Token::SKIP ) {
	   _token = makeToken(_ttype);
	   _token->setText(text.substr(_begin, text.length()-_begin));
	}
	_returnToken = _token;
	_saveIndex=0;
}

void CPPLexer::mHexQuad(bool _createToken) {
	int _ttype; ANTLR_USE_NAMESPACE(antlr)RefToken _token; ANTLR_USE_NAMESPACE(std)string::size_type _begin = text.length();
	_ttype = HexQuad;
	ANTLR_USE_NAMESPACE(std)string::size_type _saveIndex;
	
	mHexadecimalDigit(false);
	mHexadecimalDigit(false);
	mHexadecimalDigit(false);
	mHexadecimalDigit(false);
	if ( _createToken && _token==ANTLR_USE_NAMESPACE(antlr)nullToken && _ttype!=ANTLR_USE_NAMESPACE(antlr)Token::SKIP ) {
	   _token = makeToken(_ttype);
	   _token->setText(text.substr(_begin, text.length()-_begin));
	}
	_returnToken = _token;
	_saveIndex=0;
}

void CPPLexer::mVocabulary(bool _createToken) {
	int _ttype; ANTLR_USE_NAMESPACE(antlr)RefToken _token; ANTLR_USE_NAMESPACE(std)string::size_type _begin = text.length();
	_ttype = Vocabulary;
	ANTLR_USE_NAMESPACE(std)string::size_type _saveIndex;
	
	matchRange('\3',static_cast<unsigned char>('\377'));
	if ( _createToken && _token==ANTLR_USE_NAMESPACE(antlr)nullToken && _ttype!=ANTLR_USE_NAMESPACE(antlr)Token::SKIP ) {
	   _token = makeToken(_ttype);
	   _token->setText(text.substr(_begin, text.length()-_begin));
	}
	_returnToken = _token;
	_saveIndex=0;
}

void CPPLexer::mNumber(bool _createToken) {
	int _ttype; ANTLR_USE_NAMESPACE(antlr)RefToken _token; ANTLR_USE_NAMESPACE(std)string::size_type _begin = text.length();
	_ttype = Number;
	ANTLR_USE_NAMESPACE(std)string::size_type _saveIndex;
	
	bool synPredMatched737 = false;
	if ((((LA(1) >= 0x30 /* '0' */  && LA(1) <= 0x39 /* '9' */ )) && (_tokenSet_9.member(LA(2))) && (true))) {
		int _m737 = mark();
		synPredMatched737 = true;
		inputState->guessing++;
		try {
			{
			{ // ( ... )+
			int _cnt735=0;
			for (;;) {
				if (((LA(1) >= 0x30 /* '0' */  && LA(1) <= 0x39 /* '9' */ ))) {
					mDigit(false);
				}
				else {
					if ( _cnt735>=1 ) { goto _loop735; } else {throw ANTLR_USE_NAMESPACE(antlr)NoViableAltForCharException(LA(1), getFilename(), getLine(), getColumn());}
				}
				
				_cnt735++;
			}
			_loop735:;
			}  // ( ... )+
			{
			switch ( LA(1)) {
			case 0x2e /* '.' */ :
			{
				match('.' /* charlit */ );
				break;
			}
			case 0x65 /* 'e' */ :
			{
				match('e' /* charlit */ );
				break;
			}
			case 0x45 /* 'E' */ :
			{
				match('E' /* charlit */ );
				break;
			}
			default:
			{
				throw ANTLR_USE_NAMESPACE(antlr)NoViableAltForCharException(LA(1), getFilename(), getLine(), getColumn());
			}
			}
			}
			}
		}
		catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& pe) {
			synPredMatched737 = false;
		}
		rewind(_m737);
		inputState->guessing--;
	}
	if ( synPredMatched737 ) {
		{ // ( ... )+
		int _cnt739=0;
		for (;;) {
			if (((LA(1) >= 0x30 /* '0' */  && LA(1) <= 0x39 /* '9' */ ))) {
				mDigit(false);
			}
			else {
				if ( _cnt739>=1 ) { goto _loop739; } else {throw ANTLR_USE_NAMESPACE(antlr)NoViableAltForCharException(LA(1), getFilename(), getLine(), getColumn());}
			}
			
			_cnt739++;
		}
		_loop739:;
		}  // ( ... )+
		{
		switch ( LA(1)) {
		case 0x2e /* '.' */ :
		{
			match('.' /* charlit */ );
			{ // ( ... )*
			for (;;) {
				if (((LA(1) >= 0x30 /* '0' */  && LA(1) <= 0x39 /* '9' */ ))) {
					mDigit(false);
				}
				else {
					goto _loop742;
				}
				
			}
			_loop742:;
			} // ( ... )*
			{
			if ((LA(1) == 0x45 /* 'E' */  || LA(1) == 0x65 /* 'e' */ )) {
				mExponent(false);
			}
			else {
			}
			
			}
			if ( inputState->guessing==0 ) {
#line 2894 "CPP_parser.g"
				_ttype = FLOATONE;
#line 2284 "CPPLexer.cpp"
			}
			break;
		}
		case 0x45 /* 'E' */ :
		case 0x65 /* 'e' */ :
		{
			mExponent(false);
			if ( inputState->guessing==0 ) {
#line 2895 "CPP_parser.g"
				_ttype = FLOATTWO;
#line 2295 "CPPLexer.cpp"
			}
			break;
		}
		default:
		{
			throw ANTLR_USE_NAMESPACE(antlr)NoViableAltForCharException(LA(1), getFilename(), getLine(), getColumn());
		}
		}
		}
		{
		switch ( LA(1)) {
		case 0x46 /* 'F' */ :
		case 0x66 /* 'f' */ :
		{
			mFloatSuffix(false);
			break;
		}
		case 0x4c /* 'L' */ :
		case 0x6c /* 'l' */ :
		{
			mLongSuffix(false);
			break;
		}
		default:
			{
			}
		}
		}
	}
	else {
		bool synPredMatched746 = false;
		if (((LA(1) == 0x2e /* '.' */ ) && (LA(2) == 0x2e /* '.' */ ))) {
			int _m746 = mark();
			synPredMatched746 = true;
			inputState->guessing++;
			try {
				{
				match("...");
				}
			}
			catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& pe) {
				synPredMatched746 = false;
			}
			rewind(_m746);
			inputState->guessing--;
		}
		if ( synPredMatched746 ) {
			match("...");
			if ( inputState->guessing==0 ) {
#line 2901 "CPP_parser.g"
				_ttype = ELLIPSIS;
#line 2347 "CPPLexer.cpp"
			}
		}
		else if ((LA(1) == 0x30 /* '0' */ ) && (LA(2) == 0x58 /* 'X' */  || LA(2) == 0x78 /* 'x' */ )) {
			match('0' /* charlit */ );
			{
			switch ( LA(1)) {
			case 0x78 /* 'x' */ :
			{
				match('x' /* charlit */ );
				break;
			}
			case 0x58 /* 'X' */ :
			{
				match('X' /* charlit */ );
				break;
			}
			default:
			{
				throw ANTLR_USE_NAMESPACE(antlr)NoViableAltForCharException(LA(1), getFilename(), getLine(), getColumn());
			}
			}
			}
			{ // ( ... )+
			int _cnt762=0;
			for (;;) {
				if ((_tokenSet_8.member(LA(1)))) {
					mHexadecimalDigit(false);
				}
				else {
					if ( _cnt762>=1 ) { goto _loop762; } else {throw ANTLR_USE_NAMESPACE(antlr)NoViableAltForCharException(LA(1), getFilename(), getLine(), getColumn());}
				}
				
				_cnt762++;
			}
			_loop762:;
			}  // ( ... )+
			{ // ( ... )*
			for (;;) {
				switch ( LA(1)) {
				case 0x4c /* 'L' */ :
				case 0x6c /* 'l' */ :
				{
					mLongSuffix(false);
					break;
				}
				case 0x55 /* 'U' */ :
				case 0x75 /* 'u' */ :
				{
					mUnsignedSuffix(false);
					break;
				}
				default:
				{
					goto _loop764;
				}
				}
			}
			_loop764:;
			} // ( ... )*
			if ( inputState->guessing==0 ) {
#line 2925 "CPP_parser.g"
				_ttype = HEXADECIMALINT;
#line 2410 "CPPLexer.cpp"
			}
		}
		else if ((LA(1) == 0x2e /* '.' */ ) && (true)) {
			match('.' /* charlit */ );
			if ( inputState->guessing==0 ) {
#line 2903 "CPP_parser.g"
				_ttype = DOT;
#line 2418 "CPPLexer.cpp"
			}
			{
			if (((LA(1) >= 0x30 /* '0' */  && LA(1) <= 0x39 /* '9' */ ))) {
				{ // ( ... )+
				int _cnt749=0;
				for (;;) {
					if (((LA(1) >= 0x30 /* '0' */  && LA(1) <= 0x39 /* '9' */ ))) {
						mDigit(false);
					}
					else {
						if ( _cnt749>=1 ) { goto _loop749; } else {throw ANTLR_USE_NAMESPACE(antlr)NoViableAltForCharException(LA(1), getFilename(), getLine(), getColumn());}
					}
					
					_cnt749++;
				}
				_loop749:;
				}  // ( ... )+
				{
				if ((LA(1) == 0x45 /* 'E' */  || LA(1) == 0x65 /* 'e' */ )) {
					mExponent(false);
				}
				else {
				}
				
				}
				if ( inputState->guessing==0 ) {
#line 2904 "CPP_parser.g"
					_ttype = FLOATONE;
#line 2447 "CPPLexer.cpp"
				}
				{
				switch ( LA(1)) {
				case 0x46 /* 'F' */ :
				case 0x66 /* 'f' */ :
				{
					mFloatSuffix(false);
					break;
				}
				case 0x4c /* 'L' */ :
				case 0x6c /* 'l' */ :
				{
					mLongSuffix(false);
					break;
				}
				default:
					{
					}
				}
				}
			}
			else {
			}
			
			}
		}
		else if ((LA(1) == 0x30 /* '0' */ ) && (true) && (true)) {
			match('0' /* charlit */ );
			{ // ( ... )*
			for (;;) {
				if (((LA(1) >= 0x30 /* '0' */  && LA(1) <= 0x37 /* '7' */ ))) {
					matchRange('0','7');
				}
				else {
					goto _loop753;
				}
				
			}
			_loop753:;
			} // ( ... )*
			{ // ( ... )*
			for (;;) {
				switch ( LA(1)) {
				case 0x4c /* 'L' */ :
				case 0x6c /* 'l' */ :
				{
					mLongSuffix(false);
					break;
				}
				case 0x55 /* 'U' */ :
				case 0x75 /* 'u' */ :
				{
					mUnsignedSuffix(false);
					break;
				}
				default:
				{
					goto _loop755;
				}
				}
			}
			_loop755:;
			} // ( ... )*
			if ( inputState->guessing==0 ) {
#line 2914 "CPP_parser.g"
				_ttype = OCTALINT;
#line 2514 "CPPLexer.cpp"
			}
		}
		else if (((LA(1) >= 0x31 /* '1' */  && LA(1) <= 0x39 /* '9' */ )) && (true) && (true)) {
			matchRange('1','9');
			{ // ( ... )*
			for (;;) {
				if (((LA(1) >= 0x30 /* '0' */  && LA(1) <= 0x39 /* '9' */ ))) {
					mDigit(false);
				}
				else {
					goto _loop757;
				}
				
			}
			_loop757:;
			} // ( ... )*
			{ // ( ... )*
			for (;;) {
				switch ( LA(1)) {
				case 0x4c /* 'L' */ :
				case 0x6c /* 'l' */ :
				{
					mLongSuffix(false);
					break;
				}
				case 0x55 /* 'U' */ :
				case 0x75 /* 'u' */ :
				{
					mUnsignedSuffix(false);
					break;
				}
				default:
				{
					goto _loop759;
				}
				}
			}
			_loop759:;
			} // ( ... )*
			if ( inputState->guessing==0 ) {
#line 2919 "CPP_parser.g"
				_ttype = DECIMALINT;
#line 2557 "CPPLexer.cpp"
			}
		}
	else {
		throw ANTLR_USE_NAMESPACE(antlr)NoViableAltForCharException(LA(1), getFilename(), getLine(), getColumn());
	}
	}
	if ( _createToken && _token==ANTLR_USE_NAMESPACE(antlr)nullToken && _ttype!=ANTLR_USE_NAMESPACE(antlr)Token::SKIP ) {
	   _token = makeToken(_ttype);
	   _token->setText(text.substr(_begin, text.length()-_begin));
	}
	_returnToken = _token;
	_saveIndex=0;
}

void CPPLexer::mID(bool _createToken) {
	int _ttype; ANTLR_USE_NAMESPACE(antlr)RefToken _token; ANTLR_USE_NAMESPACE(std)string::size_type _begin = text.length();
	_ttype = ID;
	ANTLR_USE_NAMESPACE(std)string::size_type _saveIndex;
	
	bool synPredMatched768 = false;
	if (((LA(1) == 0x5f /* '_' */  || LA(1) == 0x61 /* 'a' */ ) && (LA(2) == 0x5f /* '_' */  || LA(2) == 0x61 /* 'a' */  || LA(2) == 0x73 /* 's' */ ) && (LA(3) == 0x61 /* 'a' */  || LA(3) == 0x6d /* 'm' */  || LA(3) == 0x73 /* 's' */ ))) {
		int _m768 = mark();
		synPredMatched768 = true;
		inputState->guessing++;
		try {
			{
			{
			if ((LA(1) == 0x5f /* '_' */ ) && (LA(2) == 0x61 /* 'a' */ )) {
				match("_asm");
			}
			else if ((LA(1) == 0x5f /* '_' */ ) && (LA(2) == 0x5f /* '_' */ )) {
				match("__asm");
			}
			else if ((LA(1) == 0x61 /* 'a' */ )) {
				match("asm");
			}
			else {
				throw ANTLR_USE_NAMESPACE(antlr)NoViableAltForCharException(LA(1), getFilename(), getLine(), getColumn());
			}
			
			}
			mWhitespace(false);
			}
		}
		catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& pe) {
			synPredMatched768 = false;
		}
		rewind(_m768);
		inputState->guessing--;
	}
	if ( synPredMatched768 ) {
		{
		if ((LA(1) == 0x5f /* '_' */ ) && (LA(2) == 0x61 /* 'a' */ )) {
			match("_asm");
		}
		else if ((LA(1) == 0x5f /* '_' */ ) && (LA(2) == 0x5f /* '_' */ )) {
			match("__asm");
		}
		else if ((LA(1) == 0x61 /* 'a' */ )) {
			match("asm");
		}
		else {
			throw ANTLR_USE_NAMESPACE(antlr)NoViableAltForCharException(LA(1), getFilename(), getLine(), getColumn());
		}
		
		}
		{ // ( ... )+
		int _cnt771=0;
		for (;;) {
			switch ( LA(1)) {
			case 0xa /* '\n' */ :
			case 0xd /* '\r' */ :
			{
				mEndOfLine(false);
				if ( inputState->guessing==0 ) {
#line 2934 "CPP_parser.g"
					deferredNewline();
#line 2635 "CPPLexer.cpp"
				}
				break;
			}
			case 0x9 /* '\t' */ :
			case 0xc /* '\14' */ :
			case 0x20 /* ' ' */ :
			{
				mSpace(false);
				break;
			}
			default:
			{
				if ( _cnt771>=1 ) { goto _loop771; } else {throw ANTLR_USE_NAMESPACE(antlr)NoViableAltForCharException(LA(1), getFilename(), getLine(), getColumn());}
			}
			}
			_cnt771++;
		}
		_loop771:;
		}  // ( ... )+
		{
		switch ( LA(1)) {
		case 0x28 /* '(' */ :
		{
			mLPAREN(false);
			{ // ( ... )*
			for (;;) {
				if ((LA(1) == 0xa /* '\n' */  || LA(1) == 0xd /* '\r' */ )) {
					mEndOfLine(false);
					if ( inputState->guessing==0 ) {
#line 2939 "CPP_parser.g"
						deferredNewline();
#line 2667 "CPPLexer.cpp"
					}
				}
				else if ((_tokenSet_10.member(LA(1)))) {
					{
					match(_tokenSet_10);
					}
				}
				else {
					goto _loop775;
				}
				
			}
			_loop775:;
			} // ( ... )*
			mRPAREN(false);
			if ( inputState->guessing==0 ) {
#line 2942 "CPP_parser.g"
				_ttype = ANTLR_USE_NAMESPACE(antlr)Token::SKIP;
#line 2686 "CPPLexer.cpp"
			}
			break;
		}
		case 0x7b /* '{' */ :
		{
			mLCURLY(false);
			{ // ( ... )*
			for (;;) {
				if ((LA(1) == 0xa /* '\n' */  || LA(1) == 0xd /* '\r' */ )) {
					mEndOfLine(false);
					if ( inputState->guessing==0 ) {
#line 2945 "CPP_parser.g"
						deferredNewline();
#line 2700 "CPPLexer.cpp"
					}
				}
				else if ((_tokenSet_11.member(LA(1)))) {
					{
					match(_tokenSet_11);
					}
				}
				else {
					goto _loop778;
				}
				
			}
			_loop778:;
			} // ( ... )*
			mRCURLY(false);
			if ( inputState->guessing==0 ) {
#line 2948 "CPP_parser.g"
				_ttype = ANTLR_USE_NAMESPACE(antlr)Token::SKIP;
#line 2719 "CPPLexer.cpp"
			}
			break;
		}
		default:
			if ((_tokenSet_12.member(LA(1)))) {
				{
				{
				match(_tokenSet_12);
				}
				}
				{ // ( ... )*
				for (;;) {
					if ((_tokenSet_13.member(LA(1)))) {
						{
						match(_tokenSet_13);
						}
					}
					else {
						goto _loop783;
					}
					
				}
				_loop783:;
				} // ( ... )*
				{
				if ((LA(1) == 0xa /* '\n' */  || LA(1) == 0xd /* '\r' */ )) {
					mEndOfLine(false);
					if ( inputState->guessing==0 ) {
#line 2952 "CPP_parser.g"
						newline();
#line 2750 "CPPLexer.cpp"
					}
				}
				else {
				}
				
				}
				if ( inputState->guessing==0 ) {
#line 2953 "CPP_parser.g"
					_ttype = ANTLR_USE_NAMESPACE(antlr)Token::SKIP;
#line 2760 "CPPLexer.cpp"
				}
			}
		else {
			throw ANTLR_USE_NAMESPACE(antlr)NoViableAltForCharException(LA(1), getFilename(), getLine(), getColumn());
		}
		}
		}
	}
	else if ((_tokenSet_2.member(LA(1))) && (true) && (true)) {
		{
		switch ( LA(1)) {
		case 0x61 /* 'a' */ :
		case 0x62 /* 'b' */ :
		case 0x63 /* 'c' */ :
		case 0x64 /* 'd' */ :
		case 0x65 /* 'e' */ :
		case 0x66 /* 'f' */ :
		case 0x67 /* 'g' */ :
		case 0x68 /* 'h' */ :
		case 0x69 /* 'i' */ :
		case 0x6a /* 'j' */ :
		case 0x6b /* 'k' */ :
		case 0x6c /* 'l' */ :
		case 0x6d /* 'm' */ :
		case 0x6e /* 'n' */ :
		case 0x6f /* 'o' */ :
		case 0x70 /* 'p' */ :
		case 0x71 /* 'q' */ :
		case 0x72 /* 'r' */ :
		case 0x73 /* 's' */ :
		case 0x74 /* 't' */ :
		case 0x75 /* 'u' */ :
		case 0x76 /* 'v' */ :
		case 0x77 /* 'w' */ :
		case 0x78 /* 'x' */ :
		case 0x79 /* 'y' */ :
		case 0x7a /* 'z' */ :
		{
			matchRange('a','z');
			break;
		}
		case 0x41 /* 'A' */ :
		case 0x42 /* 'B' */ :
		case 0x43 /* 'C' */ :
		case 0x44 /* 'D' */ :
		case 0x45 /* 'E' */ :
		case 0x46 /* 'F' */ :
		case 0x47 /* 'G' */ :
		case 0x48 /* 'H' */ :
		case 0x49 /* 'I' */ :
		case 0x4a /* 'J' */ :
		case 0x4b /* 'K' */ :
		case 0x4c /* 'L' */ :
		case 0x4d /* 'M' */ :
		case 0x4e /* 'N' */ :
		case 0x4f /* 'O' */ :
		case 0x50 /* 'P' */ :
		case 0x51 /* 'Q' */ :
		case 0x52 /* 'R' */ :
		case 0x53 /* 'S' */ :
		case 0x54 /* 'T' */ :
		case 0x55 /* 'U' */ :
		case 0x56 /* 'V' */ :
		case 0x57 /* 'W' */ :
		case 0x58 /* 'X' */ :
		case 0x59 /* 'Y' */ :
		case 0x5a /* 'Z' */ :
		{
			matchRange('A','Z');
			break;
		}
		case 0x5f /* '_' */ :
		{
			match('_' /* charlit */ );
			break;
		}
		default:
		{
			throw ANTLR_USE_NAMESPACE(antlr)NoViableAltForCharException(LA(1), getFilename(), getLine(), getColumn());
		}
		}
		}
		{ // ( ... )*
		for (;;) {
			switch ( LA(1)) {
			case 0x61 /* 'a' */ :
			case 0x62 /* 'b' */ :
			case 0x63 /* 'c' */ :
			case 0x64 /* 'd' */ :
			case 0x65 /* 'e' */ :
			case 0x66 /* 'f' */ :
			case 0x67 /* 'g' */ :
			case 0x68 /* 'h' */ :
			case 0x69 /* 'i' */ :
			case 0x6a /* 'j' */ :
			case 0x6b /* 'k' */ :
			case 0x6c /* 'l' */ :
			case 0x6d /* 'm' */ :
			case 0x6e /* 'n' */ :
			case 0x6f /* 'o' */ :
			case 0x70 /* 'p' */ :
			case 0x71 /* 'q' */ :
			case 0x72 /* 'r' */ :
			case 0x73 /* 's' */ :
			case 0x74 /* 't' */ :
			case 0x75 /* 'u' */ :
			case 0x76 /* 'v' */ :
			case 0x77 /* 'w' */ :
			case 0x78 /* 'x' */ :
			case 0x79 /* 'y' */ :
			case 0x7a /* 'z' */ :
			{
				matchRange('a','z');
				break;
			}
			case 0x41 /* 'A' */ :
			case 0x42 /* 'B' */ :
			case 0x43 /* 'C' */ :
			case 0x44 /* 'D' */ :
			case 0x45 /* 'E' */ :
			case 0x46 /* 'F' */ :
			case 0x47 /* 'G' */ :
			case 0x48 /* 'H' */ :
			case 0x49 /* 'I' */ :
			case 0x4a /* 'J' */ :
			case 0x4b /* 'K' */ :
			case 0x4c /* 'L' */ :
			case 0x4d /* 'M' */ :
			case 0x4e /* 'N' */ :
			case 0x4f /* 'O' */ :
			case 0x50 /* 'P' */ :
			case 0x51 /* 'Q' */ :
			case 0x52 /* 'R' */ :
			case 0x53 /* 'S' */ :
			case 0x54 /* 'T' */ :
			case 0x55 /* 'U' */ :
			case 0x56 /* 'V' */ :
			case 0x57 /* 'W' */ :
			case 0x58 /* 'X' */ :
			case 0x59 /* 'Y' */ :
			case 0x5a /* 'Z' */ :
			{
				matchRange('A','Z');
				break;
			}
			case 0x5f /* '_' */ :
			{
				match('_' /* charlit */ );
				break;
			}
			case 0x30 /* '0' */ :
			case 0x31 /* '1' */ :
			case 0x32 /* '2' */ :
			case 0x33 /* '3' */ :
			case 0x34 /* '4' */ :
			case 0x35 /* '5' */ :
			case 0x36 /* '6' */ :
			case 0x37 /* '7' */ :
			case 0x38 /* '8' */ :
			case 0x39 /* '9' */ :
			{
				matchRange('0','9');
				break;
			}
			default:
			{
				goto _loop787;
			}
			}
		}
		_loop787:;
		} // ( ... )*
	}
	else {
		throw ANTLR_USE_NAMESPACE(antlr)NoViableAltForCharException(LA(1), getFilename(), getLine(), getColumn());
	}
	
	_ttype = testLiteralsTable(_ttype);
	if ( _createToken && _token==ANTLR_USE_NAMESPACE(antlr)nullToken && _ttype!=ANTLR_USE_NAMESPACE(antlr)Token::SKIP ) {
	   _token = makeToken(_ttype);
	   _token->setText(text.substr(_begin, text.length()-_begin));
	}
	_returnToken = _token;
	_saveIndex=0;
}


const unsigned long CPPLexer::_tokenSet_0_data_[] = { 4608UL, 1UL, 0UL, 4096UL, 0UL, 0UL, 0UL, 0UL, 0UL, 0UL };
// 0x9 0xc   l 
const ANTLR_USE_NAMESPACE(antlr)BitSet CPPLexer::_tokenSet_0(_tokenSet_0_data_,10);
const unsigned long CPPLexer::_tokenSet_1_data_[] = { 0UL, 67059712UL, 0UL, 0UL, 0UL, 0UL, 0UL, 0UL, 0UL, 0UL };
// . 0 1 2 3 4 5 6 7 8 9 
const ANTLR_USE_NAMESPACE(antlr)BitSet CPPLexer::_tokenSet_1(_tokenSet_1_data_,10);
const unsigned long CPPLexer::_tokenSet_2_data_[] = { 0UL, 0UL, 2281701374UL, 134217726UL, 0UL, 0UL, 0UL, 0UL, 0UL, 0UL };
// A B C D E F G H I J K L M N O P Q R S T U V W X Y Z _ a b c d e f g 
// h i j k l m n o p q r s t u v w x y z 
const ANTLR_USE_NAMESPACE(antlr)BitSet CPPLexer::_tokenSet_2(_tokenSet_2_data_,10);
const unsigned long CPPLexer::_tokenSet_3_data_[] = { 4294958079UL, 4294966271UL, 4294967295UL, 4294967295UL, 4294967295UL, 4294967295UL, 4294967295UL, 4294967295UL, 0UL, 0UL, 0UL, 0UL, 0UL, 0UL, 0UL, 0UL };
// 0x0 0x1 0x2 0x3 0x4 0x5 0x6 0x7 0x8 0x9 0xb 0xc 0xe 0xf 0x10 0x11 0x12 
// 0x13 0x14 0x15 0x16 0x17 0x18 0x19 0x1a 0x1b 0x1c 0x1d 0x1e 0x1f   ! 
// \" # $ % & \' ( ) + , - . / 0 1 2 3 4 5 6 7 8 9 : ; < = > ? @ A B C 
// D E F G H I J K L M N O P Q R S T U V W X Y Z [ 0x5c ] ^ _ ` a b c d 
// e f g h i j k l m n o p q r s t u v w x y z { | } ~ 0x7f 0x80 0x81 0x82 
// 0x83 0x84 0x85 0x86 0x87 0x88 0x89 0x8a 0x8b 0x8c 0x8d 0x8e 0x8f 0x90 
// 0x91 0x92 0x93 0x94 0x95 0x96 0x97 0x98 0x99 0x9a 0x9b 0x9c 0x9d 0x9e 
// 0x9f 0xa0 0xa1 0xa2 0xa3 0xa4 0xa5 0xa6 0xa7 0xa8 0xa9 0xaa 0xab 0xac 
// 0xad 0xae 0xaf 0xb0 0xb1 0xb2 0xb3 0xb4 0xb5 0xb6 0xb7 
const ANTLR_USE_NAMESPACE(antlr)BitSet CPPLexer::_tokenSet_3(_tokenSet_3_data_,16);
const unsigned long CPPLexer::_tokenSet_4_data_[] = { 4294958079UL, 4294967295UL, 4294967295UL, 4294967295UL, 4294967295UL, 4294967295UL, 4294967295UL, 4294967295UL, 0UL, 0UL, 0UL, 0UL, 0UL, 0UL, 0UL, 0UL };
// 0x0 0x1 0x2 0x3 0x4 0x5 0x6 0x7 0x8 0x9 0xb 0xc 0xe 0xf 0x10 0x11 0x12 
// 0x13 0x14 0x15 0x16 0x17 0x18 0x19 0x1a 0x1b 0x1c 0x1d 0x1e 0x1f   ! 
// \" # $ % & \' ( ) * + , - . / 0 1 2 3 4 5 6 7 8 9 : ; < = > ? @ A B 
// C D E F G H I J K L M N O P Q R S T U V W X Y Z [ 0x5c ] ^ _ ` a b c 
// d e f g h i j k l m n o p q r s t u v w x y z { | } ~ 0x7f 0x80 0x81 
// 0x82 0x83 0x84 0x85 0x86 0x87 0x88 0x89 0x8a 0x8b 0x8c 0x8d 0x8e 0x8f 
// 0x90 0x91 0x92 0x93 0x94 0x95 0x96 0x97 0x98 0x99 0x9a 0x9b 0x9c 0x9d 
// 0x9e 0x9f 0xa0 0xa1 0xa2 0xa3 0xa4 0xa5 0xa6 0xa7 0xa8 0xa9 0xaa 0xab 
// 0xac 0xad 0xae 0xaf 0xb0 0xb1 0xb2 0xb3 0xb4 0xb5 0xb6 0xb7 
const ANTLR_USE_NAMESPACE(antlr)BitSet CPPLexer::_tokenSet_4(_tokenSet_4_data_,16);
const unsigned long CPPLexer::_tokenSet_5_data_[] = { 0UL, 2164195460UL, 268435456UL, 22298694UL, 0UL, 0UL, 0UL, 0UL, 0UL, 0UL };
// \" \' 0 1 2 3 4 5 6 7 ? 0x5c a b f n r t v x 
const ANTLR_USE_NAMESPACE(antlr)BitSet CPPLexer::_tokenSet_5(_tokenSet_5_data_,10);
const unsigned long CPPLexer::_tokenSet_6_data_[] = { 4294958079UL, 4294967291UL, 4026531839UL, 4294967295UL, 4294967295UL, 4294967295UL, 4294967295UL, 4294967295UL, 0UL, 0UL, 0UL, 0UL, 0UL, 0UL, 0UL, 0UL };
// 0x0 0x1 0x2 0x3 0x4 0x5 0x6 0x7 0x8 0x9 0xb 0xc 0xe 0xf 0x10 0x11 0x12 
// 0x13 0x14 0x15 0x16 0x17 0x18 0x19 0x1a 0x1b 0x1c 0x1d 0x1e 0x1f   ! 
// # $ % & \' ( ) * + , - . / 0 1 2 3 4 5 6 7 8 9 : ; < = > ? @ A B C D 
// E F G H I J K L M N O P Q R S T U V W X Y Z [ ] ^ _ ` a b c d e f g 
// h i j k l m n o p q r s t u v w x y z { | } ~ 0x7f 0x80 0x81 0x82 0x83 
// 0x84 0x85 0x86 0x87 0x88 0x89 0x8a 0x8b 0x8c 0x8d 0x8e 0x8f 0x90 0x91 
// 0x92 0x93 0x94 0x95 0x96 0x97 0x98 0x99 0x9a 0x9b 0x9c 0x9d 0x9e 0x9f 
// 0xa0 0xa1 0xa2 0xa3 0xa4 0xa5 0xa6 0xa7 0xa8 0xa9 0xaa 0xab 0xac 0xad 
// 0xae 0xaf 0xb0 0xb1 0xb2 0xb3 0xb4 0xb5 0xb6 0xb7 
const ANTLR_USE_NAMESPACE(antlr)BitSet CPPLexer::_tokenSet_6(_tokenSet_6_data_,16);
const unsigned long CPPLexer::_tokenSet_7_data_[] = { 4294958079UL, 4294967167UL, 4026531839UL, 4294967295UL, 4294967295UL, 4294967295UL, 4294967295UL, 4294967295UL, 0UL, 0UL, 0UL, 0UL, 0UL, 0UL, 0UL, 0UL };
// 0x0 0x1 0x2 0x3 0x4 0x5 0x6 0x7 0x8 0x9 0xb 0xc 0xe 0xf 0x10 0x11 0x12 
// 0x13 0x14 0x15 0x16 0x17 0x18 0x19 0x1a 0x1b 0x1c 0x1d 0x1e 0x1f   ! 
// \" # $ % & ( ) * + , - . / 0 1 2 3 4 5 6 7 8 9 : ; < = > ? @ A B C D 
// E F G H I J K L M N O P Q R S T U V W X Y Z [ ] ^ _ ` a b c d e f g 
// h i j k l m n o p q r s t u v w x y z { | } ~ 0x7f 0x80 0x81 0x82 0x83 
// 0x84 0x85 0x86 0x87 0x88 0x89 0x8a 0x8b 0x8c 0x8d 0x8e 0x8f 0x90 0x91 
// 0x92 0x93 0x94 0x95 0x96 0x97 0x98 0x99 0x9a 0x9b 0x9c 0x9d 0x9e 0x9f 
// 0xa0 0xa1 0xa2 0xa3 0xa4 0xa5 0xa6 0xa7 0xa8 0xa9 0xaa 0xab 0xac 0xad 
// 0xae 0xaf 0xb0 0xb1 0xb2 0xb3 0xb4 0xb5 0xb6 0xb7 
const ANTLR_USE_NAMESPACE(antlr)BitSet CPPLexer::_tokenSet_7(_tokenSet_7_data_,16);
const unsigned long CPPLexer::_tokenSet_8_data_[] = { 0UL, 67043328UL, 126UL, 126UL, 0UL, 0UL, 0UL, 0UL, 0UL, 0UL };
// 0 1 2 3 4 5 6 7 8 9 A B C D E F a b c d e f 
const ANTLR_USE_NAMESPACE(antlr)BitSet CPPLexer::_tokenSet_8(_tokenSet_8_data_,10);
const unsigned long CPPLexer::_tokenSet_9_data_[] = { 0UL, 67059712UL, 32UL, 32UL, 0UL, 0UL, 0UL, 0UL, 0UL, 0UL };
// . 0 1 2 3 4 5 6 7 8 9 E e 
const ANTLR_USE_NAMESPACE(antlr)BitSet CPPLexer::_tokenSet_9(_tokenSet_9_data_,10);
const unsigned long CPPLexer::_tokenSet_10_data_[] = { 4294958079UL, 4294966783UL, 4294967295UL, 4294967295UL, 4294967295UL, 4294967295UL, 4294967295UL, 4294967295UL, 0UL, 0UL, 0UL, 0UL, 0UL, 0UL, 0UL, 0UL };
// 0x0 0x1 0x2 0x3 0x4 0x5 0x6 0x7 0x8 0x9 0xb 0xc 0xe 0xf 0x10 0x11 0x12 
// 0x13 0x14 0x15 0x16 0x17 0x18 0x19 0x1a 0x1b 0x1c 0x1d 0x1e 0x1f   ! 
// \" # $ % & \' ( * + , - . / 0 1 2 3 4 5 6 7 8 9 : ; < = > ? @ A B C 
// D E F G H I J K L M N O P Q R S T U V W X Y Z [ 0x5c ] ^ _ ` a b c d 
// e f g h i j k l m n o p q r s t u v w x y z { | } ~ 0x7f 0x80 0x81 0x82 
// 0x83 0x84 0x85 0x86 0x87 0x88 0x89 0x8a 0x8b 0x8c 0x8d 0x8e 0x8f 0x90 
// 0x91 0x92 0x93 0x94 0x95 0x96 0x97 0x98 0x99 0x9a 0x9b 0x9c 0x9d 0x9e 
// 0x9f 0xa0 0xa1 0xa2 0xa3 0xa4 0xa5 0xa6 0xa7 0xa8 0xa9 0xaa 0xab 0xac 
// 0xad 0xae 0xaf 0xb0 0xb1 0xb2 0xb3 0xb4 0xb5 0xb6 0xb7 
const ANTLR_USE_NAMESPACE(antlr)BitSet CPPLexer::_tokenSet_10(_tokenSet_10_data_,16);
const unsigned long CPPLexer::_tokenSet_11_data_[] = { 4294958079UL, 4294967295UL, 4294967295UL, 3758096383UL, 4294967295UL, 4294967295UL, 4294967295UL, 4294967295UL, 0UL, 0UL, 0UL, 0UL, 0UL, 0UL, 0UL, 0UL };
// 0x0 0x1 0x2 0x3 0x4 0x5 0x6 0x7 0x8 0x9 0xb 0xc 0xe 0xf 0x10 0x11 0x12 
// 0x13 0x14 0x15 0x16 0x17 0x18 0x19 0x1a 0x1b 0x1c 0x1d 0x1e 0x1f   ! 
// \" # $ % & \' ( ) * + , - . / 0 1 2 3 4 5 6 7 8 9 : ; < = > ? @ A B 
// C D E F G H I J K L M N O P Q R S T U V W X Y Z [ 0x5c ] ^ _ ` a b c 
// d e f g h i j k l m n o p q r s t u v w x y z { | ~ 0x7f 0x80 0x81 0x82 
// 0x83 0x84 0x85 0x86 0x87 0x88 0x89 0x8a 0x8b 0x8c 0x8d 0x8e 0x8f 0x90 
// 0x91 0x92 0x93 0x94 0x95 0x96 0x97 0x98 0x99 0x9a 0x9b 0x9c 0x9d 0x9e 
// 0x9f 0xa0 0xa1 0xa2 0xa3 0xa4 0xa5 0xa6 0xa7 0xa8 0xa9 0xaa 0xab 0xac 
// 0xad 0xae 0xaf 0xb0 0xb1 0xb2 0xb3 0xb4 0xb5 0xb6 0xb7 
const ANTLR_USE_NAMESPACE(antlr)BitSet CPPLexer::_tokenSet_11(_tokenSet_11_data_,16);
const unsigned long CPPLexer::_tokenSet_12_data_[] = { 4294953471UL, 4294966526UL, 4294967295UL, 3623878655UL, 4294967295UL, 4294967295UL, 4294967295UL, 4294967295UL, 0UL, 0UL, 0UL, 0UL, 0UL, 0UL, 0UL, 0UL };
// 0x0 0x1 0x2 0x3 0x4 0x5 0x6 0x7 0x8 0xb 0xe 0xf 0x10 0x11 0x12 0x13 
// 0x14 0x15 0x16 0x17 0x18 0x19 0x1a 0x1b 0x1c 0x1d 0x1e 0x1f ! \" # $ 
// % & \' * + , - . / 0 1 2 3 4 5 6 7 8 9 : ; < = > ? @ A B C D E F G H 
// I J K L M N O P Q R S T U V W X Y Z [ 0x5c ] ^ _ ` a b c d e f g h i 
// j k l m n o p q r s t u v w x y z | ~ 0x7f 0x80 0x81 0x82 0x83 0x84 
// 0x85 0x86 0x87 0x88 0x89 0x8a 0x8b 0x8c 0x8d 0x8e 0x8f 0x90 0x91 0x92 
// 0x93 0x94 0x95 0x96 0x97 0x98 0x99 0x9a 0x9b 0x9c 0x9d 0x9e 0x9f 0xa0 
// 0xa1 0xa2 0xa3 0xa4 0xa5 0xa6 0xa7 0xa8 0xa9 0xaa 0xab 0xac 0xad 0xae 
// 0xaf 0xb0 0xb1 0xb2 0xb3 0xb4 0xb5 0xb6 0xb7 
const ANTLR_USE_NAMESPACE(antlr)BitSet CPPLexer::_tokenSet_12(_tokenSet_12_data_,16);
const unsigned long CPPLexer::_tokenSet_13_data_[] = { 4294958079UL, 4294966527UL, 4294967295UL, 3623878655UL, 4294967295UL, 4294967295UL, 4294967295UL, 4294967295UL, 0UL, 0UL, 0UL, 0UL, 0UL, 0UL, 0UL, 0UL };
// 0x0 0x1 0x2 0x3 0x4 0x5 0x6 0x7 0x8 0x9 0xb 0xc 0xe 0xf 0x10 0x11 0x12 
// 0x13 0x14 0x15 0x16 0x17 0x18 0x19 0x1a 0x1b 0x1c 0x1d 0x1e 0x1f   ! 
// \" # $ % & \' * + , - . / 0 1 2 3 4 5 6 7 8 9 : ; < = > ? @ A B C D 
// E F G H I J K L M N O P Q R S T U V W X Y Z [ 0x5c ] ^ _ ` a b c d e 
// f g h i j k l m n o p q r s t u v w x y z | ~ 0x7f 0x80 0x81 0x82 0x83 
// 0x84 0x85 0x86 0x87 0x88 0x89 0x8a 0x8b 0x8c 0x8d 0x8e 0x8f 0x90 0x91 
// 0x92 0x93 0x94 0x95 0x96 0x97 0x98 0x99 0x9a 0x9b 0x9c 0x9d 0x9e 0x9f 
// 0xa0 0xa1 0xa2 0xa3 0xa4 0xa5 0xa6 0xa7 0xa8 0xa9 0xaa 0xab 0xac 0xad 
// 0xae 0xaf 0xb0 0xb1 0xb2 0xb3 0xb4 0xb5 0xb6 0xb7 
const ANTLR_USE_NAMESPACE(antlr)BitSet CPPLexer::_tokenSet_13(_tokenSet_13_data_,16);

