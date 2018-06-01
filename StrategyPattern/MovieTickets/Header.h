#ifndef Header_h__
#define Header_h__

/*
Sunny�����˾Ϊĳ��ӰԺ������һ��ӰԺ��Ʊϵͳ��
�ڸ�ϵͳ����ҪΪ��ͬ���͵��û��ṩ��ͬ�ĵ�ӰƱ���۷�ʽ��
������۷������£�

(1) ѧ��ƾѧ��֤������Ʊ��8���Żݣ�

(2) ������10���꼰���µĶ�ͯ������ÿ��Ʊ����10Ԫ���Żݣ�ԭʼƱ������ڵ���20Ԫ����

(3) ӰԺVIP�û�������Ʊ�۰���Ż��⻹�ɽ��л��֣������ۼƵ�һ����ȿɻ�ȡ��ӰԺ���͵Ľ�Ʒ��

��ϵͳ�ڽ������ܻ�Ҫ������Ҫ�����µĴ��۷�ʽ��
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
