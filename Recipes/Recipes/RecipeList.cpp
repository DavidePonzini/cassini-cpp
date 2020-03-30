#include <iostream>
#include <fstream>

#include "RecipeList.h"
#include "Global.h"

using namespace std;


vector<Recipe*> RecipeList::GetRecipes()
{
	// TODO
}

Recipe* RecipeList::FindRecipeByName(string name)
{
	// TODO
}

vector<Recipe*> RecipeList::FindRecipesByIngredient(string name)
{
	// TODO
}

vector<Recipe*> RecipeList::FindRecipesByCalories(float cals_min, float cals_max)
{
	// TODO
}

void RecipeList::ReadRecipeFromInput()
{
	// TODO
}

bool RecipeList::ReadRecipeFromFile(string filename)
{
	// TODO
}

bool RecipeList::SaveRecipeToFile(string name, string filename)
{
	// TODO
}

bool RecipeList::DeleteRecipe(string name)
{
	// TODO
}

Recipe* RecipeList::FindRecipeWithMostIngredients()
{
	// TODO
}

Recipe* RecipeList::FindRecipeWithLeastIngredients()
{
	// TODO
}

Recipe* RecipeList::FindRecipeWithMostCalories()
{
	// TODO
}

Recipe* RecipeList::FindRecipeWithLeastCalories()
{
	// TODO
}

vector<Recipe*> RecipeList::FindRecipesLowFat()
{
	// TODO
}

float RecipeList::GetAverageCalories()
{
	// TODO
}

float* RecipeList::GetMacronutrientsDistribution()
{
	// TODO
}
