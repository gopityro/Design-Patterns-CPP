//
//  main.cpp
//  FacadeDesignPattern
//
//  Created by gopityro on 2024-06-01.
//

#include <iostream>
#include <string>

// Subsystem: Meal Preparation
class MealPreparation {
public:
    void prepareMeal(const std::string& mealType) {
        std::cout << "Preparing " << mealType << "...\n";
    }
};

// Subsystem: Notification
class Notification {
public:
    void notifyCustomer(const std::string& mealType) {
        std::cout << "Notifying customer: Your " << mealType << " is ready!\n";
    }
};

// Facade: RestaurantFacade
class RestaurantFacade {
private:
    MealPreparation mealPreparation;
    Notification notification;

public:
    void prepareAndNotify(const std::string& mealType) {
        mealPreparation.prepareMeal(mealType);
        notification.notifyCustomer(mealType);
    }
};

// Client Code
int main() {
    RestaurantFacade restaurantFacade;

    // Client interacts with the restaurant through the facade
    restaurantFacade.prepareAndNotify("Vegetarian Meal");
    restaurantFacade.prepareAndNotify("Non-Vegetarian Meal");

    return 0;
}
/*
 output:
 Preparing Vegetarian Meal...
 Notifying customer: Your Vegetarian Meal is ready!
 Preparing Non-Vegetarian Meal...
 Notifying customer: Your Non-Vegetarian Meal is ready!
 */
