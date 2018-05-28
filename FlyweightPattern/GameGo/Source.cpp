#include "gogame.h"

int main()
{
	GoChessmanFactory& fc = GoChessmanFactory::getInstance();

	GoChessman *b1 = fc.getGoChessman("b");
	GoChessman *b2 = fc.getGoChessman("b");

	GoChessman *w1 = fc.getGoChessman("w");
	GoChessman *w2 = fc.getGoChessman("w");

	std::cout << (b1 == b2) << std::endl;
	std::cout << (w1 == w2) << std::endl;

	b1->display();
	b2->display();
	w1->display();
	w2->display();
}