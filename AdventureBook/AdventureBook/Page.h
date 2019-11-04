#pragma once

#define PAGE_LEN 100

#include <string>
#include <vector>


using namespace std;


struct Action;
class Book;


class Page
{
public:
	Page(string filename, int id, Book* book);

public:
	int Id;
	Book* MyBook;
	string Filename;

private:
	string Text;
	vector<Action*> Actions;

public:
	void ShowText();
	Page* GetNextPage();

private:
	void ReadText(string filename);
	void ShowActions();
	Page* const GetActionDestination(int action);
};

