/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luca <luca@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 15:18:29 by luca              #+#    #+#             */
/*   Updated: 2024/10/16 17:56:56 by luca             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.Class.hpp"

MateriaSource::MateriaSource()
{
    std::cout << YELLOW << "MateriaSource - constructor - call." 
        << RESET << std::endl;
        
    for(int i = 0; i < 4; i++)
        this->_learnedMaterias[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource& src)
{
    std::cout << YELLOW << "MateriaSource - copy constructor - call." 
        << RESET << std::endl;

    for (int i = 0; i < 4; i++)
    {
        if (src._learnedMaterias[i])
            this->_learnedMaterias[i] = src._learnedMaterias[i]->clone();
        else
            this->_learnedMaterias[i] = NULL;
    }
}


MateriaSource& MateriaSource::operator=(const MateriaSource& src)
{
    std::cout << YELLOW << "MateriaSource - assignation operator - call."
        << RESET << std::endl;

    if (this != &src)
    {
        for (int i = 0; i < 4; i++)
        {
            if (this->_learnedMaterias[i])
                delete this->_learnedMaterias[i];
            if (src._learnedMaterias[i])
                this->_learnedMaterias[i] = src._learnedMaterias[i]->clone();
            else
                this->_learnedMaterias[i] = NULL;
        }
    }
    return (*this);
}

MateriaSource::~MateriaSource()
{
    std::cout << YELLOW << "MateriaSource - destructor - call." 
        << RESET << std::endl;
    for (int i = 0; i < 4; i++)
        delete _learnedMaterias[i];
}

/*
* Method: MateriaSource::learnMateria
* -----------------------------------
* This method allows the MateriaSource to learn a new Materia.
* It adds the Materia to the first available slot in the _learnedMaterias array.
*
* Parameter:
* - m: A pointer to the AMateria object to be learned.
*
* Null check
* ----------
* - If the provided Materia pointer is NULL, the method returns immediately.
*
* Adding the Materia
* ------------------
* - Iterates through the _learnedMaterias array to find the first available slot (NULL).
* - If an available slot is found, the Materia is added to that slot.
* - Prints a message indicating that the Materia has been learned.
* - Returns immediately after adding the Materia.
*
* Inventory full
* --------------
* - If no available slot is found, prints a message indicating that the inventory is full.
*/
void MateriaSource::learnMateria(AMateria* m)
{
    if (!m)
        return;

    for (int i = 0; i < 4; i++)
    {
        if (this->_learnedMaterias[i] == NULL)
        {
            std::cout << YELLOW << "MateriaSource learned: " << m->getType() 
                << RESET << std::endl;
            this->_learnedMaterias[i] = m;
            return;
        }
    }
    std::cout << YELLOW << "MateriaSource: inventory is full." 
        << RESET << std::endl;
}

/*
* Method: MateriaSource::createMateria
* ------------------------------------
* This method creates a new Materia of the specified type if it has been learned 
* by the MateriaSource.
* It searches through the _learnedMaterias array to find a Materia of the 
* given type and clones it.
*
* Parameter:
* - type: A reference to a string representing the type of Materia to be created.
*
* Searching for the Materia
* -------------------------
* - Iterates through the _learnedMaterias array to find a Materia that matches the specified type.
* - If a matching Materia is found, prints a message indicating that the Materia has been created.
* - Clones the found Materia and returns the clone.
*
* Materia not found
* -----------------
* - If no matching Materia is found, prints a message indicating that the Materia type was not found.
* - Returns NULL to indicate that the Materia could not be created.
*/
AMateria* MateriaSource::createMateria(const std::string& type)
{
    for (int i = 0; i < 4; i++)
    {
        if (this-> _learnedMaterias[i] && this-> _learnedMaterias[i]->getType() == type)
        {
            std::cout << YELLOW << "MateriaSource: " << type 
                << " created." << RESET << std::endl;
            return (this->_learnedMaterias[i]->clone());
        }
    }
    std::cout << YELLOW << "MateriaSource: " << type 
        << " not found." << RESET << std::endl;
    return (NULL);
}