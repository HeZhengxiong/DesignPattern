#ifndef composite_h__
#define composite_h__

#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <string>

class Component
{
public:
	Component(const std::string name) : _name(name){ }
	virtual ~Component(){}


	virtual void add(Component *c) = 0;
	virtual void remove(Component *c) = 0;
	virtual Component* getChild(int i) = 0;
	virtual void operation() = 0;

protected:
	std::string		_name;
};


class Leaf : public Component
{
public:
	Leaf(const std::string& name) : Component(name) { }

	void add(Component *c) override {
		std::cerr << "Leaf cannot add component" << std::endl;
		exit(-1);
	}

	void remove(Component *c) override {
		std::cerr << "Leaf cannot remove component" << std::endl;
		exit(-1);
	}

	Component* getChild(int i) override {
		std::cerr << "Leaf cannot have child component" << std::endl;
		return nullptr;
	}

	void operation() override
	{
		std::cout << "Leaf: " << _name << " Leaf Operation" << std::endl;
	}
};



class Composite : public Component
{
public:
	Composite(const std::string& name) : Component(name){ }
	Composite() = default;

	void add(Component *c) override
	{
		_list.push_back(c);
	}

	void remove(Component *c) override
	{
		auto iter = std::find(_list.begin(), _list.end(), c);
		if (iter != _list.end())
			_list.erase(iter);
	}

	Component* getChild(int i) override
	{
		return (Component*)_list.at(i);
	}

	void operation() override
	{
		for (auto iter : _list)
		{
			iter->operation();
		}
	}


private:
	std::vector<Component*>	_list;
};





#endif // composite_h__
