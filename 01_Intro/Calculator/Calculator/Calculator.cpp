#include <iostream>
#include <string>

#include "Operazioni.h"

using namespace std;

int main()
{
    cout << "Inserire operazione:" << endl;
	cout << "\t+ Somma\n";
	cout << "\t- Sottrazione\n";
	cout << "\t* Moltiplicazione\n";
	cout << "\t/ Divisione\n";
	cout << "\t% Resto della divisione\n";
	cout << "\t|| Valore assoluto\n";
	
	string op;
	cin >> op;

	if (op == "||")
		valoreAssoluto();
	else if (op == "+")
		somma();
	else if (op == "-")
		sottrazione();
	else if (op == "*")
		moltiplicazione();
	else if (op == "/")
		divisione();
	else if (op == "%")
		resto();
}
