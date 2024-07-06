/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abablil <abablil@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 16:14:03 by abablil           #+#    #+#             */
/*   Updated: 2024/07/06 16:19:56 by abablil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
	Zombie	*zombies;
	int		number_of_zombies = 9;
	
	zombies = zombieHorde(number_of_zombies, "Horde");
	for (int i = 0; i < number_of_zombies; i++)
		zombies[i].announce();
	delete []zombies;
}