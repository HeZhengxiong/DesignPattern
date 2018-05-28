#ifndef flyweight_h__
#define flyweight_h__


#include <iostream>
#include <string>
#include <map>



class Flyweight
{
public:
	virtual ~Flyweight() { }

	Flyweight(const std::string& intrinsicState)
		: _intrinsicState(intrinsicState){ }

	virtual void operation(const std::string& extrinsicState) = 0;

	std::string getIntrinsicState()
	{
		return _intrinsicState;
	}

protected:
	std::string	_intrinsicState;
};


class ConcreteFlyweight : public Flyweight
{
public:
	ConcreteFlyweight(const std::string& intrinsicState)
		: Flyweight(intrinsicState)
	{

	}

	void operation(const std::string& extrinsicState)
	{
		std::cout << getIntrinsicState() << std::endl;
		std::cout << "ExtrinsicState" << std::endl;
	}
};


class UnsharedConcreteFlyweight : public Flyweight
{
public:
	UnsharedConcreteFlyweight(const std::string& intrinsicState) :
		Flyweight(intrinsicState)
	{ 
			
	}

	void operation(const std::string& extrinsicState)
	{
		std::cout << extrinsicState << std::endl;
	}
};


class FlyweightFactory
{
public:
	Flyweight*	getFlyweight(const std::string& key)
	{
		if (_flyweights.find(key) != _flyweights.end())
			return _flyweights[key];

		Flyweight *fly = new ConcreteFlyweight(key);
		_flyweights[key] = fly;

		return fly;
	}

protected:
	std::map<std::string, Flyweight*>	_flyweights;
};



#endif // flyweight_h__
