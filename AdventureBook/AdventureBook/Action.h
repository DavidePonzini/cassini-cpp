#pragma once


#include <string>


using namespace std;


class Page;


struct Action
{
	Action(Page* destination, string text);

	Page* Destination;
	string Text;
};

