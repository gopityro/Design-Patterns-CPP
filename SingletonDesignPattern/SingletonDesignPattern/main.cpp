//
//  main.cpp
//  SingletonDesignPattern
//
//  Created by gopityro on 2024-05-29.
//

#include <iostream>
#include <memory>
#include <mutex>

// Singleton class: MealManager
class MealManager {
public:
    // Public method to get the singleton instance
    static MealManager& getInstance() {
        // Ensure the instance is initialized only once
        std::call_once(initInstanceFlag, &MealManager::initSingleton);
        return *instance;
    }

    // Method to perform some operations
    void manageMeals() const {
        std::cout << "Managing meals...\n";
    }

private:
    // Private constructor to prevent direct instantiation
    MealManager() {
        std::cout << "MealManager instance created.\n";
    }

    // Private copy constructor and assignment operator to prevent copying
    MealManager(const MealManager&) = delete;
    MealManager& operator=(const MealManager&) = delete;

    // Static method to initialize the singleton instance
    static void initSingleton() {
        instance = std::unique_ptr<MealManager>(new MealManager());
    }

    // Static unique pointer to hold the singleton instance
    inline static std::unique_ptr<MealManager> instance;  // Definition and declaration in one place
    // Flag to ensure the instance is initialized only once
    inline static std::once_flag initInstanceFlag;  // Definition and declaration in one place
};

int main() {
    // Get the singleton instance and call a method on it
    MealManager& manager = MealManager::getInstance();
    manager.manageMeals();

    // Attempting to get the instance again
    MealManager& manager2 = MealManager::getInstance();
    manager2.manageMeals();

    return 0;
}

