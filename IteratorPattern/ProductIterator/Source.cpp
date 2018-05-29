#include "iterator.h"
#include <iostream>
#include <string>
#include <vector>



int main()
{
	std::vector<std::string> strvec{ "hello", "world", "you", "and", "i" };

	ProductList<std::string> productList(strvec);

	AbstractIterator<std::string> *iter = productList.createIterator();

	std::cout << "�������:" << std::endl;
	while (!iter->isLast())
	{
		std::cout << iter->getCurrentItem() << std::endl;
		iter->next();
	}
	std::cout << "�������:" << std::endl;
	while (!iter->isFirst())
	{
		std::cout << iter->getReverseItem() << std::endl;
		iter->previous();
	}
}