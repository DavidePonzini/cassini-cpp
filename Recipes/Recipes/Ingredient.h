/*
 *	IMPORTANTE: NON MODIFICARE QUESTO FILE!
 *		TUTTE LE MODIFICHE SARANNO SOVRASCRITTE PRIMA DI CORREGGERE LA VERIFICA
 *
 */

#pragma once
#include <string>

using namespace std;


class Ingredient
{
public:
	Ingredient(string name, float carbs, float fats, float proteins);

private:
	string Name;
	float Carbs;
	float Fats;
	float Proteins;

public:
	const string GetName();
	const float GetCarbs();
	const float GetFats();
	const float GetProteins();
	const float GetCalories();
	
	void SetValues(float carbs, float fats, float proteins);

	void Print();
};

