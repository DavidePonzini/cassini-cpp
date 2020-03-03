#include <iostream>
#include <vector>
#include <string>
#include <fstream>

#include "Recipe.h"
#include "RecipeList.h"
#include "Ingredient.h"
#include "Global.h"


using namespace std;


int main(int argc, char* argv[])
{
	if (argc < 2)
	{
		cerr << strings::MissingArgumentMessage(argv[0]);
		return 1;
	}

	if(!Ingredients.ReadFile(argv[1]))
	{
		cerr << strings::ERR_READ_FILE;
		return 2;
	}

	RecipeList recipes;

	int choice = -1;
	while (choice != 0)
	{
		cout << strings::ACTIONS;

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
				cout << strings::ERR_NO_RECIPE;
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
			
			if (recipes.ReadRecipeFromFile(name))
				cout << strings::SUCCESS_ADD_RECIPE;
			else
				cout << strings::ERR_READ_FILE;
			
			break;
		}
		case 7:
		{
			string name;
			cout << "Nome ricetta: ";
			getline(cin >> ws, name);

			string filename;
			cout << "Nome file: ";
			getline(cin >> ws, filename);
			
			if (recipes.SaveRecipeToFile(name, filename))
				cout << strings::ERR_WRITE_FILE;
			else
				cout << strings::SUCCESS_SAVE_RECIPE;
			
			break;
		}
		case 8:
		{
			string name;
			cout << "Nome ricetta: ";
			getline(cin >> ws, name);
			
			if (recipes.DeleteRecipe(name))
				cout << strings::SUCCESS_DELETE_RECIPE;
			else
				cout << strings::ERR_NO_RECIPE;

			break;
		}
		case 9:
		{
			string name;
			cout << "Nome ingrediente: ";
			getline(cin >> ws, name);

			Ingredient* ingredient = Ingredients.Get(name);
			if (!ingredient) {
				cout << strings::ERR_NO_INGREDIENT;
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
			Ingredients.ChangeValues(name);
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
