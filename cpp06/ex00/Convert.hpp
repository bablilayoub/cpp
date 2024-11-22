/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Convert.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abablil <abablil@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 17:59:17 by abablil           #+#    #+#             */
/*   Updated: 2024/11/22 18:01:16 by abablil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
};
