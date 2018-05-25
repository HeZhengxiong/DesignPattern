#ifndef fasade_h__
#define fasade_h__

#include <iostream>

class SubSystemA
{
    public:
        void MethodA()
        {
            std::cout << "Calling SubSystem A Method A" << std::endl;
        }
};


class SubSystemB
{
    public:
        void MethodB()
        {
            std::cout << "Calling SubSystemB::MethodB" << std::endl;
        }
};


class Facade
{
    public:

        Facade() = default;

        void setSubSytemA(SubSystemA *a)
        {
            objA = a;
        }

        void setSubSytemB(SubSystemB* b)
        {
            objB = b;
        }

        void Method()
        {
            objA->MethodA();
            objB->MethodB();
        }

    private:
        SubSystemA* objA;
        SubSystemB* objB;
};



#endif