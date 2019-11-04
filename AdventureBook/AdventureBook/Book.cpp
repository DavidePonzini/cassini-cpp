#include "Book.h"
#include "Page.h"

#include <stdexcept>
#include <iostream>


using namespace std;


Book::Book(string pagesDir, string firstPage, string logFile)
{
	PagesDir = pagesDir;
	FirstPage = firstPage;
	
	Log.open(logFile, ostream::out | ostream::trunc);

	LoadPage(firstPage);
}

Book::~Book()
{
	Log.close();
}

Page* Book::LoadPage(string filename)
{
	try {
		Page* page = Pages.at(filename);

		Log << "[Initialization] Page " << filename << " already loaded!" << endl;

		return page;
	}
	catch (out_of_range e)
	{
		Log << "[Initialization] Loading " << filename << endl;
		Page* newPage = new Page(PagesDir + '/' + filename, Pages.size()+1, this);
		
		Pages[filename] = newPage;

		return newPage;
	}
}

void Book::StartGame()
{
	Page* page = Pages.at(FirstPage);
	
	while (page)
	{
		system("cls");
	
		page->ShowText();
		page = page->GetNextPage();
	}

	cout << endl << "THE END" << endl;
}
