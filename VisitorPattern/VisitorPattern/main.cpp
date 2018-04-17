#include "Visitor.h"
#include "Element.h"

#include <iostream>
#include <vector>


int main()
{
	ElementA a;
	ElementB b;
	ElementC c;

	std::vector<Element*> es;
	es.push_back(&a);
	es.push_back(&b);
	es.push_back(&c);

	PrintInfoVisitor piv;

	for (auto item : es)
	{
		item->accept(piv);
	}
}