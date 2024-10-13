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
	private:
		Brain* _brain;
		
	public:
		Dog();
		Dog& operator=(const Dog& src);
		Dog(const Dog& src);
		~Dog();

		Brain* getBrain() const;

		void makeSound() const;
};

#endif