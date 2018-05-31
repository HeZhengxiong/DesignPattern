#include "Header.h"

int main()
{

	Observer *yg = new Player("���");
	Observer *gj = new Player("����");
	Observer *hr = new Player("����");

	AllyControlCenter *playerCenter = new ConcreteAllyController("��ӹȺ��");
	playerCenter->join(yg);
	playerCenter->join(gj);
	playerCenter->join(hr);

	hr->beAttacked(playerCenter);

}