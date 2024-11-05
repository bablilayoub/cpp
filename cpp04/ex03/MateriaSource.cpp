/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abablil <abablil@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 15:26:20 by abablil           #+#    #+#             */
/*   Updated: 2024/11/05 15:08:48 by abablil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	for (int i = 0; i < 4; i++)
		materias[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource &obj)
{
	for (int i = 0; i < 4; i++)
	{
		if (obj.materias[i])
			materias[i] = obj.materias[i]->clone();
		else
			materias[i] = NULL;
	}
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < 4; i++)
	{
		if (materias[i])
			delete materias[i];
	}
}

MateriaSource &MateriaSource::operator=(const MateriaSource &obj)
{
	if (this != &obj)
	{
		for (int i = 0; i < 4; i++)
		{
			if (materias[i])
				delete materias[i];
			if (obj.materias[i])
				materias[i] = obj.materias[i]->clone();
			else
				materias[i] = NULL;
		}
	}
	return *this;
}

void MateriaSource::learnMateria(AMateria *m)
{
	for (int i = 0; i < 4; i++)
	{
		if (!materias[i])
		{
			materias[i] = m;
			break;
		}
	}
}

AMateria *MateriaSource::createMateria(std::string const &type)
{
	for (int i = 0; i < 4; i++)
	{
		if (materias[i] && materias[i]->getType() == type)
			return materias[i]->clone();
	}
	return NULL;
}
