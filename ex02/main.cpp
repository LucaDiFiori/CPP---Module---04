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

/*
* NOTES:
*
* why animals[i] = new Dog() and not animals[i] = Dog()?;
* ---------------------------
* animals is defined as an array of pointers to Animal. This means that each 
* element in the array should point to an instance of an Animal 
* (or a derived class like Dog or Cat), not hold an instance directly.
*
* When you write animals[i] = Dog();, you're creating a temporary Dog object 
* and trying to assign it to animals[i]. Since animals[i] is a pointer and Dog() 
* creates a Dog object, this leads to object slicing. The Dog object will be 
* sliced down to an Animal object when assigned to the pointer, losing all 
* the specific properties and behaviors of the Dog class.
* 
* Assigning a temporary object to a pointer in this way also means that you do 
* not manage memory properly. The temporary Dog will be destructed immediately 
* after the assignment, leading to undefined behavior when you try to access it 
* through animals[i].
*
* You should use new to allocate objects dynamically when you are dealing with 
* an array of pointers. This is because new returns a pointer to the allocated
* object, which can be stored in the array of pointers. The objects will be
* properly managed and destructed when you call delete on them.
*/
int main()
{
	const int arraySize = 10;
	Animal* animals[arraySize];

	std::cout << "=== Creating " << arraySize/2 << " new Dog ===" << std::endl;
	for (int i = 0; i < arraySize/2; i++)
		animals[i] = new Dog();

	std::cout << std::endl;

	std::cout << "=== Creating " << arraySize/2 << " new Cat ===" << std::endl;
	for (int i = arraySize/2; i < arraySize; i++)
		animals[i] = new Cat();

	std::cout << "\n=== Making sounds ===" << std::endl;
	for (int i = 0; i < arraySize; i++)
		animals[i]->makeSound();

	
	std::cout << "\n\n=== Tring to instantiate Animal ===" << std::endl;
	std::cout << "Uncomment Animal animal; in main.cpp to see the error" << std::endl;
	// Animal animal; // Error: cannot instantiate abstract class

	std::cout << "\n\n=== Deleting animals ===" << std::endl;
	for (int i = 0; i < arraySize; i++)
		delete animals[i];

}