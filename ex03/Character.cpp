/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luca <luca@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 11:59:54 by ldi-fior          #+#    #+#             */
/*   Updated: 2024/10/16 15:38:29 by luca             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Character.Class.hpp"

Character::Character()
{
	std::cout << RED << "Character - default constructor - call" << RESET << std::endl;
	
	this->_droppedMaterias = new AMateria*[4];
	this->_droppedCount = 0;
	this->_droppedCapacity = 4;

	for (int i = 0; i < 4; i++)
	{
		_inventory[i] = NULL;
		_droppedMaterias[i] = NULL;
	}
}

/*
* Copy constructor for the Character class
* ----------------------------------------
* This constructor performs a deep copy of the src object to ensure that
* the new Character object has its own copies of the dynamically allocated
* memory, avoiding potential issues with shared pointers and memory management.
*
* Initialization list
* -------------------
* - _name: Copies the name from the src object.
* - _droppedCount: Copies the count of dropped items from the src object.
* - _droppedCapacity: Copies the capacity of dropped items from the src object.
* - _droppedMaterias: Allocates new memory for dropped items with the same capacity as the src object.
*
* First for loop
* --------------
* - Iterates through the _inventory array (size 4).
* - Checks if each item in the src._inventory exists.
* - If it exists, clones the item to ensure a deep copy and assigns it to this->_inventory.
* - If it does not exist, assigns NULL to this->_inventory.
* Note: We use the clone method to ensure a deep copy of each item in the inventory.
*
* Second for loop
* ---------------
* - Iterates through the _droppedMaterias array up to the count of dropped items.
* - Clones each item in the src._droppedMaterias to ensure a deep copy and assigns it to this->_droppedMaterias.
* Note: We use the clone method to ensure a deep copy of each dropped item.
*/
Character::Character(const std::string& name)
{
	std::cout << RED << "Character: " << name <<" joined the game" << RESET << std::endl;
	
	this->_name = name;
	this->_droppedMaterias = new AMateria*[4];
	this->_droppedCount = 0;
	this->_droppedCapacity = 4;

	for (int i = 0; i < 4; i++)
	{
		_inventory[i] = NULL;
		_droppedMaterias[i] = NULL;
	}
}


Character::Character(const Character& src) : 
	_name(src._name), 
	_droppedCount(src._droppedCount), 
	_droppedCapacity(src._droppedCapacity),
	_droppedMaterias(new AMateria*[src._droppedCapacity])
{
	std::cout << RED << "Character - copy constructor - call" << RESET << std::endl;
	
	for (int i = 0; i < 4; i++)
	{
		if (src._inventory[i])
		{
			this->_inventory[i] = src._inventory[i]->clone();
		}
		else
			this->_inventory[i] = NULL;	
	}
	for (int i = 0; i < src._droppedCount; i++)
		this->_droppedMaterias[i] = src._droppedMaterias[i]->clone();
}


/*
* Assignment operator for the Character class
* -------------------------------------------
* This operator performs a deep copy of the src object to ensure that
* the current Character object has its own copies of the dynamically allocated
* memory, avoiding potential issues with shared pointers and memory management.
*
* Check for self-assignment
* -------------------------
* - If the current object is not the same as the src object, proceed with copying.
*
* Copy basic attributes
* ---------------------
* - _name: Copies the name from the src object.
* - _droppedCount: Copies the count of dropped items from the src object.
* - _droppedCapacity: Copies the capacity of dropped items from the src object.
*
* First for loop
* --------------
* - Iterates through the _inventory array (size 4).
* - If the current object has an item in the inventory, deletes it to avoid memory leaks.
* - Checks if each item in the src._inventory exists.
* - If it exists, clones the item to ensure a deep copy and assigns it to this->_inventory.
* - If it does not exist, assigns NULL to this->_inventory.
* Note: We use the clone method to ensure a deep copy of each item in the inventory.
*
* Second for loop
* ---------------
* - Iterates through the _droppedMaterias array up to the count of dropped items.
* - If the current object has an item in the droppedMaterias, deletes it to avoid memory leaks.
* - Clones each item in the src._droppedMaterias to ensure a deep copy and assigns it to this->_droppedMaterias.
* Note: We use the clone method to ensure a deep copy of each dropped item.
*/
Character& Character::operator=(const Character& src)
{
	if(this != &src)
	{
		this->_name = src._name;
		this->_droppedCount = src._droppedCount;
		this->_droppedCapacity = src._droppedCapacity;

		for (int i = 0; i < 4; i++)
		{
			if (this->_inventory[i])
				delete this->_inventory[i];
			if (src._inventory[i])
				this->_inventory[i] = src._inventory[i]->clone();
			else
				this->_inventory[i] = NULL;
		}

		for (int i = 0; i < src._droppedCount; i++)
		{
			if (this->_droppedMaterias[i])
			{
				delete this->_droppedMaterias[i];
			}
			this->_droppedMaterias[i] = src._droppedMaterias[i]->clone();
		}
	}
	return (*this);
}


