#include <iostream>
#include <fstream>
#include <algorithm>

#include "RecipeList.h"
#include "Global.h"

using namespace std;

bool cmp(Recipe* r1, Recipe* r2)
{
	// TODO
	return false;
}

vector<Recipe*> RecipeList::GetRecipes()
{
	// TODO
	return vector<Recipe*>(); // empty vector
}

Recipe* RecipeList::FindRecipeByName(string name)
{
	// TODO
	return nullptr;
}

vector<Recipe*> RecipeList::FindRecipesByIngredient(string name)
{
	// TODO
	return vector<Recipe*>(); // empty vector
}

vector<Recipe*> RecipeList::FindRecipesByCalories(float cals_min, float cals_max)
{
	// TODO
	return vector<Recipe*>(); // empty vector
}

void RecipeList::ReadRecipeFromInput()
{
	// TODO
}

bool RecipeList::ReadRecipeFromFile(string filename)
{
	// TODO
	return false;
}

bool RecipeList::SaveRecipeToFile(string name, string filename)
{
	// TODO
	return false;
}

bool RecipeList::DeleteRecipe(string name)
{
	// TODO
	return false;
}

Recipe* RecipeList::FindRecipeWithMostIngredients()
{
	// TODO
	return nullptr;
}

Recipe* RecipeList::FindRecipeWithLeastIngredients()
{
	// TODO
	return nullptr;
}

Recipe* RecipeList::FindRecipeWithMostCalories()
{
	// TODO
	return nullptr;
}

Recipe* RecipeList::FindRecipeWithLeastCalories()
{
	// TODO
	return nullptr;
}

vector<Recipe*> RecipeList::FindRecipesLowFat()
{
	// TODO
	return vector<Recipe*>(); // empty vector
}

float RecipeList::GetAverageCalories()
{
	// TODO
	return 0;
}

float* RecipeList::GetMacronutrientsDistribution()
{
	// TODO
	return nullptr;
}
