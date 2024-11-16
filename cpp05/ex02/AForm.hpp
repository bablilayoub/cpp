/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                           :+:      :+:    :+:   */
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
class AForm
{
private:
	const std::string name;
	bool isSigned;
	const int gradeToSign;
	const int gradeToExecute;

public:
	AForm();
	~AForm();
	AForm(const AForm &obj);
	AForm &operator=(const AForm &obj);
	AForm(const std::string &name, int gradeToSign, int gradeToExecute);

	std::string const &getName() const;
	bool const &getIsSigned() const;
	int const &getGradeToSign() const;
	int const &getGradeToExecute() const;

	void beSigned(Bureaucrat &obj);

	virtual void execute(Bureaucrat const &executor) const = 0;

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

std::ostream &operator<<(std::ostream &os, const AForm &obj);
