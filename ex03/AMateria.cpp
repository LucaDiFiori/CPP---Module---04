/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldi-fior <marvin@42.fr>                    #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-10-15 07:35:52 by ldi-fior          #+#    #+#             */
/*   Updated: 2024-10-15 07:35:52 by ldi-fior         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.Class.hpp"


//Constructors__________________________________________________________________
AMateria::AMateria() : _type("unknown")
{
	std::cout << PURPLE << "AMateria - Default constructor - call" 
		<< RESET << std::endl;
}

AMateria::AMateria(const std::string& type) : _type(type)
{
	std::cout << PURPLE << "AMateria - Parameterized constructor - call" 
		<< RESET << std::endl;
}

AMateria::AMateria(const AMateria& src) : _type(src._type)
{
	std::cout << PURPLE << "AMateria - Copy constructor - call" 
		<< RESET << std::endl;
}

/*
* The body of the assignment operator is empty because the _type attribute is
* const and cannot be modified.
* ("While assigning a Materia to another, copying the type doesn’t make
* sense.")
*/
AMateria& AMateria::operator=(const AMateria& src)
{
	(void)src;
	std::cout << PURPLE << "AMateria - Assignation operator - call" 
		<< RESET << std::endl;
	return (*this);
}

//Destructor____________________________________________________________________
AMateria::~AMateria()
{
	std::cout << RED << "AMateria - Destructor - call" << RESET << std::endl;
}


//Methods_______________________________________________________________________
const std::string& AMateria::getType() const
{
	return(this->_type);
}


// virtual AMateria* clone() const = 0; // Pure virtual method

// No need to implement this method in the base class
void AMateria::use(ICharacter& target)
{
	(void)target;
}