/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldi-fior <marvin@42.fr>                    #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-10-12 10:22:42 by ldi-fior          #+#    #+#             */
/*   Updated: 2024-10-12 10:22:42 by ldi-fior         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.Class.hpp"

Brain::Brain()
{
	std::cout << PURPLE << "Brain -constructor- called" << RESET << std::endl;
}

Brain& Brain::operator=(const Brain& src)
{
	std::cout << PURPLE << "Brain -assignation operator- called" << RESET << std::endl;
	if(this != &src)
	{
		for(int i = 0; i < 100; i++)
			this->_ideas[i] = src._ideas[i];
	}
	return (*this);
}

Brain::Brain(const Brain& src)
{
	std::cout << PURPLE << "Brain -copy constructor- called" << RESET << std::endl;
	*this = src;
}

Brain::~Brain()
{
	std::cout << PURPLE << "Brain -destructor- called" << RESET << std::endl;
}

void Brain::setIdea(std::string idea, int index)
{
	this->_ideas[index] = idea;
}

std::string Brain::getIdea(int index)
{
	return(this->_ideas[index]);
}