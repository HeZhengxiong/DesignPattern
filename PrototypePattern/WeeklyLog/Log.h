#ifndef Log_h__
#define Log_h__

#include <iostream>
#include <string>



class Log
{
public:
	virtual ~Log() { }
	virtual Log* clone() = 0;
private:
	std::string		_name;
	std::string		_date;
	std::string		_content;

public:
	void setName(const std::string& name)
	{
		_name = name;
	}

	std::string getName() const { return _name; }

	void setDate(const std::string& date)
	{
		_date = date;
	}

	std::string getDate() const { return _date; }

	void setContent(const std::string& content)
	{
		_content = content;
	}

	std::string getContent() const { return _content; }
};


class WeeklyLog : public Log
{
	virtual Log* clone() override
	{
		Log *log = new WeeklyLog();
		log->setName(this->getName());
		log->setDate(this->getDate());
		log->setContent(this->getContent());
		return log;
	}
};








#endif // Log_h__
