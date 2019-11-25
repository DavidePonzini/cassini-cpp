#include <iostream>
#include <string>

#include "Operazioni.h"

using namespace std;

int leggiInt()
{
	int a;

	cout << "Inserisci un numero (intero): ";
	cin >> a;
	
	return a;
}

float leggiFloat()
{
	float a;

	cout << "Inserisci un numero (con virgola): ";
	cin >> a;

	return a;
}

void somma()
{
	float a = leggiFloat();
	float b = leggiFloat();

	cout << a + b << endl;
}

void sottrazione()
{
	float a = leggiFloat();
	float b = leggiFloat();

	cout << a - b << endl;
}

void moltiplicazione()
{
	float a = leggiFloat();
	float b = leggiFloat();

	cout << a * b << endl;
}

void divisione()
{
	float a = leggiFloat();
	float b = leggiFloat();

	if (b != 0)
		cout << a / b << endl;
	else
		cout << "Impossibile dividere per 0" << endl;
}

void resto()
{
	int a = leggiInt();
	int b = leggiInt();

	cout << a % b << endl;
}

void valoreAssoluto()
{
	int a = leggiInt();

	cout << (a > 0 ? a : -a) << endl;
}
