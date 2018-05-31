#ifndef observer_h__
#define observer_h__


#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

class Observer;

class Subject
{
public:
	virtual ~Subject(){ }

	void attach(Observer *obs);
	void detach(Observer *obs);
	virtual void notify() = 0;

protected:
	std::vector<Observer*>	_observers;
};

class ConcreteSubject : public Subject
{
public:
	void notify() override;
};


class Observer
{
public:
	virtual ~Observer(){ }
	virtual void update() = 0;
};


class ConcreteObserver : public Observer
{
public:
	virtual void update()
	{
		std::cout << "Respond to ConcreteSubject" << std::endl;
	}
};



//Subject

void Subject::attach(Observer *obs)
{
	_observers.push_back(obs);
}

void Subject::detach(Observer *obs)
{
	auto iter = std::find(_observers.begin(), _observers.end(),
		obs);
	if (iter != _observers.end())
		_observers.erase(iter);
}



//ConcreteSubject
void ConcreteSubject::notify()
{
	for (auto e : _observers)
	{
		e->update();
	}
}
#endif // observer_h__
