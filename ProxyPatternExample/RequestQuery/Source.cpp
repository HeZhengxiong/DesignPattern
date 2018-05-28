#include "proxy.h"

int main()
{
	ProxySearcher *s = new ProxySearcher();

	s->doSearch("Frank", "AA");
}