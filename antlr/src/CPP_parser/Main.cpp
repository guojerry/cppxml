/*
* PUBLIC DOMAIN PCCTS-BASED C++ GRAMMAR (cplusplus.g, stat.g, expr.g)
*
* Authors: Sumana Srinivasan, NeXT Inc.;            sumana_srinivasan@next.com
*          Terence Parr, Parr Research Corporation; parrt@parr-research.com
*          Russell Quong, Purdue University;        quong@ecn.purdue.edu
*
* VERSION 1.1
*
* SOFTWARE RIGHTS
*
* This file is a part of the ANTLR-based C++ grammar and is free
* software.  We do not reserve any LEGAL rights to its use or
* distribution, but you may NOT claim ownership or authorship of this
* grammar or support code.  An individual or company may otherwise do
* whatever they wish with the grammar distributed herewith including the
* incorporation of the grammar or the output generated by ANTLR into
* commerical software.  You may redistribute in source or binary form
* without payment of royalties to us as long as this header remains
* in all source distributions.
*
* We encourage users to develop parsers/tools using this grammar.
* In return, we ask that credit is given to us for developing this
* grammar.  By "credit", we mean that if you incorporate our grammar or
* the generated code into one of your programs (commercial product,
* research project, or otherwise) that you acknowledge this fact in the
* documentation, research report, etc....  In addition, you should say nice
* things about us at every opportunity.
*
* As long as these guidelines are kept, we expect to continue enhancing
* this grammar.  Feel free to send us enhancements, fixes, bug reports,
* suggestions, or general words of encouragement at parrt@parr-research.com.
*
* NeXT Computer Inc.
* 900 Chesapeake Dr.
* Redwood City, CA 94555
* 12/02/1994
*
* Restructured for public consumption by Terence Parr late February, 1995.
*
* Requires PCCTS 1.32b4 or higher to get past ANTLR.
*
* DISCLAIMER: we make no guarantees that this grammar works, makes sense,
*             or can be used to do anything useful.
*/
/* 1999-2004 Version 3.0 July 2004
* Modified by David Wigg at London South Bank University for CPP_parser.g
*/
/* 2004-2005 Version 3.1 November 2005
* Modified by David Wigg at London South Bank University for CPP_parser.g
*/
/* 2005-2007 Version 3.2 November 2007
* Modified by David Wigg at London South Bank University for CPP_parser.g
*
* This is the main program of the C++ parser
*
* Based on 'main.cpp' supplied with John Lilley's C++ parser and modified
*	by David Wigg at London South Bank University
*
* See MyReadMe.txt for further information
*
* This file is best viewed in courier font with tabs set to 4 spaces
*
* The input file must be pre-processed if any types used in the principal/user's program 
*	to be parsed have been declared in any #include files. Otherwise the parser fails.
*
* To run in DOS window enter,
*
* >...\debug\CPP_parser program_name.i (/a or /A may be used to specify that included files should
*                                       also be processed by your application instead of just
*                                       the principal/user's file. See MyCode.cpp for coding)
*
* Error/Warning messages may be displayed in DOS window.
*/

#include <iostream>
#include <fstream>
#include <string>
#include "conio.h"
#include "windows.h"
#include "CPPLexer.hpp"
#include "CPPParser.hpp"
#include "antlr/CommonAST.hpp"

#ifdef MYCODE
#include "MyCode.hpp"
#endif MYCODE

ANTLR_USING_NAMESPACE(std)
ANTLR_USING_NAMESPACE(antlr)

void myDebugOutputA(const char* format, ...)
{
	va_list argptr;
	va_start(argptr, format);
	char szData[1024] = {0};
	_vsnprintf(szData, 1023, format, argptr);
	va_end(argptr);

	OutputDebugStringA(szData);
}

void indent(int indent_level)
{
	if (indent_level > 0) {
		const size_t BUFSIZE = 127;
		char buf[ BUFSIZE+1 ];
		int i;

		for (i = 0; i < indent_level && i < BUFSIZE; i++) {
			buf[i] = '  ';
		}
		buf[i] = '\0';
		myDebugOutputA("%s", buf );
	}
} // pr_indent


void trav_tree(RefPNode top, int ind )
{
	if (top != NULL) 
	{
		myDebugOutputA("%03d ", top->getLine());

		std::string str;
		indent( ind );

		str = top->getText();
		myDebugOutputA("%s\r\n", str.c_str());
		if (top->getFirstChild() != NULL) 
		{
			myDebugOutputA("kid: ");
			trav_tree( top->getFirstChild(), ind+2 );
		}
		if (top->getNextSibling()) 
		{
			myDebugOutputA("sib: ");
			trav_tree( top->getNextSibling(), ind);
		}
	}
}

int main(int argc,char* argv[])
{
	// Adapt the following if block to the requirements of your application
	if (argc < 2 || argc > 3)
		{
		cerr << "Usage:\n" << argv[0] << " filename.i (/a or /A)" << "\n";
		exit(1);
		}

	// check for input file
	FILE *input_file_ptr = fopen(argv[1], "r");
	if (input_file_ptr == NULL)
		{
		cerr << "Failed to open input file " << argv[1] << "\n";
		exit(1);
		}
	else
		// close input file
		fclose(input_file_ptr);

	char *f = argv[1];

	try {
		ifstream s(f);
		if (!s)
			{
			cerr << "Input stream could not be opened for " << f << "\n";
			exit(1);
			}

		// Create a scanner that reads from the input stream
		CPPLexer lexer(s);
		lexer.setFilename(f);

#ifdef MYCODE
		// Create subclass of parser for MYCODE code that reads from scanner
		MyCode myCode(lexer);
		_PNodeFactory my_factory;	// generates CommonAST per default..

		// Do setup from the AST factory repeat this for all parsers using the AST
		myCode.initializeASTFactory(my_factory);
		myCode.setASTFactory(&my_factory);

		myCode.setFilename(f);
		myCode.init();
		myCode.myCode_pre_processing(argc, argv);
		myCode.translation_unit();

		RefPNode ast = RefPNode(myCode.getAST());
		myDebugOutputA("sid: ");
		trav_tree(ast, 0);

		myCode.myCode_post_processing();
#else
		// Create a parser that reads from the scanner
		CPPParser parser(lexer);
		parser.setFilename(f);
        parser.init();
		parser.translation_unit();
#endif MYCODE
		}
	catch(ANTLRException& e)	// Put in 30/10/07
		{
		cerr << "exception: " << e.getMessage() << endl;
		return -1;
		}
	catch (exception& e) 
		{
		cerr << "parser exception: " << e.what() << endl;
//		e.printStackTrace();   // so we can get stack trace		
		
		return -1;	// Put in 30/10/07
		}
	printf("\nParse ended\n");
//	getch();
	return 0;
	}