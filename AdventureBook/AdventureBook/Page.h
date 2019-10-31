#pragma once


#include <string>
#include <vector>

using namespace std;


class Page
{
public:
	Page(string filename);

public:
	int Id;

private:
	string Text;
	vector<Page*> Actions;

public:
	void ShowText();
	Page* SelectAction();

private:
	void ReadText(string filename);
};

