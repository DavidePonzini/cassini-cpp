#pragma once


#include <string>


using namespace std;

class Page;


class Action
{
public:
	Action(Page* destination, string text);

private:
	Page* Destination;

public:
	string Text;

public:
	void Execute();
};

