#ifndef Visitor_h__
#define Visitor_h__

#include <iostream>

class ElementA;
class ElementB;
class ElementC;

class Visitor
{
public:
	Visitor(){ }
	virtual ~Visitor(){ }

	virtual void visit(ElementA& element) abstract;
	virtual void visit(ElementB& element) abstract;
	virtual void visit(ElementC& element) abstract;
};


class PrintInfoVisitor : public Visitor
{
public:
	virtual void visit(ElementA& element) override
	{
		std::cout << "ElementA" << std::endl;
	}

	virtual void visit(ElementB& element) override
	{
		std::cout << "ElementB" << std::endl;
	}

	virtual void visit(ElementC& element) override
	{
		std::cout << "ElementC" << std::endl;
	}
};



#endif // Visitor_h__
