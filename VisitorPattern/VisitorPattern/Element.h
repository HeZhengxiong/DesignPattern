#ifndef Element_h__
#define Element_h__


class Element
{
public:
	virtual void accept(Visitor& visitor) abstract;
};


class ElementA : public Element
{
public:
	virtual void accept(Visitor& visitor) override
	{
		visitor.visit(*this);
	}
};

class ElementB : public Element
{
public:
	virtual void accept(Visitor& visitor) override
	{
		visitor.visit(*this);
	}
};

class ElementC : public Element
{
public:
	virtual void accept(Visitor& visitor) override
	{
		visitor.visit(*this);
	}
};


#endif // Element_h__
