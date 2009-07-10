#ifndef INC_MyTokenTypes_hpp_
#define INC_MyTokenTypes_hpp_

/* $ANTLR 2.7.7 (20060906): "grammer.g" -> "MyTokenTypes.hpp"$ */

#ifndef CUSTOM_API
# define CUSTOM_API
#endif

#ifdef __cplusplus
struct CUSTOM_API MyTokenTypes {
#endif
	enum {
		EOF_ = 1,
		PLUS = 4,
		SEMI = 5,
		STAR = 6,
		INT = 7,
		WS = 8,
		LPAREN = 9,
		RPAREN = 10,
		NULL_TREE_LOOKAHEAD = 3
	};
#ifdef __cplusplus
};
#endif
#endif /*INC_MyTokenTypes_hpp_*/
