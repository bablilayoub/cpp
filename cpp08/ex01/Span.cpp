/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abablil <abablil@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 20:46:52 by abablil           #+#    #+#             */
/*   Updated: 2024/12/10 16:41:58 by abablil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span() : N(0) {}

Span::Span(const Span &obj) : N(obj.N), numbers(obj.numbers) {}

Span::~Span() {}

Span::Span(unsigned int N) : N(N) {}

Span &Span::operator=(const Span &obj)
{
	if (this != &obj)
	{
		this->N = obj.N;
		this->numbers = obj.numbers;
	}
	return *this;
}

void Span::addNumber(int number)
{
	if (this->numbers.size() >= this->N)
		throw std::overflow_error("Span is full");
	this->numbers.push_back(number);
}

int Span::shortestSpan()
{
	if (this->numbers.size() <= 1)
		throw std::logic_error("Not enough numbers to find a span");
	std::vector<int> sortedNumbers = this->numbers;
	std::sort(sortedNumbers.begin(), sortedNumbers.end());
	int lowest = sortedNumbers[1] - sortedNumbers[0];
	for (size_t i = 1; i < sortedNumbers.size() - 1; i++)
	{
		int span = sortedNumbers[i + 1] - sortedNumbers[i];
		if (span < lowest)
			lowest = span;
	}
	return lowest;
}

int Span::longestSpan()
{
	if (this->numbers.size() <= 1)
		throw std::logic_error("Not enough numbers to find a span");
	std::vector<int> sortedNumbers = this->numbers;
	std::sort(sortedNumbers.begin(), sortedNumbers.end());
	return sortedNumbers.back() - sortedNumbers.front();
}

void Span::addRange(vec_iter begin, vec_iter end)
{
	size_t distance = std::distance(begin, end);

	if (this->numbers.size() + distance > this->N)
		throw std::overflow_error("Adding range would exceed the span limit");

	this->numbers.insert(this->numbers.end(), begin, end);
}