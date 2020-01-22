#include <iostream>
#include <vector>
#include <string>
#include <fstream>

#include "Recipe.h"
#include "Recipes.h"
#include "Ingredient.h"


using namespace std;


bool ReadIngredients(string filename, vector<Ingredient*>& ingredients);
Ingredient* FindIngredient(string name, vector<Ingredient*>& ingredients);
void ChangeIngredient(string name, vector<Ingredient*>& ingredients);


int main(int argc, char* argv[])
{
	if (argc < 2)
	{
		cerr << argv[0] << " <ingredients_file>" << endl;
		return 1;
	}

	vector<Ingredient*> Ingredients;

	if(!ReadIngredients(argv[1], Ingredients))
	{
		cerr << "Error reading file" << endl;
	}

	Recipes recipes;

	int choice = -1;
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
			recipes.FindRecipesByIngredient(name);
			break;
		}
		case 3:
		{
			float cal_min, cal_max;
			cout << "Minimo calorie: ";
			cin >> cal_min;
			cout << "Massimo calorie: ";
			cin >> cal_max;
			recipes.FindRecipesByCalories(cal_min, cal_max);
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
			cout << "Nome ricetta: ";
			cin >> name;
			
			if (recipes.DeleteRecipe(name))
				cout << "Ricetta cancellata" << endl;
			else
				cout << "Ricetta non esistente" << endl;

			break;
		}
		case 8:
		{
			string name;
			cout << "Nome ingrediente: ";
			cin >> name;

			Ingredient* ingredient = FindIngredient(name, Ingredients);
			if (!ingredient) {
				cout << "L'ingrediente non esiste" << endl;
				break;
			}

			ingredient->Print();

			break;
		}
		case 9:
		{
			string name;
			cout << "Nome ingrediente: ";
			cin >> name;
			ChangeIngredient(name, Ingredients);
			break;
		}
		case 0:
			return 0;
		default:
			break;
		}
	}
}

bool ReadIngredients(string filename, vector<Ingredient*>& ingredients)
{
	ifstream file(filename);

	if (!file)
		return false;

	string buf;
	getline(file, buf); // discard first line
	cerr << buf << endl;

	while (!getline(file, buf, ','))
	{
		string name = buf;
		cerr << buf << endl;

		getline(file, buf, ',');
		float carbs = stof(buf);

		getline(file, buf, ',');
		float fats = stof(buf);

		getline(file, buf);
		float proteins = stof(buf);
		

		Ingredient* ingredient = new Ingredient(name, carbs, fats, proteins);
		ingredients.push_back(ingredient);
	}

	file.close();

	return true;
}

Ingredient* FindIngredient(string name, vector<Ingredient*>& ingredients)
{
	for (auto ingredient : ingredients)
	{
		if (ingredient->GetName() == name)
			return ingredient;
	}

	return nullptr;
}

void ChangeIngredient(string name, vector<Ingredient*>& ingredients)
{

}
