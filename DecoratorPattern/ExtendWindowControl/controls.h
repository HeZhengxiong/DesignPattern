#ifndef controls_h__
#define controls_h__


#include <iostream>
#include <string>


class Component
{
public:
	virtual ~Component() { }
	virtual void display() = 0;
};


class Window : public Component
{
public:
	virtual void display()
	{
		std::cout << "Display Window" << std::endl;
	}
};


class TextBox : public Component
{
public:
	virtual void display()
	{
		std::cout << "Display TextBox" << std::endl;
	}
};


class ListBox : public Component
{
public:
	virtual void display()
	{
		std::cout << "Display ListBox" << std::endl;
	}
};


class ComponentDecorator : public Component
{
public:
	ComponentDecorator() = default;
	ComponentDecorator(Component *c) : _component(c)
	{
		//NOP
	}

	virtual void display()
	{
		_component->display();
	}



protected:
	Component	*_component;
};


class ScrollBarDecorator : public ComponentDecorator
{
public:
	ScrollBarDecorator(Component *c) : ComponentDecorator(c){ }
	virtual void display()
	{
		_component->display();
		std::cout << "Setting Scroll Bar" << std::endl;
	}
};


class BlackBorderDecorator : public ComponentDecorator
{
public:
	BlackBorderDecorator(Component *c) : ComponentDecorator(c) { }
	virtual void display()
	{
		_component->display();
		this->setBlackBorder();
	}

	void setBlackBorder()
	{
		std::cout << "Setting BlackBorder" << std::endl;
	}
};


#endif // controls_h__
