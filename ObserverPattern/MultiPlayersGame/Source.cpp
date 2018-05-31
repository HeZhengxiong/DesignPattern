#include "Header.h"

int main()
{

	Observer *yg = new Player("Ñî¹ı");
	Observer *gj = new Player("¹ù¾¸");
	Observer *hr = new Player("»ÆÈØ");

	AllyControlCenter *playerCenter = new ConcreteAllyController("½ğÓ¹ÈºÏÀ");
	playerCenter->join(yg);
	playerCenter->join(gj);
	playerCenter->join(hr);

	hr->beAttacked(playerCenter);

}