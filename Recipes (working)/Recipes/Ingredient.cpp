#include <iostream>

#include "Ingredient.h"


using namespace std;


Ingredient::Ingredient(string name, float carbs, float fats, float proteins)
{
	this->Name = name;
	SetValues(carbs, fats, proteins);
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

void Ingredient::SetValues(float carbs, float fats, float proteins)
{
	this->Carbs = carbs < 0 ? 0 : carbs;
	this->Fats = fats < 0 ? 0 : fats;
	this->Proteins = proteins < 0 ? 0 : proteins;
}

void Ingredient::Print()
{
	cout << "--- " << Name << " ---" << endl;
	cout << "Calorie (per 100g):     " << GetCalories() << " cals" << endl;
	cout << "Carboidrati (per 100g): " << Carbs << "g" << endl;
	cout << "Grassi (per 100g):      " << Fats<< "g" << endl;
	cout << "Proteine (per 100g):    " << Proteins << "g" << endl;
}
