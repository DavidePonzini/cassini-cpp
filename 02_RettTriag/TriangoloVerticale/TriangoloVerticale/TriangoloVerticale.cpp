#include <iostream>

using namespace std;

void disegna(int h);
void disegnaRiga(int padding, int row);

int main(int argc, char* argv[])
{
	if (argc < 2)
	{
		cerr << "Altezza non specificata" << endl;
		return 1;
	}

	int h = atoi(argv[1]);

	disegna(h);

	return 0;
}

void disegna(int h)
{
	/*
		Questa volta devo calcolare in anticipo la dimensione della riga piu` lunga (la base),
		per poter mettere il numero corretto di spazi in cima.

		Con un po' di matematica, o esperimenti, noto che la base e` h * 2 - 1.
		
		A questo punto tengo anche conto dell'altezza per capire quanti # devo mettere in quella riga,
		il resto sara` riempito da spazi
	*/
	
	int lengthMax = h * 2 - 1;

	for (int i = 0; i < h; i++)
	{
		int row = i * 2 + 1;					// lunghezza di una riga (carattere #)
		int padding = (lengthMax - row) / 2;	// il resto della riga saranno spazi (ovviamente divido per 2 perche` mi serve solo la parte a sinistra)

		disegnaRiga(padding, row);
	}
}

void disegnaRiga(int padding, int row)
{
	for (int i = 0; i < padding; i++)
		cout << ' ';
	for (int i = 0; i < row; i++)
		cout << '#';
	cout << endl;
}