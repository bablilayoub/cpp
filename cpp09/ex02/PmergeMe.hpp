/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abablil <abablil@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 16:53:46 by abablil           #+#    #+#             */
/*   Updated: 2024/12/13 17:29:48 by abablil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <vector>
#include <deque>
#include <stdexcept>

class PmergeMe
{
public:
	PmergeMe();
	~PmergeMe();
	PmergeMe(const PmergeMe &obj);
	PmergeMe &operator=(const PmergeMe &obj);
	bool isValidNumber(const char *number);
};