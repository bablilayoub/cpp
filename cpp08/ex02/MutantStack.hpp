/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abablil <abablil@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 16:54:57 by abablil           #+#    #+#             */
/*   Updated: 2024/12/10 21:43:28 by abablil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <algorithm>
#include <stack>

template <typename T>
class MutantStack : public std::stack<T>
{
public:
	typedef typename std::stack<T>::container_type::iterator iterator;
	typedef typename std::stack<T>::container_type::const_iterator const_iterator;

	MutantStack() : std::stack<T>() {}
	MutantStack(const MutantStack<T> &other) : std::stack<T>(other) {}
	MutantStack &operator=(const MutantStack<T> &other)
	{
		if (this != &other)
			std::stack<T>::operator=(other);
		return *this;
	}
	~MutantStack() {}

	iterator begin() { return this->c.begin(); }
	iterator end() { return this->c.end(); }
	const_iterator begin() const { return this->c.begin(); }
	const_iterator end() const { return this->c.end(); }
};
