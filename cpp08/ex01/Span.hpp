/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abablil <abablil@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 20:42:58 by abablil           #+#    #+#             */
/*   Updated: 2024/12/10 16:43:29 by abablil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <stdexcept>
#include <algorithm>
#include <vector>

typedef std::vector<int>::iterator vec_iter;

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
	void addRange(vec_iter begin, vec_iter end);
};

