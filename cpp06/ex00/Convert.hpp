/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Convert.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abablil <abablil@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 17:59:17 by abablil           #+#    #+#             */
/*   Updated: 2024/11/26 12:30:40 by abablil          ###   ########.fr       */
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

	bool isInfOrNan(const std::string &literal, bool isFloat);

	bool isChar(const std::string &literal);
	bool isInt(const std::string &literal);
	bool isFloat(const std::string &literal);
	bool isDouble(const std::string &literal);

	void toChar(const std::string &literal);
	void toInt(const std::string &literal);
	void toFloat(const std::string &literal);
	void toDouble(const std::string &literal);

	void execute(const std::string &literal);
};
