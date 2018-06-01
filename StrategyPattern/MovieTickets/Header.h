#ifndef Header_h__
#define Header_h__

/*
Sunny软件公司为某电影院开发了一套影院售票系统，
在该系统中需要为不同类型的用户提供不同的电影票打折方式，
具体打折方案如下：

(1) 学生凭学生证可享受票价8折优惠；

(2) 年龄在10周岁及以下的儿童可享受每张票减免10元的优惠（原始票价需大于等于20元）；

(3) 影院VIP用户除享受票价半价优惠外还可进行积分，积分累计到一定额度可换取电影院赠送的奖品。

该系统在将来可能还要根据需要引入新的打折方式。
*/

#include <iostream>

class Discount
{
public:
	virtual ~Discount() { }

	virtual double calculate(double price) = 0;
};


class StudentDiscount : public Discount
{
public:
	virtual double calculate(double price)
	{
		std::cout << "student ticket: \n";
		return price * .8;
	}
};


class ChildrenDiscount : public Discount
{
public:
	virtual double calculate(double price)
	{
		std::cout << "child ticket\n";
		return price - 10;
	}
};


class VIPDiscount : public Discount
{
public:
	virtual double calculate(double price)
	{
		std::cout << "vip ticket" << std::endl;
		return price * 0.5;
	}
};


class MovieTicket
{
private:
	double _price;
	Discount * _discount;


public:
	virtual void setPrice(double price)
	{
		_price = price;
	}

	void setDiscount(Discount *d)
	{
		_discount = d;
	}

	double getPrice()
	{
		return _discount->calculate(_price);
	}
};



#endif // Header_h__
