#include <iostream>
#include <string>

#include "Operazioni.h"

using namespace std;

int main(int argc, char* argv[])
{
	if (argc < 2)
	{
		cerr << "Manca l'operazione da fare" << endl;
		return 1;
	}

	string op = argv[1];

	// Gestisco il valore assoluto a parte, visto che e` l'unico che ha un solo argomento
	if (op == "||") {
		if (argc < 3)
		{
			cerr << "Manca il numero" << endl;
			return 1;
		}

		valoreAssoluto(argv[2]);
	}
	else
	{
		if (argc < 4)
		{
			cerr << "Mancano i numeri" << endl;
			return 1;
		}

		if (op == "+")
			somma(argv[2], argv[3]);
		else if (op == "-")
			sottrazione(argv[2], argv[3]);
		else if (op == "*")
			moltiplicazione(argv[2], argv[3]);
		else if (op == "/")
			divisione(argv[2], argv[3]);
		else if (op == "%")
			resto(argv[2], argv[3]);
	}

}
