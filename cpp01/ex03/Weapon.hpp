/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abablil <abablil@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 16:54:20 by abablil           #+#    #+#             */
/*   Updated: 2024/07/06 19:22:07 by abablil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class Weapon
{
private:
	std::string type;

public:
	Weapon(std::string type);
	~Weapon();
	const std::string &getType();
	void setType(std::string type);
};