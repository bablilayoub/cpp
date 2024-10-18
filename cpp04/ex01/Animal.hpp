/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abablil <abablil@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 18:39:01 by abablil           #+#    #+#             */
/*   Updated: 2024/09/03 16:04:00 by abablil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class Animal
{
protected:
	std::string type;

public:
	Animal();
	Animal(std::string name);
	Animal(const Animal &obj);
	Animal &operator=(const Animal &obj);
	virtual ~Animal();
	std::string getType() const;
	virtual void	makeSound() const;
};
