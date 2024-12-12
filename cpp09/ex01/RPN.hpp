/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abablil <abablil@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 22:59:06 by abablil           #+#    #+#             */
/*   Updated: 2024/12/12 21:19:36 by abablil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <stack>
#include <sstream>
#include <stdexcept>

class RPN
{
private:
	std::stack<int> numbers;
	bool isNumber(const std::string &value);
	bool isOperation(const std::string &value);
	void process(const std::string &value);
	
public:
	RPN();
	RPN(const std::string &value);
	~RPN();
	RPN(const RPN &obj);
	RPN &operator=(const RPN &obj);
};
