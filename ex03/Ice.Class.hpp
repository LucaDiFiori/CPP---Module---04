/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.Class.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldi-fior <marvin@42.fr>                    #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-10-15 08:18:42 by ldi-fior          #+#    #+#             */
/*   Updated: 2024-10-15 08:18:42 by ldi-fior         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_CLASS_HPP
# define ICE_CLASS_HPP

#include "AMateria.Class.hpp"
#include "ICharacter.Class.hpp"

class Ice : public AMateria
{
	public:
		Ice();
		Ice(const Ice& src);
		Ice& operator=(const Ice& src);
		~Ice();

		//Override
		AMateria* clone() const;
		void use(ICharacter& target);
};

#endif