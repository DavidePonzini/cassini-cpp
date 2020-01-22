#include <iostream>
#include <vector>
#include <string>
#include <fstream>

#include "Recipe.h"
#include "Recipes.h"
#include "Ingredient.h"
#include "Global.h"


using namespace std;


int main(int argc, char* argv[])
{
	if (argc < 2)
	{
		cerr << argv[0] << " <ingredients_file>" << endl;
		return 1;
	}

	if(!global::IngredientList.ReadFile(argv[1]))
	{
		cerr << "Error reading file" << endl;
		return 2;
	}

	Recipes recipes;

	int choice = -1;
	while (choice != 0)
	{
		cout << global::ACTIONS;

		int tmp;
		cin >> tmp;
		switch (tmp)
		{
		case 1:
			for (auto recipe : recipes.GetRecipes())
				cout << recipe->GetName() << endl;
			break;
		case 2:
		{
			string name;
			cout << "Nome ricetta: ";
			getline(cin >> ws, name);
			
			Recipe* recipe = recipes.FindRecipeByName(name);
			if (!recipe)
				cout << "La ricetta non esiste" << endl;
			else
				recipe->Print();
			
			break;
		}
		case 3:
		{
			string name;
			cout << "Nome ingrediente: ";
			getline(cin >> ws, name);

			for (auto recipe : recipes.FindRecipesByIngredient(name))
				cout << recipe->GetName();
			
			break;
		}
		case 4:
		{
			float cal_min, cal_max;
			cout << "Minimo calorie: ";
			cin >> cal_min;
			cout << "Massimo calorie: ";
			cin >> cal_max;
			
			for (auto recipe : recipes.FindRecipesByCalories(cal_min, cal_max))
				cout << recipe->GetName();

			break;
		}
		case 5:
			recipes.ReadRecipeFromInput();
			break;
		case 6:
		{
			string name;
			cout << "Nome file: ";
			getline(cin >> ws, name);
			
			recipes.ReadRecipeFromFile(name);
			
			break;
		}
		case 7:
		{
			string name;
			cout << "Nome file: ";
			getline(cin >> ws, name);
			
			recipes.SaveRecipeToFile(name);
			
			break;
		}
		case 8:
		{
			string name;
			cout << "Nome ricetta: ";
			getline(cin >> ws, name);
			
			if (recipes.DeleteRecipe(name))
				cout << "Ricetta cancellata" << endl;
			else
				cout << "Ricetta non esistente" << endl;

			break;
		}
		case 9:
		{
			string name;
			cout << "Nome ingrediente: ";
			getline(cin >> ws, name);

			Ingredient* ingredient = global::IngredientList.Get(name);
			if (!ingredient) {
				cout << "L'ingrediente non esiste" << endl;
				break;
			}

			ingredient->Print();

			break;
		}
		case 10:
		{
			string name;
			cout << "Nome ingrediente: ";
			getline(cin >> ws, name);
			global::IngredientList.ChangeValues(name);
			break;
		}
		case 11:
			cout << recipes.FindRecipeWithMostCalories()->GetName() << endl;
			break;
		case 12:
			cout << recipes.FindRecipeWithLeastCalories()->GetName() << endl;
			break;
		case 13:
			cout << recipes.FindRecipeWithMostIngredients()->GetName() << endl;
			break;
		case 14:
			cout << recipes.FindRecipeWithLeastIngredients()->GetName() << endl;
			break;
		case 15:
			for (auto recipe : recipes.FindRecipesLowFat())
				cout << recipe->GetName() << endl;
			break;
		case 16:
			cout << recipes.GetAverageCalories() << " cals" << endl;
			break;
		case 17:
		{
			float* distribution = recipes.GetMacronutrientsDistribution();
			cout << "Carboidrati: " << distribution[0] * 100 << "%" << endl;
			cout << "Grassi:      " << distribution[1] * 100 << "%" << endl;
			cout << "Proteine:    " << distribution[2] * 100 << "%" << endl;
			break;
		}
		case 0:
			return 0;
		default:
			break;
		}
	}
}
