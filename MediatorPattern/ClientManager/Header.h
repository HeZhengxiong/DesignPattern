#ifndef Header_h__
#define Header_h__

#include <iostream>
#include <string>

class Component;
class Button;
class List;
class ComboBox;
class TextBox;
class Mediator;


class Component
{
public:
	void setMediator(Mediator *m);


	void changed();

	virtual void update() = 0;

protected:
	Mediator*	_mediator;
};

class Button : public Component
{
public:
	virtual void update()
	{
		std::cout << "No operation" << std::endl;
	}
};

class List : public Component
{
public:
	virtual void update() override
	{
		std::cout << "列表添加一项" << std::endl;
	}

	void select()
	{
		std::cout << "选择项" << std::endl;
	}
};


class ComboBox : public Component
{
public:
	void update() override
	{
		std::cout << "新增一项" << std::endl;
	}

	void select()
	{
		std::cout << "组合框选中" << std::endl;
	}
};

class TextBox : public Component
{
public:
	virtual void update()
	{
		std::cout << "新增后文本清空" << std::endl;
	}

	void setText()
	{
		std::cout << "文本框显示" << std::endl;
	}
};



class Mediator
{
public:
	virtual ~Mediator(){ }
	virtual void componentChanged(Component *c) = 0;
};


class ConcreteMediator : public Mediator
{
public:
	Button*		_addButton;
	List*		_list;
	TextBox*		_userNameTextBox;
	ComboBox*	_comboBox;

	void componentChanged(Component* c) override
	{
		if (c == _addButton)
		{
			std::cout << "单机添加按钮" << std::endl;
			_list->update();
			_comboBox->update();
			_userNameTextBox->update();
		}

		else if (c == _list)
		{
			std::cout << "从列表选择客户" << std::endl;
			_comboBox->select();
			_userNameTextBox->setText();
		}

		else if (c == _comboBox)
		{
			std::cout << "从组合框选择客户" << std::endl;
			_comboBox->select();
			_userNameTextBox->setText();
		}
	}
};



void Component::setMediator(Mediator *m)
{
	_mediator = m;
}

void Component::changed()
{
	_mediator->componentChanged(this);
}



#endif // Header_h__
