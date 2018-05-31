#include "observer.h"


int main()
{
	Observer *obs = new ConcreteObserver;
	Observer *obs1 = new ConcreteObserver;

	Subject *sub = new ConcreteSubject;
	sub->attach(obs);
	sub->attach(obs1);

	sub->notify();
}