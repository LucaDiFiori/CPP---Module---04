/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.Class.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldi-fior <marvin@42.fr>                    #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-10-11 16:13:54 by ldi-fior          #+#    #+#             */
/*   Updated: 2024-10-11 16:13:54 by ldi-fior         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef ANIMAL_CLASS_HPP
#define ANIMAL_CLASS_HPP

#include <iostream>
#include <string>
#include "Brain.Class.hpp"

#  define GREEN "\033[1;32m"
#  define RED "\033[1;31m"
#  define CYAN "\033[1;36m"
#  define PURPLE "\033[1;35m"
#  define RESET "\033[0m"

/*
* To modify the Animal class so that it cannot be instantiated directly, 
* you can make it abstract by introducing at least one pure virtual function.
* This prevents the Animal class from being instantiated DIRECTLY, while derived 
* classes like Dog and Cat still need to implement makeSound(). 
* Since animals are supposed to make sounds, a good candidate for the pure 
* virtual function would be makeSound(), which already exists in your class.
*/
class Animal
{
	protected:
		std::string _type;

	public:
		Animal(void);
		Animal& operator = (const Animal& src);
		Animal(const Animal& src);
		virtual ~Animal(void);

		//getter and setter
		std::string getType() const;
		void setType(std::string type);

		//methods
		virtual void makeSound() const = 0;
};

#endif