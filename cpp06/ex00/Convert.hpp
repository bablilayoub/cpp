/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Convert.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abablil <abablil@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 17:59:17 by abablil           #+#    #+#             */
/*   Updated: 2024/11/25 21:40:39 by abablil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "ScalarConverter.hpp"

class Convert
{
public:
	Convert();
	~Convert();
	Convert(const Convert &obj);
	Convert &operator=(const Convert &obj);

	bool isChar(const std::string &literal);
	bool isInt(const std::string &literal);
	bool isFloat(const std::string &literal);
	bool isDouble(const std::string &literal);

	char toChar(const std::string &literal);
	int toInt(const std::string &literal);
	float toFloat(const std::string &literal);
	double toDouble(const std::string &literal);

	void execute(const std::string &literal);
};
