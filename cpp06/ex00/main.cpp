/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abablil <abablil@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 21:46:52 by abablil           #+#    #+#             */
/*   Updated: 2024/11/27 14:29:59 by abablil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main(int ac, char **args)
{
	if (ac != 2)
	{
		std::cout << "Usage: ./program [literal]" << std::endl;
		return 1;
	}
	ScalarConverter::convert(std::string(args[1]));
	return 0;
}