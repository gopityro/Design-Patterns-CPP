//
//  main.cpp
//  PrototypeDesignPattern
//
//  Created by gopityro on 2024-05-24.
//
#include <iostream>
#include <memory>
#include <unordered_map>
#include <string>

// Abstract Prototype: Meal
class Meal {
public:
    virtual ~Meal() = default;
    
    // It returns a unique pointer to a new Meal object that is a copy of the current object.
    virtual std::unique_ptr<Meal> clone() const = 0;
    
    virtual void prepare() const = 0;
    virtual void serve() const = 0;
};

// Concrete Prototype: StandardMeal
class StandardMeal : public Meal {
public:
    std::unique_ptr<Meal> clone() const override {
        return std::make_unique<StandardMeal>(*this);
    }
    void prepare() const override {
        std::cout << "Preparing standard meal...\n";
    }
    void serve() const override {
        std::cout << "Serving standard meal...\n";
    }
};

// Prototype Manager
class MealManager {
public:
    void registerPrototype(const std::string& key, std::unique_ptr<Meal> prototype) {
        prototypes[key] = std::move(prototype);
    }

    std::unique_ptr<Meal> createMeal(const std::string& key) {
        return prototypes[key]->clone();
    }

private:
    std::unordered_map<std::string, std::unique_ptr<Meal>> prototypes;
};

int main() {
    // Create the meal manager
    MealManager manager;

    // Register a prototype meal under the key "standard"
    manager.registerPrototype("standard", std::make_unique<StandardMeal>());

    // Create a new meal instance by cloning the "standard" prototype
    auto meal = manager.createMeal("standard");

    // Prepare and serve the meal
    meal->prepare();
    meal->serve();

    return 0;
}
