/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.Class.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldi-fior <marvin@42.fr>                    #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-10-11 16:19:41 by ldi-fior          #+#    #+#             */
/*   Updated: 2024-10-11 16:19:41 by ldi-fior         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef CAT_CLASS_HPP
# define CAT_CLASS_HPP

# include "Animal.Class.hpp"

class Cat : public Animal
{
	private:
		Brain* _brain;

	public:
		Cat();
		Cat& operator=(const Cat& src);
		Cat(const Cat& src);
		~Cat();

		Brain* getBrain() const;

		void makeSound() const;
};

#endif