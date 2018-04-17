#ifndef TVContorl_h__
#define TVContorl_h__

/*
Question:
	示例1：实现一个电视机遥控器功能
Answer：
电视机是请求的接收者，
遥控器是请求的发送者，
遥控器上有一些按钮，不同的按钮对应电视机的不同操作。
抽象命令角色由一个命令接口来扮演，有三个具体的命令类实现了抽象命令接口，
这三个具体命令类分别代表三种操作：
打开电视机、
关闭电视机
和切换频道。
*/

#include <iostream>
#include <vector>
#include <map>


class Television
{
public:
	Television(){ }
	virtual ~Television(){ }

	void open()
	{
		std::cout << "Open TV" << std::endl;
	}

	void close()
	{
		std::cout << "Close TV" << std::endl;
	}

	void switchChannel()
	{
		std::cout << "Switch Channel" << std::endl;
	}
};


class ITVCommand
{
public:
	ITVCommand(){ }
	virtual ~ITVCommand(){ }

	virtual void execute() abstract;
};


class TVOpenCommand : public ITVCommand
{
public:
	TVOpenCommand(Television *tv) : _tv(tv){ }
	virtual ~TVOpenCommand(){ }

	virtual void execute() override
	{
		if (_tv)
			_tv->open();
	}

private:
	Television * _tv;
};

class TVCloseCommand : public ITVCommand
{
public:
	TVCloseCommand(Television *tv) : _tv(tv) { }
	virtual void execute() override
	{
		if (_tv)
			_tv->close();
	}

private:
	Television * _tv;
};

class TVSwitchChannelCommand : public ITVCommand
{
public:
	TVSwitchChannelCommand(Television *tv) : _tv(tv) { }
	virtual ~TVSwitchChannelCommand() { }

	virtual void execute() override
	{
		if (_tv)
			_tv->switchChannel();
	}

private:
	Television * _tv;
};


class TVController
{
public:
	TVController()
	{
		
	}

	virtual ~TVController()
	{

	}

	void setCommand(std::string commandName, ITVCommand* command)
	{
		_commandMap[commandName] = command;
	}

	void ButtonClicked(std::string commandName)
	{
		auto iter = _commandMap.find(commandName);
		if (iter != _commandMap.end())
		{
			ITVCommand *command = _commandMap[commandName];
			command->execute();
		}
	}

private:
	std::map<std::string, ITVCommand*>		_commandMap;
};

#endif // TVContorl_h__
