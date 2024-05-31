//
//  main.cpp
//  AdapterDesignPattern
//
//  Created by gopityro on 2024-05-31.
//

#include <iostream>
#include <memory>
#include <string>

// Old Meal Preparation Interface
class MealPreparation {
public:
    virtual ~MealPreparation() = default;
    virtual void prepareMeal(const std::string& mealType) const = 0;
};

// Old Meal Preparation Implementation
class TraditionalMealPreparation : public MealPreparation {
public:
    void prepareMeal(const std::string& mealType) const override {
        std::cout << "Preparing " << mealType << " using traditional methods.\n";
    }
};

// New Meal Preparation System
class ModernMealPreparation {
public:
    void prepareModernMeal(const std::string& mealType) const {
        std::cout << "Preparing " << mealType << " using modern methods.\n";
    }
};

// Adapter to Use Modern Meal Preparation with Old Interface
class NewMealAdapter : public MealPreparation {
private:
    std::unique_ptr<ModernMealPreparation> modernMealPreparation;
public:
    NewMealAdapter(std::unique_ptr<ModernMealPreparation> modernMealPrep)
        : modernMealPreparation(std::move(modernMealPrep)) {}

    void prepareMeal(const std::string& mealType) const override {
        modernMealPreparation->prepareModernMeal(mealType);
    }
};

// Client Code
int main() {
    // Using Traditional Meal Preparation
    std::unique_ptr<MealPreparation> traditionalPreparation = std::make_unique<TraditionalMealPreparation>();
    traditionalPreparation->prepareMeal("Vegetarian Meal");

    // Using Modern Meal Preparation through Adapter
    std::unique_ptr<MealPreparation> modernPreparation = std::make_unique<NewMealAdapter>(std::make_unique<ModernMealPreparation>());
    modernPreparation->prepareMeal("Non-Vegetarian Meal");

    return 0;
}

