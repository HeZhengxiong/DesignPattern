#ifndef Header_h__
#define Header_h__

class AbstractClass
{
public:
	virtual ~AbstractClass(){ }

	virtual void TemplateMethod()
	{
		primitiveOp1();
		primitiveOp2();
		primitiveOp3();
	}

	virtual void primitiveOp1()
	{
	}

	virtual void primitiveOp2() = 0;

	virtual void primitiveOp3()
	{
	}
};


class ConcreteClass : public AbstractClass
{
public:
	virtual void primitiveOp2()
	{

	}

	virtual void primitiveOp3()
	{

	}
};



#endif // Header_h__
