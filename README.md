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

- Define the Base Class:
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