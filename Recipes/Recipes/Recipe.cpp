#include "Recipe.h"

Recipe::Recipe(string name)
{
	this->Name = name;
}

const string Recipe::GetName()
{
	return this->Name;
}

const float Recipe::GetCalories()
{
	float calories = 0.f;

	for (auto ingredient : Ingredients)
		calories += ingredient.first->GetCalories() * ingredient.second / 100;

	return calories;
}

const float Recipe::GetCarbs()
{
	float carbs = 0;
	for (auto ingredient : Ingredients)
		carbs += ingredient.first->GetCarbs();

	return carbs;
}

const float Recipe::GetFats()
{
	float fats = 0;
	for (auto ingredient : Ingredients)
		fats += ingredient.first->GetFats();

	return fats;
}

const float Recipe::GetProteins()
{
	float proteins = 0;
	for (auto ingredient : Ingredients)
		proteins+= ingredient.first->GetProteins();

	return proteins;
}

const bool Recipe::ContainsIngredient(string name)
{
	for (auto ingredient : Ingredients)
	{
		if (ingredient.first->GetName() == name)
			return true;
	}

	return false;
}
