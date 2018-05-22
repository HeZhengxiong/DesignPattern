#ifndef gameactor_h__
#define gameactor_h__

/*
Sunny�����˾��Ϸ����С���������һ����Ϊ��SunnyȺ��������������Ϸ��
����Ϸ����������RPG(Role Playing Game,��ɫ������Ϸ)ģʽ��
��ҿ�������Ϸ�а������������е�һ���ض���ɫ��
��ɫ���ݲ�ͬ����Ϸ��ں�ͳ�����ݣ���������ħ�������ܵȣ����в�ͬ��������
��ɫҲ�����Ų���������ӵ�и���ǿ���������

��ΪRPG��Ϸ��һ����Ҫ��ɲ��֣�
��Ҫ����Ϸ��ɫ������ƣ�
�������Ÿ���Ϸ�����������������µĽ�ɫ��
��ͬ���͵���Ϸ��ɫ�����Ա����͡���װ�����͵��ⲿ���Զ��������죬
���硰��ʹ��ӵ�����������ݺ�����ĳ���������һϮ��ȹ��������ħ�������ª��
���Ź�ͷ����һ�����۵ĺ��¡�

Sunny��˾��������һ��С������������Ϸ��ɫ�����Դ�����ͬ���͵Ľ�ɫ��������������µĽ�ɫ��
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
