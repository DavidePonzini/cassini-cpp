/*
 *	IMPORTANTE: NON MODIFICARE QUESTO FILE!
 *		TUTTE LE MODIFICHE SARANNO SOVRASCRITTE PRIMA DI CORREGGERE LA VERIFICA
 *
 */

#pragma once
#include <vector>
#include "Recipe.h"

using namespace std;


class Recipes
{
private:
	vector<Recipe*> RecipeList;

public:
	vector<Recipe*> GetRecipes();
	
	// Find (necessarie per il 6)
	Recipe* FindRecipeByName(string name);
	vector<Recipe*> FindRecipesByIngredient(string name);
	vector<Recipe*> FindRecipesByCalories(float cals_min, float cals_max);
	
	// Create (necessarie per il 6)
	void ReadRecipeFromInput();
	bool ReadRecipeFromFile(string filename);	// se il file non esiste, avvisa l'utente. Il programma non termina

	// Save (necessaria per il 6)
	void SaveRecipeToFile(string filename);
	
	// Delete (necessaria per il 6)
	bool DeleteRecipe(string name);	// se non esiste, ritorna false
	
	// Advanced Search (ciascuna funzione vale 0.5 punti)
	Recipe* FindRecipeWithMostIngredients();
	Recipe* FindRecipeWithLeastIngredients();
	Recipe* FindRecipeWithMostCalories();
	Recipe* FindRecipeWithLeastCalories();
	vector<Recipe*> FindRecipesLowFat();
	
	// Analysis (ciascuna funzione vale 0.75 punti)
	float GetAverageCalories();
	float* GetMacronutrientsDistribution(); // suggerimento: dovete ritornare 3 valori, perche` vi sto chiedento un float* ?
};

