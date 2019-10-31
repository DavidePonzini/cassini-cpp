#include "Page.h"
#include "Constants.h"

#include <fstream>
#include <sstream>
#include <iostream>



Page::Page(string filename)
{
	Id = -1;

	ReadText(filename);
}

void Page::ShowText()
{
	system("cls");

	cout << "Pagina " << Id << endl << endl;
	
	cout << Text << endl;

	Page* newPage = SelectAction();
}

Page* Page::SelectAction()
{
	if (Actions.size() == 0)
	{
		cout << endl << END_MESSAGE << endl;

		return nullptr;
	}

	int action = -1;
	
	do
	{
		cout << "Scegli un'azione: ";
		cin >> action;
	} while (action < 0 || action >= Actions.size());
	
	return Actions[action];
}

void Page::ReadText(string filename)
{
	ifstream inFile(filename);

	if (!inFile)
		throw ERR_FILE_READ;

	stringstream ss;
	ss << inFile.rdbuf();
	Text = ss.str();

	inFile.close();
}
