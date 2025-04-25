#include "Account.hpp"
#include <iostream>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

void	Account::_displayTimestamp()
{
    
}

Account::Account(int initial_deposit) 
{
    _accountIndex = _nbAccounts;
    _amount = initial_deposit;
    _nbDeposits = 0;
    _nbWithdrawals = 0;
    std::cout << "[0]" << "index:" <<  _accountIndex  
        << ";amount:" << _amount << ";created" << std::endl;
    _nbAccounts++;
    _totalAmount += _amount;
}

Account::~Account()
{
    std::cout << "[0]" << "index:" <<  _accountIndex  
        << ";amount:" << _amount << ";created" << std::endl;
}

void	Account::displayAccountsInfos()
{
    std::cout << "[0]" << "accounts:" <<  _nbAccounts 
        << ";total:" << _totalAmount << ";diposits:" << _totalNbDeposits 
        << ";withdrawals:" << _totalNbWithdrawals << std::endl;
} 

void    Account::displayStatus() const 
{
    std::cout << "index:" << _accountIndex <<  ";amount:" << _amount 
        << ";deposits:" << _nbDeposits << ";withdrawals:" << _nbWithdrawals << std::endl;
}

void    Account::makeDeposit(int deposit)
{
    int p_amount;

    p_amount = _amount;
    _amount += deposit;
    _nbDeposits++;
    _totalNbDeposits++;
    _totalAmount += deposit;
    std::cout << "index:" << _accountIndex <<  ";p_amount:" << p_amount 
        << ";deposits:" << deposit <<  ";amount:" << _amount
        << ";nb_deposits:" << _nbDeposits << std::endl;
}

bool    Account::makeWithdrawal(int withdrawal)
{
    std::cout << "index:" << _accountIndex <<  ";p_amount:" << _amount;
    if (withdrawal > _amount)
    {   
        std::cout << ";withdrawal:refused" << std::endl;
        return false;
    }
    _amount -= withdrawal;
    _nbWithdrawals++;
    _totalNbWithdrawals++;
    _totalAmount -= withdrawal;
    std::cout << ";withdrawal:" << withdrawal <<  ";amount:" << _amount
        << ";nb_withdrawals:" << _nbWithdrawals << std::endl;
    return true;
}
