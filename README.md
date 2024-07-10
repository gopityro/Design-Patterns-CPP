# Design Patterns Using C++
<img width="1000" alt="image" src="https://github.com/gopityro/Design-Patterns-CPP/assets/25153647/6c13b554-cc35-4c4d-a287-e470da992492">

## Creational Design Patterns
 ### 1. Factory Method
Instead of directly instantiating concrete classes within client code, the Factory pattern allows you to delegate the responsibility of object creation to specialized factory classes or methods. These factories encapsulate the logic for creating instances of various related classes. Definitions always make confusing! 

***Example:***
Customers order meals at the restaurant, we need a flexible way to create different types of meals (e.g., vegetarian, non-vegetarian). Directly instantiating meal objects using their constructors can lead to tight coupling between the client code and the concrete meal classes.

<img width="700" alt="image" src="https://github.com/gopityro/Design-Patterns-CPP/assets/25153647/76959992-6e41-474f-859a-2627f8fdd460">

### 2. Abstract Factory
The Abstract Factory pattern extends the concept of the Factory Method pattern by providing an interface for creating families of related or dependent objects. It allows you to encapsulate multiple factory methods within a single abstract factory interface, each responsible for creating a different family of related objects

***Example:***
We will continue the example described in Factory Method. In a restaurant, customers not only choose between different types of meals (e.g., vegetarian, non-vegetarian) but also the style of dining (e.g., casual, fine dining)

<img width="700" alt="image" src="https://github.com/gopityro/Design-Patterns-CPP/assets/25153647/4d6ef590-8144-48ab-b543-9f1286f39f3b">


### 3. Builder Pattern
The Builder Pattern is used to construct a complex object step by step. Unlike the Factory Pattern, which focuses on the creation of a single object, the Builder Pattern constructs an object using a series of steps or a sequence of method calls.

***Example:***
In a restaurant scenario, meals can have multiple varieties of dishes, and customers can customize their meals according to their preferences.

<img width="700" alt="image" src="https://github.com/gopityro/Design-Patterns-CPP/assets/25153647/a66fe75e-84e1-4c17-9f67-553886062652">


### 4. Prototype Pattern
In some scenarios, creating an instance of a class is costly or complex. For instance, an object may involve expensive database operations or complex computations. The Prototype Pattern allows you to make new instances by copying existing ones, thus improving performance, and simplifying the creation process.

***Example:***
Let’s consider a scenario where we are managing meals in a restaurant. Creating a new meal from scratch might be costly, so we create a prototype meal and clone it to create new meal instances
<img width="700" alt="image" src="https://github.com/gopityro/Design-Patterns-CPP/assets/25153647/5a3d5c68-c51a-4115-9dac-52b8ed089e21">

### 5. Singleton pattern
The Singleton pattern ensures a class has only one instance and provides a global point of access to that instance. This pattern is useful when exactly one object is needed to coordinate actions across the system.

***Example:***
Let's consider a scenario where we have a MealManager class responsible for managing meal-related operations in a restaurant system. We want to ensure that there's only one instance of MealManager throughout the application's lifecycle.

<img width="700" alt="image" src="https://github.com/gopityro/Design-Patterns-CPP/assets/25153647/d3e0a879-7f5a-489e-955a-8a59aefcc51b">

## Structural Design Patterns
### 1. Adaptor Pattern
The Adapter Pattern allows objects with incompatible interfaces to work together. It acts as a bridge between two incompatible interfaces by wrapping an object with an interface that the client expects.

***Example:***
Imagine a restaurant that has upgraded to a new, modern meal preparation system but still needs to support the old, traditional system. The goal is to allow both systems to work together without modifying the existing code.

<img width="700" alt="image" src="https://github.com/gopityro/Design-Patterns-CPP/assets/25153647/6bdc9fd0-a9b2-4dac-817c-839798a3df7d">

### 2. Bridge Pattern
The Bridge Pattern decouples the abstraction from its implementation so that both can vary independently. This is useful when you want to avoid a proliferation of classes due to multiple combinations of abstractions and implementations.

***Example:***
Let's consider a scenario where we have different types of meals in a restaurant, and each meal can be prepared using different methods. We'll use the Bridge Pattern to separate the meal types (abstraction) from the preparation methods (implementation).

<img width="700" alt="image" src="https://github.com/gopityro/Design-Patterns-CPP/assets/25153647/5cbaccb9-822e-4b83-b1a9-dcb5806954b5">

### 3. Composite Pattern
The Composite Pattern allows you to treat individual objects and compositions of objects uniformly. This means you can work with single items and groups of items in the same way, making your code more flexible and easier to maintain.

***Example:***
Imagine you have a restaurant menu where some items are individual dishes (like a pancake or a sandwich), and some items are categories of dishes (like breakfast or lunch menus) that contain other items.

