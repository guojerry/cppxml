#ifndef PNode_hpp__
#define PNode_hpp__

#include "antlr/CommonAST.hpp"

ANTLR_USING_NAMESPACE(std)
ANTLR_USING_NAMESPACE(antlr)

class PNode;
typedef antlr::ASTRefCount<PNode> RefPNode;

class PNode : public CommonAST 
{
public:
	PNode( void ) : down(), right()
	{
		lineNumber = 0;
	}

	PNode(antlr::RefToken t) : down(), right()
	{
		CommonAST::setType(t->getType() );
		CommonAST::setText(t->getText() );

		PNode::setLine(t->getLine() );
	}
	~PNode( void ){}

	void initialize(int t, const std::string& txt)
	{
		CommonAST::setType(t);
		CommonAST::setText(txt);

		lineNumber = 0; // to be noticed !
	}

	// used by PNodeFactory
	void initialize( RefPNode t )
	{
		CommonAST::setType(t->getType() );
		CommonAST::setText(t->getText() );

		PNode::setLine(t->getLine() );
	}

	void initialize( RefAST t )
	{
		CommonAST::initialize(t);
	}
	void initialize( antlr::RefToken t )
	{
		CommonAST::initialize(t);

		PNode::setLine(t->getLine() );
	}

	void setText(const std::string& txt)
	{
		CommonAST::setText(txt);
	}

	void setType(int type)
	{
		CommonAST::setType(type);
	}

	void addChild( RefPNode c )
	{
		BaseAST::addChild( static_cast<RefAST>(c) );
	}

	static antlr::RefAST factory( void )
	{
		antlr::RefAST ret = static_cast<RefAST>(RefPNode(new PNode));
		return ret;
	}

	RefPNode PNode::getFirstChild()
	{
		return static_cast<RefAST>(BaseAST::getFirstChild());
	}

	RefPNode PNode::getNextSibling()
	{
		return static_cast<RefAST>(BaseAST::getNextSibling());
	}

	// my extensions
	void PNode::setLine(int l_)
	{
		lineNumber = l_;
	}

	// ok cause imaginary tokens always has childs...
	//
	//
	int PNode::getLine(void) const
	{
		if(lineNumber != 0)
			return lineNumber;
		else {
			if(static_cast<RefPNode>(BaseAST::getFirstChild()) == NULL)
			{
				return lineNumber;
			}
			else
			{
				return ( (static_cast<RefPNode>(BaseAST::getFirstChild()))->getLine() );
			}
		}
	}

private:
	RefPNode down;
	RefPNode right;
	// append your own extensions to PNode here !
	int		lineNumber;
};

#endif
