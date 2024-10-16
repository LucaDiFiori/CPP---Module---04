/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.Class.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luca <luca@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 09:50:12 by ldi-fior          #+#    #+#             */
/*   Updated: 2024/10/16 15:21:31 by luca             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_CLASS_HPP
# define AMATERIA_CLASS_HPP

# ifndef COLORS
#  define COLORS
#  define PURPLE "\033[1;35m"
#  define GREEN "\033[1;32m"
#  define CYAN "\033[1;36m"
#  define RED "\033[1;31m"
# define YELLOW "\033[1;33m"
#  define RESET "\033[0m"
# endif

# include <iostream>
# include <string>

// Forward declaration
class ICharacter;


/*
* Note: virtual void use(ICharacter& target);
* -------------------------------------------
*
* When a method takes an interface reference as an argument, 
* it means that the method can accept any object that implements that interface. 
* In this case, the method use(ICharacter& target) takes a reference to an 
* object that implements the ICharacter interface.
*
*
* Note: clone Method:
* -------------------
* Declared as virtual and pure virtual (abstract), meaning any class derived from 
* AMateria must provide an implementation for this method.
*/
class AMateria
{
	protected:
		// Use "const" because of this note in the subject:
		// "While assigning a Materia to another, copying the type doesn’t make
        // sense".
		const std::string _type;
	
	public:
		AMateria();
		AMateria(const std::string& type);
		AMateria(const AMateria& src);
		AMateria& operator=(const AMateria& src);
		virtual ~AMateria();

		const std::string& getType() const;
		
		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target);
};

#endif