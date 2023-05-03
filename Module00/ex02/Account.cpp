#include "Account.hpp"
#include <iostream>
#include <time.h>

int	Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account(void) {}

Account::~Account(void)
{ 
	_displayTimestamp();
	std::cout	<< "index:" << _accountIndex << ";" << "amount:" << _amount << ";closed" << std :: endl;
}

Account::Account(int initial_deposit)
{
	_displayTimestamp();
	std :: cout	<< "index:" << _nbAccounts << ";" << "amount:" << initial_deposit << ";created" << std :: endl;
	_amount = initial_deposit;
	_totalAmount += _amount;
	_accountIndex = _nbAccounts;
	_nbAccounts++;
}

int Account::getNbAccounts(void)
{
	return (_nbAccounts);
}

int		Account::getTotalAmount(void)
{
	return (_totalAmount);
}
int		Account::getNbDeposits(void)
{
	return (_totalNbDeposits);
}
int		Account::getNbWithdrawals(void)
{
	return (_totalNbWithdrawals);
}

void Account::_displayTimestamp( void )
{
	time_t current_time;
    struct tm* time_info;
    char time_string[20];

    time(&current_time);
    time_info = localtime(&current_time);
    strftime(time_string, sizeof(time_string), "%Y%m%d_%H%M%S", time_info);
    std::cout << "[" << time_string << "] "; 
}

void Account::displayAccountsInfos ( void )
{
	_displayTimestamp();
	std::cout << "accounts:" << getNbAccounts() << ";total:" << getTotalAmount() << ";deposits:" << getNbDeposits() << ";withdrawals:" << getNbWithdrawals() << std::endl;
}

void	Account::makeDeposit( int deposit )
{
	_displayTimestamp();
	_nbDeposits++;
	_totalNbDeposits++;
	std::cout	<< "index:" << _accountIndex << ";p_amount:" << _amount << ";deposit:" << deposit << ";amount:" << deposit + _amount << ";nb_deposits:" << _nbDeposits << std::endl;
	_amount += deposit;
	_totalAmount += deposit;
}

bool	Account :: makeWithdrawal(int withdrawal)
{
	bool	check;
	
	check = _amount - withdrawal >= 0;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";p_amount:" << _amount << ";";
	if (!check)
		std::cout << "withdrawal:refused" << std::endl;
	else
	{
		_amount -= withdrawal;
		_totalAmount -= withdrawal;
		std::cout << "withdrawal:" << withdrawal << ";amount:" << _amount << ";nb_withdrawals:" << ++_nbWithdrawals << std :: endl;
		_totalNbWithdrawals++;
	}
	return (check);
}

int		Account::checkAmount( void ) const
{
	return (_amount);
}

void	Account::displayStatus( void ) const
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";deposits:" << _nbDeposits << ";withdrawals:" << _nbWithdrawals << std::endl;
}
