#include <iostream>
#include <fstream>

#include "RecipeList.h"
#include "Global.h"

using namespace std;


vector<Recipe*> RecipeList::GetRecipes()
{
	return Recipes;
}

Recipe* RecipeList::FindRecipeByName(string name)
{
	for (auto recipe : Recipes)
	{
		if (recipe->GetName() == name)
			return recipe;
	}

	return nullptr;
}

vector<Recipe*> RecipeList::FindRecipesByIngredient(string name)
{
	vector<Recipe*> result;

	for (auto recipe : Recipes)
	{
		if (recipe->ContainsIngredient(name))
			result.push_back(recipe);
	}

	return result;
}

vector<Recipe*> RecipeList::FindRecipesByCalories(float cals_min, float cals_max)
{
	vector<Recipe*> result;

	for (auto recipe : Recipes)
	{
		if (recipe->GetCalories() >= cals_min && recipe->GetCalories() <= cals_max)
			result.push_back(recipe);
	}

	return result;
}

void RecipeList::ReadRecipeFromInput()
{
	string recipeName, ingredientName;
	float ingredientQuantity;
	
	cout << "Nome ricetta: ";
	getline(cin >> ws, recipeName);

	while (FindRecipeByName(recipeName))
	{
		cout << strings::WARN_RECIPE_NAME_EXISTS;
		getline(cin >> ws, recipeName);
	}

	Recipe* recipe = new Recipe(recipeName);
	Recipes.push_back(recipe);

	
	cout << strings::FIRST_INGREDIENT_NAME;
	getline(cin >> ws, ingredientName);

	while (ingredientName != "stop")
	{
		Ingredient* ingredient = Ingredients.Get(ingredientName);

		while (!ingredient)
		{
			cout << strings::WARN_NO_INGREDIENT;
			getline(cin >> ws, ingredientName);
		
			continue;
		}

		cout << "Quantita`: ";
		cin >> ingredientQuantity;

		while (ingredientQuantity <= 0)
		{
			cout << strings::WARN_AMOUNT_NEGATIVE;
			cin >> ingredientQuantity;
		}

		recipe->AddIngredient(ingredient, ingredientQuantity);

		cout << strings::NEXT_INGREDIENT_NAME;
		getline(cin >> ws, ingredientName);
	}
}

bool RecipeList::ReadRecipeFromFile(string filename)
{
	ifstream file(filename);
	if (!file)
		return false;

	string name;
	getline(file >> ws, name);

	Recipe* recipe = new Recipe(name);
	Recipes.push_back(recipe);

	string ingredientName;
	float quantity;
	while (getline(file >> ws, ingredientName, ','))
	{
		file >> ws >> quantity;

		Ingredient* ingredient = Ingredients.Get(ingredientName);
		if (!ingredient)
			continue;

		recipe->AddIngredient(ingredient, quantity);
	}

	return true;
}

bool RecipeList::SaveRecipeToFile(string name, string filename)
{
	Recipe* recipe = FindRecipeByName(name);

	if (!recipe)
		return false;

	return recipe->WriteToFile(filename);
}

bool RecipeList::DeleteRecipe(string name)
{
	for (vector<Recipe*>::iterator itr = Recipes.begin(); itr != Recipes.end(); itr++)
	{
		if ((*itr)->GetName() == name)
		{
			Recipes.erase(itr);
			return true;
		}
	}

	return false;
}

Recipe* RecipeList::FindRecipeWithMostIngredients()
{
	Recipe* result = nullptr;

	for (auto recipe : Recipes)
	{
		if (!result) {
			result = recipe;
			continue;
		}

		if (recipe->GetIngredients().size() > result->GetIngredients().size())
			result = recipe;
	}

	return result;
}

Recipe* RecipeList::FindRecipeWithLeastIngredients()
{
	Recipe* result = nullptr;

	for (auto recipe : Recipes)
	{
		if (!result) {
			result = recipe;
			continue;
		}

		if (recipe->GetIngredients().size() < result->GetIngredients().size())
			result = recipe;
	}

	return result;
}

Recipe* RecipeList::FindRecipeWithMostCalories()
{
	Recipe* result = nullptr;

	for (auto recipe : Recipes)
	{
		if (!result) {
			result = recipe;
			continue;
		}

		if (recipe->GetCalories() / recipe->GetWeight() > result->GetCalories() / result->GetWeight())
			result = recipe;
	}

	return result;
}

Recipe* RecipeList::FindRecipeWithLeastCalories()
{
	Recipe* result = nullptr;

	for (auto recipe : Recipes)
	{
		if (!result) {
			result = recipe;
			continue;
		}

		if (recipe->GetCalories()/recipe->GetWeight() < result->GetCalories()/result->GetWeight())
			result = recipe;
	}

	return result;
}

vector<Recipe*> RecipeList::FindRecipesLowFat()
{
	vector<Recipe*> result;

	for (auto recipe : Recipes)
	{
		auto fats = recipe->GetFats();
		auto carbs = recipe->GetCarbs();
		auto proteins = recipe->GetProteins();

		auto fatsPerc = fats / (fats + carbs + proteins);

		if (fatsPerc < 0.1f)
			result.push_back(recipe);
	}

	return result;
}

float RecipeList::GetAverageCalories()
{
	float total = 0.f;

	for (auto recipe : Recipes)
		total += recipe->GetCalories() / recipe->GetWeight() * 100;

	return total / Recipes.size();
}

float* RecipeList::GetMacronutrientsDistribution()
{
	auto totalCarbs = 0.f;
	auto totalFats = 0.f;
	auto totalProteins = 0.f;

	for (auto recipe : Recipes)
	{
		totalCarbs += recipe->GetCarbs();
		totalFats += recipe->GetFats();
		totalProteins += recipe->GetProteins();
	}

	auto total = totalCarbs + totalFats + totalProteins;

	float* result = new float[3];
	result[0] = totalCarbs / total;
	result[1] = totalFats / total;
	result[2] = totalProteins / total;

	return result;
}
