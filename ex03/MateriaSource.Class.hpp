/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.Class.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luca <luca@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 15:09:49 by luca              #+#    #+#             */
/*   Updated: 2024/10/16 16:11:11 by luca             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_CLASS_H
# define MATERIASOURCE_CLASS_H

#include "IMateriaSource.Class.hpp"

class MateriaSource : public IMateriaSource
{
    private:
        AMateria* _learnedMaterias[4];

    public:
        MateriaSource();
        MateriaSource(const MateriaSource& src);
        MateriaSource& operator=(const MateriaSource& src);
        ~MateriaSource();

        void learnMateria(AMateria* m);
        AMateria* createMateria(const std::string& type);  
};

#endif