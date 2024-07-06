/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abablil <abablil@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 19:13:39 by abablil           #+#    #+#             */
/*   Updated: 2024/07/06 19:33:52 by abablil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "Weapon.hpp"

class HumanB
{
private:
	std::string name;
	Weapon* weapon;

public:
	HumanB(std::string name);
	~HumanB();
	void	attack();
	void	setWeapon(Weapon &weapon);
};
