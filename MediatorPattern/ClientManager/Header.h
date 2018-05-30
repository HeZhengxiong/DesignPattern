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
		std::cout << "�б����һ��" << std::endl;
	}

	void select()
	{
		std::cout << "ѡ����" << std::endl;
	}
};


class ComboBox : public Component
{
public:
	void update() override
	{
		std::cout << "����һ��" << std::endl;
	}

	void select()
	{
		std::cout << "��Ͽ�ѡ��" << std::endl;
	}
};

class TextBox : public Component
{
public:
	virtual void update()
	{
		std::cout << "�������ı����" << std::endl;
	}

	void setText()
	{
		std::cout << "�ı�����ʾ" << std::endl;
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
			std::cout << "������Ӱ�ť" << std::endl;
			_list->update();
			_comboBox->update();
			_userNameTextBox->update();
		}

		else if (c == _list)
		{
			std::cout << "���б�ѡ��ͻ�" << std::endl;
			_comboBox->select();
			_userNameTextBox->setText();
		}

		else if (c == _comboBox)
		{
			std::cout << "����Ͽ�ѡ��ͻ�" << std::endl;
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
