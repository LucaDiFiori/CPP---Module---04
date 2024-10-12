/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.Class.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldi-fior <marvin@42.fr>                    #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-10-12 08:48:14 by ldi-fior          #+#    #+#             */
/*   Updated: 2024-10-12 08:48:14 by ldi-fior         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_CLASS_HPP
# define WRONGCAT_CLASS_HPP

#include <iostream>
#include "WrongAnimal.Class.hpp"

class WrongCat : public WrongAnimal
{
	public:
		WrongCat(void);
		WrongCat& operator = (const WrongCat& src);
		WrongCat(const WrongCat& src);
		~WrongCat(void);

		//methods
		void makeSound() const;
};

#endif