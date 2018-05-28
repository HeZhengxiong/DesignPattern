#include "flyweight.h"

int main()
{
	std::string extrinsicState = "ext";

	FlyweightFactory *fc = new FlyweightFactory();
	Flyweight *fly1 = fc->getFlyweight("hello");
	Flyweight *fly2 = fc->getFlyweight("hello");
	Flyweight *fly3 = fc->getFlyweight("world");

	fly1->operation(extrinsicState);

	std::cout << (fly1 == fly2) << std::endl;

}