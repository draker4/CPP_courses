/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperriol <bperriol@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 10:39:26 by bperriol          #+#    #+#             */
/*   Updated: 2023/02/07 11:39:21 by bperriol         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <ctime>
#include <iomanip>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit) : _amount(initial_deposit)
{
	_displayTimestamp();
	_accountIndex = _nbAccounts++;
	_totalAmount += _amount;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
	std::cout << "index:" << _accountIndex << ";" << std::flush;
	std::cout << "amount:" << _amount << ";" << std::flush;
	std::cout << "created" << std::endl;
}

Account::~Account()
{
	_displayTimestamp();
	_nbAccounts--;
	std::cout << "index:" << _accountIndex << ";" << std::flush;
	std::cout << "amount:" << _amount << ";" << std::flush;
	std::cout << "closed" << std::endl;
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
	_displayTimestamp();
	std::cout << "accounts:" << _nbAccounts << ";" << std::flush;
	std::cout << "total:" << _totalAmount << ";" << std::flush;
	std::cout << "deposits:" << _totalNbDeposits << ";" << std::flush;
	std::cout << "withdrawals:" << _totalNbWithdrawals << std::endl;
}

void Account::displayStatus(void) const
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";" << std::flush;
	std::cout << "amount:" << _amount << ";" << std::flush;
	std::cout << "deposits:" << _nbDeposits << ";" << std::flush;
	std::cout << "withdrawals:" << _nbWithdrawals << std::endl;
}

void Account::makeDeposit(int deposit)
{
	_displayTimestamp();
	_nbDeposits++;
	_totalNbDeposits++;
	std::cout << "index:" << _accountIndex << ";" << std::flush;
	std::cout << "p_amount:" << _amount << ";" << std::flush;
	std::cout << "deposit:" << deposit << ";" << std::flush;
	_amount += deposit;
	std::cout << "amount:" << _amount << ";" << std::flush;
	std::cout << "nb_deposits:" << _nbDeposits << std::endl;
}

bool Account::makeWithdrawal(int withdrawal)
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";" << std::flush;
	std::cout << "p_amount:" << _amount << ";" << std::flush;
	if (_amount - withdrawal < 0)
	{
		std::cout << "withdrawal:refused" << std::endl;
		return false;
	}
	_amount -= withdrawal;
	_nbWithdrawals++;
	_totalNbWithdrawals++;
	std::cout << "withdrawal:" << withdrawal << ";" << std::flush;
	std::cout << "amount:" << _amount << ";" << std::flush;
	std::cout << "nb_withdrawals:" << _nbWithdrawals << std::endl;
	return true;
}

void Account::_displayTimestamp(void)
{
	std::time_t time_now = std::time(NULL);
	std::cout << std::setfill('0') << "[" << 1900 + std::localtime(&time_now)->tm_year
			  << std::setw(2) << 1 + std::localtime(&time_now)->tm_mon
			  << std::setw(2) << std::localtime(&time_now)->tm_mday
			  << "_"
			  << std::setw(2) << std::localtime(&time_now)->tm_hour
			  << std::setw(2) << std::localtime(&time_now)->tm_min
			  << std::setw(2) << std::localtime(&time_now)->tm_sec
			  << "] " << std::flush;
}
