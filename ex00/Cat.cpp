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
	std::cout << RED << this->getType() << " -constructor- called" 
		<< RESET << std::endl;
}

Cat& Cat::operator=(const Cat& src)
{
	std::cout << RED << this->getType() << " -assignation operator- called" 
		<< RESET << std::endl;
	if (this != &src)
	{
		this->setType(src.getType());
	}
	return (*this);
}

Cat::Cat(const Cat& src) : Animal(src)
{
	std::cout << RED << this->getType() << " -copy constructor- called" 
		<< RESET << std::endl;
	*this = src;
}

Cat::~Cat()
{
	std::cout << RED << this->getType() << " -destructor- called" 
		<< RESET << std::endl;
}


//Member functions (Override)__________________________________________________
void Cat::makeSound() const
{
	std::cout << RED << this->getType() << ": Miaou Miaou" << RESET << std::endl;
}