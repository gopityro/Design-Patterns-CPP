//
//  main.cpp
//  AbstractFactoryDesignPattern
//
//  Created by gopityro on 2024-05-16.
//

#include <iostream>
#include <memory>

// Abstract Product: Meal
class Meal {
public:
    virtual void prepare() = 0;
    virtual void serve() = 0;
    virtual ~Meal() = default;
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

// Abstract Factory: MealFactory
class MealFactory {
public:
    virtual std::unique_ptr<Meal> createVegetarianMeal() = 0;
    virtual std::unique_ptr<Meal> createNonVegetarianMeal() = 0;
    virtual ~MealFactory() = default;
};

// Concrete Factories: CasualMealFactory and FineDiningMealFactory
class CasualMealFactory : public MealFactory {
public:
    std::unique_ptr<Meal> createVegetarianMeal() override {
        std::cout << "Creating Casual vegetarian meal...\n";
        return std::make_unique<VegetarianMeal>();
    }

    std::unique_ptr<Meal> createNonVegetarianMeal() override {
        std::cout << "Creating Casual non-vegetarian meal...\n";
        return std::make_unique<NonVegetarianMeal>();
    }
};

class FineDiningMealFactory : public MealFactory {
public:
    std::unique_ptr<Meal> createVegetarianMeal() override {
        // Assume a different kind of vegetarian meal for fine dining experience
        std::cout << "Creating fine dining vegetarian meal...\n";
        return std::make_unique<VegetarianMeal>();
    }

    std::unique_ptr<Meal> createNonVegetarianMeal() override {
        // Assume a different kind of non-vegetarian meal for fine dining experience
        std::cout << "Creating fine dining non-vegetarian meal...\n";
        return std::make_unique<NonVegetarianMeal>();
    }
};

// Client Code: Ordering Meals
int main() {
    std::unique_ptr<MealFactory> casualFactory = std::make_unique<CasualMealFactory>();
    std::unique_ptr<Meal> casualVegetarianMeal = casualFactory->createVegetarianMeal();
    casualVegetarianMeal->prepare();
    casualVegetarianMeal->serve();

    std::unique_ptr<Meal> casualNonVegetarianMeal = casualFactory->createNonVegetarianMeal();
    casualNonVegetarianMeal->prepare();
    casualNonVegetarianMeal->serve();

    std::unique_ptr<MealFactory> fineDiningFactory = std::make_unique<FineDiningMealFactory>();
    std::unique_ptr<Meal> fineDiningVegetarianMeal = fineDiningFactory->createVegetarianMeal();
    fineDiningVegetarianMeal->prepare();
    fineDiningVegetarianMeal->serve();

    std::unique_ptr<Meal> fineDiningNonVegetarianMeal = fineDiningFactory->createNonVegetarianMeal();
    fineDiningNonVegetarianMeal->prepare();
    fineDiningNonVegetarianMeal->serve();

    return 0;
}
