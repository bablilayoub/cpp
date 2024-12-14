/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abablil <abablil@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 17:02:55 by abablil           #+#    #+#             */
/*   Updated: 2024/12/14 17:56:07 by abablil          ###   ########.fr       */
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

template <typename Container>
void PmergeMe::merge(Container &numbers, int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    Container L(n1);
    Container R(n2);

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

template <typename Container>
void PmergeMe::mergeSort(Container &numbers, int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;
        this->mergeSort(numbers, left, mid);
        this->mergeSort(numbers, mid + 1, right);

        this->merge(numbers, left, mid, right);
    }
}

template <typename Container>
void PmergeMe::print(int ac, char **args, Container &container)
{
    std::cout << "Before: ";
    for (int i = 1; i < ac; i++)
        std::cout << args[i] << " ";
    std::cout << std::endl;
    std::cout << "After: ";
    for (size_t i = 0; i < container.size(); i++)
        std::cout << container[i] << " ";
    std::cout << std::endl;
}

template <typename Container>
void PmergeMe::startSorting(Container &biggerNumbers, Container &lowerNumbers, const std::string &oddNumber)
{
    this->mergeSort(biggerNumbers, 0, biggerNumbers.size() - 1);
    for (size_t i = 0; i < lowerNumbers.size(); i++)
    {
        typename Container::iterator pos = std::lower_bound(biggerNumbers.begin(), biggerNumbers.end(), lowerNumbers[i]);
        biggerNumbers.insert(pos, lowerNumbers[i]);
    }
    if (!oddNumber.empty())
    {
        int oddNum = std::atoi(oddNumber.c_str());
        typename Container::iterator pos = std::lower_bound(biggerNumbers.begin(), biggerNumbers.end(), oddNum);
        biggerNumbers.insert(pos, oddNum);
    }
}

template <typename Container>
void PmergeMe::initializeContainers(int ac, char **args, Container &biggerNumbers, Container &lowerNumbers, std::string &oddNumber)
{
    bool isEven = (ac % 2 != 0);

    for (int i = 1; i < ac; i += 2)
    {
        if (isEven && (!this->isValidNumber(args[i]) || !this->isValidNumber(args[i + 1])))
            throw std::runtime_error("Invalid number");
        else if (args[i] && !args[i + 1])
        {
            if (!this->isValidNumber(args[i]))
                throw std::runtime_error("Invalid number");
            oddNumber = args[i];
        }
        else
        {
            int first = std::atoi(args[i]);
            int second = std::atoi(args[i + 1]);
            if (first < second)
            {
                lowerNumbers.push_back(first);
                biggerNumbers.push_back(second);
            }
            else
            {
                lowerNumbers.push_back(second);
                biggerNumbers.push_back(first);
            }
        }
    }
}

clock_t PmergeMe::runVector(int ac, char **args, bool &printed)
{
    std::vector<int> biggerNumbers;
    std::vector<int> lowerNumbers;
    std::string oddNumber;

    initializeContainers(ac, args, biggerNumbers, lowerNumbers, oddNumber);

    clock_t time = clock();
    this->startSorting(biggerNumbers, lowerNumbers, oddNumber);
    if (!printed)
    {
        this->print(ac, args, biggerNumbers);
        printed = true;
    }
    return clock() - time;
}

clock_t PmergeMe::runDeque(int ac, char **args, bool &printed)
{
    std::deque<int> biggerNumbers;
    std::deque<int> lowerNumbers;
    std::string oddNumber;

    initializeContainers(ac, args, biggerNumbers, lowerNumbers, oddNumber);

    clock_t time = clock();
    this->startSorting(biggerNumbers, lowerNumbers, oddNumber);
    if (!printed)
    {
        this->print(ac, args, biggerNumbers);
        printed = true;
    }
    return clock() - time;
}

void PmergeMe::run(int ac, char **args)
{
    bool printed = false;
    clock_t a = this->runVector(ac, args, printed);
    clock_t b = this->runDeque(ac, args, printed);

    std::cout << "Time to process a range of " << ac - 1 << " elements with std::vector : " << a << "ms" << std::endl;
    std::cout << "Time to process a range of " << ac - 1 << " elements with std::deque : " << b << "ms" << std::endl;
}