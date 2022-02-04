#pragma once
#include <iostream>	
#include <string>
#include <fstream>
#include <vector>
#include <random>

struct Productie
{
	std::vector<std::string> productiiStanga;
	std::vector<std::string> productiiDreapta;
};

class Gramatica
{
private:
	std::string m_VN;
	std::string m_VT;
	std::string m_S;
	Productie m_P;

public:

	Gramatica();

	void citire();
	void verificare(bool& conditie);
	void afisare();
	void generare(bool optiune);
};

