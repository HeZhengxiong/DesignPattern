#ifndef Header_h__
#define Header_h__

/*
Sunny�����˾������һ�����������Android
ƽ̨�Ĵ���ʽ�й����������
���ڿ��ǵ���Щ�û��ǡ����񡱣�
������С���ߴ��壻
����Щ�û���Ϊ��ϰ��ʹ����ָ���ֻ���Ļ���϶����ӣ�
�������ֲ���ʧ����˸��й��������Ҫ�ṩ�����塱���ܣ�
�û��ߴ�������ʧ���ɻָ���ǰһ�����衣
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
