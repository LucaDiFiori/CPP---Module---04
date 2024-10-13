/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongWrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldi-fior <marvin@42.fr>                    #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-10-12 08:46:15 by ldi-fior          #+#    #+#             */
/*   Updated: 2024-10-12 08:46:15 by ldi-fior         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.Class.hpp"

WrongAnimal::WrongAnimal()
{
	std::cout << GREEN << "WrongAnimal -constructor- called" << RESET << std::endl;
}

WrongAnimal& WrongAnimal::operator = (const WrongAnimal& src)
{
	std::cout << GREEN << "WrongAnimal -assignation operator- called" << RESET << std::endl;
	if (this != &src)
	{
		this->_type = src._type;
	}
	return (*this);
}

WrongAnimal::WrongAnimal(const WrongAnimal& src)
{
	std::cout << GREEN << "WrongAnimal -copy constructor- called" << RESET << std::endl;
	*this = src;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << GREEN << "WrongAnimal -destructor- called" << RESET << std::endl;
}

//getter and setter_____________________________________________________________
std::string WrongAnimal::getType() const
{
	return (this->_type);
}

void WrongAnimal::setType(std::string type)
{
	this->_type = type;
}

//getter and setter_____________________________________________________________
void WrongAnimal::makeSound() const
{
	std::cout << GREEN << "The WrongAnimal makes a sound" << RESET << std::endl;
}