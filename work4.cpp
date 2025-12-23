#include<vector>
#include<string> 
#include<iostream> 

class PotionRecipe
{
public:
	PotionRecipe(const std::string& potionName, const std::string& coreIngredient)
	{
		potionName_ = potionName;
		coreIngredient_ = coreIngredient;
	}

	const std::string& GetPotionName() const
	{
		return potionName_;
	}

	const std::string& GetCoreIngredient() const
	{
		return coreIngredient_;
	}

private:
	std::string potionName_;
	std::string coreIngredient_;

};

class AlchemyWorkshop
{
public:
	void AddRecipe(const std::string& potionName, const std::string& coreIngredient)
	{
		recipes_.push_back(PotionRecipe(potionName, coreIngredient));
	}

	void DisplayAllRecipes() const
	{
		for (const PotionRecipe& recipe : recipes_)
		{
			std::cout << recipe.GetPotionName() << " : " << recipe.GetCoreIngredient() << std::endl;
		}
	}

	PotionRecipe SearchRecipeByName(const std::string& name) const
	{
		for (const PotionRecipe& recipe : recipes_)
		{
			if (recipe.GetPotionName() == name)
			{
				return recipe;
			}
		}
			return PotionRecipe("NONE", "NONE");
		
	}

	std::vector<PotionRecipe> SearchRecipeByIngredient(const std::string& ingredient) const
	{
		std::vector<PotionRecipe> ret;
		for (const PotionRecipe& recipe : recipes_)
		{
			if (recipe.GetCoreIngredient() == ingredient)
			{
				ret.push_back(recipe);
			}
		}
		return ret;
	}


private:
	std::vector<PotionRecipe> recipes_;
};

int main()
{
	AlchemyWorkshop workshop;
	workshop.AddRecipe("Healing Potion", "Herb");
	workshop.AddRecipe("Mana Potion", "Magic Water");
	workshop.AddRecipe("Stamina Potion", "Herb");
	workshop.AddRecipe("Fire REsistance Potion", "Fire Flower");

	workshop.DisplayAllRecipes();

	PotionRecipe recipe = workshop.SearchRecipeByName("Mana Potion");
	std::cout << "검색된 레시피" << recipe.GetPotionName() << std::endl;

	std::vector<PotionRecipe> herbRecipes = workshop.SearchRecipeByIngredient("Herb");

	std::cout << "Herb를 사용하는 레시피 수:" << herbRecipes.size() << std::endl;

	return 0;
}