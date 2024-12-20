/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abablil <abablil@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 15:57:43 by abablil           #+#    #+#             */
/*   Updated: 2024/12/15 15:58:13 by abablil          ###   ########.fr       */
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
	std::map<std::string, double>::const_iterator it;
	std::map<std::string, double>::const_iterator prev = database.end();

	for (it = database.begin(); it != database.end(); ++it)
	{
		if (it->first == date)
			return it->second;
		if (it->first > date)
			break;
		prev = it;
	}

	if (prev != database.end())
		return prev->second;
	return -1;
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
		if ((isLeapYear(year) && day > 29) || (!isLeapYear(year) && day > 28))
			return false;

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
			if (seenDot || lastNumberIndex == 0)
			{
				std::cout << "Error: invalid value." << std::endl;
				return false;
			}
			dotIndex = i;
			seenDot = true;
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

std::string BitcoinExchange::formatRate(double result)
{
	std::string newValue = std::to_string(result);
	int i = newValue.size() - 1;
	while (newValue[i] == '0')
		i--;
	if (newValue[i] == '.')
		i--;
	return newValue.substr(0, i + 1);
}

void BitcoinExchange::parseLine(const std::string &line)
{
	if (line.size() == 0)
	{
		std::cout << "Line can't be empty" << std::endl;
		return;
	}

	std::size_t pipePos = line.find('|');
	if (pipePos == std::string::npos)
	{
		std::cout << "Error: bad input => " << line << std::endl;
		return;
	}

	std::string date = line.substr(0, line.find('|'));
	if (!this->isValidDate(date))
	{
		std::cout << "Error: bad input => " << date << std::endl;
		return;
	}

	std::string rateStr = line.substr(line.find('|') + 1);
	if (!this->isValidRate(rateStr))
		return;

	double value = atof(rateStr.c_str());
	double rate = getExchangeRate(date);
	if (rate == -1)
	{
		std::cerr << "Error: no exchange rate found for date " << date << std::endl;
		return;
	}
	std::cout << date << " => " << value << " = " << this->formatRate(value * rate) << std::endl;
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
	if (line.size() == 0 || line != "date | value")
	{
		file.close();
		throw std::runtime_error("Error: Invalid file format.");
	}
	while (std::getline(file, line))
		parseLine(line);
	file.close();
}