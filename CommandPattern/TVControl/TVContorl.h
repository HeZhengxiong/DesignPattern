#ifndef TVContorl_h__
#define TVContorl_h__

/*
Question:
	ʾ��1��ʵ��һ�����ӻ�ң��������
Answer��
���ӻ�������Ľ����ߣ�
ң����������ķ����ߣ�
ң��������һЩ��ť����ͬ�İ�ť��Ӧ���ӻ��Ĳ�ͬ������
���������ɫ��һ������ӿ������ݣ������������������ʵ���˳�������ӿڣ�
����������������ֱ�������ֲ�����
�򿪵��ӻ���
�رյ��ӻ�
���л�Ƶ����
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
