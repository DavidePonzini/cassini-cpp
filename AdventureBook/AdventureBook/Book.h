#pragma once

#include <map>
#include <string>
#include <fstream>

using namespace std;


class Page;


class Book
{
public:
	Book(string pagesDir, string firstPage, string logFile);
	~Book();

private:
	map<string, Page*> Pages;

	string PagesDir;
	string FirstPage;
	ofstream Log;

public:
	Page* LoadPage(string filename);
	void StartGame();
};

