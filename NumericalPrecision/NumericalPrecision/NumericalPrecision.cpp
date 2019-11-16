// NumericalPrecision.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#define INCR 200000

#include <iostream>

using namespace std;

int main(int argc, char* argv[])
{
	int x = 0;
	int next = x + INCR;

	while (next > x)
	{
		cout << next << endl;

		x = next;
		next += INCR;
	}

	cout << "   x: " << x << endl;
	cout << "next: " << next;
	
	return 0;
}
