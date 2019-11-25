#include <iostream>

using namespace std;

void disegna(int h);

int main(int argc, char* argv[])
{
	if (argc < 2)
	{
		cerr << "Altezza non specificata" << endl;
		return 1;
	}

	int h = atoi(argv[1]);

	disegna(h);

	return 0;
}

void disegna(int h)
{
	// Se non capite perche` funziona, mettete DEBUG = true
	const bool DEBUG = false;

	for (int i = -h + 1; i < h; i++)	// attenzione al valore di i
	{
		if (DEBUG)
			cout << "i = " << i << "\t\t\th - abs(i) = " << h - abs(i) << endl;
		else
		{
			for (int j = 0; j < h - abs(i); j++)
				cout << '#';
			cout << endl;
		}
	}
}