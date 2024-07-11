//
//  main.cpp
//  ChainOfResponsibilityDesignPattern
//
//  Created by gopityro on 2024-07-10.
//

#include <iostream>
#include <memory>
#include <string>

// Base handler class
class OrderHandler
{
protected:
    std::unique_ptr<OrderHandler> nextHandler;
public:
    virtual ~OrderHandler() = default;
    virtual void handleOrder(const std::string orderType) =0;
    void setNextHandler(std::unique_ptr<OrderHandler> handler)
    {
        if (nextHandler) {
            nextHandler->setNextHandler(std::move(handler));
        } else {
            nextHandler = std::move(handler);
        }
    }
};

// Concrete handlers
class RegularOrderHandler: public OrderHandler
{
public:
    void handleOrder(const std::string orderType) override
    {
        std::cout<<"Inside RegularOrder Handler.. "<<std::endl;
        if(orderType=="Regular")
        {
            std::cout<<"Regular Order Handled"<<std::endl;
        }
        else if(nextHandler)
        {
            nextHandler->handleOrder(orderType);
        }
    }
};

class UrgentOrderHandler: public OrderHandler
{
public:
    void handleOrder(const std::string orderType) override
    {
        std::cout<<"Inside UrgentOrder Handler"<<std::endl;
        if(orderType=="Urgent")
        {
            std::cout<<"Urgent Order Handled.."<<std::endl;
        }
        else if(nextHandler)
        {
            nextHandler->handleOrder((orderType));
        }
    }
};

class VIPOrderHandler: public OrderHandler
{
public:
    void handleOrder(const std::string orderType)
    {
        std::cout<<"Inside VIPOrder Handler"<<std::endl;
        if(orderType=="VIP")
        {
            std::cout<<"VIP Order Handled.."<<std::endl;
        }
        else if(nextHandler)
        {
            nextHandler->handleOrder((orderType));
        }
    }
};

//client code
int main(int argc, const char * argv[]) {
    std::unique_ptr<OrderHandler> regularOrderHandler = std::make_unique<RegularOrderHandler>();
    std::unique_ptr<OrderHandler> urgentOrderHandler  = std::make_unique<UrgentOrderHandler>();
    std::unique_ptr<OrderHandler> vipOrderHandler     = std::make_unique<VIPOrderHandler>();
    
    regularOrderHandler->setNextHandler(std::move(urgentOrderHandler));
    regularOrderHandler->setNextHandler(std::move(vipOrderHandler));
    
    std::string orderType = "VIP";
    regularOrderHandler->handleOrder(orderType);

    return 0;
}
/*
 Output:
 Inside RegularOrder Handler..
 Inside UrgentOrder Handler
 Inside VIPOrder Handler
 VIP Order Handled..
 */
