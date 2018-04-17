#ifndef ICommand_h__
#define ICommand_h__


class ICommand
{
public:
	virtual void execute() abstract;
	virtual ~ICommand(){ }
};



#endif // ICommand_h__
