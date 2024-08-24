/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abablil <abablil@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 16:03:46 by abablil           #+#    #+#             */
/*   Updated: 2024/08/22 16:46:26 by abablil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
{	
private:
	std::string name;
	DiamondTrap();
	DiamondTrap(std::string name);
	DiamondTrap(const DiamondTrap &obj);
	~DiamondTrap();
	DiamondTrap &operator=(const DiamondTrap &obj);
};