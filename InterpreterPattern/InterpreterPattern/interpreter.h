#ifndef interpreter_h__
#define interpreter_h__

#include <iostream>
#include <string>

class Context;


class AbstractExpression
{
public:
	virtual ~AbstractExpression(){ }

	virtual void interpret(Context* ctx) = 0;

};



class TerminalExpression : public AbstractExpression
{
public:
	TerminalExpression(const std::string& statement) : _statement(statement){}
	virtual void interpret(Context* ctx)
	{
		std::cout << "Terminal Expression" << std::endl;
	}

protected:
	std::string _statement;
};


class NonterminalExpression : public AbstractExpression
{
public:
	NonterminalExpression(AbstractExpression *expression, int times)
		: _expression(expression), _times(times){ }

	virtual void interpret(Context* ctx)
	{
		for (int i = 0; i < _times; i++)
		{
			_expression->interpret(ctx);
		}
	}

protected:
	AbstractExpression*	_expression;
	int					_times;
};


class Context
{
public:
	Context(){ }
	~Context(){ }
};


#endif // interpreter_h__
