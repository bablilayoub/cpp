/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abablil <abablil@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 10:54:55 by abablil           #+#    #+#             */
/*   Updated: 2024/11/05 14:59:31 by abablil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure() : AMateria("cure") {}

Cure::Cure(const Cure &obj) : AMateria(obj) {}

Cure::Cure(std::string const &type) : AMateria(type) {}

Cure::~Cure() {}

Cure &Cure::operator=(const Cure &obj)
{
	if (this != &obj)
		this->type = obj.type;
	return *this;
}

AMateria *Cure::clone() const { return new Cure(*this); }

void Cure::use(ICharacter &target)
{
	std::cout << "* heals " << target.getName() << "’s wounds *" << std::endl;
}
