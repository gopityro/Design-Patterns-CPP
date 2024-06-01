//
//  main.cpp
//  CompositeDesignPattern
//
//  Created by gopityro on 2024-06-01.
//

#include <iostream>
#include <vector>
#include <memory>
#include <string>

// Component
class MenuComponent {
public:
    virtual ~MenuComponent() = default;
    virtual void add(std::shared_ptr<MenuComponent> component) {}
    virtual void display() const = 0;
};

// Leaf
class MenuItem : public MenuComponent {
private:
    std::string name;
public:
    MenuItem(const std::string& name) : name(name) {}
    void display() const override {
        std::cout << " - MenuItem: " << name << std::endl;
    }
};

// Composite
class Menu : public MenuComponent {
private:
    std::vector<std::shared_ptr<MenuComponent>> components;
    std::string name;
public:
    Menu(const std::string& name) : name(name) {}
    void add(std::shared_ptr<MenuComponent> component) override {
        components.push_back(component);
    }
    void display() const override {
        std::cout << "Menu: " << name << std::endl;
        for (const auto& component : components) {
            component->display();
        }
    }
};

// Client Code
int main() {
    auto breakfastMenu = std::make_shared<Menu>("Breakfast Menu");
    auto lunchMenu = std::make_shared<Menu>("Lunch Menu");

    auto pancake = std::make_shared<MenuItem>("Pancake");
    auto sandwich = std::make_shared<MenuItem>("Sandwich");

    breakfastMenu->add(pancake);
    lunchMenu->add(sandwich);

    auto allMenus = std::make_shared<Menu>("All Menus");
    allMenus->add(breakfastMenu);
    allMenus->add(lunchMenu);

    allMenus->display();

    return 0;
}



