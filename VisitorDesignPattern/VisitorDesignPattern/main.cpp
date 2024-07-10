//
//  main.cpp
//  VisitorDesignPattern
//
//  Created by gopityro on 2024-07-10.
//

#include <iostream>

// Visitor interface
class MenuVisitor
{
public:
    virtual ~MenuVisitor() = default;
    virtual void Visit(class MainCourse&) = 0;
    virtual void Visit(class Dessert&) = 0;
};


// Abstract Element
class MenuItem
{
public:
    virtual ~MenuItem() = default;
    virtual void Accept(MenuVisitor&) = 0;
    
};

// Concrete Elements
class MainCourse: public MenuItem
{
public:
    void Accept(MenuVisitor& visitor)
    {
        visitor.Visit(*this);
    }
    
};
class Dessert : public MenuItem
{
public:
    void Accept(MenuVisitor& visitor)
    {
        visitor.Visit(*this);
    }
};

//concrete visitors
class PriceCalculationVisitor:public MenuVisitor
{
public:
    void Visit(MainCourse& mainCourse)
    {
        std::cout<<"Calculate Main Course Price.."<<std::endl;
        
    }
    void Visit(Dessert& dessert)
    {
        std::cout<<"Calculate Dessert Price.."<<std::endl;
    }
};

class DietaryCheckVisitor: public MenuVisitor
{
public:
    void Visit(MainCourse& mainCourse)
    {
        std::cout<<"Checking dietary restrictions for main course."<<std::endl;
        
    }
    void Visit(Dessert& dessert)
    {
        std::cout<<"Checking dietary restrictions for dessert."<<std::endl;
    }
    
};

//client code
int main(int argc, const char * argv[]) {
    MainCourse mainCourse;
    Dessert    dessert;
    
    PriceCalculationVisitor priceVisitor;
    DietaryCheckVisitor dietaryCheckVisitor;
    
    mainCourse.Accept(priceVisitor);
    mainCourse.Accept(dietaryCheckVisitor);
    
    dessert.Accept(priceVisitor);
    dessert.Accept(dietaryCheckVisitor);
    
    return 0;
}
/*
 Output:
 Calculate Main Course Price..
 Checking dietary restrictions for main course.
 Calculate Dessert Price..
 Checking dietary restrictions for dessert.
 */
