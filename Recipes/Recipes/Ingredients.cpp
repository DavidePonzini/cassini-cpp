#include <fstream>
#include <iostream>

#include "Ingredients.h"


using namespace std;


void Ingredients::Add(string name, float carbs, float fats, float proteins)
{
	Ingredient* ingredient = new Ingredient(name, carbs, fats, proteins);
	IngredientList.push_back(ingredient);
}

Ingredient* Ingredients::Get(string name)
{
	for (auto ingredient : IngredientList)
	{
		if (ingredient->GetName() == name)
			return ingredient;
	}

	return nullptr;
}

void Ingredients::ChangeValues(string name)
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

bool Ingredients::ReadFile(string filename)
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
