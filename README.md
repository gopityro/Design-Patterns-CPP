# Design Patterns Using C++
 <img width="1000" alt="image" src="https://github.com/gopityro/Design-Patterns-CPP/assets/25153647/478509ca-c4d1-4edf-9407-6962102a6ad3">

 ## Factory Method:
Instead of directly instantiating concrete classes within client code, the Factory pattern allows you to delegate the responsibility of object creation to specialized factory classes or methods. These factories encapsulate the logic for creating instances of various related classes. Definitions always make confusing! 

***Example:***
Customers order meals at the restaurant, we need a flexible way to create different types of meals (e.g., vegetarian, non-vegetarian). Directly instantiating meal objects using their constructors can lead to tight coupling between the client code and the concrete meal classes.

<img width="700" alt="image" src="https://github.com/gopityro/Design-Patterns-CPP/assets/25153647/76959992-6e41-474f-859a-2627f8fdd460">


