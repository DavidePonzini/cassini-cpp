#include <iostream>
#include <string>
#include <time.h>

using namespace std;

int main(int argc, char* argv[])
{
	srand(time(NULL));

	if (argc < 3)
	{
		cerr << argv[0] << " <base> <altezza>" << endl;
		return 1;
	}

	int length = atoi(argv[1]);
	int height = atoi(argv[2]);

	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < length; j++)
		{
			if (i == 0 || i == height - 1 || j == 0 || j == length - 1)
				cout << "#";
			else
				cout << (rand() % 2 ? "#" : " ");
		}

		cout << endl;
	}

}
