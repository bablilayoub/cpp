/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abablil <abablil@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 18:07:48 by abablil           #+#    #+#             */
/*   Updated: 2024/11/19 18:15:37 by abablil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern
{
public:
	Intern();
	Intern(const Intern &obj);
	~Intern();
	Intern &operator=(const Intern &obj);
	AForm *makeForm(std::string name, std::string target);
	
	AForm *createShrubberyCreationForm(std::string target);
	AForm *createRobotomyRequestForm(std::string target);
	AForm *createPresidentialPardonForm(std::string target);
};

typedef AForm *(Intern::*FormHandler)(std::string target);