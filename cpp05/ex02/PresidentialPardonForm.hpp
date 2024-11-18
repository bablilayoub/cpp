/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abablil <abablil@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 22:27:01 by abablil           #+#    #+#             */
/*   Updated: 2024/11/18 17:13:56 by abablil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
private:
	std::string target;
public:
	PresidentialPardonForm();
	~PresidentialPardonForm();
	PresidentialPardonForm(std::string target);
	PresidentialPardonForm(const PresidentialPardonForm &obj);
	PresidentialPardonForm &operator=(const PresidentialPardonForm &obj);
	
	void execute(Bureaucrat const &executor) const;

	class FormNotSignedException : public std::exception
	{
	public:
		const char *what() const throw();
	};
};
