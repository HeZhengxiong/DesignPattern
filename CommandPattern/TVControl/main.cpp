#include "TVContorl.h"


int main()
{
	Television *television = new Television();

	TVOpenCommand *openCommand = new TVOpenCommand(television);
	TVCloseCommand *closeCommand = new TVCloseCommand(television);
	TVSwitchChannelCommand *switchCommand = new TVSwitchChannelCommand(television);

	TVController *tvController = new TVController();
	tvController->setCommand("open", openCommand);
	tvController->setCommand("close", closeCommand);
	tvController->setCommand("switch", switchCommand);

	tvController->ButtonClicked("open");
	tvController->ButtonClicked("switch");
	tvController->ButtonClicked("close");

	return 0;
}