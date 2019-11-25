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
	/*
		Il trucco sta nell'intuire che se sono in una riga pari devo disegnare tutti i # in posizioni pari,
		mentre se sono in una riga dispari devo disegnare i # solo nelle posizioni dispari.

		In altre parole, le celle da colorare sono quelle in cui la riga e la colonna sono entrambe pari (od entrambe dispari).
		Ragionando si deduce che:
			- Riga pari, colonna pari (COLORO):
				r % 2 = 0
				c % 2 = 0
			- Riga dispari, colonna dispari (COLORO):
				r % 2 = 1
				c % 2 = 1

			- Riga dispari, colonna pari (NON COLORO):
				r % 2 = 1
				c % 2 = 0
			- Riga pari, colonna dispari (NON COLORO):
				r % 2 = 0
				c % 2 = 1

		Come vediamo, nelle righe in cui devo colorare, i resti sono uguali: questa diventa quindi la condizione del mio if.
	*/
	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < b; j++)
		{
			cout << (i % 2 == j % 2 ? '#' : ' ');
		}
		cout << endl;
	}
}