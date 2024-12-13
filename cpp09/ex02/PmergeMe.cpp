/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abablil <abablil@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 17:02:55 by abablil           #+#    #+#             */
/*   Updated: 2024/12/13 17:29:52 by abablil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::~PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe &obj) { *this = obj; }

PmergeMe &PmergeMe::operator=(const PmergeMe &obj)
{
	(void)obj;
	return *this;
}

bool PmergeMe::isValidNumber(const char *number)
{
	std::string newNumber = number;
	if (newNumber.empty())
		return false;
	for (size_t i = 0; i < newNumber.size(); i++)
	{
		if (!std::isdigit(newNumber[i]))
			return false;
	}
	return true;
}