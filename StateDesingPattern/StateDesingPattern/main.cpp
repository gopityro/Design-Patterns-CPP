//
//  main.cpp
//  StateDesingPattern
//
//  Created by gopityro on 2024-07-05.
//

#include <iostream>
#include<memory>

// State Interface
class OrderState
{
public:
    virtual ~OrderState() = default;
    virtual void handelOrder() = 0;
};

// Concrete States
class PlacedState: public OrderState
{
public:
    void handelOrder() override
    {
        std::cout<<"Order has been placed.."<<std::endl;
    }
};

class PrepareState: public OrderState
{
public:
    void handelOrder() override
    {
        std::cout<<"Order is Prepared.."<<std::endl;
    }
};

class DeliveredState: public OrderState
{
public:
    void handelOrder() override
    {
        std::cout<<"Order has been Delivered.."<<std::endl;
    }
};

// Context
class Order
{
private:
    std::unique_ptr<OrderState> currentOrderState;
public:
    Order(std::unique_ptr<OrderState> orderState):currentOrderState(std::move(orderState)){}
    
    void setNewState(std::unique_ptr<OrderState> newState)
    {
        currentOrderState = std::move(newState);
    }
    void handelOrder()
    {
        currentOrderState->handelOrder();
    }
};

//client code
int main(int argc, const char * argv[]) {
    
    // Initial state is Placed
    std::unique_ptr<OrderState> orderPlaced = std::make_unique<PlacedState>();
    
    Order order(std::move(orderPlaced));
    order.handelOrder();
    
    // Transition to Prepared state
    order.setNewState(std::make_unique<PrepareState>());
    order.handelOrder();
    
    // Transition to Delivered state
    order.setNewState(std::make_unique<DeliveredState>());
    order.handelOrder();
    
    std::cout << "Hello, World!\n";
    return 0;
}

/*
 output:
 Order has been placed..
 Order is Prepared..
 Order has been Delivered..
 */

