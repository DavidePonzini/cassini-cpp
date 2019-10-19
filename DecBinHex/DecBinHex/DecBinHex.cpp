#include <iostream>
#include <algorithm>

#include "DecBinHex.h"

using namespace std;

const int MAX_BASE = 37;

int main()
{
	int base = MAX_BASE + 1;
	while(true)
	{
		cout << "Insert base: ";
		cin >> base;

		if (base < 2)
		{
			cout << "Value is not valid" << endl;
			continue;
		}
		if (base > MAX_BASE)
		{
			cout << "Value must be < " + MAX_BASE << endl;
			continue;
		}

		break;
	}
	
	int num;
	cout << "Insert number to convert: ";
	cin >> num;

	cout << "Result: " << convert_num(num, base) << endl;
}

string dec2bin(int n)
{	
	return convert_num(n, 2);
}

string dec2hex(int n)
{
	return "0x" + convert_num(n, 16);
}

string convert_num(int n, int base)
{
	string res = "";

	while (n)
	{
		int r = n % base;
		res += convert_digit(r);

		n /= base;
	}

	reverse(res.begin(), res.end());

	return res;
}

char convert_digit(int n)
{
	if (n < 0)
		return '*';
	if (n > 37)
		return '*';

	if (n < 10)
		return '0' + n;
	return 'a' + n - 10;
}