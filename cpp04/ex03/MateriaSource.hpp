/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abablil <abablil@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 15:23:51 by abablil           #+#    #+#             */
/*   Updated: 2024/11/03 15:25:58 by abablil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
private:
	AMateria *materias[4];
public:
	MateriaSource();
	MateriaSource(const MateriaSource &obj);
	MateriaSource &operator=(const MateriaSource &obj);
	~MateriaSource();
	void learnMateria(AMateria *m);
	AMateria *createMateria(std::string const &type);
};
