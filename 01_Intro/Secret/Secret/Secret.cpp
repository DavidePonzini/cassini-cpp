#include <iostream>
#include <string>

using namespace std;

string lowercase(string s);

int main()
{
	string s;

	cout << "Type something... ";
	getline(cin, s);

	cout << "You typed: " << s << endl;

	string s1 = lowercase(s);
	if (s1 == "secret")
		cout << "You discovered the secret message!" << endl;

	return 0;
}

string lowercase(string s)
{
	string res = "";
	
	for (int i = 0; i < s.size(); i++)
		res += tolower(s[i]);
	
	return res;
}
