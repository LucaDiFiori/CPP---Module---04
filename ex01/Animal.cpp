/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldi-fior <marvin@42.fr>                    #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-10-11 16:14:52 by ldi-fior          #+#    #+#             */
/*   Updated: 2024-10-11 16:14:52 by ldi-fior         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.Class.hpp"

//Canonic form__________________________________________________________________
Animal::Animal()
{
	std::cout << GREEN << "Animal -constructor- called" << RESET << std::endl;
}

Animal& Animal::operator = (const Animal& src)
{
	std::cout << GREEN << "Animal -assignation operator- called" << RESET << std::endl;
	if (this != &src)
	{
		this->_type = src._type;
	}
	return (*this);
}

Animal::Animal(const Animal& src) : _type(src._type)
{
	std::cout << GREEN << "Animal -copy constructor- called" << RESET << std::endl;
}

Animal::~Animal()
{
	std::cout << GREEN << "Animal -destructor- called" << RESET << std::endl;
}

//getter and setter_____________________________________________________________
std::string Animal::getType() const
{
	return (this->_type);
}

void Animal::setType(std::string type)
{
	this->_type = type;
}

//methods_____________________________________________________________
void Animal::makeSound() const
{
	std::cout << GREEN << "The animal makes a sound" << RESET << std::endl;
}