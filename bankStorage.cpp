#include "bankStorage.h"
#include "bank.h"
#include <fstream>

bool BankStorage::Save(const Bank& bank, const std::string& filename)
{
	std::ofstream out(filename);
	if (!out) return false;
	
	out << "ACCOUNTS\n";
	for (const auto& acc : bank.getAccounts())
	{
		out << acc.GetName() << " "
			<< acc.GetBalance() << '\n';
	}
	out << "TRANSACTIONS\n";
	for (const auto& t : bank.getTransactions())
	{
		out << t.GetAccountName() << " "
			<< t.GetType() << " "
			<< t.GetAmount() << '\n';
	}

	return true;
}
bool BankStorage::Load(Bank& bank, const std::string& filename)
{
	std::ifstream in(filename);
	if (!in) return false;

	bank.clearAccounts();
	bank.clearTransactions();

	std::string name;
	int balance;

	std::string word;
	in >> word; // ACCOUNTS

	if (word != "ACCOUNTS")
	{
		return false;
	}
	while (in >> name)
	{
		if (name == "TRANSACTIONS") break;

		in >> balance;
		bank.AddAccount(name, balance);
	}

	std::string type;
	int amount;

	while (in >> type >> name >> amount)
	{	
		bank.AddTransaction(name, type, amount);
	}

	return true;
}