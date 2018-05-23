#include "bridgePattern.h"


int main()
{
    Abstraction *ab = new RefinedAbstraction();
    ConcreteBImplementor *bImpl = new ConcreteBImplementor();
    ab->setImpl(bImpl);
    ab->operation();
}