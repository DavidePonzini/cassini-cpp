/*
 *	IMPORTANTE: NON MODIFICARE QUESTO FILE!
 *		TUTTE LE MODIFICHE SARANNO SOVRASCRITTE PRIMA DI CORREGGERE LA VERIFICA
 *
 */

#pragma once
#include <vector>
#include "Ingredient.h"

using namespace std;


class Ingredients
{
private:
	vector<Ingredient*> IngredientList;

public:
	void Add(string name, float carbs, float fats, float proteins);
	Ingredient* Get(string name);
	void ChangeValues(string name);
	
	bool ReadFile(string filename);
};

