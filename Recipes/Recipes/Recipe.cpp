#include <iostream>
#include <fstream>

#include "Recipe.h"


using namespace std;


Recipe::Recipe(string name)
{
	// TODO
}

const string Recipe::GetName()
{
	// TODO
	return "";
}

const float Recipe::GetCalories()
{
	// TODO
	return 0;
}

const float Recipe::GetCarbs()
{
	// TODO
	return 0;
}

const float Recipe::GetFats()
{
	// TODO
	return 0;
}

const float Recipe::GetProteins()
{
	// TODO
	return 0;
}

vector<Ingredient*> Recipe::GetIngredients()
{
	// TODO
	return vector<Ingredient*>(); // empty vector
}

float Recipe::GetWeight()
{
	// TODO
	return 0;
}

void Recipe::AddIngredient(Ingredient* ingredient, float quantity)
{
	// TODO
}

const bool Recipe::ContainsIngredient(string name)
{
	// TODO
	return false;
}

void Recipe::Print()
{
	// TODO
}

bool Recipe::WriteToFile(string filename)
{
	// TODO
	return false;

}
