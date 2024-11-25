/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abablil <abablil@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 18:12:31 by abablil           #+#    #+#             */
/*   Updated: 2024/11/25 18:21:07 by abablil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

int main()
{
	Intern intern;
	Bureaucrat bureaucrat("bureaucrat", 1);

	AForm *form1 = intern.makeForm("shrubbery creation", "target1");
	AForm *form2 = intern.makeForm("robotomy request", "target2");
	AForm *form3 = intern.makeForm("presidential pardon", "target3");
	AForm *form4 = intern.makeForm("unknown form", "target4");

	bureaucrat.signForm(*form1);
	bureaucrat.executeForm(*form1);

	bureaucrat.signForm(*form2);
	bureaucrat.executeForm(*form2);

	bureaucrat.signForm(*form3);
	bureaucrat.executeForm(*form3);

	delete form1;
	delete form2;
	delete form3;
	
	return 0;
}