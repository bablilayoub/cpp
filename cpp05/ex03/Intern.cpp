/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abablil <abablil@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 18:15:07 by abablil           #+#    #+#             */
/*   Updated: 2024/11/18 20:51:41 by abablil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern() {}

Intern::Intern(const Intern &obj) { *this = obj; }

Intern::~Intern() {}

Intern &Intern::operator=(const Intern &obj)
{
	(void)obj;
	return *this;
}

AForm *Intern::makeForm(std::string name, std::string target)
{
	if (name.empty() || target.empty())
	{
		std::cerr << "Error: empty form name or target" << std::endl;
		return NULL;
	}

	std::string forms[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	AForm *form = NULL;

	for (int i = 0; i < 3; i++)
	{
		if (name == forms[i])
		{
			switch (i)
			{
			case 0:
				form = new ShrubberyCreationForm(target);
				break;
			case 1:
				form = new RobotomyRequestForm(target);
				break;
			case 2:
				form = new PresidentialPardonForm(target);
				break;
			}
			std::cout << "Intern creates " << form->getName() << std::endl;
			return form;
		}
	}
	std::cerr << "Error: form name not found" << std::endl;
	return NULL;
}