//
//  main.cpp
//  FactoryDesignPattern
//
//  Created by gopityro on 2024-05-15.
//

#include <iostream>
#include <memory>
#include <vector>

// Abstract Product: Meal
class Meal {
public:
    virtual ~Meal() = default;
    virtual void prepare() = 0;
    virtual void serve() = 0;
};

// Concrete Products: VegetarianMeal and NonVegetarianMeal
class VegetarianMeal : public Meal {
public:
    void prepare() override {
        std::cout << "Preparing vegetarian meal...\n";
    }

    void serve() override {
        std::cout << "Serving vegetarian meal...\n";
    }
};

class NonVegetarianMeal : public Meal {
public:
    void prepare() override {
        std::cout << "Preparing non-vegetarian meal...\n";
    }

    void serve() override {
        std::cout << "Serving non-vegetarian meal...\n";
    }
};

// Abstract Creator: MealFactory
class IMealFactory {
public:
    virtual ~IMealFactory() = default;
    virtual std::unique_ptr<Meal> createMeal() = 0;
};

// Concrete Creators: VegetarianMealFactory and NonVegetarianMealFactory
class VegetarianMealFactory : public IMealFactory {
public:
    std::unique_ptr<Meal> createMeal() override {
        return std::make_unique<VegetarianMeal>();
    }
};

class NonVegetarianMealFactory : public IMealFactory {
public:
    std::unique_ptr<Meal> createMeal() override {
        return std::make_unique<NonVegetarianMeal>();
    }
};

int main() {
    // Create meal factories
    VegetarianMealFactory vegetarianFactory;
    NonVegetarianMealFactory nonVegetarianFactory;

    // Create and serve meals
    std::vector<std::unique_ptr<Meal>> meals;
    meals.push_back(vegetarianFactory.createMeal());
    meals.push_back(nonVegetarianFactory.createMeal());

    for (const auto& meal : meals) {
        meal->prepare();
        meal->serve();
    }

    return 0;
}
