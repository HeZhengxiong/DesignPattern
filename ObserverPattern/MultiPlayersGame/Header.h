#ifndef Header_h__
#define Header_h__

/*
Sunny软件公司欲开发一款多人联机对战游戏（类似魔兽世界、星际争霸等游戏），
在该游戏中，多个玩家可以加入同一战队组成联盟，
当战队中某一成员受到敌人攻击时将给所有其他盟友发送通知，
盟友收到通知后将作出响应。
Sunny软件公司开发人员需要提供一个设计方案来实现战队成员之间的联动。
*/

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

class Observer;



class AllyControlCenter
{
public:
	AllyControlCenter(const std::string& allayName = "") : 
		_allyName(allayName){}
	virtual ~AllyControlCenter(){ }

	void setAllyName(const std::string& name)
	{
		_allyName = name;
	}
	std::string getAllyName()
	{
		return _allyName;
	}

	void join(Observer *obs);
	void quit(Observer *obs);

	virtual void notifyObs(const std::string& obs) = 0;

protected:
	std::string _allyName;
	std::vector<Observer*>	_players;
};



class ConcreteAllyController : public AllyControlCenter
{
public:
	ConcreteAllyController(const std::string& allayName)
		: AllyControlCenter(allayName)
	{
		std::cout << _allyName << " build successful" << std::endl;
	}

	virtual void notifyObs(const std::string& obs) override;
};


class Observer
{
public:
	virtual ~Observer() { }

	virtual void setName(const std::string& name) = 0;
	virtual std::string getName() = 0;

	virtual void help() = 0;
	virtual void beAttacked(AllyControlCenter *acc) = 0;
};


class Player : public Observer
{
public:
	Player(const std::string& name) : _name(name){ }

	void setName(const std::string& name){ _name = name; }
	std::string getName(){ return _name; }

	virtual void help() override
	{
		std::cout << "Stay clam " << _name << " help you" << std::endl;
	}

	virtual void beAttacked(AllyControlCenter *acc) override
	{
		std::cout << _name << " is being attacked " << std::endl;
		acc->notifyObs(_name);
	}

protected:
	std::string _name;
};


void AllyControlCenter::join(Observer *obs)
{
	_players.push_back(obs);
}


void AllyControlCenter::quit(Observer *obs)
{
	auto iter = std::find(_players.begin(), _players.end(),
		obs);
	if (iter != _players.end())
		_players.erase(iter);
}


void ConcreteAllyController::notifyObs(const std::string& obs)
{
	std::cout << "team: " << _allyName << " emergency: ";
	std::cout << obs << " is being attack" << std::endl;

	for (int i = 0; i < _players.size(); i++)
	{
		if (_players.at(i)->getName() != obs)
		{
			_players.at(i)->help();
		}
	}
}

#endif // Header_h__
