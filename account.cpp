#include "account.h"

Account::Account(const std::string& ownerName, int balance)
	: ownerName(ownerName), balance(balance){}
bool Account::Deposit(int amount)
{
	if (amount <= 0)
	{
		return false;
	}
	balance += amount;
	return true;
}
bool Account::Withdraw(int amount)
{
	if (amount <= 0 || amount > balance)
	{
		return false;
	}
	balance -= amount;
	return true;
}
int Account::GetBalance() const
{
	return balance;
}
const std::string& Account::GetName() const
{
	return ownerName;
}