#include "Invoker.h"
#include "ICommand.h"
#include <iostream>


Invoker::Invoker(ICommand *command) : _command(command)
{

}

Invoker::~Invoker()
{

}

void Invoker::call()
{
	std::cout << "Invoker calling" << std::endl;

	_command->execute();
}
