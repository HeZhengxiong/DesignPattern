#include "builder.h"

int main()
{
	ProductABuilder *abuilder = new ProductABuilder();
	Director *director = new Director(abuilder);
	Product *pa = director->construct();

	ProductBBuilder *bbuilder = new ProductBBuilder();
	Director *db = new Director(bbuilder);
	Product *pb = db->construct();

	return 0;
}