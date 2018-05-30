#include "Header.h"

int main()
{
	Chessman *s = new Chessman("che", 1, 2);
	MementoCaretaker *c = new MementoCaretaker;
	c->setMemento(s->save());

	s->setLabel("ma");
	s->setX(3);
	s->setY(3);

	std::cout << "Current: " << s->getLabel() << " " << s->getX() <<
		" " << s->getY() << std::endl;

	std::cout << "Afeter restore" << std::endl;
	s->restore(c->getMemento());

	std::cout << "Current: " << s->getLabel() << " " << s->getX() <<
		" " << s->getY() << std::endl;
}