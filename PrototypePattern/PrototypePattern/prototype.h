#ifndef prototype_h__
#define prototype_h__

class Prototype
{
public:
	Prototype() = default;
	virtual ~Prototype(){ }

	virtual Prototype* clone() = 0;

	void setVal(double v) { _val = v; }
	double getVal() const { return _val; }

protected:
	double _val = 0.0;
};



class ConcretePrototypeA : public Prototype
{
public:
	virtual Prototype* clone() override
	{
		Prototype *pa = new ConcretePrototypeA();
		//clone a so every member should be the same!
		pa->setVal(this->getVal());
		return pa;
	}
};


class ConcretePrototypeB : public Prototype
{
public:
	virtual Prototype* clone() override
	{
		Prototype *pb = new ConcretePrototypeB();
		pb->setVal(this->getVal());
		return pb;
	}
};




#endif // prototype_h__
