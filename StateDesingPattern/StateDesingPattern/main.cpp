//
//  main.cpp
//  StateDesignPattern
//
//  Created by gopityro on 2024-07-05.
//

#include <iostream>
#include <memory>
#include <string>

class Order; // Forward declaration
class PrepareState; // Forward declaration
class DeliveredState; // Forward declaration

// State Interface
class OrderState {
public:
    virtual ~OrderState() = default;
    virtual void handleOrder(Order& order) = 0;
};

// Context
class Order {
private:
    std::unique_ptr<OrderState> currentOrderState;
public:
    Order(std::unique_ptr<OrderState> orderState) : currentOrderState(std::move(orderState)) {}

    void setNewState(std::unique_ptr<OrderState> newState) {
        currentOrderState = std::move(newState);
    }

    void process() {
        currentOrderState->handleOrder(*this);
    }
};

// Concrete States
class PlacedState : public OrderState {
public:
    void handleOrder(Order& order) override;
};

class PrepareState : public OrderState {
public:
    void handleOrder(Order& order) override;
};

class DeliveredState : public OrderState {
public:
    void handleOrder(Order& order) override {
        std::cout << "Order has been delivered...\n";
    }
};

// Implementing transitions
void PlacedState::handleOrder(Order& order) {
    std::cout << "Order has been placed...\n";
    // Handle order placed and then change to next state which is order preparation.
    order.setNewState(std::make_unique<PrepareState>());
}

void PrepareState::handleOrder(Order& order) {
    std::cout << "Order is being prepared...\n";
    // Handle order preparation and then change to next state which is order delivery.
    order.setNewState(std::make_unique<DeliveredState>());
}

// client code
int main(int argc, const char * argv[]) {
    // Initial state is Placed
    std::unique_ptr<OrderState> orderPlaced = std::make_unique<PlacedState>();
    Order order(std::move(orderPlaced));

    // Process the order through various states
    order.process(); // Placed -> Prepared
    order.process(); // Prepared -> Delivered
    order.process(); // Delivered
    return 0;
}

/*
 Output:
 Order has been placed...
 Order is being prepared...
 Order has been delivered...
 */