Character::~Character()
{
	std::cout << RED << "Character: " << this->_name << " left the game" 
		<< RESET << std::endl;
	
	for (int i = 0; i < 4; i++)
	{
		if (this->_inventory[i])
		{
			delete this->_inventory[i];
			this->_inventory[i] = NULL;
		}
	}
	for (int i = 0; i < _droppedCount; i++)
	{
		if (this->_droppedMaterias[i])
		{
			delete this->_droppedMaterias[i];
			this->_droppedMaterias[i] = NULL;
		}
	}
	delete[] this->_droppedMaterias;
	this->_droppedMaterias = NULL;
}





// Public methods_______________________________________________________________
const std::string& Character::getName() const
{
    return (this->_name);
}

void Character::equip(AMateria* m)
{
	for (int i = 0; i < 4; i++)
	{
		if(this->_inventory[i] == NULL)
		{
			this->_inventory[i] = m;
			std::cout << GREEN << "Character: " << this->_name 
				<< "- equiped -" << m->getType() << RESET << std::endl;
			
			return;
		}
	}
	std::cout << "Inventory is full" << std::endl;
}


/*
* Method: Character::unequip
* --------------------------
* This method unequips an item from the character's inventory and moves it to the dropped items array.
* It ensures that the dropped items array has enough capacity to store the new item.
*
* Parameter:
* - idx: The index of the item in the inventory to unequip.
*
* Index validation
* ----------------
* - Checks if the index is within the valid range (0 to 3) and if the inventory slot is not NULL.
* - If the index is invalid, prints an error message and returns.
*
* Capacity check and reallocation
* -------------------------------
* - Checks if the dropped items array has reached its capacity.
* - If the capacity is reached, doubles the capacity and reallocates the array.
* - Copies the existing dropped items to the new array.
* - Deletes the old array and assigns the new array to _droppedMaterias.
*
* Unequip item
* ------------
* - Prints a message indicating the item has been unequipped.
* - Moves the item from the inventory to the dropped items array.
* - Increments the dropped items count.
* - Sets the inventory slot to NULL.
*/
void Character::unequip(int idx)
{
	if (idx < 0 || idx >= 4 || this->_inventory[idx] == NULL)
	{
		std::cout << "Invalid index" << std::endl;
		return;
	}

	if (this->_droppedCount >= this->_droppedCapacity)
	{
		this->_droppedCapacity *= 2;
		AMateria** newDroppedMaterias = new AMateria*[this->_droppedCapacity];

		for (int i = 0; i < this->_droppedCount; i++)
			newDroppedMaterias[i] = this->_droppedMaterias[i];

		delete[] this->_droppedMaterias;

		this->_droppedMaterias = newDroppedMaterias;	
	}

	std::cout << RED << "Character: " << this->_name 
		<< " - unequiped -" << this->_inventory[idx]->getType() << RESET << std::endl;

	this->_droppedMaterias[this->_droppedCount] = this->_inventory[idx];
	this->_droppedCount++;
	this->_inventory[idx] = NULL;
}


void Character::use(int idx, ICharacter& target)
{
	if (idx < 0 || idx >= 4 || this->_inventory[idx] == NULL)
	{
		std::cout << "Invalid index" << std::endl;
		return;
	}
	this->_inventory[idx]->use(target);
}