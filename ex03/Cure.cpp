/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldi-fior <marvin@42.fr>                    #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-10-15 08:57:07 by ldi-fior          #+#    #+#             */
/*   Updated: 2024-10-15 08:57:07 by ldi-fior         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.Class.hpp"

Cure::Cure() : AMateria("cure")
{
	std::cout << GREEN << "Cure - default constructor - call" 
		<< RESET << std::endl;
}

Cure::Cure (const Cure& src) : AMateria(src)
{
	std::cout << GREEN << "Cure - copy constructor - call" 
		<< RESET << std::endl;
}

Cure& Cure::operator=(const Cure& src)
{
	std::cout << GREEN << "Cure - assignation operator - call" 
		<< RESET << std::endl;
	return (*this);
}

Cure::~Cure()
{
	std::cout << GREEN << "Cure - destructor - call" 
		<< RESET << std::endl;
}

//Override
AMateria* Cure::clone() const
{
	std::cout << GREEN << "Cure - clone - call" << RESET << std::endl;
	return (new Cure(*this));
}

void Cure::use(ICharacter& target)
{
	std::cout << GREEN << "* heals " << target.getName() << "'s wounds *" 
		<< RESET << std::endl;
}