//
//  main.cpp
//  BuilderDesignPattern
//
//  Created by gopityro on 2024-05-22.
//

#include <iostream>
#include <memory>
#include <string>

// Abstract Product: Meal
class Meal {
public:
    virtual ~Meal() = default;
    virtual void prepare() = 0;
    virtual void serve() = 0;
};

// Concrete Product: A complete meal with multiple components
class CompleteMeal : public Meal {
private:
    std::string m_starter;
    std::string m_mainCourse;
    std::string m_sideDish;
    std::string m_drink;
    std::string m_dessert;

public:
    CompleteMeal(const std::string& starter, const std::string& mainCourse, const std::string& sideDish, const std::string& drink, const std::string& dessert)
        : m_starter(starter), m_mainCourse(mainCourse), m_sideDish(sideDish), m_drink(drink), m_dessert(dessert) {}

    void prepare() override {
        std::cout << "Preparing meal...\n";
        std::cout << "1. " << m_starter << "\n";
        std::cout << "2. " << m_mainCourse << "\n";
        std::cout << "3. " << m_sideDish << "\n";
        std::cout << "4. " << m_drink << "\n";
        std::cout << "5. " << m_dessert << "\n";
    }

    void serve() override {
        std::cout << "Serving meal...\n";
        std::cout << "1. " << m_starter << "\n";
        std::cout << "2. " << m_mainCourse << "\n";
        std::cout << "3. " << m_sideDish << "\n";
        std::cout << "4. " << m_drink << "\n";
        std::cout << "5. " << m_dessert << "\n";
    }
};

// Builder Interface
class MealBuilder {
protected:
    std::string m_starter;
    std::string m_mainCourse;
    std::string m_sideDish;
    std::string m_drink;
    std::string m_dessert;

public:
    virtual ~MealBuilder() = default;
    virtual void addStarter() = 0;
    virtual void addMainCourse() = 0;
    virtual void addSideDish() = 0;
    virtual void addDrink() = 0;
    virtual void addDessert() = 0;

    std::unique_ptr<Meal> getResult() {
        return std::make_unique<CompleteMeal>(m_starter, m_mainCourse, m_sideDish, m_drink, m_dessert);
    }
};

// Concrete Builder for Vegetarian Meal
class VegetarianMealBuilder : public MealBuilder {
public:
    void addStarter() override {
        m_starter = "Vegetable Soup";
    }

    void addMainCourse() override {
        m_mainCourse = "Vegetable Lasagna";
    }

    void addSideDish() override {
        m_sideDish = "Salad";
    }

    void addDrink() override {
        m_drink = "Orange Juice";
    }

    void addDessert() override {
        m_dessert = "Fruit Salad";
    }
};

// Concrete Builder for Non-Vegetarian Meal
class NonVegetarianMealBuilder : public MealBuilder {
public:
    void addStarter() override {
        m_starter = "Chicken Soup";
    }

    void addMainCourse() override {
        m_mainCourse = "Grilled Chicken";
    }

    void addSideDish() override {
        m_sideDish = "Mashed Potatoes";
    }

    void addDrink() override {
        m_drink = "Red Wine";
    }

    void addDessert() override {
        m_dessert = "Cheesecake";
    }
};

// Director
class MealDirector {
public:
    void construct(MealBuilder& builder) {
        builder.addStarter();
        builder.addMainCourse();
        builder.addSideDish();
        builder.addDrink();
        builder.addDessert();
    }
};

int main() {
    // client code..
    MealDirector director;

    VegetarianMealBuilder vegBuilder;
    NonVegetarianMealBuilder nonVegBuilder;

    director.construct(vegBuilder);
    std::unique_ptr<Meal> vegMeal = vegBuilder.getResult();
    std::cout << "Vegetarian Meal:\n";
    vegMeal->prepare();
    vegMeal->serve();

    director.construct(nonVegBuilder);
    std::unique_ptr<Meal> nonVegMeal = nonVegBuilder.getResult();
    std::cout << "\nNon-Vegetarian Meal:\n";
    nonVegMeal->prepare();
    nonVegMeal->serve();

    return 0;
}
