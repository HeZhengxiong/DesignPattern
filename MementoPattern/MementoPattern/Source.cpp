#include "Header.h"

int main()
{
	Originator *s = new Originator();
	s->setState("ABC");

	Memento *m = new Memento(s);
	Caretaker *c = new Caretaker;
	c->setMemento(m);

	s->setState("EFG");
	std::cout << "Before restore" << std::endl;
	std::cout << s->getState() << std::endl;

	std::cout << "After restore:" << std::endl;
	s->restoreMemento(c->getMemento());
	std::cout << s->getState() << std::endl;

}