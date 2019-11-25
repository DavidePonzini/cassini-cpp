#include <iostream>

using namespace std;

void disegna(int b, int h);

int main(int argc, char* argv[])
{
	if (argc < 3)
	{
		cerr << "Base ed altezza non specificate" << endl;
		return 1;
	}

	int b = atoi(argv[1]);
	int h = atoi(argv[2]);

	disegna(b, h);

	return 0;
}

void disegna(int b, int h)
{
	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < b; j++)
		{
			if (j == 1 || j == b - 2)	// seconda e penultima colonna
			{
				if (i > 0 && i < h - 1)
					cout << ' ';
				else
					cout << '#';
			}
			else
			if (i == 1 || i == h - 2)	// seconda e penultima riga
			{
				if (j > 0 && j < b - 1)
					cout << ' ';
				else
					cout << '#';
			}
			else
				cout << '#';
		}
		cout << endl;
	}
}