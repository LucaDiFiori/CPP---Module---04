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
	_droppedMaterias(new AMateria*[src._droppedCapacity]),
	_droppedCount(src._droppedCount), 
	_droppedCapacity(src._droppedCapacity)
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
		}
	}
	for (int i = 0; i < _droppedCount; i++)
	{
		if (this->_droppedMaterias[i])
		{
			delete this->_droppedMaterias[i];
		}
	}
	delete[] this->_droppedMaterias;
}





// Public methods_______________________________________________________________
const std::string& Character::getName() const
{
    return (this->_name);
}


/*
* Method: Character::equip
* ------------------------
* This method equips a given AMateria to the character's inventory. It ensures that 
* the same instance of Materia is not equipped multiple times and that the inventory 
* is not full before equipping.
*
* Parameter:
* - m: A pointer to the AMateria to be equipped.
*
* Null pointer check
* ------------------
* - Checks if the passed Materia pointer (m) is NULL.
* - If the pointer is NULL, the method returns immediately without any action.
*
* Checking for duplicates
* -----------------------
* - Loops through the inventory to check if the same instance of the given Materia 
*   is already equipped.
* - If found, prints a message indicating that the Materia is already equipped and 
*   returns without taking further action.
*
* Finding an empty slot
* ---------------------
* - During the loop, it also checks for the first available (NULL) slot in the 
*   inventory where the Materia can be equipped.
* - The index of the first free slot is saved in "freeSlot" variable.
*
* Equipping the Materia
* ---------------------
* - After the loop, if an empty slot is found, the Materia is equipped in that slot.
* - Prints a message indicating that the Materia has been successfully equipped.
* - If no free slot is found, prints a message stating that the inventory is full.
*/
void Character::equip(AMateria* m)
{
	if (!m)
        return;
		
	int freeSlot = -1;

    for (int i = 0; i < 4; i++)
    {
        if (this->_inventory[i] == m)
        {
            std::cout << GREEN << "Character: " << this->_name 
                      << " already has this Materia equipped!" << RESET << std::endl;
            return;
        }
        if (this->_inventory[i] == NULL && freeSlot == -1)
            freeSlot = i;
    }

    if (freeSlot != -1)
    {
        this->_inventory[freeSlot] = m;
        std::cout << GREEN << "Character: " << this->_name 
                  << " - equipped - " << m->getType() << RESET << std::endl;
    }
    else
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
		std::cout << "Invalid inventory slot" << std::endl;
		return;
	}
	this->_inventory[idx]->use(target);
}