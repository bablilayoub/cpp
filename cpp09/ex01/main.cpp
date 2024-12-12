/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abablil <abablil@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 20:45:57 by abablil           #+#    #+#             */
/*   Updated: 2024/12/12 22:27:01 by abablil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int ac, char **args)
{
	if (ac != 2)
	{
		std::cout << "Usage : ./rpn \"eg: 4 1 -\"" << std::endl;
		return 1;
	}
	try
	{
		std::string str(args[1]);
		RPN obj(str);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	return (0);
}