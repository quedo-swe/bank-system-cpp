#include "transaction.h"
#include <iostream>

Transaction::Transaction(const std::string& accountName, const std::string& type, int amount)
	:accountName(accountName), type(type), amount(amount) {
}
const std::string& Transaction::GetAccountName() const
{
	return accountName;
}
const std::string& Transaction::GetType() const
{
	return type;
}
int Transaction::GetAmount() const
{
	return amount;
}