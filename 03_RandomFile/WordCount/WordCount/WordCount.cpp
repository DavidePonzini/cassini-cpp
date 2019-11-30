#include <iostream>
#include <map>
#include <string>
#include <fstream>


using namespace std;


map<string, int> ReadFile(char*);
string StripPunctuation(string);
void PrintCounter(map<string, int>);


int main(int argc, char* argv[])
{
	if (argc < 2)
	{
		cerr << "Missing file name" << endl;
		return 1;
	}

	map<string, int> counter = ReadFile(argv[1]);
	PrintCounter(counter);
	
	return 0;
}

map<string, int> ReadFile(char* filename)
{
	map<string, int> counter;

	ifstream is(filename);

	string word;
	while (is >> word)
	{
		word = StripPunctuation(word);

		counter[word] += 1;
	}

	return counter;
	
}

string StripPunctuation(string s)
{
	string res;
	
	for (unsigned int i = 0; i < s.size(); i++)
		if (!ispunct(s[i]))
			res += s[i];

	return res;
}

void PrintCounter(map<string, int> counter)
{
	for (map<string, int>::iterator itr = counter.begin(); itr != counter.end(); itr++)
		if(itr->second > 1)
			cout << itr->first << " (" << itr->second << ")" << endl;
		else
			cout << itr->first << endl;
}