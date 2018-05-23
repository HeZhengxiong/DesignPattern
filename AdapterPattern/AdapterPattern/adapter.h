#ifndef adapter_h__
#define adapter_h__

#include <iostream>

class Target
{
public:
	virtual void request(){ }

};


class Adaptee
{
public:
	void specificMethod()
	{
		std::cout << "Calling Adaptee Method" << std::endl;
	}
};

class Adapter : public Target
{
public:
	Adapter(Adaptee *adaptee) : _adaptee(adaptee){ }


	void request() override
	{
		_adaptee->specificMethod();
	}

private:
	Adaptee*		_adaptee;
};





#endif // adapter_h__
