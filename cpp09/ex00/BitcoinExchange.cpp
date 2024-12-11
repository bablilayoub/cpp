/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abablil <abablil@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 15:57:43 by abablil           #+#    #+#             */
/*   Updated: 2024/12/11 22:56:03 by abablil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &obj) { *this = obj; }

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &obj)
{
	if (this != &obj)
		this->database = obj.database;
	return *this;
}

BitcoinExchange::BitcoinExchange(const std::string &dbFile)
{
	this->loadDatabase();
	this->startProcessing(dbFile);
}

double BitcoinExchange::getExchangeRate(const std::string &date) const
{
	std::map<std::string, double>::const_iterator it = database.lower_bound(date);
	if (it != database.begin())
		--it;
	return it->second;
}

bool BitcoinExchange::isLeapYear(int year)
{
	return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

bool BitcoinExchange::isValidDate(const std::string &date)
{
	if (date.length() != 11 || date[4] != '-' || date[7] != '-' || date[10] != ' ')
		return false;
	int year = std::atoi(date.substr(0, 4).c_str());
	int month = std::atoi(date.substr(5, 2).c_str());
	int day = std::atoi(date.substr(8, 2).c_str());
	if (year < 0 || month < 1 || month > 12 || day < 1 || day > 31)
		return false;
	if (month == 2)
	{
		if (isLeapYear(year) && day > 29)
			return false;
		if (!isLeapYear(year) && day > 28)
			return false;
	}
	if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)
		return false;
	return true;
}

void BitcoinExchange::loadDatabase()
{
	std::ifstream file("data.csv");

	if (!file.is_open())
		throw std::runtime_error("Error: could not open database file.");

	std::string line;
	std::getline(file, line);
	while (std::getline(file, line))
	{
		std::string key = line.substr(0, line.find(','));
		double value = std::atof(line.substr(line.find(',') + 1).c_str());
		database[key] = value;
	}
	file.close();
}

bool BitcoinExchange::isValidRate(const std::string &rate)
{
	if (rate.empty() || rate[0] != ' ' || (rate.size() == 1 && rate[0] == ' '))
	{
		std::cout << "Error: invalid value." << std::endl;
		return false;
	}

	bool seenDot = false;
	size_t lastNumberIndex = 0;
	size_t dotIndex = 0;

	for (size_t i = 1; i < rate.size(); ++i)
	{
		if (rate[i] == '.')
		{
			if (seenDot)
			{
				std::cout << "Error: invalid value." << std::endl;
				return false;
			}
			dotIndex = i;
			seenDot = true;
			if (lastNumberIndex == 0)
			{
				std::cout << "Error: invalid value." << std::endl;
				return false;
			}
		}
		else if (!std::isdigit(rate[i]))
		{
			std::cout << "Error: invalid value." << std::endl;
			return false;
		}
		else
			lastNumberIndex = i;
	}

	if (dotIndex > lastNumberIndex)
	{
		std::cout << "Error: invalid value." << std::endl;
		return false;
	}

	double rateDouble = std::atof(rate.c_str());
	if (rateDouble > 1000)
	{
		std::cout << "Error: number is too large." << std::endl;
		return false;
	}
	if (rateDouble < 0)
	{
		std::cout << "Error: not a positive number." << std::endl;
		return false;
	}
	return true;
}

void BitcoinExchange::startProcessing(const std::string &dbFile)
{
	if (dbFile.empty())
		throw std::runtime_error("Error: database path can't be empty");

	std::ifstream file(dbFile);

	if (!file.is_open())
		throw std::runtime_error("Error: could not open database file.");

	std::string line;

	std::getline(file, line);
	if (line.size() == 0)
	{
		file.close();
		throw std::runtime_error("Error: Invalid file format.");
	}
	if (line != "date | value")
	{
		file.close();
		throw std::runtime_error("Error: Invalid input.");
	}
	while (std::getline(file, line))
	{
		std::size_t dotPos = line.find('|');
		if (dotPos == std::string::npos)
		{
			std::cout << "Error: invalid input." << std::endl;
			continue;
		}

		std::string date = line.substr(0, line.find('|'));

		if (!this->isValidDate(date))
		{
			std::cout << "Error: bad input => " << date << std::endl;
			continue;
		}

		std::string rateStr = line.substr(line.find('|') + 1);

		if (!this->isValidRate(rateStr))
			continue;

		double value = atof(rateStr.c_str());
		double rate = getExchangeRate(date);
		std::string newValue = std::to_string(value * rate);
		int i = newValue.size() - 1;
		while (newValue[i] == '0')
			i--;
		if (newValue[i] == '.')
			i--;
		std::cout << date << " => " << value << " = " << newValue.substr(0, i + 1) << std::endl;
	}
	file.close();
}