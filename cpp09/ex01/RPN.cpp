/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abablil <abablil@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 20:52:36 by abablil           #+#    #+#             */
/*   Updated: 2024/12/12 21:20:28 by abablil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN() {}

RPN::~RPN() {}

RPN::RPN(const std::string &value)
{
	std::stringstream buffer(value);
	std::string word;
	size_t result = 0;

	while (buffer >> word)
	{
		if (!this->isNumber(word) && !this->isOperation(word))
			throw std::logic_error("Error");
		if (this->isOperation(word) && numbers.size() < 2)
			throw std::logic_error("Error");
		if (this->isNumber(word))
			numbers.push(static_cast<int>(std::atof(word.c_str())));
		if (this->isOperation(word))
			this->process(word);
	}
	if (numbers.size() > 1)
		throw std::logic_error("Error");
	result = numbers.top();
	std::cout << result << std::endl;
}

void RPN::process(const std::string &operation)
{
	size_t first;
	size_t second;
	char op = operation[0];

	second = numbers.top();
	numbers.pop();
	first = numbers.top();
	numbers.pop();

	if (op == '+')
		numbers.push(first + second);
	else if (op == '-')
		numbers.push(first - second);
	else if (op == '/')
		numbers.push(first / second);
	else if (op == '*')
		numbers.push(first * second);
}

RPN::RPN(const RPN &obj) { *this = obj; }

RPN &RPN::operator=(const RPN &obj)
{
	if (this != &obj)
		this->numbers = obj.numbers;
	return *this;
}

bool RPN::isNumber(const std::string &value)
{
	if (value.size() == 1 && std::isdigit(value[0]))
		return true;
	return false;
}

bool RPN::isOperation(const std::string &value)
{
	if (value.size() != 1)
		return false;
	if (value[0] != '+' && value[0] != '-' && value[0] != '/' && value[0] != '*')
		return false;
	return true;
}