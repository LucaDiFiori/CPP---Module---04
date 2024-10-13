/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldi-fior <marvin@42.fr>                    #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-10-11 16:18:44 by ldi-fior          #+#    #+#             */
/*   Updated: 2024-10-11 16:18:44 by ldi-fior         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.Class.hpp"

//Canonic form__________________________________________________________________
Dog::Dog() : Animal()
{

	std::cout << CYAN << "Dog -constructor- called" << RESET << std::endl;
	this->setType("Dog");

	this->_brain = new Brain();
}

Dog& Dog::operator=(const Dog& src)
{
	std::cout << CYAN << "Dog -assignation operator- called" << RESET << std::endl;
	if (this != &src)
	{
		Animal::operator=(src);
		if (this->_brain)
			delete this->_brain;
		this->_brain = new Brain(*src._brain);
	}
	return (*this);
}

Dog::Dog(const Dog& src) : Animal(src), _brain(new Brain(*src._brain))
{
	std::cout << CYAN << "Dog -copy constructor- called" << RESET << std::endl;
}

Dog::~Dog()
{
	std::cout << CYAN << "Dog -destructor- called" << RESET << std::endl;
	if (this->_brain)
		delete this->_brain;
}

//Getters_______________________________________________________________________
Brain* Dog::getBrain() const
{
	return (this->_brain);
}


//Member functions (Override)___________________________________________________
void Dog::makeSound() const
{
	std::cout << CYAN << "Dog: Woof Woof" << RESET << std::endl;
}