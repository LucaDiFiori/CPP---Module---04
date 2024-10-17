/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luca <luca@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 17:57:45 by luca              #+#    #+#             */
/*   Updated: 2024/10/16 17:57:47 by luca             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.Class.hpp"
#include "Character.Class.hpp"
#include "Ice.Class.hpp"
#include "Cure.Class.hpp"


int main()
{
    // Creazione del MateriaSource

	std::cout << " == Test 0: MateriaSource creation and Materias learning" << std::endl;
    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());

    std::cout << "\n\n== Test 1: Character 'me' creation" << std::endl;
    ICharacter* me = new Character("me");
    
	std::cout << "\n\n== Test 2: AMaterias creation and equip" << std::endl;
	AMateria* tmp;
    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);

    std::cout << "\n\n== Test 3: Character 'bob'" << std::endl;
    ICharacter* bob = new Character("bob");

    std::cout << "\n== Test 4: 'me' use Materias on 'bob'" << std::endl;
    me->use(0, *bob);
    me->use(1, *bob);

	std::cout << "\n\n== Test 5: Equipping beyond the limit ==" << std::endl;
    AMateria* ice1 = src->createMateria("ice");
    AMateria* cure2 = src->createMateria("cure");
    AMateria* extraMateria = src->createMateria("ice");


    me->equip(ice1);
    me->equip(cure2);
    me->equip(extraMateria);

	std::cout << "\n\n== Test 6: Testing a non-existing slot ==" << std::endl;
    me->use(4, *bob);

    std::cout << "\n\n== Test 7: Try to equip the same Materia instance twice ==" << std::endl;
    AMateria* sameMateria = src->createMateria("ice");
    me->equip(sameMateria);
    me->equip(sameMateria);


    std::cout << "\n\n== Test 8: Deep copy of the character ==" << std::endl;;
    /*
    * Note: new Character(*dynamic_cast<Character*>(me))
    * ---------------------------------------------------
    * The cast is required because me is declared as ICharacter*, and to create 
    * a copy of the Character object, you need to downcast it to Character* 
    * to call the Character copy constructor (we can not istantiate an abstract class).
    */
    Character* clone = new Character(*dynamic_cast<Character*>(me));

    std::cout << " --> Use the clone's Materias on 'bob'" << std::endl;
    clone->use(0, *bob);
    clone->use(1, *bob);

    std::cout << " --> Unequip the Materia in slot 0 from the source Character" << std::endl;
    me->unequip(0);
    std::cout << " --> Check if the clone still has the Materia in slot 0" << std::endl;
    clone->use(0, *bob); // Il clone dovrebbe ancora avere la Materia nello slot 0
    delete clone;


    std::cout << "\n\n== Test 9: Unknown Materia creation ==" << std::endl;
    AMateria* unknownMateria = src->createMateria("fire");
    if (unknownMateria == NULL)
        std::cout << "Unknown Materia not created as expected" << std::endl;
    else
        std::cout << "Error: Unknown Materia should return nullptr" << std::endl;


    std::cout << "\n== Destroying the objects ==" << std::endl;
    delete bob;
    delete me;
    delete src;
    delete extraMateria;
    delete sameMateria;
    delete unknownMateria;

    return 0;
}
