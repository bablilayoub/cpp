/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abablil <abablil@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 17:01:52 by abablil           #+#    #+#             */
/*   Updated: 2024/09/02 17:07:29 by abablil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int main()
{
	FragTrap ayoub("ayoub");
	ayoub.attack("target");
	ayoub.takeDamage(25);
	ayoub.takeDamage(25);
	ayoub.takeDamage(30);
	ayoub.takeDamage(1);
	ayoub.beRepaired(100);
	ayoub.takeDamage(50);
	ayoub.takeDamage(50);
	ayoub.takeDamage(1);
	ayoub.highFivesGuys();
	return 0;
}
