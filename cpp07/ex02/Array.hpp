/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abablil <abablil@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 22:51:51 by abablil           #+#    #+#             */
/*   Updated: 2024/12/07 23:12:35 by abablil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <stdexcept>

template <typename T>
class Array
{
private:
	T *elements;
	unsigned int n;

public:
	Array() : elements(nullptr), n(0) {}

	Array(unsigned int n) : elements(new T[n]), n(n) {}

	Array(const Array &obj) : elements(new T[obj.n]), n(obj.n)
	{
		for (unsigned int i = 0; i < n; ++i)
			this->elements[i] = obj.elements[i];
	}

	Array &operator=(const Array &other)
	{
		if (this != &other)
		{
			delete[] this->elements;
			n = other.n;
			this->elements = new T[n];
			for (unsigned int i = 0; i < n; ++i)
				this->elements[i] = other.elements[i];
		}
		return *this;
	}

	~Array() { delete[] this->elements; }

	T &operator[](unsigned int index)
	{
		if (index >= n)
			throw std::out_of_range("Index out of bounds");
		return this->elements[index];
	}

	unsigned int size() const { return n; }
};