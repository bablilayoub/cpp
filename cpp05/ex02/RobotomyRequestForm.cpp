/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abablil <abablil@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 23:19:22 by abablil           #+#    #+#             */
/*   Updated: 2024/11/19 15:57:29 by abablil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45), target("default") {}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm(target, 72, 45), target(target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &obj) : AForm(obj), target(obj.target) {}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &obj)
{
	if (this != &obj)
		AForm::operator=(obj);
	return (*this);
}

const char *RobotomyRequestForm::FormNotSignedException::what() const throw()
{
	return "Form not signed!";
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	if (!this->getIsSigned())
		throw FormNotSignedException();
	if (executor.getGrade() > this->getGradeToExecute())
		throw Bureaucrat::GradeTooLowException();

	std::cout << "We drilling baby!, BRRRRRR" << std::endl;
	
	std::srand(std::time(NULL));
	if (std::rand() % 2 == 0)
		std::cout << "Robotomized " << target << std::endl;
	else
		std::cout << "Failed to robotomize " << target << std::endl;
}
