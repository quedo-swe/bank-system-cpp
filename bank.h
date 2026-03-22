#pragma once
#include <string>
#include <vector>
#include "account.h"
#include "transaction.h"
class Bank
{
private:
	std::vector<Account> accounts;
	std::vector<Transaction> transactions;
	Account* FindAccount(const std::string& name);
public:
	void clearAccounts();
	void clearTransactions();
	bool AddAccount(const std::string& name, int balance);
	void AddTransaction(const std::string& name, const std::string& type, int amount);
	const std::vector<Account>& getAccounts() const;
	const std::vector<Transaction>& getTransactions() const;
	bool Deposit(const std::string& name, int amount);
	bool Withdraw(const std::string& name, int amount);
};