/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abablil <abablil@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 15:10:52 by abablil           #+#    #+#             */
/*   Updated: 2024/08/24 15:24:09 by abablil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class Zombie
{
private:
	std::string name;

public:
	Zombie();
	~Zombie();
	Zombie(std::string name);
	void announce(void);
};

Zombie*	newZombie(std::string name);
void	randomChump(std::string name);