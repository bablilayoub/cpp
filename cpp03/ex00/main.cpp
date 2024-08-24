/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abablil <abablil@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 17:01:52 by abablil           #+#    #+#             */
/*   Updated: 2024/08/22 12:00:56 by abablil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main()
{
	ClapTrap clapTrap("default");
	clapTrap.attack("target");
	clapTrap.takeDamage(5);
	clapTrap.takeDamage(5);
	clapTrap.takeDamage(5);
	clapTrap.beRepaired(5);
	clapTrap.takeDamage(5);
	clapTrap.takeDamage(5);
	return 0;
}