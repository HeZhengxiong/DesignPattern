#ifndef state_h__
#define state_h__

#include <iostream>

class State
{
public:
	virtual ~State(){ }

	virtual void handle() = 0;
};


class ConcreteStateA : public State
{
public:
	virtual void handle()
	{
		std::cout << "A handling" << std::endl;
	}
};



class ConcreteStateB : public State
{
public:
	virtual void handle()
	{
		std::cout << "B handling" << std::endl;
	}
};



class Context
{
public:
	void setState(State *state)
	{
		_state = state;
	}

	void setVal(int v)
	{
		_value = v;
	}

	void request()
	{
		_state->handle();
	}

	void changeState()
	{
		if (_value == 0)
			_state = new ConcreteStateA();
		else if (_value == 1)
			_state = new ConcreteStateB();
	}


private:
	State*	_state;
	int		_value;


};


#endif // state_h__
