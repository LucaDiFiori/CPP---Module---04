/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongWrongAnimal.Class.hpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldi-fior <marvin@42.fr>                    #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-10-12 08:41:49 by ldi-fior          #+#    #+#             */
/*   Updated: 2024-10-12 08:41:49 by ldi-fior         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_CLASS_HPP
# define WRONGANIMAL_CLASS_HPP

#include <iostream>

#  define GREEN "\033[1;32m"
#  define RED "\033[1;31m"
#  define CYAN "\033[1;36m"
#  define PURPLE "\033[1;35m"
#  define RESET "\033[0m"

/* 
*  No "virtual" keyword in the destructor
*  No "virtual" keyword in the makeSound method
*/
class WrongAnimal
{
	protected:
		std::string _type;

	public:
		WrongAnimal(void);
		WrongAnimal& operator = (const WrongAnimal& src);
		WrongAnimal(const WrongAnimal& src);
		~WrongAnimal(void);

		//getter and setter
		std::string getType() const;
		void setType(std::string type);

		//methods
		void makeSound() const;
};


#endif