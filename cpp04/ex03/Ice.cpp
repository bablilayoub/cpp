/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abablil <abablil@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 10:53:34 by abablil           #+#    #+#             */
/*   Updated: 2024/10/10 10:54:48 by abablil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice() : AMateria("ice")
{
	std::cout << "Ice default constructor called" << std::endl;
}

Ice::Ice(const Ice &obj) : AMateria(obj)
{
	std::cout << "Ice copy constructor called" << std::endl;
}

Ice &Ice::operator=(const Ice &obj)
{
	if (this != &obj)
		this->type = obj.type;
	std::cout << "Ice copy assignment operator called" << std::endl;
	return *this;
}

Ice::Ice(std::string const &type) : AMateria(type)
{
	std::cout << "Ice type constructor called" << std::endl;
}

AMateria *Ice::clone() const
{
	std::cout << "Ice clone called" << std::endl;
	return new Ice(*this);
}

void Ice::use(ICharacter &target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}

Ice::~Ice()
{
	std::cout << "Ice destructor called" << std::endl;
}