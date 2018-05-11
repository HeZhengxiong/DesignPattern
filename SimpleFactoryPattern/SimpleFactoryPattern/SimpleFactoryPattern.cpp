#include <iostream>
#include "Product.h"

int main()
{
	Product *aP = ProductFactory::createProduct("A");
	Product *bP = ProductFactory::createProduct("B");

	if (!aP || !bP)
		return -1;

	aP->use();
	bP->use();

	delete aP;
	delete bP;

	return 0;
}
