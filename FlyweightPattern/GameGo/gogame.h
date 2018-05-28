#ifndef gogame_h__
#define gogame_h__

/*
Sunny软件公司开发人员通过对围棋软件进行分析，
发现在围棋棋盘中包含大量的黑子和白子，
它们的形状、大小都一模一样，只是出现的位置不同而已。
如果将每一个棋子都作为一个独立的对象存储在内存中，
将导致该围棋软件在运行时所需内存空间较大，
如何降低运行代价、提高系统性能是Sunny公司开发人员需要解决的一个问题。
为了解决这个问题，
Sunny公司开发人员决定使用享元模式来设计该围棋软件的棋子对象
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
