#include "Page.h"
#include "Error.h"
#include "Action.h"
#include "Book.h"

#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>



Page::Page(string filename, int id, Book* book)
{
	Id = id;
	MyBook = book;
	Filename = filename;
	
}

void Page::ShowText()
{
	ReadText(Filename);

	for (int i = 0; i < (PAGE_LEN - 8)/2; i++)
		cout << ' ';
	cout << "Pagina " << Id << endl;
	
	for (int i = 0; i < PAGE_LEN; i++)
		cout << '=';
	cout << endl;

	cout << Text << endl;

	for (int i = 0; i < PAGE_LEN; i++)
		cout << '=';
	cout << endl;

}

Page* Page::GetNextPage()
{
	if (Actions.size() == 0)
		return nullptr;

	Page* destination = nullptr;
	
	while (!destination)
	{
		ShowActions();

		cout << endl << "Scegli un'azione... ";
		
		int action;
		cin >> action;

		destination = GetActionDestination(action);
	}
	
	return destination;
}

void Page::ReadText(string filename)
{
	if (!Text.empty())
		return;

	ifstream file(filename);

	if (!file) 
		throw Error::ERR_FILE_READ;

	string buf;

	// get text until first tag
	while (getline(file, buf, '['))
	{
		Text += buf;

		string text, dest;
		getline(file, text, '|');
		getline(file, dest, ']');

		if (text != "")
		{
			Page* destPage = MyBook->LoadPage(dest);
			Actions.push_back(new Action(destPage, text));

			Text += to_string(destPage->Id);
		}
	}

	file.close();
}

void Page::ShowActions()
{
	cout << endl <<  "Cosa vuoi fare?" << endl;

	for (int i = 0; i < Actions.size(); i++)
		cout << "  [" << Actions[i]->Destination->Id << "]  " << Actions[i]->Text << endl;
}

Page* const Page::GetActionDestination(int action)
{
	for (int i = 0; i < Actions.size(); i++)
	{
		Page* Destination = Actions[i]->Destination;
		
		if (action == Destination->Id)
			return Destination;
	}
	
	return nullptr;
}
