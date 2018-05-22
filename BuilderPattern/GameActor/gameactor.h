#ifndef gameactor_h__
#define gameactor_h__

/*
Sunny软件公司游戏开发小组决定开发一款名为《Sunny群侠传》的网络游戏，
该游戏采用主流的RPG(Role Playing Game,角色扮演游戏)模式，
玩家可以在游戏中扮演虚拟世界中的一个特定角色，
角色根据不同的游戏情节和统计数据（如力量、魔法、技能等）具有不同的能力，
角色也会随着不断升级而拥有更加强大的能力。

作为RPG游戏的一个重要组成部分，
需要对游戏角色进行设计，
而且随着该游戏的升级将不断增加新的角色。
不同类型的游戏角色，其性别、脸型、服装、发型等外部特性都有所差异，
例如“天使”拥有美丽的面容和披肩的长发，并身穿一袭白裙；而“恶魔”极其丑陋，
留着光头并穿一件刺眼的黑衣。

Sunny公司决定开发一个小工具来创建游戏角色，可以创建不同类型的角色并可以灵活增加新的角色。
*/

#include <iostream>
#include <string>


class Actor
{
public:
	void setType(const std::string& type)
	{
		_type = type;
	}
	std::string getType(){ return _type; }

	void setSex(const std::string& sex)
	{
		_sex = sex;
	}
	std::string getSex(){ return _sex; }

	void setFace(const std::string& face)
	{
		_face = face;
	}
	std::string getFace() { return _face; }

	void setCostume(const std::string& costume)
	{
		_costume = costume;
	}
	std::string getCostume(){ return _costume; }


private:
	std::string  _type;
	std::string  _sex;
	std::string  _face;
	std::string  _costume;
};


class ActorBuilder
{
public:
	ActorBuilder() : _actor(new Actor()){ }

	virtual ~ActorBuilder(){ }

	virtual void buildType() = 0;
	virtual void buildSex() = 0;
	virtual void buildFace() = 0;
	virtual void buildCostume() = 0;

	Actor* createActor(){ return _actor; }

protected:
	Actor*	_actor;
};


class HeroBuilder : public ActorBuilder
{
public:
	void buildType(){ _actor->setType("hero");}
	void buildSex(){ _actor->setSex("Male"); }
	void buildFace(){ _actor->setFace("Handsome"); }
	void buildCostume(){ _actor->setCostume("amaor"); }
};

class AngelBuilder : public ActorBuilder
{
public:
	void buildType(){ _actor->setType("angel"); }
	void buildSex(){ _actor->setSex("Female"); }
	void buildFace(){ _actor->setFace("Beauty"); }
	void buildCostume(){ _actor->setCostume("skirt"); }
};

class ActorController
{
public:
	Actor* construct(ActorBuilder *ab)
	{
		Actor *actor;
		ab->buildType();
		ab->buildSex();
		ab->buildCostume();
		ab->buildFace();
		actor = ab->createActor();

		return actor;
	}
};


#endif // gameactor_h__
