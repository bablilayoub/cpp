/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abablil <abablil@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 17:01:52 by abablil           #+#    #+#             */
/*   Updated: 2024/09/02 17:08:19 by abablil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main()
{
	ClapTrap clapTrap("ayoub");
	clapTrap.attack("target");
	clapTrap.takeDamage(5);
	clapTrap.takeDamage(5);
	clapTrap.takeDamage(5);
	clapTrap.beRepaired(5);
	clapTrap.takeDamage(5);
	clapTrap.takeDamage(5);
	return 0;
}