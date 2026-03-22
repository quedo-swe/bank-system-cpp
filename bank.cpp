#include "bank.h"
#include <iostream>

Account* Bank::FindAccount(const std::string& name)
{
	for (auto& acc : accounts)
	{
		if (acc.GetName() == name)
			return &acc;
	}
	return nullptr;
}
void Bank::clearAccounts()
{
	accounts.clear();
}
void Bank::clearTransactions()
{
	transactions.clear();
}
bool Bank::AddAccount(const std::string& name, int balance)
{
	if (FindAccount(name))
	{
		return false;
	}
	accounts.emplace_back(name, balance);
	return true;
}
void Bank::AddTransaction(const std::string& name, const std::string& type, int amount)
{
	transactions.emplace_back(name, type, amount);
}
const std::vector<Account>& Bank::getAccounts() const
{
	return accounts;
}
const std::vector<Transaction>& Bank::getTransactions() const
{
	return transactions;
}
bool Bank::Deposit(const std::string& name, int amount)
{
	auto acc = FindAccount(name);
	if (!acc)
	{
		return false;
	}

	if (acc->Deposit(amount))
	{
		transactions.emplace_back(name, "deposit", amount);
		return true;
	}
	return false;

}
bool Bank::Withdraw(const std::string& name, int amount)
{
	auto acc = FindAccount(name);
	if (!acc)
	{
		return false;
	}

	if (acc->Withdraw(amount))
	{
		transactions.emplace_back(name, "withdraw", amount);
		return true;
	}
	return false;
}