/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abablil <abablil@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 16:53:46 by abablil           #+#    #+#             */
/*   Updated: 2024/12/14 17:00:39 by abablil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <vector>
#include <deque>
#include <stdexcept>

class PmergeMe
{
private:
	bool isValidNumber(const char *number);

	template <typename Container>
	void merge(Container &numbers, int left, int mid, int right);

	template <typename Container>
	void mergeSort(Container &numbers, int left, int right);

	template <typename Container>
	void print(int ac, char **args, Container &biggerNumbers, const std::string &name, clock_t time);

	template <typename Container>
	void startSorting(Container &biggerNumbers, Container &lowerNumbers, const std::string &oddNumber);

	template <typename Container>
	void initializeContainers(int ac, char **args, Container &biggerNumbers, Container &lowerNumbers, std::string &oddNumber);

public:
	PmergeMe();
	~PmergeMe();
	PmergeMe(const PmergeMe &obj);
	PmergeMe &operator=(const PmergeMe &obj);
	void runVector(int ac, char **args);
	void runDeque(int ac, char **args);
};