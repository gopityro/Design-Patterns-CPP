//
//  main.cpp
//  DecoratorDesignPattern
//
//  Created by gopityro on 2024-06-01.
//

#include <iostream>
#include <memory>
#include <string>

// Component
class Meal {
public:
    virtual ~Meal() = default;
    virtual std::string getDescription() const = 0;
    virtual double cost() const = 0;
};

// Concrete Component
class BasicMeal : public Meal {
public:
    std::string getDescription() const override {
        return "Basic Meal";
    }
    
    double cost() const override {
        return 5.0;
    }
};

// Decorator
class MealDecorator : public Meal {
protected:
    std::unique_ptr<Meal> meal;
public:
    MealDecorator(std::unique_ptr<Meal> m) : meal(std::move(m)) {}
};

// Concrete Decorator: CheeseDecorator
class CheeseDecorator : public MealDecorator {
public:
    CheeseDecorator(std::unique_ptr<Meal> m) : MealDecorator(std::move(m)) {}

    std::string getDescription() const override {
        return meal->getDescription() + ", Extra Cheese";
    }
    
    double cost() const override {
        return meal->cost() + 1.5;
    }
};

// Concrete Decorator: SpicyDecorator
class SpicyDecorator : public MealDecorator {
public:
    SpicyDecorator(std::unique_ptr<Meal> m) : MealDecorator(std::move(m)) {}

    std::string getDescription() const override {
        return meal->getDescription() + ", Spicy";
    }
    
    double cost() const override {
        return meal->cost() + 0.5;
    }
};

// Client Code
int main() {
    // Create a basic meal
    std::unique_ptr<Meal> meal = std::make_unique<BasicMeal>();
    std::cout << meal->getDescription() << " $" << meal->cost() << std::endl;
    
    // Add extra cheese
    meal = std::make_unique<CheeseDecorator>(std::move(meal));
    std::cout << meal->getDescription() << " $" << meal->cost() << std::endl;
    
    // Add spicy
    meal = std::make_unique<SpicyDecorator>(std::move(meal));
    std::cout << meal->getDescription() << " $" << meal->cost() << std::endl;

    return 0;
}
