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
		cerr << strings::error::MissingArgumentMessage(argv[0]);
		return 1;
	}

	if(!Ingredients.ReadFile(argv[1]))
	{
		cerr << strings::error::READ_FILE;
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
			cout << strings::input::RECIPE_NAME;
			getline(cin >> ws, name);
			
			Recipe* recipe = recipes.FindRecipeByName(name);
			if (!recipe)
				cout << strings::error::NO_RECIPE;
			else
				recipe->Print();
			
			break;
		}
		case 3:
		{
			string name;
			cout << strings::input::INGREDIENT_NAME;
			getline(cin >> ws, name);

			for (auto recipe : recipes.FindRecipesByIngredient(name))
				cout << recipe->GetName();
			
			break;
		}
		case 4:
		{
			float cal_min, cal_max;
			cout << strings::input::CALS_MIN;
			cin >> cal_min;
			cout << strings::input::CALS_MAX;
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
			cout << strings::input::FILE_NAME;
			getline(cin >> ws, name);
			
			if (recipes.ReadRecipeFromFile(name))
				cout << strings::success::ADD_RECIPE;
			else
				cout << strings::error::READ_FILE;
			
			break;
		}
		case 7:
		{
			string name;
			cout << strings::input::RECIPE_NAME;
			getline(cin >> ws, name);

			string filename;
			cout << strings::input::FILE_NAME;
			getline(cin >> ws, filename);
			
			if (recipes.SaveRecipeToFile(name, filename))
				cout << strings::error::WRITE_FILE;
			else
				cout << strings::success::SAVE_RECIPE;
			
			break;
		}
		case 8:
		{
			string name;
			cout << strings::input::RECIPE_NAME;
			getline(cin >> ws, name);
			
			if (recipes.DeleteRecipe(name))
				cout << strings::success::DELETE_RECIPE;
			else
				cout << strings::error::NO_RECIPE;

			break;
		}
		case 9:
		{
			string name;
			cout << strings::input::INGREDIENT_NAME;
			getline(cin >> ws, name);

			Ingredient* ingredient = Ingredients.Get(name);
			if (!ingredient) {
				cout << strings::error::NO_INGREDIENT;
				break;
			}

			ingredient->Print();

			break;
		}
		case 10:
		{
			string name;
			cout << strings::input::INGREDIENT_NAME;
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
