/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abablil <abablil@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 15:35:54 by abablil           #+#    #+#             */
/*   Updated: 2024/07/06 15:42:36 by abablil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
	// Stack example
	randomChump("Stack Zombie");

	// Heap example
	Zombie* heapZombie = newZombie("Heap Zombie");
	heapZombie->announce();
	delete heapZombie;	
}