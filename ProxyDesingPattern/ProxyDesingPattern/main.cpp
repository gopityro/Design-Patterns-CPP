//
//  main.cpp
//  ProxyDesingPattern
//
//  Created by gopityro on 2024-07-04.
//

#include <iostream>
#include<memory>

// Subject Interface
class Kitchen
{
public:
    virtual ~Kitchen()=default;
    virtual void prepareMeal(const std::string& mealType)=0;
};

// RealSubject
class RealKitchen:public Kitchen
{
public:
    void prepareMeal(const std::string& mealType) override
    {
        std::cout<<"Preparing : "<<mealType<<std::endl;
    }
};

// Proxy
class KitchenProxy: public Kitchen
{
private:
    std::unique_ptr<RealKitchen> realKitchen;
    bool hasAccess;
public:
    KitchenProxy(bool hasAccess):hasAccess(hasAccess),realKitchen(std::make_unique<RealKitchen>()){}
    
    void prepareMeal(const std::string& mealType) override
    {
        if(hasAccess)
        {
            realKitchen->prepareMeal(mealType);
        }
        else{
            std::cout<<"Cannot Prepare "<<mealType<<". Access denied !"<<std::endl;
        }
    }
};

// Client Code
int main(int argc, const char * argv[]) {
    
    // Create a proxy with access
    KitchenProxy kitchenWithAccess(true);
    kitchenWithAccess.prepareMeal("Burger");

    // Create a proxy without access
    KitchenProxy kitchenWithoutAccess(false);
    kitchenWithoutAccess.prepareMeal("coffee");
    return 0;
}
