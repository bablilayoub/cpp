/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abablil <abablil@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 15:41:34 by abablil           #+#    #+#             */
/*   Updated: 2024/11/16 22:07:41 by abablil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm() : name("default"), isSigned(false), gradeToSign(1), gradeToExecute(1) {}

AForm::AForm(const AForm &obj) : name(obj.name), gradeToSign(obj.gradeToSign), gradeToExecute(obj.gradeToExecute) { *this = obj; }

AForm::~AForm() {}

AForm &AForm::operator=(const AForm &obj)
{
	if (this != &obj)
		this->isSigned = obj.isSigned;
	return *this;
}

AForm::AForm(const std::string &name, int gradeToSign, int gradeToExecute) : name(name), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute)
{
	if (gradeToSign > 150 || gradeToExecute > 150)
		throw GradeTooLowException();
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw GradeTooHighException();
	this->isSigned = false;
}

const char *AForm::GradeTooHighException::what() const throw()
{
	return "Grade too high!";
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return "Grade too low!";
}

std::string const &AForm::getName() const { return this->name; }

bool const &AForm::getIsSigned() const { return this->isSigned; }

int const &AForm::getGradeToSign() const { return this->gradeToSign; }

int const &AForm::getGradeToExecute() const { return this->gradeToExecute; }

void AForm::beSigned(Bureaucrat &obj)
{
	if (this->getGradeToSign() >= obj.getGrade())
		this->isSigned = true;
	else
		throw GradeTooLowException();
}

std::ostream &operator<<(std::ostream &os, const AForm &obj)
{
	os << "============ AForm info ==============" << std::endl;
	os << "Name: " << obj.getName() << std::endl;
	os << "Is signed: " << obj.getIsSigned() << std::endl;
	os << "Grade to sign: " << obj.getGradeToSign() << std::endl;
	os << "Grade to execute: " << obj.getGradeToSign() << std::endl;
	os << "=====================================" << std::endl;
	return os;
}