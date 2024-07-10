//
//  main.cpp
//  StrategyDesignPattern
//
//  Created by gopityro on 2024-07-09.
//
//
/* Class Diagram
 
+------------------+         +--------------------+
|   Meal           |         |   CookingStrategy  |
|------------------|         |--------------------|
| - cookingStrategy|<>------>| + cook()           |
|------------------|         +--------------------+
| + prepareMeal()  |                      ^
| + setCookingStrategy() |                |
+------------------+                      |
                                          |
                    +---------------------+----------------------+
                    |                     |                      |
         +------------------+  +--------------------+  +----------------------+
         | VegetarianStrategy| |   VeganStrategy    |  | NonVegetarianStrategy|
         +------------------+  +--------------------+  +----------------------+
         | + cook()         |  | + cook()           |  | + cook()             |
         +------------------+  +--------------------+  +----------------------+
*/

#include <iostream>

// Strategy Interface
class CookingStrategy
{
public:
    virtual ~CookingStrategy() = default;
    virtual void cook() = 0;
    
};

// Concrete Strategies
class VegetarianStrategy: public CookingStrategy
{
public:
    void cook() override
    {
        std::cout<<"cooking Vegetrarian meal.."<<std::endl;
    }
};
class VeganStrategy: public CookingStrategy
{
public:
    void cook() override
    {
        std::cout<<"cooking Vegan Meal.."<<std::endl;
    }
    
};
class NonVegetarianStrategy: public CookingStrategy
{
public:
    void cook() override
    {
        std::cout<<"cooking NonVegetarian Meal..."<<std::endl;
    }
};

//context
class Meal
{
private:
    std::unique_ptr<CookingStrategy> cookingStrategy;
public:
    void setCookingStrategy(std::unique_ptr<CookingStrategy> strategy)
    {
        cookingStrategy = std::move(strategy);
    }
    
    void prepareMeal () const
    {
        if(cookingStrategy)
            cookingStrategy->cook();
        else
            std::cout<<"No Strategy selected.."<<std::endl;
    }
};

//client code
int main(int argc, const char * argv[]) {
    Meal meal;
    meal.prepareMeal();
    
    // Change strategy to Vegetarian
    std::unique_ptr<CookingStrategy> vegCookingStrategy = std::make_unique<VegetarianStrategy>();
    meal.setCookingStrategy(std::move(vegCookingStrategy));
    meal.prepareMeal();
    
    // Change strategy to Vegan
    std::unique_ptr<CookingStrategy> veganCookingStrategy = std::make_unique<VeganStrategy>();
    meal.setCookingStrategy(std::move(veganCookingStrategy));
    meal.prepareMeal();
    
    // Change strategy to NonVegetarian
    std::unique_ptr<CookingStrategy> nonVegCookingStrategy = std::make_unique<NonVegetarianStrategy>();
    meal.setCookingStrategy(std::move(nonVegCookingStrategy));
    meal.prepareMeal();
    
    return 0;
}
/*
 output:
 No Strategy selected..
 cooking Vegetrarian meal..
 cooking Vegan Meal..
 cooking NonVegetarian Meal...
 */
