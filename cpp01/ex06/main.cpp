/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abablil <abablil@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 09:50:15 by abablil           #+#    #+#             */
/*   Updated: 2024/07/08 16:52:15 by abablil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int check_errors(int total, char **args)
{
	if (total != 2)
	{
		std::cout << "Usage ./harlFilter (lavel)" << std::endl;
		return (0);
	}
	if (std::string(args[1]).empty())
	{
		std::cout << "Level can't be empty" << std::endl;
		return (0);
	}
	return (1);
}

int main(int total, char **args)
{
	if (!check_errors(total, args))
		return (1);
	Harl test = Harl();
	test.complain(std::string(args[1]));
	return (0);
}