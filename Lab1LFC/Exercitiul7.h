#pragma once
#include <iostream>
#include <vector>
#include <string>

class Exercitiul7
{
public:
	void Run();

private:
	void inputData(std::vector<std::string>& stringVector, std::string& subString);
	void generateVector(std::vector<std::string> stringVector, std::string subString);
};
