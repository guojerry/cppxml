#include <iostream>
#include <fstream>
#include <string>
#include "conio.h"
#include "MyLexer.hpp"
#include "MyParser.hpp"
#include "PNodeFactory.hpp"
#include "PNode.hpp"

ANTLR_USING_NAMESPACE(std)
ANTLR_USING_NAMESPACE(antlr)

void indent(int indent_level)
{
	if (indent_level > 0) {
		const size_t BUFSIZE = 127;
		char buf[ BUFSIZE+1 ];
		int i;

		for (i = 0; i < indent_level && i < BUFSIZE; i++) {
			buf[i] = ' ';
		}
		buf[i] = '\0';
		printf("%s", buf );
	}
} // pr_indent


void trav_tree(RefPNode top, int ind )
{
	if (top != NULL) 
	{
		std::string str;
		indent( ind );

		str = top->getText();
		std::cout << str <<  "\n";
		if (top->getFirstChild() != NULL) 
		{
			printf("kid: ");
			trav_tree( top->getFirstChild(), ind+2 );
		}
		if (top->getNextSibling()) 
		{
			printf("sib: ");
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

	try 
	{
		ifstream s(f);
		if (!s)
			{
			cerr << "Input stream could not be opened for " << f << "\n";
			exit(1);
			}

		// Create a scanner that reads from the input stream
		MyLexer lexer(s);
		lexer.setFilename(f);

		// Create a parser that reads from the scanner
		MyParser parser(lexer);
		_PNodeFactory my_factory;	// generates CommonAST per default..

		// Do setup from the AST factory repeat this for all parsers using the AST
		parser.initializeASTFactory(my_factory);
		parser.setASTFactory(&my_factory);
		parser.setFilename(f);
		parser.interpretation_unit();

		RefPNode ast = RefPNode(parser.getAST());
		trav_tree(ast, 0);
	}
	catch(ANTLRException& e)	// Put in 30/10/07
	{
		cerr << "exception: " << e.getMessage() << endl;
		return -1;
	}
	catch (exception& e) 
	{
		cerr << "parser exception: " << e.what() << endl;
		
		return -1;	// Put in 30/10/07
	}
	printf("\nParse ended\n");
	getch();
	return 0;
}
