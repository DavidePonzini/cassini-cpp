#pragma once
#include <vector>
#include "Recipe.h"


using namespace std;


class Recipes
{
private:
	vector<Recipe*> Recipes;

public:
	Recipe* FindRecipeByName(string name);
	Recipe* FindRecipeByIngredient(string name);
	Recipe* FindRecipeByCalories(float cals_min, float cals_max);
	
	void ReadRecipeFromInput();
	void ReadRecipeFromFile(string filename);

	void SaveRecipeToFile(string filename);
};

