#include "Ingredient.h"

Ingredient::Ingredient(string name, float carbs, float fats, float proteins)
{
	this->Name = name;
	this->Carbs = carbs;
	this->Fats = fats;
	this->Proteins = proteins;
}

const string Ingredient::GetName()
{
	return this->Name;
}

const float Ingredient::GetCarbs()
{
	return this->Carbs;
}

const float Ingredient::GetFats()
{
	return this->Fats;
}

const float Ingredient::GetProteins()
{
	return this->Proteins;
}

const float Ingredient::GetCalories()
{
	return this->Carbs * 4 + this->Proteins * 4 + this->Fats * 9;
}
