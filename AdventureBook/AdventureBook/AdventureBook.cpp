#include "Page.h"

#include <iostream>
#include <string>

using namespace std;


int main(int argc, char* argv[])
{
	if (argc < 3)
	{
		cerr << "Usage:" << endl;
		cerr << '\t' << argv[0] << "<pages folder> <first page>" << endl;

		exit(1);
	}

	string dir = argv[1];
	string firstPageName = argv[2];

	Page* firstPage = new Page(dir + '/' + firstPageName);
	
	firstPage->ShowText();
}
