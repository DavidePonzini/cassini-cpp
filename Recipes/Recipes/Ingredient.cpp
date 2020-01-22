#include <iostream>

#include "Ingredient.h"


using namespace std;


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

void Ingredient::Print()
{
	cout << "--- " << Name << " ---" << endl;
	cout << "\tCalorie (per 100g): " << GetCalories() << "cals" << endl;
	cout << "\tCarboidrati (per 100g): " << Carbs << "g" << endl;
	cout << "\tGrassi (per 100g): " << Fats<< "g" << endl;
	cout << "\tProteine (per 100g): " << Proteins << "g" << endl;
}
