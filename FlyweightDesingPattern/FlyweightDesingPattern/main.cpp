//
//  main.cpp
//  FlyweightDesignPattern
//
//  Created by gopityro on 2024-06-25.
//

#include <iostream>
#include <string>
#include <memory>
#include <unordered_map>

// Flyweight Interface
class MenuItem {
public:
    virtual ~MenuItem() = default;
    virtual void display() const = 0; // Pure virtual function to display menu item details
};

// Concrete Flyweight
class ConcreteMenuItem : public MenuItem {
private:
    std::string itemName;
    std::string description;
    double price;

public:
    // Constructor to initialize item details
    ConcreteMenuItem(const std::string& itemName, const std::string& description, const double price)
        : itemName(itemName), description(description), price(price) {}

    // Getter for item name
    const std::string& getItemName() const {
        return this->itemName;
    }

    // Getter for item description
    const std::string& getDescription() const {
        return this->description;
    }

    // Override the display function to show item details
    void display() const override {
        std::cout << "Menu" << std::endl;
        std::cout << "Item: " << this->itemName << std::endl;
        std::cout << "Description: " << this->description << std::endl;
        std::cout << "Price: " << this->price << std::endl;
        std::cout << "------------------------" << std::endl;
    }
};

// Flyweight Factory
class MenuItemFactory {
private:
    // Map to store shared menu items
    std::unordered_map<std::string, std::shared_ptr<MenuItem>> menuItems;

public:
    // Function to get a menu item, creating it if it doesn't exist
    std::shared_ptr<MenuItem> getMenuItem(const std::string& itemName, const std::string& description, const double price) {
        std::string key = itemName + description; // Combine item name and description as the key

        // Check if the item already exists in the map
        if (this->menuItems.find(key) == this->menuItems.end()) {
            // Create a new item and add it to the map
            menuItems[key] = std::make_shared<ConcreteMenuItem>(itemName, description, price);
        }

        // Return the shared item
        return menuItems[key];
    }
};

// Client Code
int main(int argc, const char * argv[]) {
    MenuItemFactory factory;

    // Create or get a shared "Burger" menu item
    std::shared_ptr<MenuItem> menu1 = factory.getMenuItem("Burger", "Delicious burger", 4.99);
    menu1->display(); // Display details of menu1

    // Get the same "Burger" menu item, should be the same instance as menu1
    std::shared_ptr<MenuItem> menu2 = factory.getMenuItem("Burger", "Delicious burger", 4.99);

    // Create or get a different "Pizza" menu item
    std::shared_ptr<MenuItem> menu3 = factory.getMenuItem("Pizza", "Delicious Pizza", 5.99);

    // Check if menu1 and menu2 are the same instance
    std::cout << "menu1 and menu2 objects are the same instance?: " << (menu1 == menu2) << std::endl;

    // Check if menu2 and menu3 are different instances
    std::cout << "menu2 and menu3 objects are the same instance?: " << (menu3 == menu2) << std::endl;

    return 0;
}

