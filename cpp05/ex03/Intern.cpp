/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abablil <abablil@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 18:15:07 by abablil           #+#    #+#             */
/*   Updated: 2024/11/19 18:20:58 by abablil          ###   ########.fr       */
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

AForm *Intern::createShrubberyCreationForm(std::string target)
{
	return new ShrubberyCreationForm(target);
}

AForm *Intern::createRobotomyRequestForm(std::string target)
{
	return new RobotomyRequestForm(target);
}

AForm *Intern::createPresidentialPardonForm(std::string target)
{
	return new PresidentialPardonForm(target);
}

AForm *Intern::makeForm(std::string name, std::string target)
{
	if (name.empty() || target.empty())
	{
		std::cerr << "Error: empty form name or target" << std::endl;
		return NULL;
	}

	std::string forms[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};

	FormHandler handlers[3] = {
		&Intern::createShrubberyCreationForm,
		&Intern::createRobotomyRequestForm,
		&Intern::createPresidentialPardonForm
	};

	AForm *form = NULL;

	for (int i = 0; i < 3; i++)
	{
		if (name == forms[i])
		{
			form = (this->*handlers[i])(target);
			std::cout << "Intern creates " << form->getName() << std::endl;
			return form;
		}
	}
	std::cerr << "Error: form name not found" << std::endl;
	return NULL;
}