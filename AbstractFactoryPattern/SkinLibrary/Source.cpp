#include "skin.h"

int main()
{
	SkinFactory *factory = new SummerFactory();
	Button *bt = factory->createButton();
	TextField *tf = factory->createTextField();
	ComboBox *cb = factory->createComboBox();

	bt->display();
	tf->display();
	cb->display();

	return 0;
}