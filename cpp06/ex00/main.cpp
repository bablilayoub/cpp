/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abablil <abablil@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 21:46:52 by abablil           #+#    #+#             */
/*   Updated: 2024/11/25 21:50:26 by abablil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main(int ac, char **args)
{
	if (ac == 2)
	{
		ScalarConverter::convert(std::string(args[1]));
		return 0;
	}
	std::cout << "Invalid number of arguments" << std::endl;
	return 1;
}