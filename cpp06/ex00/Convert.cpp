/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Convert.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abablil <abablil@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 17:59:25 by abablil           #+#    #+#             */
/*   Updated: 2024/11/26 12:35:36 by abablil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Convert.hpp"

Convert::Convert() {}

Convert::~Convert() {}

Convert::Convert(const Convert &obj) { *this = obj; }

Convert &Convert::operator=(const Convert &obj)
{
	(void)obj;
	return *this;
}

bool Convert::isInfOrNan(const std::string &literal, bool isFloat)
{
	if ((literal == "-inf" || literal == "+inf" || literal == "nan") && !isFloat)
		return true;
	if ((literal == "-inff" || literal == "+inff" || literal == "nanf") && isFloat)
		return true;
	return false;
}

bool Convert::isChar(const std::string &literal)
{
	if (literal.empty())
		return false;
	if (literal.length() == 1 && !std::isdigit(literal[0]) && std::isprint(literal[0]))
		return true;
	return false;
}

bool Convert::isInt(const std::string &literal)
{
	if (literal.empty())
		return false;
	if (literal.find('f') != std::string::npos || literal.find('.') != std::string::npos)
		return false;
	size_t i = 0;
	if (literal[i] == '+' || literal[i] == '-')
		i++;
	if (i == literal.length())
		return false;
	while (i < literal.length())
	{
		if (!std::isdigit(literal[i]))
			return false;
		i++;
	}
	long result = 0;
	int sign = (literal[0] == '-') ? -1 : 1;
	i = (literal[0] == '+' || literal[0] == '-') ? 1 : 0;
	for (size_t j = i; j < literal.length(); j++)
	{
		result = result * 10 + (literal[j] - '0');
		if (result * sign > std::numeric_limits<int>::max() || result * sign < std::numeric_limits<int>::min())
			return false;
	}
	return true;
}

bool Convert::isFloat(const std::string &literal)
{
	if (literal.empty())
		return false;
	if (this->isInfOrNan(literal, true))
		return true;

	bool dotSeen = false;
	bool fSeen = false;
	bool foundNumber = false;
	size_t i = 0;

	if (literal[i] == '+' || literal[i] == '-')
		i++;
	if (i == literal.length())
		return false;
	while (i < literal.length())
	{
		if (literal[i] == '.')
		{
			if (dotSeen || !foundNumber)
				return false;
			dotSeen = true;
		}
		else if (literal[i] == 'f')
		{
			if (fSeen || i != literal.length() - 1)
				return false;
			fSeen = true;
		}
		else if (std::isdigit(literal[i]))
			foundNumber = true;
		else
			return false;
		i++;
	}
	return dotSeen && fSeen;
}

bool Convert::isDouble(const std::string &literal)
{
	if (literal.empty())
		return false;
	if (this->isInfOrNan(literal, false))
		return true;

	bool dotSeen = false;
	bool foundNumber = false;
	size_t i = 0;

	if (literal[i] == '+' || literal[i] == '-')
		i++;
	if (i == literal.length())
		return false;
	while (i < literal.length())
	{
		if (literal[i] == '.')
		{
			if (dotSeen || !foundNumber)
				return false;
			dotSeen = true;
		}
		else if (std::isdigit(literal[i]))
			foundNumber = true;
		else
			return false;
		i++;
	}
	return true;
}

void Convert::toChar(const std::string &literal)
{
	char c = literal[0];
	std::cout << "char: '" << c << "'" << std::endl;
	std::cout << "int: " << static_cast<int>(c) << std::endl;
	std::cout << "float: " << static_cast<float>(c) << "f" << std::endl;
	std::cout << "double: " << static_cast<double>(c) << std::endl;
}

void Convert::toInt(const std::string &literal)
{
	int i = std::atof(literal.c_str());

	if (i >= 32 && i <= 126)
		std::cout << "char: '" << static_cast<char>(i) << "'" << std::endl;
	else
		std::cout << "char: " << "Non displayable" << std::endl;
	std::cout << "int: " << i << std::endl;
	std::cout << "float: " << static_cast<float>(i) << "f" << std::endl;
	std::cout << "double: " << static_cast<double>(i) << std::endl;
}

void Convert::toFloat(const std::string &literal)
{
	float f = std::atof(literal.c_str());

	if (this->isInfOrNan(literal, true))
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
	}
	else
	{
		if (f >= 32 && f <= 126)
			std::cout << "char: " << "'" << static_cast<char>(f) << "'" << std::endl;
		else
			std::cout << "char: " << "Non displayable" << std::endl;
		if (f > std::numeric_limits<int>::max() || f < std::numeric_limits<int>::min())
			std::cout << "int: impossible" << std::endl;
		else
			std::cout << "int: " << static_cast<int>(f) << std::endl;
	}
	std::cout << "float: " << f << "f" << std::endl;
	std::cout << "double: " << static_cast<double>(f) << std::endl;
}

void Convert::toDouble(const std::string &literal)
{
	double d = std::atof(literal.c_str());

	if (this->isInfOrNan(literal, false))
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
	}
	else
	{
		if (d >= 32 && d <= 126)
			std::cout << "char: " << "'" << static_cast<char>(d) << "'" << std::endl;
		else
			std::cout << "char: " << "Non displayable" << std::endl;
		if (d > std::numeric_limits<int>::max() || d < std::numeric_limits<int>::min())
			std::cout << "int: impossible" << std::endl;
		else
			std::cout << "int: " << static_cast<int>(d) << std::endl;
	}
	std::cout << "float: " << static_cast<double>(d) << "f" << std::endl;
	std::cout << "double: " << d << std::endl;
}

void Convert::execute(const std::string &literal)
{
	std::cout << std::fixed << std::setprecision(1);

	if (this->isChar(literal))
		return this->toChar(literal);

	if (this->isInt(literal))
		return this->toInt(literal);

	if (this->isFloat(literal))
		return this->toFloat(literal);

	if (this->isDouble(literal))
		return this->toDouble(literal);

	std::cout << "Invalid input!" << std::endl;
}