#pragma once
#include <iostream>
#include <unordered_map>
#include <vector>
#include <fstream>

class AFN
{
private:
	std::vector<std::string> m_stari;
	std::string m_sigma;
	std::unordered_map<std::string, std::vector<std::pair<std::string, std::string>>> m_delta;
	std::string m_stareInit;
	std::vector<std::string> m_finale;

public:
	void citire();
	void afisare();
	void verificare(bool& conditie);
	int accepta(std::string cuvant, std::string stare);

	std::string getStareInitiala();
};
