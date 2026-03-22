#pragma once
#include <string>
class Account
{
private:
	const std::string ownerName;
	int balance{};
public:
	Account(const std::string& ownerName, int balance);

	bool Deposit(int amount);
	bool Withdraw(int amount);

	int GetBalance() const;
	const std::string& GetName() const;
};