/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abablil <abablil@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 18:12:31 by abablil           #+#    #+#             */
/*   Updated: 2024/11/15 19:40:40 by abablil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
	try
	{
		Bureaucrat b1("Ayoub", 2);
		std::cout << b1 << std::endl;

		b1.incrementGrade();
		std::cout << b1 << std::endl;

		b1.incrementGrade(); // Grade too hight
	}
	catch (const std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	std::cout << "|================================|" << std::endl;

	try
	{
		Bureaucrat b1("Ayoub", 149);
		std::cout << b1 << std::endl;

		b1.decrementGrade();
		std::cout << b1 << std::endl;

		b1.decrementGrade(); // Grade too low
	}
	catch (const std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	std::cout << "|================================|" << std::endl;

	// Grade too high
	try
	{
		Bureaucrat b2("Bablil", 0);
	}
	catch (const std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	std::cout << "|================================|" << std::endl;

	// Grade too low
	try
	{
		Bureaucrat b2("Bablil", 160);
	}
	catch (const std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}
}