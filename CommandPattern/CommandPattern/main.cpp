#include "ConcreteCommand.h"
#include "Invoker.h"
#include "Receiver.h"


int main()
{
	Receiver *receiver = new Receiver();
	ConcreteCommand *concreteCommand = new ConcreteCommand(receiver);
	Invoker *invoker = new Invoker(concreteCommand);
	invoker->call();

	delete receiver;
	delete concreteCommand;
	delete invoker;

	return 0;
}