#include <iostream>

#include "Recipe.h"


using namespace std;


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

vector<Ingredient*> Recipe::GetIngredients()
{
	vector<Ingredient*> ingredients;

	for (auto elem : Ingredients)
		ingredients.push_back(elem.first);

	return ingredients;
}

void Recipe::AddIngredient(Ingredient* ingredient, float quantity)
{
	this->Ingredients[ingredient] = quantity;
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

void Recipe::Print()
{
	cout << "--- " << GetName() << " ---" << endl;
	
	cout << "Ingredients:" << endl;
	for (auto ingredient : Ingredients)
		cout << "\t - " << ingredient.first->GetName() << ": " << ingredient.second << "g" << endl;

	cout << "Calorie:     " << GetCalories() << " cals" << endl;
	cout << "Carboidrati: " << GetCarbs() << "g" << endl;
	cout << "Grassi:      " << GetFats() << "g" << endl;
	cout << "Proteine:    " << GetProteins() << "g" << endl;
}
