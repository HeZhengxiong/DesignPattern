#include "composite.h"


/*
	tree structre

					cs2(Ä¿Â¼£©
					 |
				------------
				|          |
				cs1(Ä¿Â¼£©  leaf3 
				 |
			  --------
			  |      |
			 leaf1  leaf2
*/


int main()
{
	Component *cs1 = new Composite("cs1");
	Component *leaf1 = new Leaf("leaf1");
	Component *leaf2 = new Leaf("leaf2");
	cs1->add(leaf1);
	cs1->add(leaf2);

	Component *	cs2 = new Composite("cs2");
	Component *leaf3 = new Leaf("leaf3");
	cs2->add(cs1);
	cs2->add(leaf3);
	

	cs2->operation();
}