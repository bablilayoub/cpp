/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abablil <abablil@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 17:07:39 by abablil           #+#    #+#             */
/*   Updated: 2024/12/13 19:12:52 by abablil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

void merge(std::vector<int> &numbers, int left, int mid, int right)
{
	int n1 = mid - left + 1;
	int n2 = right - mid;

	std::vector<int> L(n1);
	std::vector<int> R(n2);

	for (int i = 0; i < n1; ++i)
		L[i] = numbers[left + i];
	for (int j = 0; j < n2; ++j)
		R[j] = numbers[mid + 1 + j];

	int i = 0;
	int j = 0;
	int k = left;
	while (i < n1 && j < n2)
	{
		if (L[i] <= R[j])
		{
			numbers[k] = L[i];
			++i;
		}
		else
		{
			numbers[k] = R[j];
			++j;
		}
		++k; 
	}

	while (i < n1)
	{
		numbers[k] = L[i];
		++i;
		++k;
	}

	while (j < n2)
	{
		numbers[k] = R[j];
		++j;
		++k;
	}
}

void mergeSort(std::vector<int> &numbers, int left, int right)
{
	if (left < right)
	{
		int mid = left + (right - left) / 2;
		// Sort first and second halves
		mergeSort(numbers, left, mid);
		mergeSort(numbers, mid + 1, right);

		// Merge the sorted halves
		merge(numbers, left, mid, right);
	}
}

int main(int ac, char **args)
{
	if (ac <= 2)
	{
		std::cout << "Usage : ./PmergeMe 2 1" << std::endl;
		return 1;
	}
	try
	{
		PmergeMe app;
		std::vector<std::pair<int, int> > numbers;
		std::vector<int> biggerNumbers;
		bool isEven = (ac % 2 != 0);
		std::string oddNumber;

		for (int i = 1; i < ac; i += 2)
		{
			if (isEven && (!app.isValidNumber(args[i]) || !app.isValidNumber(args[i + 1])))
				throw std::runtime_error("Invalid number");
			else if (args[i] && !args[i + 1])
			{
				if (!app.isValidNumber(args[i]))
					throw std::runtime_error("Invalid number");
				oddNumber = args[i];
			}
			else
			{
				int first = std::atoi(args[i]);
				int second = std::atoi(args[i + 1]);
				if (first < second)
				{
					numbers.push_back(std::make_pair(first, second));
					biggerNumbers.push_back(second);
				}
				else
				{
					numbers.push_back(std::make_pair(second, first));
					biggerNumbers.push_back(first);
				}
			}
		}

		// for (size_t i = 0; i < biggerNumbers.size(); i++)
		// 	std::cout << "(" << biggerNumbers[i] << ")" << std::endl;
		mergeSort(biggerNumbers, 0, biggerNumbers.size() - 1);
		// std::cout << "\n\n";
		// Print the pairs to verify
		// for (size_t i = 0; i < numbers.size(); i++)
		// 	std::cout << "Pair: (" << numbers[i].first << ", " << numbers[i].second << ")" << std::endl;
		// std::cout << "Bigger numbers :" << std::endl;
		// for (size_t i = 0; i < biggerNumbers.size(); i++)
		// 	std::cout << "(" << biggerNumbers[i] << ")" << std::endl;
		// if (!oddNumber.empty())
		// 	std::cout << "Odd Number: (" << oddNumber << ")" << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	return 0;
}