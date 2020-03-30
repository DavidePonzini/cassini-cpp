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
}

const float Recipe::GetCalories()
{
	// TODO
}

const float Recipe::GetCarbs()
{
	// TODO
}

const float Recipe::GetFats()
{
	// TODO
}

const float Recipe::GetProteins()
{
	// TODO
}

vector<Ingredient*> Recipe::GetIngredients()
{
	// TODO
}

float Recipe::GetWeight()
{
	// TODO
}

void Recipe::AddIngredient(Ingredient* ingredient, float quantity)
{
	// TODO
}

const bool Recipe::ContainsIngredient(string name)
{
	// TODO
}

void Recipe::Print()
{
	// TODO
}

bool Recipe::WriteToFile(string filename)
{
	// TODO
}
