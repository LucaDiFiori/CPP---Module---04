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
/* 
* Although you cannot instantiate an object of the abstract class Animal directly, 
* subclasses like Dog and Cat can still call the Animal constructor. 
* When you instantiate a subclass (Dog or Cat), the constructor of Animal is 
* called indirectly as part of the derived class's construction process.
*/
Cat::Cat() : Animal()
{
	this->setType("Cat");
	std::cout << RED << this->getType() << " -constructor- called" << RESET << std::endl;

	this->_brain = new Brain();
}

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