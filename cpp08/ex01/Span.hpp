/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abablil <abablil@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 20:42:58 by abablil           #+#    #+#             */
/*   Updated: 2024/12/09 21:53:04 by abablil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <stdexcept>
#include <algorithm>
#include <vector>

class Span
{
private:
	unsigned int N;
	std::vector<int> numbers;

public:
	Span();
	~Span();
	Span(const Span &obj);
	Span(unsigned int N);
	Span &operator=(const Span &obj);
	void addNumber(int number);
	int shortestSpan();
	int longestSpan();
	template <typename InputIt>
	void addRange(InputIt first, InputIt last);
};

