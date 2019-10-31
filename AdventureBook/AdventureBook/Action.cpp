#include "Action.h"
#include "Page.h"

Action::Action(Page* destination, string text)
{
	Destination = destination;
	Text = text;
}

void Action::Execute()
{
	Destination->ShowText();
}


