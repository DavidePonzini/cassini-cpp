#include <fstream>
#include <iostream>

#include "IngredientList.h"


using namespace std;


void IngredientList::Add(string name, float carbs, float fats, float proteins)
{
	Ingredient* ingredient = new Ingredient(name, carbs, fats, proteins);
	Ingredients.push_back(ingredient);
}

Ingredient* IngredientList::Get(string name)
{
	for (auto ingredient : Ingredients)
	{
		if (ingredient->GetName() == name)
			return ingredient;
	}

	return nullptr;
}

void IngredientList::ChangeValues(string name)
{
	Ingredient* ingredient = Get(name);

	if (!ingredient)
	{
		cout << "L'ingrediente non esiste" << endl;
		return;
	}

	cout << "Carboidrati (per 100g): ";
	float carbs;
	cin >> carbs;

	cout << "Grassi (per 100g):      ";
	float fats;
	cin >> fats;

	cout << "Proteine (per 100g):    ";
	float proteins;
	cin >> proteins;

	ingredient->SetValues(carbs, fats, proteins);
}

bool IngredientList::ReadFile(string filename)
{
	ifstream file(filename);

	if (!file)
		return false;

	string buf;
	getline(file, buf); // discard first line

	while (getline(file, buf, ','))
	{
		string name = buf;

		getline(file, buf, ',');
		float carbs = stof(buf);

		getline(file, buf, ',');
		float fats = stof(buf);

		getline(file, buf);
		float proteins = stof(buf);

		Add(name, carbs, fats, proteins);
	}

	file.close();

	return true;
}
