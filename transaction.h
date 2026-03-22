#pragma once
#include <string>
class Transaction
{
private:
	std::string accountName;
	std::string type;
	int amount;
public:
	Transaction(const std::string& accountName, const std::string& type, int amount);
	const std::string& GetAccountName() const;
	const std::string& GetType() const;
	int GetAmount() const;
};