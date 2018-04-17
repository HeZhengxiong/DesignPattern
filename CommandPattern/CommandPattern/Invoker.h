#ifndef Invoker_h__
#define Invoker_h__

class ICommand;

class Invoker
{
public:
	Invoker(ICommand *command);
	virtual ~Invoker();
	void call();


private:
	ICommand * _command;
};




#endif // Invoker_h__
