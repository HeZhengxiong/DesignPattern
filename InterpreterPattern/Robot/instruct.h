#ifndef instruct_h__
#define instruct_h__

/*
Sunny软件公司欲为某玩具公司开发一套机器人控制程序，
在该机器人控制程序中包含一些简单的英文控制指令，
每一个指令对应一个表达式(expression)，
该表达式可以是简单表达式也可以是复合表达式，
每一个简单表达式由移动方向(direction)，
移动方式(action)和移动距离(distance)三部分组成，
其中移动方向包括上(up)、下(down)、左(left)、右(right)；
移动方式包括移动(move)和快速移动(run)；移动距离为一个正整数。
两个表达式之间可以通过与(and)连接，形成复合(composite)表达式。

用户通过对图形化的设置界面进行操作可以创建一个机器人控制指令，
机器人在收到指令后将按照指令的设置进行移动，
例如输入控制指令：up move 5，则“向上移动5个单位”；
输入控制指令：down  run 10 and left move 20，
则“向下快速移动10个单位再向左移动20个单位”。
*/

//TODO: doesn't implement,because of syntax analysis.

#include <iostream>
#include <string>



class AbstractNode
{
public:
	virtual ~AbstractNode(){ }

	virtual	std::string interpret() = 0;
};


class AndNode : public AbstractNode
{
public:
	AndNode(AbstractNode* left, AbstractNode *right)
	{
		_left = left;
		_right = right;
	}

	virtual std::string interpret() override
	{
		return _left->interpret() + "再" + _right->interpret();
	}


private:
	AbstractNode*	_left;
	AbstractNode*	_right;
};


class SentenceNode : public AbstractNode
{
public:
	SentenceNode(AbstractNode *dir, AbstractNode *action, AbstractNode *dis) :
		_direction(dir), _action(action), _distance(dis){ }

	virtual std::string interpret() override
	{
		return _direction->interpret() + _action->interpret() + _direction->interpret();
	}
		

protected:
	AbstractNode *_direction;
	AbstractNode *_action;
	AbstractNode *_distance;
};


class DirectionNode : public AbstractNode
{
public:
	DirectionNode(const std::string& direction) : _direction(direction){ }

	virtual std::string interpret()
	{
		if (_direction == "up")
			return "向上";
		else if (_direction == "down")
			return "向下";
		else if (_direction == "left")
			return "向左";
		else if (_direction == "right")
			return "向右";
		else
			return "无效指令";
	}


private:
	std::string _direction;
};


class ActionNode : public AbstractNode
{
public:
	ActionNode(const std::string& action) : _action(action) { }

	virtual std::string interpret() override
	{
		if (_action == "move")
			return "移动";
		else if (_action == "run")
			return "快速移动";
		else
			return "无效指令";
	}

private:
	std::string _action;
};


class Distance : public AbstractNode
{
public:
	Distance(const std::string& d) : _dis(d){}

	std::string interpret() override
	{
		return _dis;
	}

private:
	std::string _dis;
};



#endif // instruct_h__
