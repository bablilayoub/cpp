/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abablil <abablil@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 15:57:43 by abablil           #+#    #+#             */
/*   Updated: 2024/12/15 15:58:22 by abablil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <stdexcept>
#include <algorithm>
#include <map>
#include <fstream>
#include <sstream>
#include <iomanip>

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
	std::string formatRate(double result);
	
public:
	BitcoinExchange();
	BitcoinExchange(const std::string &dbFile);
	~BitcoinExchange();
	BitcoinExchange(const BitcoinExchange &obj);
	BitcoinExchange &operator=(const BitcoinExchange &obj);
};
