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
//     by writing "Ingredients IngredientList;" in any .cpp file.
// If another file needs to access this variable, we only need to import this .h file,
//     and not the .cpp one defining its actual value.
//     In this way, we can prevent circular dependencies, which could make our code uncompilable.
extern IngredientList Ingredients;


namespace strings
{
	/* There's no need to declare these variables "extern", since their values are constant */

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

	namespace input
	{
		const string FIRST_INGREDIENT_NAME = "Nome ingrediente (\"stop\" per terminare): ";
		const string NEXT_INGREDIENT_NAME = "Nome prossimo ingrediente (\"stop\" per terminare): ";
		const string RECIPE_NAME = "Nome ricetta: ";
		const string INGREDIENT_NAME = "Nome ingrediente: ";
		const string FILE_NAME = "Nome file: ";
		const string CALS_MIN = "Minimo calorie: ";
		const string CALS_MAX = "Massimo calorie: ";
		const string QUANTITY = "Quantita`: ";
	}
	
	namespace error
	{
		const string READ_FILE = "Impossibile leggere il file\n";
		const string WRITE_FILE = "Impossibile salvare il file\n";
		const string NO_RECIPE = "La ricetta non esiste\n";
		const string NO_INGREDIENT = "L'ingrediente non esiste\n";

		const string MissingArgumentMessage(char* argv_0);
	}
	
	namespace retry
	{
		const string NO_INGREDIENT = "L'ingrediente non esiste, riprova: ";
		const string RECIPE_NAME_EXISTS = "La ricetta esiste gia`, scegli un altro nome: ";
		const string AMOUNT_NEGATIVE = "La quantita` deve essere maggiore di 0, riprova: ";
	}
	
	namespace success
	{
		const string ADD_RECIPE = "Ricetta aggiunta\n";
		const string SAVE_RECIPE = "Ricetta salvata\n";
		const string DELETE_RECIPE = "Ricetta cancellata\n";
	}

}
