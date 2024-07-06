/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abablil <abablil@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 18:46:20 by abablil           #+#    #+#             */
/*   Updated: 2024/07/06 19:12:47 by abablil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::~Weapon() {}

Weapon::Weapon(std::string type)
{
	this->type = type;
}

const std::string &Weapon::getType()
{
	return this->type;
}

void Weapon::setType(std::string type)
{
	this->type = type;
}