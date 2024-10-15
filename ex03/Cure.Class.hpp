/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldi-fior <marvin@42.fr>                    #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-10-15 08:55:47 by ldi-fior          #+#    #+#             */
/*   Updated: 2024-10-15 08:55:47 by ldi-fior         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_CLASS_HPP
# define CURE_CLASS_HPP

#include "AMateria.Class.hpp"
#include "ICharacter.Class.hpp"

class Cure : public AMateria
{
	public:
		Cure();
		Cure(const Cure& src);
		Cure& operator=(const Cure& src);
		~Cure();

		//Override
		AMateria* clone() const;
		void use(ICharacter& target);
};

#endif