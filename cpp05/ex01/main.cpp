/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abablil <abablil@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 18:12:31 by abablil           #+#    #+#             */
/*   Updated: 2024/11/16 22:07:09 by abablil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
	// Invalid test
	try
	{
		Bureaucrat b1("Ayoub", 2);
		std::cout << b1 << std::endl;

		Form form("ticket", 1, 1); // Grade too low

		form.beSigned(b1);
	}
	catch (const std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	std::cout << "|================================|" << std::endl;

	// Valid test
	try
	{
		Bureaucrat b1("Bablil", 140);
		std::cout << b1 << std::endl;

		Form form("ticket", 145, 1);

		form.beSigned(b1);
		b1.signForm(form);
	}
	catch (const std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	std::cout << "|================================|" << std::endl;

	// Valid & Invalid
	try
	{
		Bureaucrat b1("1337", 1);
		std::cout << b1 << std::endl;

		Form form("ticket", 2, 1);

		form.beSigned(b1); // will be signed

		std::cout << form.getName() << " is signed" << std::endl;

		b1.decrementGrade();
		b1.decrementGrade();

		std::cout << b1 << std::endl;

		b1.signForm(form); // will throw an exception
	}
	catch (const std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}
}