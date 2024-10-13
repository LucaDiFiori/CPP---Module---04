/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldi-fior <marvin@42.fr>                    #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-10-11 16:19:57 by ldi-fior          #+#    #+#             */
/*   Updated: 2024-10-11 16:19:57 by ldi-fior         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.Class.hpp"

//Canonic form__________________________________________________________________

Cat::Cat() : Animal()
{
	this->setType("Cat");
	std::cout << RED << this->getType() << " -constructor- called" << RESET << std::endl;

	this->_brain = new Brain();
}

/*
* if (this != &src)
* -----------------
* This condition checks for self-assignment. If the object is being assigned to itself, 
* it returns early and avoids the rest of the code.
*
* Animal::operator=(src);
* -----------------------
* This line explicitly calls the assignment operator of the base class, `Animal`.
* It is a common practice when overloading the assignment operator in a derived class, 
* ensuring that the members of the base class are copied correctly.
*
* if (this->_brain)
* -----------------
* If the current object already has a pointer to a `Brain` object (`_brain`), 
* it deletes the old `Brain` object to avoid memory leaks before assigning a new one.
*
* this->_brain = new Brain(*src._brain);
* --------------------------------------
* `new Brain(*src._brain)` creates a new `Brain` object on the heap.
* The copy constructor of the `Brain` class is called, with the argument being 
* the object pointed to by `src._brain`.
* This means a new, independent copy of the `Brain` object is created, ensuring 
* that each `Cat` object has its own separate `Brain` instance.
*
* When you write `new Brain(*src.brain)`, you are instructing the compiler:
* "Create a new `Brain` object on the heap and initialize it with the existing object `*src.brain`."
* Since you are passing an existing object (`*src.brain`) to the constructor, 
* the compiler invokes the copy constructor of the `Brain` class.
*
* The new operator itself does not have constructors; instead, it is used to 
* allocate memory for an object and then calls the constructor of that object.
* 1. The new operator allocates memory for the object.
* 2. new calls the constructor for that type to initialize the newly allocated object.
* Example: Brain* myBrain = new Brain(param1, param2); // Calls the parameterized constructor of Brain
* The compiler determines which constructor to call based on the parameters you 
* provide when using the new operator. 
*
*
* return (*this);
* ---------------
* Finally, this line returns a reference to the current object (*this)
*/
Cat& Cat::operator=(const Cat& src)
{
	std::cout << RED << this->getType() << " -assignation operator- called" 
		<< RESET << std::endl;
	if (this != &src)
	{
		Animal::operator=(src);

		if (this->_brain)
		{
			delete this->_brain;
		}
		//copy costructor
		this->_brain = new Brain(*src._brain);
	}
	return (*this);
}

/*
* Note: Why not use *this = src?
* -------------------------------
* It is generally not advisable to use the assignment operator (operator=) 
* within the copy constructor because the assignment operator assumes that 
* the object has already been fully constructed. When you call the assignment 
* operator inside the copy constructor, you are assigning values to an object 
* that is still being constructed, which can lead to undesirable behavior or 
* inefficiencies.
*
* Furthermore, the assignment operator may involve deallocation and 
* reallocation of resources that are unnecessary during the object's 
* construction. It is more efficient and safer to directly initialize the 
* object's members within the copy constructor.
*
* Animal(src): Why should I only copy _brain?
* ---------------------------------------------
* There is no need to copy other attributes because they have already been 
* copied by Animal(src). When you write 
* Cat::Cat(const Cat& src) : Animal(src), _brain(new Brain(*src._brain)), 
* you are initializing the attributes belonging to the Animal part of 
* the Cat class using the copy constructor of the base class Animal.
*
* : Animal(src), _brain(new Brain(*src._brain))
* Initializing _brain in the constructor's initializer list:
* -----------------------------------------------------------
* Cat::Cat(const Cat& src) : Animal(src), _brain(new Brain(*src._brain)),
* is the most efficient and safe way to ensure that the pointer is properly 
* initialized. This approach prevents double initialization and guarantees 
* that _brain is ready for use before the body of the constructor is executed.
*/
Cat::Cat(const Cat& src) : Animal(src), _brain(new Brain(*src._brain))
{
	std::cout << RED << this->getType() << " -copy constructor- called" 
		<< RESET << std::endl;
}

Cat::~Cat()
{
	std::cout << RED << this->getType() << " -destructor- called" 
		<< RESET << std::endl;

	if (this->_brain)
		delete this->_brain;
}

//Getters_______________________________________________________________________
Brain* Cat::getBrain() const
{
	return (this->_brain);
}


//Member functions (Override)__________________________________________________
void Cat::makeSound() const
{
	std::cout << RED << this->getType() << ": Miaou Miaou" << RESET << std::endl;
}