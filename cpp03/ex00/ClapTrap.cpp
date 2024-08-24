/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abablil <abablil@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 16:28:53 by abablil           #+#    #+#             */
/*   Updated: 2024/08/22 15:25:42 by abablil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : hitPoints(10), energyPoints(10), attackDamage(0)
{
	std::cout << "ClapTrap default constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &obj)
{
	std::cout << "ClapTrap copy constructor called" << std::endl;
	*this = obj;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap destructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : hitPoints(10), energyPoints(10), attackDamage(0)
{
	this->name = name;
	std::cout << "ClapTrap " << this->name << " 'name' constructor called" << std::endl;
}

void ClapTrap::attack(const std::string &target)
{
	if (!this->hitPoints || !this->energyPoints || this->attackDamage < 0)
	{
		std::cout << "ClapTrap " << this->name << " can't attack anyone" << std::endl;
		return;
	}
	this->hitPoints -= this->attackDamage;
	this->energyPoints--;
	std::cout << "ClapTrap " << this->name << " attacks " << target << ", causing " << this->attackDamage << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (!this->hitPoints || amount > this->hitPoints)
	{
		std::cout << "ClapTrap " << this->name << " can't take damage" << std::endl;
		return;
	}
	this->hitPoints -= amount;
	std::cout << "ClapTrap " << this->name << " took damage of: " << amount << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	std::cout << "ClapTrap " << this->name << " health increased by " << amount << std::endl;
	this->hitPoints += amount;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &obj)
{
	std::cout << "Assignation operator called" << std::endl;
	this->name = obj.name;
	this->hitPoints = obj.hitPoints;
	this->energyPoints = obj.energyPoints;
	this->attackDamage = obj.attackDamage;
	return *this;
}