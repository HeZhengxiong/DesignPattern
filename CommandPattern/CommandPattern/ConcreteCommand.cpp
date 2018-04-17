#include "ConcreteCommand.h"
#include "Receiver.h"
#include <iostream>


ConcreteCommand::ConcreteCommand(Receiver *receiver) : _receiver(receiver)
{

}

ConcreteCommand::~ConcreteCommand()
{

}

void ConcreteCommand::execute()
{
	std::cout << "ConcreteCommand::execute" << std::endl;
	_receiver->action();
}

