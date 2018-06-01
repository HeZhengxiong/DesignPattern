#include "Header.h"

int main()
{
	MovieTicket *mt = new MovieTicket;
	mt->setPrice(100);

	Discount *d1 = new StudentDiscount;
	Discount *d2 = new ChildrenDiscount;
	Discount *d3 = new VIPDiscount;

	mt->setDiscount(d1);
	std::cout << mt->getPrice() << std::endl;

	mt->setDiscount(d2);
	std::cout << mt->getPrice() << std::endl;

	mt->setDiscount(d3);
	std::cout << mt->getPrice() << std::endl;
}