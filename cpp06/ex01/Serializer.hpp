/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abablil <abablil@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 14:39:01 by abablil           #+#    #+#             */
/*   Updated: 2024/12/07 13:28:14 by abablil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <cstdint>
#include <iostream>

struct Data
{
	int number;
	std::string text;
};

class Serializer
{
private:
	Serializer();
	~Serializer();
	Serializer(const Serializer &obj);
	Serializer &operator=(const Serializer &obj);

public:
	static uintptr_t serialize(Data *ptr);
	static Data *deserialize(uintptr_t raw);
};