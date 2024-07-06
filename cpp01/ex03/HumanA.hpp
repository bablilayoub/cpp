/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abablil <abablil@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 18:34:37 by abablil           #+#    #+#             */
/*   Updated: 2024/07/06 19:33:47 by abablil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "Weapon.hpp"

class HumanA
{
private:
	std::string name;
	Weapon &weapon;

public:
	HumanA(std::string name, Weapon &weapon);
	~HumanA();
	void attack();
};
