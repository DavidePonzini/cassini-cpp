/*
 *	IMPORTANTE: NON MODIFICARE QUESTO FILE!
 *		TUTTE LE MODIFICHE SARANNO SOVRASCRITTE PRIMA DI CORREGGERE LA VERIFICA
 *
 */

#include "Global.h"
#include "IngredientList.h"

 // Initialization of extern variable defined in Global.
IngredientList Ingredients;


const string strings::error::MissingArgumentMessage(char* argv_0)
{
	string programName(argv_0); // convert char* to string (using string constructor)

	return "Usage:\n\t" + programName + " <ingredients_file>\n";
}
