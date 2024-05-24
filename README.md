# Design Patterns Using C++
 <img width="1000" alt="image" src="https://github.com/gopityro/Design-Patterns-CPP/assets/25153647/478509ca-c4d1-4edf-9407-6962102a6ad3">

 ## Factory Method
Instead of directly instantiating concrete classes within client code, the Factory pattern allows you to delegate the responsibility of object creation to specialized factory classes or methods. These factories encapsulate the logic for creating instances of various related classes. Definitions always make confusing! 

***Example:***
Customers order meals at the restaurant, we need a flexible way to create different types of meals (e.g., vegetarian, non-vegetarian). Directly instantiating meal objects using their constructors can lead to tight coupling between the client code and the concrete meal classes.

<img width="700" alt="image" src="https://github.com/gopityro/Design-Patterns-CPP/assets/25153647/76959992-6e41-474f-859a-2627f8fdd460">

## Abstract Factory
The Abstract Factory pattern extends the concept of the Factory Method pattern by providing an interface for creating families of related or dependent objects. It allows you to encapsulate multiple factory methods within a single abstract factory interface, each responsible for creating a different family of related objects

***Example:***
We will continue the example described in Factory Method. In a restaurant, customers not only choose between different types of meals (e.g., vegetarian, non-vegetarian) but also the style of dining (e.g., casual, fine dining)

<img width="700" alt="image" src="https://github.com/gopityro/Design-Patterns-CPP/assets/25153647/4d6ef590-8144-48ab-b543-9f1286f39f3b">

## Builder Pattern
The Builder Pattern is used to construct a complex object step by step. Unlike the Factory Pattern, which focuses on the creation of a single object, the Builder Pattern constructs an object using a series of steps or a sequence of method calls.

***Example:***
In a restaurant scenario, meals can have multiple varieties of dishes, and customers can customize their meals according to their preferences.