Using the Composite Pattern, you can treat both individual dishes and categories of dishes the same way. This means you can add a pancake to the breakfast menu or display all items in the menu (including sub-menus) using the same methods.

<img width="700" alt="image" src="https://github.com/gopityro/Design-Patterns-CPP/assets/25153647/90bb04a1-0169-496a-81ce-3fc7c9002c44">

### 4. Decorator Pattern

The Decorator Pattern allows you to add new functionality to existing objects dynamically, without altering their structure. It involves creating decorator classes that wrap around the original object, providing additional behavior while maintaining compatibility with the base object's interface.

***Example:***
Let's consider a scenario where we have a base Meal class, and we want to add extra features to meals like "Extra Cheese" or "Spicy". Instead of creating multiple subclasses for each combination of features, we can use the Decorator Pattern to add these features dynamically.

<img width="700" alt="image" src="https://github.com/gopityro/Design-Patterns-CPP/assets/25153647/ee03ba0a-45d9-4b74-ad2a-8605586fec46">

### 5. Facade Pattern

The Facade Design Pattern provides a simplified interface to a set of interfaces in a subsystem (other set of classes), making it easier to use.

***Example:***
In a restaurant, preparing a meal involves multiple steps like meal preparation and notifying the customer when the meal is ready. We can use the Facade Pattern to simplify these interactions for the client.

<img width="500" alt="image" src="https://github.com/gopityro/Design-Patterns-CPP/assets/25153647/aa9f44c6-7e98-4045-bd84-445df23f8acd">

### 6. Flyweight Pattern
The Flyweight Design Pattern allows you to minimize memory usage by sharing common parts of the state between multiple objects, instead of keeping all data in each object.

***Example:***
Imagine a scenario where a restaurant has an extensive menu with many items, and each item has a name, description, and price. If we have many orders, instead of creating a separate object for each menu item in every order, we can use the Flyweight pattern to share the common data (name, description, price) among the orders.

<img width="700" alt="image" src="https://github.com/gopityro/Design-Patterns-CPP/assets/25153647/9bc159dd-15e8-4769-9cc2-322a29fb19b4">

### 7. Proxy Pattern
The Proxy Pattern provides a surrogate or placeholder for another object to control access to it. This can be useful in various scenarios such as lazy initialization, access control, logging, or even adding some functionality before or after the actual object’s method execution.

***Example:***
Imagine a meal preparation system where accessing the kitchen directly might be too expensive or requires some form of access control. We can use a proxy to control access to the kitchen.

<img width="700" alt="image" src="https://github.com/gopityro/Design-Patterns-CPP/assets/25153647/cad28933-c57f-45a1-ac6c-b8572118f776">

## Behavioral Design Patterns
### 1. Observer Pattern
The Observer Pattern defines a one-to-many dependency between objects so that when one object changes state, all its dependents are notified and updated automatically. This pattern is often used to implement distributed event handling systems.

***Example:***
In a meal ordering system, we can use the Observer Pattern to notify multiple components (observers) about changes in the order status. For example, when an order is placed or updated, the kitchen staff, the billing system, and the customer should be notified.

<img width="600" alt="image" src="https://github.com/gopityro/Design-Patterns-CPP/assets/25153647/e6ccd52c-a77c-4209-8c0f-fb1b6728a88e">

### 2. State Pattern
The State Design Pattern allows an object to change its behavior when its internal state changes. The object will appear to change its class.

***Example:***

Let’s consider a scenario where we have an Order in a restaurant that can be in different states: Placed, Prepared, and Delivered. Each state will have its own behavior for processing the order.


<img width="700" alt="image" src="https://github.com/gopityro/Design-Patterns-CPP/assets/25153647/bced8eb7-0288-4727-809f-f75d76565298">

### 3. Strategy Pattern
The Strategy pattern allows you to define a family of algorithms, encapsulate each one as a separate class, and make them interchangeable. It lets the algorithm vary independently from clients that use it.

***Note:*** The State and Strategy Patterns look almost the same.

***Example:***
In a restaurant, you might have different strategies for cooking a meal based on dietary preferences: Vegetarian, Vegan, and Non-Vegetarian. Each cooking strategy has its own way of preparing the meal.

<img width="700" alt="image" src="https://github.com/gopityro/Design-Patterns-CPP/assets/25153647/c2e88f95-1a1d-43d5-b31c-761f74570248">

### 4. Visitor Pattern
The Visitor pattern lets you add further operations to objects without having to modify them. It separates an algorithm from the object structure on which it operates, allowing you to add new operations to existing object structures without modifying those structures.

***Example:*** Let’s consider a scenario where we have different types of menu items in a restaurant, and we want to apply various operations to them, such as calculating their price, checking dietary restrictions.

<img width="700" alt="image" src="https://github.com/gopityro/Design-Patterns-CPP/assets/25153647/cb37bc21-e936-475c-9109-e485e7fdc3ad">


