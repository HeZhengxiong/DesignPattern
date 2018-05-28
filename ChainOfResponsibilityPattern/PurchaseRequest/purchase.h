#ifndef purchase_h__
#define purchase_h__


#include <iostream>
#include <string>

class PurchaseRequest
{
public:
	void setPrice(double price)
	{
		_price = price;
	}

	double getPrice() const
	{
		return _price;
	}

protected:
	double _price;
};


class Approver
{
public:
	virtual ~Approver() { }

	void setSuccessor(Approver *successor)
	{
		_successor = successor;
	}

	virtual void processRequest(PurchaseRequest request) = 0;

protected:
	Approver*		_successor;
};


class Director : public Approver
{
public:
	virtual void processRequest(PurchaseRequest request)
	{
		if (request.getPrice() < 50000)
		{
			std::cout << "Approved by Director" << std::endl;
		}
		else
		{
			_successor->processRequest(request);
		}
	}
};


class ViceManager : public Approver
{
public:
	virtual void processRequest(PurchaseRequest request)
	{
		if (request.getPrice() < 100000)
		{
			std::cout << "Approved By Vice Manager" << std::endl;
		}
		else
		{
			_successor->processRequest(request);
		}
	}
};


class Manager : public Approver
{
public:
	virtual void processRequest(PurchaseRequest r)
	{
		if (r.getPrice() < 500000)
		{
			std::cout << "Approved By Manager" << std::endl;
		}
		else
		{
			_successor->processRequest(r);
		}
	}
};


class Board : public Approver
{
public:
	virtual void  processRequest(PurchaseRequest r)
	{
		std::cout << "processed By board" << std::endl;
	}
};


#endif // purchase_h__
