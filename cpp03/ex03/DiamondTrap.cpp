/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abablil <abablil@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 16:12:15 by abablil           #+#    #+#             */
/*   Updated: 2024/08/22 16:50:42 by abablil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap()
{
	std::cout << "DiamondTrap default constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name")
{
	this->hitPoints = FragTrap::hitPoints;
	this->energyPoints = ScavTrap::energyPoints;
}

DiamondTrap::DiamondTrap(const DiamondTrap &obj)
{
	std::cout << "DiamondTrap copy constructor called" << std::endl;
	*this = obj;
}

DiamondTrap::DiamondTrap(std::string name)
{
	this->name = name;
	std::cout << "DiamondTrap " << name << " 'name' constructor called" << std::endl;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap " << this->name << " destructor called" << std::endl;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &obj)
{
	std::cout << "DiamondTrap Assignation operator called" << std::endl;
	this->name = obj.name;
	return *this;
}