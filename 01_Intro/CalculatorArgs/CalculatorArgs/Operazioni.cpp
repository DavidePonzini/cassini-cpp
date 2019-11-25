#include <iostream>
#include <string>

#include "Operazioni.h"

using namespace std;

void somma(char* x, char* y)
{
	float a = atof(x);
	float b = atof(y);

	cout << a + b << endl;
}

void sottrazione(char* x, char* y)
{
	float a = atof(x);
	float b = atof(y);

	cout << a - b << endl;
}

void moltiplicazione(char* x, char* y)
{
	float a = atof(x);
	float b = atof(y);

	cout << a * b << endl;
}

void divisione(char* x, char* y)
{
	float a = atof(x);
	float b = atof(y);

	if (b != 0)
		cout << a / b << endl;
	else
		cout << "Impossibile dividere per 0" << endl;
}

void resto(char* x, char* y)
{
	int a = atoi(x);
	int b = atoi(y);

	cout << a % b << endl;
}

void valoreAssoluto(char* x)
{
	float a = atof(x);

	cout << (a > 0 ? a : -a) << endl;
}
