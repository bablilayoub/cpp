/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abablil <abablil@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 15:28:18 by abablil           #+#    #+#             */
/*   Updated: 2024/11/07 22:09:37 by abablil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria() {}

AMateria::AMateria(std::string const &type) : type(type) {}

AMateria::AMateria(const AMateria &obj) { *this = obj; }

AMateria::~AMateria() {}

std::string const &AMateria::getType() const { return this->type; }

AMateria &AMateria::operator=(const AMateria &obj)
{
	if (this != &obj)
		this->type = obj.type;
	return *this;
}

void AMateria::use(ICharacter &target)
{
	(void)target;
}
