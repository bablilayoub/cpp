/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abablil <abablil@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 18:12:31 by abablil           #+#    #+#             */
/*   Updated: 2024/11/18 18:00:31 by abablil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	try
	{
		Bureaucrat b1("b1", 1);
		PresidentialPardonForm f1("f1");
		PresidentialPardonForm f2("f2");

		std::cout << b1 << std::endl;
		std::cout << f1 << std::endl;
		std::cout << f2 << std::endl;

		b1.signForm(f1);

		std::cout << f1 << std::endl;

		b1.executeForm(f1);
		//b1.executeForm(f2); // should throw an exception (Form not signed!)
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl << "--------------------------------" << std::endl;
	std::cout << "--------------------------------" << std::endl;
	std::cout << "--------------------------------" << std::endl << std::endl;

	try
	{
		Bureaucrat b2("b2", 5);
		PresidentialPardonForm f3("f3");
		PresidentialPardonForm f4("f4");

		std::cout << b2 << std::endl;
		std::cout << f3 << std::endl;
		std::cout << f4 << std::endl;

		b2.signForm(f3);

		std::cout << f3 << std::endl;
		
		b2.executeForm(f3);
		b2.decrementGrade();
		b2.executeForm(f3);
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	return (0);
}

// int main()
// {
// 	try
// 	{
// 		Bureaucrat b1("b1", 1);
// 		ShrubberyCreationForm f1("f1");
// 		ShrubberyCreationForm f2("f2");

// 		std::cout << b1 << std::endl;
// 		std::cout << f1 << std::endl;
// 		std::cout << f2 << std::endl;

// 		b1.signForm(f1);

// 		std::cout << f1 << std::endl;

// 		b1.executeForm(f1);
// 		//b1.executeForm(f2); // should throw an exception (Form not signed!)
// 	}
// 	catch (std::exception &e)
// 	{
// 		std::cerr << e.what() << std::endl;
// 	}

// 	std::cout << std::endl << "--------------------------------" << std::endl;
// 	std::cout << "--------------------------------" << std::endl;
// 	std::cout << "--------------------------------" << std::endl << std::endl;

// 	try
// 	{
// 		Bureaucrat b2("b2", 137);
// 		ShrubberyCreationForm f3("f3");
// 		ShrubberyCreationForm f4("f4");

// 		std::cout << b2 << std::endl;
// 		std::cout << f3 << std::endl;
// 		std::cout << f4 << std::endl;

// 		b2.signForm(f3);

// 		std::cout << f3 << std::endl;
		
// 		b2.executeForm(f3);
// 		b2.decrementGrade();
// 		b2.executeForm(f3);
// 	}
// 	catch (std::exception &e)
// 	{
// 		std::cerr << e.what() << std::endl;
// 	}
// 	return (0);
// }

// int main()
// {
// 	try
// 	{
// 		Bureaucrat b1("b1", 1);
// 		RobotomyRequestForm f1("f1");
// 		RobotomyRequestForm f2("f2");

// 		std::cout << b1 << std::endl;
// 		std::cout << f1 << std::endl;
// 		std::cout << f2 << std::endl;

// 		b1.signForm(f1);

// 		std::cout << f1 << std::endl;

// 		b1.executeForm(f1);
// 		//b1.executeForm(f2); // should throw an exception (Form not signed!)
// 	}
// 	catch (std::exception &e)
// 	{
// 		std::cerr << e.what() << std::endl;
// 	}

// 	std::cout << std::endl << "--------------------------------" << std::endl;
// 	std::cout << "--------------------------------" << std::endl;
// 	std::cout << "--------------------------------" << std::endl << std::endl;

// 	try
// 	{
// 		Bureaucrat b2("b2", 45);
// 		RobotomyRequestForm f3("f3");
// 		RobotomyRequestForm f4("f4");

// 		std::cout << b2 << std::endl;
// 		std::cout << f3 << std::endl;
// 		std::cout << f4 << std::endl;

// 		b2.signForm(f3);

// 		std::cout << f3 << std::endl;
		
// 		b2.executeForm(f3);
// 		b2.decrementGrade();
// 		b2.executeForm(f3);
// 	}
// 	catch (std::exception &e)
// 	{
// 		std::cerr << e.what() << std::endl;
// 	}
// 	return (0);
// }
