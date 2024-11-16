/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abablil <abablil@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 15:14:05 by abablil           #+#    #+#             */
/*   Updated: 2024/11/16 22:07:44 by abablil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Bureaucrat.hpp"

class Bureaucrat;
class Form
{
private:
	const std::string name;
	bool isSigned;
	const int gradeToSign;
	const int gradeToExecute;

public:
	Form();
	~Form();
	Form(const Form &obj);
	Form &operator=(const Form &obj);
	Form(const std::string &name, int gradeToSign, int gradeToExecute);

	std::string const &getName() const;
	bool const &getIsSigned() const;
	int const &getGradeToSign() const;
	int const &getGradeToExecute() const;

	void beSigned(Bureaucrat &obj);

	class GradeTooHighException : public std::exception
	{
	public:
		const char *what() const throw();
	};
	class GradeTooLowException : public std::exception
	{
	public:
		const char *what() const throw();
	};
};

std::ostream &operator<<(std::ostream &os, const Form &obj);
