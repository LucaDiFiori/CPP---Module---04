/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldi-fior <marvin@42.fr>                    #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-10-15 11:59:54 by ldi-fior          #+#    #+#             */
/*   Updated: 2024-10-15 11:59:54 by ldi-fior         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.Class.hpp"

Character::Character()
{
	this->_droppedMaterias = new AMateria*[4];
	this->_droppedCount = 0;
	this->_droppedCapacity = 4;

	for (int i = 0; i < 4; i++)
	{
		_inventory[i] = NULL;
		_droppedMaterias[i] = NULL;
	}
}

Character::Character(const std::string& name)
{
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