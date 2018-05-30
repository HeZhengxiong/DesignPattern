#ifndef Header_h__
#define Header_h__

#include <iostream>
#include <string>
#include <vector>

class Originator;

class Memento
{
private:
	std::string _state;

public:
	Memento(Originator *o);

	void setState(const std::string& state)
	{
		_state = state;
	}

	std::string getState()
	{
		return _state;
	}
};


class Originator
{
public:
	Originator(){ }

	Memento* createMemento()
	{
		return new Memento(this);
	}

	void restoreMemento(Memento *m)
	{
		_state = m->getState();
	}

	void setState(const std::string& state)
	{
		_state = state;
	}

	std::string getState()
	{
		return _state;
	}

private:
	std::string _state;
};


Memento::Memento(Originator *o)
{
	_state = o->getState();
}


class Caretaker
{
private:
	Memento* _memento;

public:
	Memento* getMemento()
	{
		return _memento;
	}

	void setMemento(Memento *m_)
	{
		_memento = m_;
	}
};



#endif // Header_h__
