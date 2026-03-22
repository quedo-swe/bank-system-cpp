#pragma once
#include <string>

class Bank;

class BankStorage
{
public:
	static bool Save(const Bank& bank,const std::string& filename);
	static bool Load(Bank& bank,const std::string& filename);
};