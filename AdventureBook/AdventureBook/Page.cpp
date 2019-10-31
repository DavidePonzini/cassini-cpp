#include "Page.h"
#include "Constants.h"
#include "Action.h"

#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>



Page::Page(string filename)
{
	Id = -1;

	cerr << "[Initialization] " << filename << endl;

	ReadText(PAGES_DIR + '/' + filename);
}

void Page::ShowText()
{
	system("cls");

	cout << "Pagina " << Id << endl << endl;
	cout << Text << endl;

	SelectAction();
}

void Page::SelectAction()
{
	if (Actions.size() == 0)
	{
		cout << endl << END_MESSAGE << endl;

		return;
	}

	int action = -1;
	
	do
	{
		cout << endl << "====================" << endl;
		cout << "Scegli un'azione:" << endl;

		for (int i = 0; i < Actions.size(); i++) {
			cout << "\t(" << i << ") " << Actions[i]->Text << endl;
		}
		
		cin >> action;
	} while (action < 0 || action >= Actions.size());
	
	Actions[action]->Execute();
}

void Page::ReadText(string filename)
{
	ifstream file(filename);

	if (!file) 
		throw Error::ERR_FILE_READ;

	string buf;

	// get text until first tag
	while (getline(file, buf, '['))
	{
		Text += buf;


		string tagText, tagDest;
		getline(file, tagText, '|');
		getline(file, tagDest, ']');

		if (tagText != "")
			Actions.push_back(new Action(new Page(tagDest), tagText));
	}

	file.close();
}

void Page::ParseText()
{

}