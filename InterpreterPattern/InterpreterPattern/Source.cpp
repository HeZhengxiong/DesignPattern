#include "interpreter.h"

int main()
{
	Context *myContext = new Context;
	AbstractExpression *terminalExpression = new TerminalExpression("T");
	AbstractExpression *nonTerminal = new NonterminalExpression(terminalExpression, 3);

	nonTerminal->interpret(myContext);
}