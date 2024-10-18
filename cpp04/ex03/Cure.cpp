/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abablil <abablil@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 10:54:55 by abablil           #+#    #+#             */
/*   Updated: 2024/10/10 10:55:46 by abablil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure() : AMateria("cure")
{
	std::cout << "Cure default constructor called" << std::endl;
}

Cure::Cure(const Cure &obj) : AMateria(obj)
{
	std::cout << "Cure copy constructor called" << std::endl;
}

Cure &Cure::operator=(const Cure &obj)
{
	if (this != &obj)
		this->type = obj.type;
	std::cout << "Cure copy assignment operator called" << std::endl;
	return *this;
}

Cure::Cure(std::string const &type) : AMateria(type)
{
	std::cout << "Cure type constructor called" << std::endl;
}

AMateria *Cure::clone() const
{
	std::cout << "Cure clone called" << std::endl;
	return new Cure(*this);
}

void Cure::use(ICharacter &target)
{
	std::cout << "* heals " << target.getName() << "’s wounds *" << std::endl;
}

Cure::~Cure()
{
	std::cout << "Cure destructor called" << std::endl;
}