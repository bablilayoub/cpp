/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abablil <abablil@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 17:07:39 by abablil           #+#    #+#             */
/*   Updated: 2024/12/14 16:56:13 by abablil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int ac, char **args)
{
	if (ac <= 2)
	{
		std::cout << "Usage : ./PmergeMe 2 1" << std::endl;
		return 1;
	}
	try
	{
		PmergeMe app;
		app.runVector(ac, args);
		app.runDeque(ac, args);
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	return 0;
}