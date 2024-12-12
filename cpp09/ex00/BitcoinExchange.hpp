/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abablil <abablil@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 15:57:43 by abablil           #+#    #+#             */
/*   Updated: 2024/12/12 23:03:51 by abablil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <stdexcept>
#include <algorithm>
#include <map>
#include <fstream>
#include <sstream>

class BitcoinExchange
{
private:
	std::map<std::string, double> database;
	void startProcessing(const std::string &dbFile);
	void loadDatabase();
	bool isValidDate(const std::string &date);
	bool isValidRate(const std::string &rate);
	double getExchangeRate(const std::string &date) const;
	bool isLeapYear(int year);
	void parseLine(const std::string &line);

public:
	BitcoinExchange();
	BitcoinExchange(const std::string &dbFile);
	~BitcoinExchange();
	BitcoinExchange(const BitcoinExchange &obj);
	BitcoinExchange &operator=(const BitcoinExchange &obj);
};
