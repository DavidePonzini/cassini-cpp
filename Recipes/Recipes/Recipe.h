#pragma once

#include <string>
#include <map>
#include "Ingredient.h"

using namespace std;


class Recipe
{
public:
	Recipe(string name);
private:
	string Name;
	map<Ingredient*, float> Ingredients;

public:
	const string GetName();
	const float GetCalories();
	const float GetCarbs();
	const float GetFats();
	const float GetProteins();

	const bool ContainsIngredient(string name);
};

