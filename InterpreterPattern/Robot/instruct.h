#ifndef instruct_h__
#define instruct_h__

/*
Sunny�����˾��Ϊĳ��߹�˾����һ�׻����˿��Ƴ���
�ڸû����˿��Ƴ����а���һЩ�򵥵�Ӣ�Ŀ���ָ�
ÿһ��ָ���Ӧһ�����ʽ(expression)��
�ñ��ʽ�����Ǽ򵥱��ʽҲ�����Ǹ��ϱ��ʽ��
ÿһ���򵥱��ʽ���ƶ�����(direction)��
�ƶ���ʽ(action)���ƶ�����(distance)��������ɣ�
�����ƶ����������(up)����(down)����(left)����(right)��
�ƶ���ʽ�����ƶ�(move)�Ϳ����ƶ�(run)���ƶ�����Ϊһ����������
�������ʽ֮�����ͨ����(and)���ӣ��γɸ���(composite)���ʽ��

�û�ͨ����ͼ�λ������ý�����в������Դ���һ�������˿���ָ�
���������յ�ָ��󽫰���ָ������ý����ƶ���
�����������ָ�up move 5���������ƶ�5����λ����
�������ָ�down  run 10 and left move 20��
�����¿����ƶ�10����λ�������ƶ�20����λ����
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
		return _left->interpret() + "��" + _right->interpret();
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
			return "����";
		else if (_direction == "down")
			return "����";
		else if (_direction == "left")
			return "����";
		else if (_direction == "right")
			return "����";
		else
			return "��Чָ��";
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
			return "�ƶ�";
		else if (_action == "run")
			return "�����ƶ�";
		else
			return "��Чָ��";
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
