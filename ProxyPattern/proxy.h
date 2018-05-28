#ifndef proxy_h__
#define proxy_h__

#include <iostream>


class Subject
{
public:
	virtual ~Subject() { }

	virtual void request() = 0;
};


class RealSubject : public Subject
{
public:
	virtual void request()
	{
		std::cout << "Request Respond from Real Subject" << std::endl;
	}
};


class Proxy : public Subject
{
public:
	Proxy() : _realSubject(new RealSubject()){ }

	void preRequest()
	{
		std::cout << "Pre request" << std::endl;
	}

	void postRequest()
	{
		std::cout << "Post request" << std::endl;
	}


	virtual void request()
	{
		preRequest();
		_realSubject->request();
		postRequest();
	}


private:
	RealSubject*		_realSubject;
};


#endif // proxy_h__
