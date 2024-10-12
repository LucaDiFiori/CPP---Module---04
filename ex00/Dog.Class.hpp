/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.Class.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldi-fior <marvin@42.fr>                    #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-10-11 16:18:00 by ldi-fior          #+#    #+#             */
/*   Updated: 2024-10-11 16:18:00 by ldi-fior         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef DOG_CLASS_HPP
#define DOG_CLASS_HPP

#include "Animal.Class.hpp"

class Dog : public Animal
{
	public:
		Dog();
		Dog& operator=(const Dog& src);
		Dog(const Dog& src);
		~Dog();

		void makeSound() const;
};

#endif