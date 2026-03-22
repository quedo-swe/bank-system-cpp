#include <iostream>
#include "bank.h"
#include"bankStorage.h"
int main()
{
	Bank bank;
	if(!bank.AddAccount("vadym",1400))
		std::cout << "Failed to add account\n";
	if (!bank.AddAccount("nazar", 1700))
		std::cout << "Failed to add account\n";
	if(!bank.Deposit("vadym",500))
		std::cout << "Deposit failed\n";
	if (!bank.Withdraw("vadym", 900))
		std::cout << "Withdraw failed\n";

	std::cout << " === Original Data === \n";
	for (const auto& acc : bank.getAccounts())
	{
		std::cout << acc.GetName() << " "
			<< acc.GetBalance() << '\n';
	}
	if (!BankStorage::Save(bank, "test.txt"))
	{
		std::cout << "Save failed!\n";
	}

	Bank newBank;

	if (!BankStorage::Load(newBank, "test.txt"))
	{
		std::cout << "Load failed!\n";
	}
	std::cout << "\n=== Loaded Data ===\n";
	for (const auto& acc : newBank.getAccounts())
	{
		std::cout << acc.GetName() << " "
			<< acc.GetBalance() << '\n';
	}

	return 0;
}