#include <iostream>
#include <vector>
#include <string>
#include <fstream>

#include "Recipe.h"
#include "Recipes.h"
#include "Ingredient.h"


using namespace std;


void ReadIngredients(string filename, vector<Ingredient*>& ingredients);
Ingredient* FindIngredient(string name);
void ChangeIngredient(string name);


int main(int argc, char* argv[])
{
	if (argc < 2)
	{
		cerr << argv[0] << " <ingredients_file>" << endl;
		return 1;
	}

	vector<Ingredient*> Ingredients;

	try {
		ReadIngredients(argv[1], Ingredients);
	}
	catch (string& error) {
		cerr << "Error:" << error << endl;
	}

	Recipes recipes;

	int choice = 0;
	while (choice != 0)
	{
		cout << "Cosa vuoi fare?" << endl
			<< "1. Ricerca ricetta per nome" << endl
			<< "2. Ricerca ricetta per ingrediente" << endl
			<< "3. Ricerca ricetta per calorie" << endl
			<< "4. Leggi ricetta da input" << endl
			<< "5. Leggi ricetta da file" << endl
			<< "6. Salva ricetta su file" << endl
			<< "7. Cancella ricetta" << endl
			<< "8. Ricerca valori ingrediente" << endl
			<< "9. Cambia valori ingrediente" << endl
			<< "10. Trova ricetta con piu` calorie" << endl
			<< "11. Trova ricetta con meno calorie" << endl
			<< "12. Trova ricetta con piu` ingredienti" << endl
			<< "13. Trova ricetta con meno ingredienti" << endl
			<< "14. Trova ricette con pochi grassi ( < 10% )" << endl
			<< "15. Calcola media calorie di tutte le ricette" << endl
			<< "16. Calcola distribuzione carboidrati/grassi/proteine tra tutte le ricette" << endl
			<< "0. Esci" << endl
			<< endl;

		int tmp;
		cin >> tmp;
		switch (tmp)
		{
		case 1:
		{
			string name;
			cout << "Nome ricetta: ";
			cin >> name;
			recipes.FindRecipeByName(name);
			break;
		}
		case 2:
		{
			string name;
			cout << "Nome ingrediente: ";
			cin >> name;
			recipes.FindRecipeByIngredient(name);
			break;
		}
		case 3:
		{
			float cal_min, cal_max;
			cout << "Minimo calorie: ";
			cin >> cal_min;
			cout << "Massimo calorie: ";
			cin >> cal_max;
			recipes.FindRecipeByCalories(cal_min, cal_max);
			break;
		}
		case 4:
			recipes.ReadRecipeFromInput();
			break;
		case 5:
		{
			string name;
			cout << "Nome file: ";
			cin >> name;
			recipes.ReadRecipeFromFile(name);
			break;
		}
		case 6:
		{
			string name;
			cout << "Nome file: ";
			cin >> name;
			recipes.SaveRecipeToFile(name);
			break;
		}
		case 7:
		{
			string name;
			cout << "Nome ingrediente: ";
			cin >> name;
			FindIngredient(name);
			break;
		}
		case 8:
		{
			string name;
			cout << "Nome ingrediente: ";
			cin >> name;
			ChangeIngredient(name);
			break;
		}
		case 9:
			return 0;
		default:
			break;
		}
	}
}

void ReadIngredients(string filename, vector<Ingredient*>& ingredients)
{
	ifstream file(filename);

	if (!file)
		throw "Error reading file";

	while (!file.eof())
	{
		string name;
		float carbs, fats, proteins;
		file >> name >> carbs >> fats >> proteins;

		Ingredient* ingredient = new Ingredient(name, carbs, fats, proteins);
		ingredients.push_back(ingredient);
	}

	file.close();
}

Ingredient* FindIngredient(string name)
{
	return nullptr;
}

void ChangeIngredient(string name)
{

}
