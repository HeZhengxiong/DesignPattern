#include "controls.h"

int main()
{
	Component *c = new Window();
	Component *sbC = new ScrollBarDecorator(c);
	sbC->display();
}
