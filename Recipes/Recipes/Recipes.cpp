#include "Recipes.h"

Recipe* Recipes::FindRecipeByName(string name)
{
	return nullptr;
}

vector<Recipe*> Recipes::FindRecipesByIngredient(string name)
{
	vector<Recipe*> result;

	for (auto recipe : RecipeList)
	{
		if (recipe->ContainsIngredient(name))
			result.push_back(recipe);
	}

	return result;
}

vector<Recipe*> Recipes::FindRecipesByCalories(float cals_min, float cals_max)
{
	vector<Recipe*> result;

	for (auto recipe : RecipeList)
	{
		if (recipe->GetCalories() >= cals_min && recipe->GetCalories() <= cals_max)
			result.push_back(recipe);
	}

	return result;
}

void Recipes::ReadRecipeFromInput()
{

}

bool Recipes::ReadRecipeFromFile(string filename)
{
	return false;
}

void Recipes::SaveRecipeToFile(string filename)
{

}

bool Recipes::DeleteRecipe(string name)
{
	return false;
}

Recipe* Recipes::FindRecipeWithMostIngredients()
{
	Recipe* result = nullptr;

	for (auto recipe : RecipeList)
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

Recipe* Recipes::FindRecipeWithLeastIngredients()
{
	Recipe* result = nullptr;

	for (auto recipe : RecipeList)
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

Recipe* Recipes::FindRecipeWithMostCalories()
{
	Recipe* result = nullptr;

	for (auto recipe : RecipeList)
	{
		if (!result) {
			result = recipe;
			continue;
		}

		if (recipe->GetCalories() > result->GetCalories())
			result = recipe;
	}

	return result;
}

Recipe* Recipes::FindRecipeWithLeastCalories()
{
	Recipe* result = nullptr;

	for (auto recipe : RecipeList)
	{
		if (!result) {
			result = recipe;
			continue;
		}

		if (recipe->GetCalories() < result->GetCalories())
			result = recipe;
	}

	return result;
}

Recipe** Recipes::FindRecipesLowFat()
{
	vector<Recipe*> result;

	for (auto recipe : RecipeList)
	{
		auto fats = recipe->GetFats();
		auto carbs = recipe->GetCarbs();
		auto proteins = recipe->GetProteins();

		auto fatsPerc = fats / (fats + carbs + proteins);

		if (fatsPerc < 0.1f)
			result.push_back(recipe);
	}

	return result.data();
}

float Recipes::GetAverageCalories()
{
	float total = 0.f;

	for (auto recipe : RecipeList)
	{
		total += recipe->GetCalories();
	}

	return total / RecipeList.size();
}

float* Recipes::GetMacronutrientsDistribution()
{
	auto totalCarbs = 0.f;
	auto totalFats = 0.f;
	auto totalProteins = 0.f;

	for (auto recipe : RecipeList)
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
