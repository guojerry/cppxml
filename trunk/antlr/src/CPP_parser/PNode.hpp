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
	PNode( void );
	PNode(RefToken t);
	~PNode( void ){}

public:
	virtual void initialize(int t, const std::string& txt);
	virtual void initialize( RefPNode t );
	virtual void initialize( RefAST t );
	virtual void initialize( antlr::RefToken t );
	virtual void setText(const std::string& txt);
	virtual void setType(int type);
	virtual void addChild( RefPNode c );
	virtual RefPNode getFirstChild();
	virtual RefPNode getNextSibling();
	virtual void setLine(int l_);
	virtual void setFilename(const char* fn);
	virtual int getLine(void) const;
	virtual string getFilename() const;

	static RefAST factory(void);

private:
	int		lineNumber;
	string  filename;
};

#endif
