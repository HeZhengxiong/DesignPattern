#ifndef ConcreteCommand_h__
#define ConcreteCommand_h__

#include "ICommand.h"

class Receiver;

class ConcreteCommand : public ICommand
{
public:
	ConcreteCommand(Receiver *receiver);
	virtual ~ConcreteCommand();

	virtual void execute() override;

private:
	Receiver	*_receiver;
};


#endif // ConcreteCommand_h__
