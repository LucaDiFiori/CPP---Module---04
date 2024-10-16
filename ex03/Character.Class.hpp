/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.Class.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luca <luca@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 11:00:49 by ldi-fior          #+#    #+#             */
/*   Updated: 2024/10/16 13:06:57 by luca             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_CLASS_HPP
# define CHARACTER_CLASS_HPP

#include "ICharacter.Class.hpp"

/*
*  
* Private attributes: 
* -------------------
* - std::string _name: the name of the character.
* - AMateria* _inventory[4]: an array of 4 AMateria pointers.
*   We use AMateria pointers because "Your character’s inventory will be able to 
*  support any type of AMateria." - Subject -
* - Character(): private constructor. It is private because we don't want to
*   create a character without a name.
* - AMateria** _droppedMaterias: an array of AMateria pointers. It is used to
*   store the AMaterias that are unequiped from the inventory.
* - int _droppedCount: the number of AMaterias in the _droppedMaterias array.
* - int _droppedCapacity: the capacity of the _droppedMaterias array.
* 
* Public methods:
* -------------------
* - Constructor, Destructor and copy assignment operator.
* - const std::string& getName() const: returns the name of the character.
* - void equip(AMateria* m): equip an AMateria in the first empty slot of the
*   inventory.
* - void unequip(int idx): unequip the AMateria in the idx slot of the inventory.
* - void use(int idx, ICharacter& target): use the AMateria in the idx slot of
*   the inventory on the target (calling the AMateria::use method).
*/
class Character : public ICharacter
{
	private:
		std::string _name;
		AMateria* _inventory[4];
		
		AMateria** _droppedMaterias;
		int _droppedCount;
		int _droppedCapacity;

		Character();

	public:
		Character(const std::string& name);
		Character(const Character& src);
		Character& operator=(const Character& src);
		~Character();

		const std::string& getName() const;

		void equip(AMateria* m);
		void unequip(int idx);
		void use(int idx, ICharacter& target);
};

#endif
