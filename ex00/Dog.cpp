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
}

Dog& Dog::operator=(const Dog& src)
{
	std::cout << CYAN << "Dog -assignation operator- called" << RESET << std::endl;
	if (this != &src)
	{
		this->setType(src.getType());
	}
	return (*this);
}

Dog::Dog(const Dog& src) : Animal(src)
{
	std::cout << CYAN << "Dog -copy constructor- called" << RESET << std::endl;
	*this = src;
}

Dog::~Dog()
{
	std::cout << CYAN << "Dog -destructor- called" << RESET << std::endl;
}

//Member functions (Override)___________________________________________________
void Dog::makeSound() const
{
	std::cout << CYAN << "Dog: Woof Woof" << RESET << std::endl;
}