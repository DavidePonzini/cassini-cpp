/*
 *	IMPORTANTE: NON MODIFICARE QUESTO FILE!
 *		TUTTE LE MODIFICHE SARANNO SOVRASCRITTE PRIMA DI CORREGGERE LA VERIFICA
 *
 */

#pragma once

#include <string>
#include <map>
#include <vector>
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

	vector<Ingredient*> GetIngredients();
	const bool ContainsIngredient(string name);

	void Print();
};

