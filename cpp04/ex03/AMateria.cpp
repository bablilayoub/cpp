/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abablil <abablil@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 15:28:18 by abablil           #+#    #+#             */
/*   Updated: 2024/10/03 16:07:56 by abablil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria()
{
	std::cout << "Default constructor called" << std::endl;
}

AMateria::AMateria(const AMateria &obj)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = obj;
}

AMateria::AMateria(std::string const &type) : type(type)
{
	std::cout << "Type constructor called" << std::endl;
}

std::string const &AMateria::getType() const
{
	return this->type;
}

AMateria::~AMateria() {
	std::cout << "Destractor called" << std::endl;
}

AMateria &AMateria::operator=(const AMateria &obj)
{
	if (this != &obj)
		this->type = obj.type;
	std::cout << "Copy assignment operator called" << std::endl;
	return *this;
}