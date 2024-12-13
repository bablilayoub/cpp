/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abablil <abablil@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 15:57:45 by abablil           #+#    #+#             */
/*   Updated: 2024/12/13 17:41:41 by abablil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int ac, char **args)
{
	if (ac != 2)
	{
		std::cout << "Usage : ./btc [input file].txt" << std::endl;
		return 1;
	}
	try
	{
		std::string str(args[1]);
		BitcoinExchange obj(str);
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	return (0);
}