#include "Header.h"

int main()
{
	ConcreteMediator *mediator = new ConcreteMediator;

	Button *b = new Button;
	List *list = new List;
	ComboBox *cb = new ComboBox;
	TextBox *tb = new TextBox;

	b->setMediator(mediator);
	list->setMediator(mediator);
	cb->setMediator(mediator);
	tb->setMediator(mediator);

	mediator->_addButton = b;
	mediator->_list = list;
	mediator->_comboBox = cb;
	mediator->_userNameTextBox = tb;

	b->changed();
	list->changed();

}