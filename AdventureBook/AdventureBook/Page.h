#pragma once


#include <string>
#include <vector>


using namespace std;

class Action;


class Page
{
public:
	Page(string filename);

public:
	int Id;

private:
	string Text;
	vector<Action*> Actions;

public:
	void ShowText();
	void SelectAction();

private:
	void ReadText(string filename);
	void ParseText();
};

