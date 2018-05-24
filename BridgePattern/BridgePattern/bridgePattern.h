#ifndef bridge_pattern_h__
#define bridge_pattern_h__

#include <iostream>

class Implementor
{
    public:
        virtual ~Implementor(){ }
        virtual void operationImpl() = 0;
};


class ConcreteAImplementor : public Implementor
{
    public:
        virtual void operationImpl()
        {
            std::cout << "concrete A impl" << std::endl;
        }

};


class ConcreteBImplementor : public Implementor
{
    public:
        virtual void operationImpl()
        {
            std::cout << "Concrete B impl" << std::endl;
        }
};



class Abstraction
{
    public:
        virtual ~Abstraction() { }

        void setImpl(Implementor *impl)
        {
            _impl = impl;
        }

        virtual void operation() = 0;

    protected:
        Implementor*    _impl;
};


class RefinedAbstraction : public Abstraction
{
    public:
        virtual void operation() override
        {
            _impl->operationImpl();
        }
};



#endif