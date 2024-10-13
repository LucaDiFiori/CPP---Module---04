/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongWrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldi-fior <marvin@42.fr>                    #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-10-12 08:49:17 by ldi-fior          #+#    #+#             */
/*   Updated: 2024-10-12 08:49:17 by ldi-fior         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.Class.hpp"

WrongCat::WrongCat() : WrongAnimal()
{
	this->setType("WrongCat");
	std::cout << RED << this->getType() << " -constructor- called" 
		<< RESET << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& src)
{
	std::cout << RED << this->getType() << " -assignation operator- called" 
		<< RESET << std::endl;
	if (this != &src)
	{
		this->setType(src.getType());
	}
	return (*this);
}

WrongCat::WrongCat(const WrongCat& src) : WrongAnimal(src)
{
	std::cout << RED << this->getType() << " -copy constructor- called" 
		<< RESET << std::endl;
	*this = src;
}

WrongCat::~WrongCat()
{
	std::cout << RED << this->getType() << " -destructor- called" 
		<< RESET << std::endl;
}


//Member functions (Override)__________________________________________________
void WrongCat::makeSound() const
{
	std::cout << RED << this->getType() << ": Miaou Miaou" << RESET << std::endl;
}