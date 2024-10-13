/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.Class.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldi-fior <marvin@42.fr>                    #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-10-12 10:13:21 by ldi-fior          #+#    #+#             */
/*   Updated: 2024-10-12 10:13:21 by ldi-fior         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef BRAIN_CLASS_HPP
#define BRAIN_CLASS_HPP

#  define GREEN "\033[1;32m"
#  define RED "\033[1;31m"
#  define CYAN "\033[1;36m"
#  define PURPLE "\033[1;35m"
#  define RESET "\033[0m"

#include <iostream>
#include <string>

class Brain
{
	private:
		std::string _ideas[100];

	public:
		Brain();
		Brain& operator=(const Brain& src);
		Brain(const Brain& src);
		~Brain();

		//set an idea at a specific index
		void setIdea(std::string idea, int index);
		//get an idea at a specific index
		std::string getIdea(int index);
};


#endif 