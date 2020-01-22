#pragma once

#include <string>

using namespace std;


class Ingredient
{
public:
	Ingredient(string name, float carbs, float fats, float proteins);

private:
	string Name;
	float Carbs;
	float Fats;
	float Proteins;

public:
	const string GetName();
	const float GetCarbs();
	const float GetFats();
	const float GetProteins();
	const float GetCalories();
};

