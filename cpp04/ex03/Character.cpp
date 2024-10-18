/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abablil <abablil@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 10:57:24 by abablil           #+#    #+#             */
/*   Updated: 2024/10/10 11:01:06 by abablil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character() : name("default")
{
	std::cout << "Character default constructor called" << std::endl;
	for (int i = 0; i < 4; i++)
		this->materia[i] = NULL;
}

Character::Character(const Character &obj)
{
	std::cout << "Character copy constructor called" << std::endl;
	*this = obj;
}

Character &Character::operator=(const Character &obj)
{
	if (this != &obj)
	{
		this->name = obj.name;
		for (int i = 0; i < 4; i++)
		{
			if (this->materia[i])
				delete this->materia[i];
			this->materia[i] = obj.materia[i]->clone();
		}
	}
	std::cout << "Character copy assignment operator called" << std::endl;
	return *this;
}

Character::Character(std::string const &name) : name(name)
{
	std::cout << "Character type constructor called" << std::endl;
	for (int i = 0; i < 4; i++)
		this->materia[i] = NULL;
}

std::string const &Character::getName() const
{
	return this->name;
}

void Character::equip(AMateria *m)
{
	for (int i = 0; i < 4; i++)
	{
		if (!this->materia[i])
		{
			this->materia[i] = m;
			break;
		}
	}
}

void Character::unequip(int idx)
{
	if (idx >= 0 && idx < 4)
		this->materia[idx] = NULL;
}

void Character::use(int idx, ICharacter &target)
{
	if (idx >= 0 && idx < 4 && this->materia[idx])
		this->materia[idx]->use(target);
}

Character::~Character()
{
	std::cout << "Character destructor called" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (this->materia[i])
			delete this->materia[i];
	}
}