/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldi-fior <marvin@42.fr>                    #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-10-15 08:28:40 by ldi-fior          #+#    #+#             */
/*   Updated: 2024-10-15 08:28:40 by ldi-fior         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.Class.hpp"

Ice::Ice() : AMateria("ice")
{
	std::cout << CYAN << "Ice - default constructor - call" << RESET << std::endl;
}
// Best practice: use the member initializer list (calling the AMateria copy constructor) 
// to initialize the base class attributes
Ice::Ice(const Ice& src) : AMateria(src)
{
	std::cout << CYAN << "Ice - copy constructor - call" << RESET << std::endl;
}

Ice& Ice::operator=(const Ice& src)
{
	std::cout << CYAN << "Ice - assignation operator - call" << RESET << std::endl;

	return (*this);
}

Ice::~Ice()
{
	std::cout << CYAN << "Ice - destructor - call" << RESET << std::endl;
}


//Override

/*
* This method is an override of the pure virtual clone method in the AMateria class. 
* It creates and returns a new instance of the Ice class, which is a copy of the current 
* instance.
*
* Purpose: 
* --------
* To create a new Ice object that is a copy of the current object.
*
* Return:
* -------
* AMateria* - A pointer to the newly created Ice object.
*
* Implementation
* --------------
* - Prints a message to indicate that the clone method has been called.
* - Uses the copy ( (new Ice(*this)) )constructor to create a new Ice object 
*   and returns a pointer to it.
*/
AMateria* Ice::clone() const
{
	std::cout << CYAN << "Ice - clone - call" << RESET << std::endl;
	return (new Ice(*this));
}


void Ice::use(ICharacter& target)
{
    std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}