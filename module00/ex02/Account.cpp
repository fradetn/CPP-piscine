/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfradet <nfradet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 15:46:25 by nfradet           #+#    #+#             */
/*   Updated: 2024/09/06 16:57:49 by nfradet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/Account.hpp"
#include <iostream>
#include <iomanip>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account( int initial_deposit ) {
	this->_amount = initial_deposit;
	this->_nbDeposits = 0;
	this->_accountIndex = Account::_nbAccounts;
	this->_nbWithdrawals = 0;
	Account::_nbAccounts += 1;
	Account::_totalAmount += this->_amount;
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex 
	<< ";amount:" << this->_amount
	<< ";created" << std::endl;
}

Account::~Account( void ) {
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex 
	<< ";amount:" << this->_amount
	<< ";closed" << std::endl;
}

int	Account::getNbAccounts( void ) {
	return Account::_nbAccounts;
}
int	Account::getTotalAmount( void ) {
	return Account::_totalAmount;
}
int	Account::getNbDeposits( void ) {
	return Account::_totalNbDeposits;
}
int	Account::getNbWithdrawals( void ) {
	return Account::_totalNbWithdrawals;
}

void	Account::displayAccountsInfos( void ) {
	Account::_displayTimestamp();
	std::cout << "accounts:" << Account::getNbAccounts()
	<< ";total:" << Account::getTotalAmount()
	<< ";deposits:" << Account::getNbDeposits()
	<< ";withdrawals:" << Account::getNbWithdrawals() << std::endl;
}

void	Account::makeDeposit( int deposit ) {
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex
	<< ";p_amount:" << this->checkAmount()
	<< ";deposit:" << deposit;
	this->_amount += deposit;
	this->_nbDeposits++;
	Account::_totalAmount += deposit;
	Account::_totalNbDeposits++;
	std::cout<< ";amount:" << this->checkAmount()
	<< ";nb_deposits:"<< this->_nbDeposits << std::endl;
}

bool	Account::makeWithdrawal( int withdrawal ) {
	if (withdrawal > this->checkAmount()){
		Account::_displayTimestamp();
		std::cout << "index:" << this->_accountIndex
		<< ";p_amount:" << this->checkAmount()
		<< ";withdrawal:refused" << std::endl;
		return (false);
	}
	else {
		Account::_displayTimestamp();
		std::cout << "index:" << this->_accountIndex
		<< ";p_amount:" << this->checkAmount()
		<< ";withdrawal:" << withdrawal;
		this->_amount -= withdrawal;
		Account::_totalAmount -= withdrawal;
		this->_nbWithdrawals++;
		Account::_totalNbWithdrawals++;
		std::cout <<";amount:"<< this->checkAmount()
		<< ";nb_withdrawals:" << this->_nbWithdrawals << std::endl;
		return (true);
	}
}

int		Account::checkAmount( void ) const {
	return (this->_amount);
}

void	Account::displayStatus( void ) const {
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex
	<< ";amount:" << this->checkAmount()
	<< ";deposits:" << this->_nbDeposits
	<< ";withdrawals:" << this->_nbWithdrawals << std::endl;
}

void	Account::_displayTimestamp( void ) {
	time_t currentTime= time(NULL);

	std::cout << std::put_time(localtime(&currentTime), "[%Y%m%d_%H%M%S] ");
}