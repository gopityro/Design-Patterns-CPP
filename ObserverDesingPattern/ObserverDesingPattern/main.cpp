//
//  main.cpp
//  ObserverDesingPattern
//
//  Created by gopityro on 2024-07-05.
//

#include <iostream>
#include <vector>
#include <memory>

// Observer Interface
class Observer
{
public:
    virtual ~Observer() = default;
    virtual void update(const std::string& status) = 0;
    
};

// Concrete Observer: KitchenStaff
class KitchenStaff : public Observer {
public:
    void update(const std::string& status) override {
        std::cout << "Kitchen Staff notified. Order Status: " << status << std::endl;
    }
};

// Concrete Observer: Customer
class Customer : public Observer {
public:
    void update(const std::string& status) override {
        std::cout << "Customer notified. Order Status: " << status << std::endl;
    }
};

// Subject Class
class Order {
private:
    std::vector<std::shared_ptr<Observer>> observers;
    std::string status;

public:
    void attach(std::shared_ptr<Observer> observer) {
        observers.push_back(observer);
    }

    void detach(std::shared_ptr<Observer> observer) {
        observers.erase(std::remove(observers.begin(), observers.end(), observer), observers.end());
    }

    void setStatus(const std::string& newStatus) {
        status = newStatus;
        notify();
    }

    void notify() {
        for (const auto& observer : observers) {
            observer->update(status);
        }
    }
};

//client code
int main() {
    // Create order
    Order order;

    // Create observers
    auto kitchenStaff = std::make_shared<KitchenStaff>();
    auto customer = std::make_shared<Customer>();

    // Attach observers to order
    order.attach(kitchenStaff);
    order.attach(customer);

    // Change order status
    order.setStatus("Order Placed");
    std::cout<<"---------------------------------------------"<<std::endl;
    order.setStatus("Order Prepared");
    std::cout<<"---------------------------------------------"<<std::endl;
    order.setStatus("Order Delivered");
    std::cout<<"---------------------------------------------"<<std::endl;

    return 0;
}
/*
 output:
 
 Kitchen Staff notified. Order Status: Order Placed
 Customer notified. Order Status: Order Placed
 ---------------------------------------------
 Kitchen Staff notified. Order Status: Order Prepared
 Customer notified. Order Status: Order Prepared
 ---------------------------------------------
 Kitchen Staff notified. Order Status: Order Delivered
 Customer notified. Order Status: Order Delivered
 ---------------------------------------------
 */
