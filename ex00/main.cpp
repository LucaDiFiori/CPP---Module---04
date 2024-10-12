/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldi-fior <marvin@42.fr>                    #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-10-11 16:12:48 by ldi-fior          #+#    #+#             */
/*   Updated: 2024-10-11 16:12:48 by ldi-fior         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.Class.hpp"
#include "Dog.Class.hpp"
#include "Cat.Class.hpp"
#include "WrongAnimal.Class.hpp"
#include "WrongCat.Class.hpp"

int main()
{
	std::cout << " === CORRECT ANIMAL === " << std::endl;
	std::cout << "Animal object creation: " << std::endl;
	const Animal* meta = new Animal();
	std::cout << std::endl;

	std::cout << "Dog object creation: " << std::endl;
	const Animal* j = new Dog();
	std::cout << std::endl;

	std::cout << "Cat object creation: " << std::endl;
	const Animal* i = new Cat();
	std::cout << std::endl;

	std::cout << "getType calls from Dog and Cat: " << std::endl;
	std::cout << CYAN << j->getType() << " " << RESET << std::endl;
	std::cout << RED << i->getType() << " " << RESET << std::endl;
	std::cout << std::endl;
	
	std::cout << "makeSound calls from Dog, Cat and Animal: " << std::endl;
	j->makeSound();
	i->makeSound(); //will output the cat sound!
	meta->makeSound();
	std::cout << std::endl;

	std::cout << "Deleting objects: " << std::endl;
	std::cout << "Animal object destruction: " << std::endl;
	delete meta;
	std::cout << "Dog object destruction: " << std::endl;
	delete j;
	std::cout << "Cat object destruction: " << std::endl;
	delete i;



	std::cout << std::endl << std::endl;
	std::cout << " ================================ " << std::endl;
	std::cout << " === WRONG ANIMAL === " << std::endl;
	const WrongAnimal* meta2 = new WrongAnimal();
	const WrongAnimal* j2 = new WrongCat();
	std::cout << std::endl;
	
	std::cout << "getType calls from WrongCat: " << std::endl;
	std::cout << PURPLE << j2->getType() << " " << RESET << std::endl;
	std::cout << "makeSound calls from WrongCat: " << std::endl;
	j2->makeSound(); //will output the animal sound!
	std::cout << "makeSound call from the WrongCat object: " << std::endl;
	meta2->makeSound();
	std::cout << std::endl;

	std::cout << "WrongAnimal object destruction: " << std::endl;
	delete meta2;
	std::cout << "WrongCat object destruction:" << std::endl;
	delete j2;

	return 0;
}