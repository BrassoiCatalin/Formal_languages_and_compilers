#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <ctime>
#include <regex>


class Exercitiul8
{
public:
	void Run();

private:
	void inputData(std::vector<std::string> allWords, std::string& word, std::string& usedWord);
	void hangMan(std::string usedWord);
};

