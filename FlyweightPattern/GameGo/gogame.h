#ifndef gogame_h__
#define gogame_h__

/*
Sunny�����˾������Աͨ����Χ��������з�����
������Χ�������а��������ĺ��ӺͰ��ӣ�
���ǵ���״����С��һģһ����ֻ�ǳ��ֵ�λ�ò�ͬ���ѡ�
�����ÿһ�����Ӷ���Ϊһ�������Ķ���洢���ڴ��У�
�����¸�Χ�����������ʱ�����ڴ�ռ�ϴ�
��ν������д��ۡ����ϵͳ������Sunny��˾������Ա��Ҫ�����һ�����⡣
Ϊ�˽��������⣬
Sunny��˾������Ա����ʹ����Ԫģʽ����Ƹ�Χ����������Ӷ���
*/


#include <iostream>
#include <string>
#include <map>


class GoChessman
{
public:
	virtual ~GoChessman() { }

	virtual std::string getColor() = 0;

	void display()
	{
		std::cout << "Chess color: " << getColor() << std::endl;
	}
};


class BlackChessman : public GoChessman
{
public:
	virtual std::string getColor()
	{
		std::cout << "Black" << std::endl;
		return "black";
	}
};


class WhiteChessman : public GoChessman
{
public:
	virtual std::string getColor()
	{
		std::cout << "White" << std::endl;
		return "white";
	}
};


class GoChessmanFactory
{
public:
	GoChessman* getGoChessman(const std::string& color)
	{
		return _ht[color];
	}

	static GoChessmanFactory& getInstance()
	{
		static GoChessmanFactory instance;
		return instance;
	}

private:
	std::map<std::string, GoChessman*>		_ht;
	
	GoChessmanFactory()
	{
		BlackChessman *bcm = new BlackChessman();
		_ht["b"] = bcm;
		WhiteChessman *wcm = new WhiteChessman();
		_ht["w"] = wcm;
	}
	GoChessmanFactory(const GoChessmanFactory&) = delete;
	GoChessmanFactory& operator=(const GoChessmanFactory&) = delete;
};


#endif // gogame_h__
