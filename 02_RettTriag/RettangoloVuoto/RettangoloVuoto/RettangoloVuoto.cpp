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
			if (i == 0 || i == h - 1 || j == 0 || j == b-1)
				cout << '#';
			else
				cout << ' ';
		}
		cout << endl;
	}
}