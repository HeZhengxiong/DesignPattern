#include "gameactor.h"

int main()
{
	ActorBuilder *ab = new HeroBuilder();
	ActorController *ac = new ActorController();
	Actor *a = ac->construct(ab);

	std::cout << a->getType() << std::endl;
	std::cout << a->getFace() << std::endl;
	std::cout << a->getCostume() << std::endl;

}