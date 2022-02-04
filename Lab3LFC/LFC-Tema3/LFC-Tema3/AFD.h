#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <tuple>
#include <fstream>
#include <queue>
#include <unordered_map>

class AFD
{
private:
	std::vector<std::string> m_stari;
	std::string m_sigma;
	std::vector<std::tuple<std::string, std::string, std::string>> m_delta;
	std::unordered_map<std::string, std::string> m_delta2;
	std::string m_stareInit;
	std::vector<std::string> m_finale;

public:
	void citire();
	void afisare();
	void verificare(bool& conditie);
	void accepta(std::string cuvant);
};
