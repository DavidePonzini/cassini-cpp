#include <iostream>

using namespace std;

int main(int argc, char* argv[])
{
	for (int i = 0; i < argc; i++)
		cout << "[Arg " << i << "] " << argv[i] << endl;

	return 0;
}
