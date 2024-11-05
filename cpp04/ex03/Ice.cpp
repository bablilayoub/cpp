/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abablil <abablil@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 10:53:34 by abablil           #+#    #+#             */
/*   Updated: 2024/11/05 15:01:32 by abablil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice() : AMateria("ice") {}

Ice::Ice(const Ice &obj) : AMateria(obj) {}

Ice::Ice(std::string const &type) : AMateria(type) {}

Ice::~Ice() {}

Ice &Ice::operator=(const Ice &obj)
{
	if (this != &obj)
		this->type = obj.type;
	return *this;
}

AMateria *Ice::clone() const { return new Ice(*this); }

void Ice::use(ICharacter &target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}