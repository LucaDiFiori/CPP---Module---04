# CPP---Module---04
This module is designed to help you understand Subtype polymorphism, abstract classes and interfaces in CPP.

***

# C++ BASICS 04

***

# Table of Contents
- [SUBTYPE POLYMORPHISM](#subtype-polymorphism)
	- [Polymorphism Overview](#polymorphism-overview)
	- [Understanding Subtype Polymorphism](#understanding-subtype-polymorphism)
	- [Implementation in C++](#Implementation-in-c++)
	- [Key Concepts and Mechanisms](#key-concepts-and-mechanisms)
		- [1. Virtual Functions](#1-virtual-functions)
		- [2. Dynamic Binding](#1-dynamic-binding)
		- [3. Base and Derived Classes](#3-base-and-derived-classes)
		- [4. The override Specifier](#4-the-override-specifier)
		- [5. ](#5-the-final-specifier)
		- [6. Virtual Destructors](#6-virtual-destructors)
	- [Practical Examples](#pratical-examples)
	- [Advantages and Considerations](#advantages-and-considerations)
	- [Common Pitfalls and Best Practices](#common-pitfalls-and-best-practices)

***
***

# SUBTYPE POLYMORPHISM
Subtype polymorphism **allows objects of different types to be treated uniformly based on a shared base type**. In C++, subtype polymorphism is primarily achieved through **inheritance** and **virtual functions**, enabling dynamic (run-time) behavior.


## Polymorphism Overview
**Polymorphism** allows entities like functions or objects to take on multiple forms. In C++, polymorphism is categorized into:

- **Compile-Time (Static) Polymorphism**: Achieved via **function overloading** and templates. Resolved during compilation.
- **Run-Time (Dynamic) Polymorphism**: Achieved via **inheritance** and **virtual functions**. Resolved during program execution.

**Subtype Polymorphism** falls under run-time polymorphism, where a base class pointer or reference can refer to objects of derived classes.


## Understanding Subtype Polymorphism
**Subtype Polymorphism** allows a function to process objects differently based on 
their actual derived type, even when accessed through a base class interface. 
This is crucial for designing systems where behavior can be extended without 
modifying existing code.

**Key Characteristics**:
- **Inheritance**: Establishes an "is-a" relationship between base and derived classes.
- **Virtual Functions**: Enable derived classes to **override** base class methods.
- **Base Class Pointers/References**: Allow generic handling of different derived objects.


## Implementation in C++
To implement subtype polymorphism in C++, follow these steps:
- **Define a Base Class**: **Contains virtual functions** that derived classes can override.
- **Derive Subclasses**: Inherit from the base class and override virtual functions to provide specific behaviors.
- **Use Base Class Pointers/References**: Access derived objects through base class interfaces, enabling dynamic binding.

### Step-by-Step Example
Consider a graphics application with different shapes (e.g., Circle, Rectangle). 
Each shape can be drawn, but the drawing process differs. 
Using subtype polymorphism, a single interface can handle various shapes seamlessly.

- a. **Define the Base Class**:
```C++
// Shape.h
#ifndef SHAPE_H
#define SHAPE_H

#include <iostream>

class Shape {
public:
    // Virtual destructor to ensure proper cleanup of derived objects
    virtual ~Shape() {}

    // Pure virtual function makes Shape an abstract class
    virtual void draw() const = 0;

    // Optional: Other virtual functions
    virtual double area() const = 0;
};

#endif // SHAPE_H
```
- **Virtual Destructor**: Ensures that when a derived object is deleted through a base class pointer, the derived class's destructor is called.
- **Pure Virtual Functions (= 0)**: Make Shape an abstract class, preventing direct instantiation. Derived classes must override these functions.

- b. **Derive Subclasses**:
```C++
// Circle.h
#ifndef CIRCLE_H
#define CIRCLE_H

#include "Shape.h"
#include <cmath>

class Circle : public Shape {
private:
    double radius;

public:
    Circle(double r) : radius(r) {}

    // Override draw method
    void draw() const override {
        std::cout << "Drawing a Circle with radius " << radius << std::endl;
    }

    // Override area method
    double area() const override {
        return M_PI * radius * radius;
    }
};

#endif // CIRCLE_H
```
```C++
// Rectangle.h
#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "Shape.h"

class Rectangle : public Shape {
private:
    double width;
    double height;

public:
    Rectangle(double w, double h) : width(w), height(h) {}

    // Override draw method
    void draw() const override {
        std::cout << "Drawing a Rectangle with width " << width 
                  << " and height " << height << std::endl;
    }

    // Override area method
    double area() const override {
        return width * height;
    }
};

#endif // RECTANGLE_H
```
- **Inheritance**: Circle and Rectangle inherit publicly from Shape.
- **Override Keyword**: Ensures that the function is correctly overriding a base class virtual function.

- c. **Utilize Polymorphism**:
```C++
#include <iostream>
#include "Circle.h"
#include "Rectangle.h"

int main() {
    // Create Circle and Rectangle objects
    Circle circle(5.0);
    Rectangle rectangle(4.0, 6.0);

    // Use BASE CLASS Shape POINTERS for polymorphism  <------
    Shape* shape1 = &circle;
    Shape* shape2 = &rectangle;

    // Invoke the overridden methods
    shape1->draw();
    std::cout << "Area: " << shape1->area() << std::endl;

    shape2->draw();
    std::cout << "Area: " << shape2->area() << std::endl;

    return 0;
}
```
Output
```BASH
Drawing a Circle with radius 5
Area: 78.5398
Drawing a Rectangle with width 4 and height 6
Area: 24
```

***

## Key Concepts and Mechanisms
### 1. Virtual Functions
A **virtual function** is a member function in a base class that you expect to be overridden in derived classes. When a function is declared as virtual in the base class, C++ uses dynamic binding (also called late binding). This means that when you call the function through a pointer or reference to the base class, the derived class's version of the function will be invoked, if it exists.

- The **virtual keyword** is **only needed in the base class**. Even though derived classes override the function, you don't need to specify virtual again in the derived class (but you can for clarity).

```C++
virtual void functionName();
```

**Pure Virtual Functions**: 
- A pure virtual function is a special kind of virtual function that is declared in a base class with the = 0 syntax. This **makes the class an abstract class**, meaning it **cannot be instantiated** on its own, and any class that derives from it must provide an implementation for the pure virtual function. 
- (**Abstract class**: A class that contains at least one pure virtual function is considered an abstract class. This means you cannot create objects directly from that class. It's intended to serve as a base class for other classes to derive from.)
- The **= 0** at the end of the declaration tells the compiler that this function has no body in the base class and must be overridden in derived classes.
- **Mandatory Override**: Any class that inherits from the abstract class must provide a concrete implementation of the pure virtual function, otherwise it will also be considered abstract and cannot be instantiated.
- Pure virtual functions are essential in polymorphism, where base classes define a general **interface** (e.g., a Shape class with a pure virtual draw() method), and derived classes (e.g., Circle or Rectangle) provide specific behavior.


### 2. Dynamic Binding