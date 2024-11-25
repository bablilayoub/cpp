/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Convert.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abablil <abablil@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 17:59:25 by abablil           #+#    #+#             */
/*   Updated: 2024/11/25 22:15:37 by abablil          ###   ########.fr       */
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
		if (result * sign > INT_MAX || result * sign < INT_MIN)
			return false;
	}
	return true;
}

bool Convert::isFloat(const std::string &literal)
{
	if (literal == "-inff" || literal == "+inff" || literal == "nanf")
		return true;

	bool dotSeen = false;
	bool fSeen = false;

	size_t i = 0;
	if (literal[i] == '+' || literal[i] == '-')
		i++;

	if (i == literal.length())
		return false;

	while (i < literal.length())
	{
		if (literal[i] == '.')
		{
			if (dotSeen)
				return false;
			dotSeen = true;
		}
		else if (literal[i] == 'f')
		{
			if (fSeen || i != literal.length() - 1)
				return false;
			fSeen = true;
		}
		else if (!std::isdigit(literal[i]))
			return false;
		i++;
	}
	return dotSeen && fSeen;
}

bool Convert::isDouble(const std::string &literal)
{
	if (literal == "-inf" || literal == "+inf" || literal == "nan")
		return true;
	bool dotSeen = false;

	size_t i = 0;
	if (literal[i] == '+' || literal[i] == '-')
		i++;

	if (i == literal.length())
		return false;
	while (i < literal.length())
	{
		if (literal[i] == '.')
		{
			if (dotSeen)
				return false;
			dotSeen = true;
		}
		else if (!std::isdigit(literal[i]))
			return false;
		i++;
	}
	return true;
}

void Convert::execute(const std::string &literal)
{
	std::cout << std::fixed << std::setprecision(1);

	if (this->isChar(literal))
	{
		char c = literal[0];
		std::cout << "char: '" << c << "'" << std::endl;
		std::cout << "int: " << static_cast<int>(c) << std::endl;
		std::cout << "float: " << static_cast<float>(c) << "f" << std::endl;
		std::cout << "double: " << static_cast<double>(c) << std::endl;
		return;
	}

	if (this->isInt(literal))
	{
		int i = std::stoi(literal);
		std::cout << "char: " << ((i >= 32 && i <= 126) ? "'" + std::string(1, static_cast<char>(i)) + "'" : "Non displayable") << std::endl;
		std::cout << "int: " << i << std::endl;
		std::cout << "float: " << static_cast<float>(i) << "f" << std::endl;
		std::cout << "double: " << static_cast<double>(i) << std::endl;
		return;
	}

	if (this->isFloat(literal)) {
        float f = std::stof(literal);

        if (std::isnan(f) || std::isinf(f)) {
            std::cout << "char: impossible" << std::endl;
            std::cout << "int: impossible" << std::endl;
        } else {
            std::cout << "char: " << ((f >= 32 && f <= 126) ? "'" + std::string(1, static_cast<char>(f)) + "'" : "Non displayable") << std::endl;
            std::cout << "int: " << ((f > std::numeric_limits<int>::max() || f < std::numeric_limits<int>::min()) ? "impossible" : std::to_string(static_cast<int>(f))) << std::endl;
        }

        std::cout << "float: " << f << "f" << std::endl;
        std::cout << "double: " << static_cast<double>(f) << std::endl;
        return;
    }

	if (this->isDouble(literal))
	{
        std::cout << "Im double" << std::endl;
        double d = std::stod(literal);

        if (std::isnan(d) || std::isinf(d)) {
            std::cout << "char: impossible" << std::endl;
            std::cout << "int: impossible" << std::endl;
        } else {
            std::cout << "char: " << ((d >= 32 && d <= 126) ? "'" + std::string(1, static_cast<char>(d)) + "'" : "Non displayable") << std::endl;
            std::cout << "int: " << ((d > std::numeric_limits<int>::max() || d < std::numeric_limits<int>::min()) ? "impossible" : std::to_string(static_cast<int>(d))) << std::endl;
        }

        std::cout << "float: " << static_cast<float>(d) << "f" << std::endl;
        std::cout << "double: " << d << std::endl;
        return;
	}

	std::cout << "Invalid input!" << std::endl;
}