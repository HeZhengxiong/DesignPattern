#ifndef Header_h__
#define Header_h__

/*
Sunny软件公司欲开发一款可以运行在Android
平台的触摸式中国象棋软件，
由于考虑到有些用户是“菜鸟”，
经常不小心走错棋；
还有些用户因为不习惯使用手指在手机屏幕上拖动棋子，
常常出现操作失误，因此该中国象棋软件要提供“悔棋”功能，
用户走错棋或操作失误后可恢复到前一个步骤。
*/

#include <iostream>
#include <string>
#include <vector>


class ChessmanMemento
{
private:
	std::string _label;
	int _x;
	int _y;

public:
	ChessmanMemento(const std::string& label, int x, int y)
		: _label(label), _x(x), _y(y){}
	
	void setLabel(const std::string& label) {
		this->_label = label;
	}

	void setX(int x) {
		_x = x;
	}

	void setY(int y) {
		_y = y;
	}

	std::string getLabel() {
		return (_label);
	}

	int getX() {
		return (_x);
	}

	int getY() {
		return (_y);
	}

};


class Chessman
{
private:
	std::string _label;
	int _x;
	int _y;

public:
	Chessman(const std::string& label, int x, int y)
		: _label(label), _x(x), _y(y){ }
	
	void setLabel(const std::string& label)
	{
		_label = label;
	}

	void setX(int x){ _x = x; }
	void setY(int y){ _y = y; }

	std::string getLabel()
	{
		return _label;
	}

	int getX(){ return _x; }
	int getY(){ return _y; }

	ChessmanMemento* save()
	{
		return new ChessmanMemento(this->_label, this->_x, this->_y);
	}

	void restore(ChessmanMemento* m)
	{
		this->_label = m->getLabel();
		this->_x = m->getX();
		this->_y = m->getY();
	}
};


class MementoCaretaker
{
private:
	ChessmanMemento* _m;

public:
	ChessmanMemento* getMemento(){ return _m; }
	void setMemento(ChessmanMemento* m)
	{
		_m = m;
	}
};




#endif // Header_h__
