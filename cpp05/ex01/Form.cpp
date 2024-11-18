/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abablil <abablil@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 15:41:34 by abablil           #+#    #+#             */
/*   Updated: 2024/11/18 16:51:09 by abablil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : name("default"), isSigned(false), gradeToSign(1), gradeToExecute(1) {}

Form::Form(const Form &obj) : name(obj.name), gradeToSign(obj.gradeToSign), gradeToExecute(obj.gradeToExecute) { *this = obj; }

Form::~Form() {}

Form &Form::operator=(const Form &obj)
{
	if (this != &obj)
		this->isSigned = obj.isSigned;
	return *this;
}

Form::Form(const std::string &name, int gradeToSign, int gradeToExecute) : name(name), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute)
{
	if (gradeToSign > 150 || gradeToExecute > 150)
		throw GradeTooLowException();
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw GradeTooHighException();
	this->isSigned = false;
}

const char *Form::GradeTooHighException::what() const throw()
{
	return "Grade too high!";
}

const char *Form::GradeTooLowException::what() const throw()
{
	return "Grade too low!";
}

std::string const &Form::getName() const { return this->name; }

bool const &Form::getIsSigned() const { return this->isSigned; }

int const &Form::getGradeToSign() const { return this->gradeToSign; }

int const &Form::getGradeToExecute() const { return this->gradeToExecute; }

void Form::beSigned(Bureaucrat &obj)
{
	if (this->getGradeToSign() >= obj.getGrade())
		this->isSigned = true;
	else
		throw GradeTooLowException();
}

std::ostream &operator<<(std::ostream &os, const Form &obj)
{
	os << "============ Form info ==============" << std::endl;
	os << "Name: " << obj.getName() << std::endl;
	os << "Is signed: " << obj.getIsSigned() << std::endl;
	os << "Grade to sign: " << obj.getGradeToSign() << std::endl;
	os << "Grade to execute: " << obj.getGradeToExecute() << std::endl;
	os << "=====================================" << std::endl;
	return os;
}