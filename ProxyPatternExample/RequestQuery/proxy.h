#ifndef proxy_h__
#define proxy_h__


/*
ĳ�����˾�н���ĳ��Ϣ��ѯ��˾���շ�������Ϣ��ѯϵͳ�Ŀ������񣬸�ϵͳ�Ļ����������£�
(1) �ڽ���������Ϣ��ѯ֮ǰ�û���Ҫͨ�������֤��ֻ�кϷ��û����ܹ�ʹ�øò�ѯϵͳ��
(2) �ڽ���������Ϣ��ѯʱϵͳ��Ҫ��¼��ѯ��־���Ա���ݲ�ѯ������ȡ��ѯ���á�
�������˾������Ա�������������Ϣ��ѯģ��Ŀ�������
��ϣ���ܹ���һ������ϵķ�ʽ��ԭ��ϵͳ���������֤����־��¼���ܣ�
�ͻ��˴������������ضԴ�ԭʼ��������Ϣ��ѯģ��������¹���֮���������Ϣ��ѯģ�飬
���ҿ����ڽ�����Ҫ�ڸ���Ϣ��ѯģ��������һЩ�µĹ��ܡ�
��ʹ�ô���ģʽ��Ʋ�ʵ�ָ��շ�������Ϣ��ѯϵͳ��
*/

#include <iostream>
#include <string>	


class AccessValidator
{
public:
	
	bool validateUser(const std::string& userID)
	{
		if (userID == "Frank")
			return true;
		else
			return false;
	}
};


class Logger
{
public:
	void log(const std::string& id)
	{
		std::cout << "userLog" << " " << id << std::endl;
	}
};



class Searcher
{
public:
	virtual ~Searcher(){ }

	virtual std::string doSearch(const std::string userID, const std::string keyword) = 0;
};


class RealSearch : public Searcher
{
public:

	virtual std::string  doSearch(const std::string userID, const std::string keyword)
	{
		std::cout << userID << " using keyword: " << keyword << " for search " << std::endl;
		return "search result";
	}
};


class ProxySearcher : public Searcher
{
public:
	std::string doSearch(const std::string userID, const std::string keyword)
	{
		if (!_validator->validateUser(userID))
		{
			std::cout << "Invalid user " << std::endl;
			return "";
		}

		_realSearch->doSearch(userID, keyword);

		_logger->log(userID);

		return "search result";
	}

	ProxySearcher()
	{
		_realSearch = new RealSearch();
		_validator = new AccessValidator();
		_logger = new Logger();
	}


private:
	RealSearch*		_realSearch;
	AccessValidator*	_validator;
	Logger*			_logger;
};





#endif // proxy_h__
