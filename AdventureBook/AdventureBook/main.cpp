#include "Book.h"

#include <iostream>
#include <string>

using namespace std;


int main(int argc, char* argv[])
{
	if (argc < 4)
	{
		cerr << "Usage:" << endl;
		cerr << '\t' << argv[0] << " <pages folder> <first page> <log file>" << endl;

		exit(1);
	}

	string pagesDir = argv[1];
	string firstPageName = argv[2];
	string logFile = argv[3];

	Book* book = new Book(pagesDir, firstPageName, logFile);
	book->StartGame();
}
