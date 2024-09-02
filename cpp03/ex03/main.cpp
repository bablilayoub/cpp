/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abablil <abablil@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 17:01:52 by abablil           #+#    #+#             */
/*   Updated: 2024/09/02 17:08:28 by abablil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int main()
{
	DiamondTrap diamondTrap("ayoub");
	diamondTrap.guardGate();
	diamondTrap.attack("target");
	diamondTrap.takeDamage(25);
	diamondTrap.takeDamage(25);
	diamondTrap.takeDamage(30);
	diamondTrap.takeDamage(1);
	diamondTrap.beRepaired(100);
	diamondTrap.takeDamage(50);
	diamondTrap.takeDamage(50);
	diamondTrap.takeDamage(1);
	diamondTrap.highFivesGuys();
	diamondTrap.whoAmI();
	return 0;
}