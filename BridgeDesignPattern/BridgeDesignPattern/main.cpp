//
//  main.cpp
//  BridgeDesignPattern
//
//  Created by gopityro on 2024-05-31.
//

#include <iostream>
#include <memory>
#include <string>

// Implementor
class MealPreparation {
public:
    virtual ~MealPreparation() = default;
    virtual void prepare(const std::string& mealType) const = 0;
};

// Concrete Implementors
class TraditionalMethod : public MealPreparation {
public:
    void prepare(const std::string& mealType) const override {
        std::cout << "Preparing " << mealType << " using traditional methods.\n";
    }
};

class ModernMethod : public MealPreparation {
public:
    void prepare(const std::string& mealType) const override {
        std::cout << "Preparing " << mealType << " using modern methods.\n";
    }
};

// Abstraction: Meal
class Meal {
protected:
    std::unique_ptr<MealPreparation> preparationMethod; // Bridge to implementation
public:
    Meal(std::unique_ptr<MealPreparation> prepMethod) : preparationMethod(std::move(prepMethod)) {}
    virtual ~Meal() = default;
    virtual void prepare() const = 0;
};


// Refined Abstraction: VegetarianMeal
class VegetarianMeal : public Meal {
public:
    VegetarianMeal(std::unique_ptr<MealPreparation> prepMethod) : Meal(std::move(prepMethod)) {}
    void prepare() const override {
        std::cout << "Preparing a vegetarian meal.\n";
        preparationMethod->prepare("Vegetarian Meal");
    }
};

// Refined Abstraction: NonVegetarianMeal
class NonVegetarianMeal : public Meal {
public:
    NonVegetarianMeal(std::unique_ptr<MealPreparation> prepMethod) : Meal(std::move(prepMethod)) {}
    void prepare() const override {
        std::cout << "Preparing a non-vegetarian meal.\n";
        preparationMethod->prepare("Non-Vegetarian Meal");
    }
};


// Client Code
int main() {
    // Prepare a vegetarian meal using traditional methods
    std::unique_ptr<Meal> traditionalVegetarianMeal = std::make_unique<VegetarianMeal>(std::make_unique<TraditionalMethod>());
    traditionalVegetarianMeal->prepare();

    // Prepare a non-vegetarian meal using modern methods
    std::unique_ptr<Meal> modernNonVegetarianMeal = std::make_unique<NonVegetarianMeal>(std::make_unique<ModernMethod>());
    modernNonVegetarianMeal->prepare();

    return 0;
}
