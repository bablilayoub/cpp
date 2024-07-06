/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abablil <abablil@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 12:12:26 by abablil           #+#    #+#             */
/*   Updated: 2024/07/06 14:18:18 by abablil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <iomanip>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit)
{
	this->_accountIndex = Account::_nbAccounts++;
	this->_amount = initial_deposit;
	Account::_totalAmount += initial_deposit;
	this->_nbWithdrawals = 0;
	this->_nbDeposits = 0;
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount << ";created" << std::endl;
}

Account::~Account(void)
{
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount << ";closed" << std::endl;
	Account::_nbAccounts--;
}

void Account::_displayTimestamp()
{
	time_t current_time = time(NULL);
	tm *time_struct = localtime(&current_time);
	std::cout
		<< std::setfill('0')
		<< "["
		<< time_struct->tm_year + 1900
		<< std::setw(2)
		<< time_struct->tm_mon + 1
		<< std::setw(2)
		<< time_struct->tm_mday
		<< "_"
		<< std::setw(2)
		<< time_struct->tm_hour
		<< std::setw(2)
		<< time_struct->tm_min
		<< std::setw(2)
		<< time_struct->tm_sec
		<< "] ";
}

int Account::getNbAccounts(void)
{
	return _nbAccounts;
}

int Account::getTotalAmount(void)
{
	return _totalAmount;
}

int Account::getNbDeposits(void)
{
	return _totalNbDeposits;
}

int Account::getNbWithdrawals(void)
{
	return _totalNbWithdrawals;
}

void Account::displayAccountsInfos(void)
{
	Account::_displayTimestamp();
	std::cout
		<< "accounts:"
		<< Account::_nbAccounts
		<< ";total:"
		<< Account::_totalAmount
		<< ";deposits:"
		<< Account::_totalNbDeposits
		<< ";withdrawals:"
		<< Account::_totalNbWithdrawals
		<< std::endl;
}

void Account::makeDeposit(int deposit)
{
	this->_nbDeposits++;
	Account::_totalNbDeposits++;
	this->_amount += deposit;
	Account::_totalAmount += deposit;
	Account::_displayTimestamp();
	std::cout
		<< "index:"
		<< this->_accountIndex
		<< ";p_amount:"
		<< this->_amount - deposit
		<< ";deposit:"
		<< deposit
		<< ";amount:"
		<< this->_amount
		<< ";nb_deposits:"
		<< this->_nbDeposits
		<< std::endl;
}

bool Account::makeWithdrawal(int withdrawal)
{
	// index:0;p_amount:47;withdrawal:refused
	// index:1;p_amount:819;withdrawal:34;amount:785;nb_withdrawals:1

	Account::_displayTimestamp();
	std::cout
		<< "index:"
		<< this->_accountIndex
		<< ";p_amount:"
		<< this->_amount
		<< ";withdrawal:";
	if (withdrawal > this->_amount)
	{
		std::cout << "refused" << std::endl;
		return false;
	}
	this->_nbWithdrawals++;
	this->_amount -= withdrawal;
	Account::_totalNbWithdrawals++;
	Account::_totalAmount -= withdrawal;
	std::cout
		<< withdrawal
		<< ";amount:"
		<< this->_amount
		<< ";nb_withdrawals:"
		<< this->_nbWithdrawals
		<< std::endl;
	return true;
}

int Account::checkAmount(void) const
{
	ret
}

void Account::displayStatus(void) const
{
	Account::_displayTimestamp();
	std::cout
		<< "index:"
		<< this->_accountIndex
		<< ";amount:"
		<< this->_amount
		<< ";deposits:"
		<< this->_nbDeposits
		<< ";withdrawals:"
		<< this->_nbWithdrawals
		<< std::endl;
}