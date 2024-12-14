/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abablil <abablil@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 16:53:46 by abablil           #+#    #+#             */
/*   Updated: 2024/12/14 17:55:39 by abablil          ###   ########.fr       */
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
    void print(int ac, char **args, Container &container);

	template <typename Container>
    void startSorting(Container &biggerNumbers, Container &lowerNumbers, const std::string &oddNumber);

	template <typename Container>
    void initializeContainers(int ac, char **args, Container &biggerNumbers, Container &lowerNumbers, std::string &oddNumber);

	clock_t runVector(int ac, char **args, bool &printed);
	clock_t runDeque(int ac, char **args, bool &printed);
public:
	PmergeMe();
	~PmergeMe();
	PmergeMe(const PmergeMe &obj);
	PmergeMe &operator=(const PmergeMe &obj);
	void run(int ac, char **args);
};