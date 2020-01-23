/*
 *	IMPORTANTE: NON MODIFICARE QUESTO FILE!
 *		TUTTE LE MODIFICHE SARANNO SOVRASCRITTE PRIMA DI CORREGGERE LA VERIFICA
 *
 */

#pragma once
#include <string>
#include <vector>
#include "IngredientList.h"

using namespace std;


// "extern" is needed to avoid declaring the same variable multiple times if this file is included multiple times.
//     It basically tells the compiler that a variable called IngredientList exists somewhere in the program,
//     but is defined in another file (hence the term "extern").
// The actual value of the variable needs to be declared only once in the program,
//     by writing "Ingredients IngredientList;" in a .cpp file of your choice.
// If another file needs to access this variable, we only need to import this .h file,
//     and not the .cpp one defining its actual value.
//     In this way, we can prevent circular dependencies, which could make our code uncompilable.
extern IngredientList Ingredients;


namespace global
{
	// There's no need to declare this variable "extern", since its value is constant
	const string ACTIONS =
		"\n"
		"* Ricette\n"
		"*    1. Elenca\n"
		"*    2. Cerca per nome\n"
		"*    3. Cerca per ingrediente\n"
		"*    4. Cerca per calorie\n"
		"*    5. Leggi da input\n"
		"*    6. Leggi da file\n"
		"*    7. Salva su file\n"
		"*    8. Cancella\n"
		"* Ingredienti\n"
		"*    9. Mostra valori nutritivi\n"
		"*   10. Cambia valori nutritivi\n"
		"* Ricerca avanzata\n"
		"*   11. Trova ricetta con piu` calorie\n"
		"*   12. Trova ricetta con meno calorie\n"
		"*   13. Trova ricetta con piu` ingredienti\n"
		"*   14. Trova ricetta con meno ingredienti\n"
		"*   15. Trova ricette con pochi grassi ( < 10% )\n"
		"* Analisi\n"
		"*   16. Calcola media calorie di tutte le ricette\n"
		"*   17. Calcola distribuzione media carboidrati/grassi/proteine tra tutte le ricette\n"
		"* 0. Esci\n"
		"\n";

}

