#include "Header.h"

int main()
{
	Account *ac1 = new CurrentAccount;
	ac1->handle("hx", "123");

	Account *ac2 = new SavingAccout;
	ac2->handle("ss", "133");
}