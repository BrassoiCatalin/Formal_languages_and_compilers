#include "Exercitiul3.h"

void Exercitiul3::Run()
{
	std::string string, subString1, subString2;

	inputData(string, subString1, subString2);
	reverseAndReplace(string, subString1, subString2);
}

void Exercitiul3::inputData(std::string& string, std::string& subString1, std::string& subString2)
{
	std::cout << "Initial string: ";
	std::getline(std::cin, string);

	std::cout << "First Substring: ";
	std::getline(std::cin, subString1);

	std::cout << "Second substring: ";
	std::getline(std::cin, subString2);
}

void Exercitiul3::reverseAndReplace(std::string& string, std::string& subString1, std::string& subString2)
{
	reverse(string.begin(), string.end());

	int position = string.find(subString1);
	while (position < string.length())
	{
		string.replace(position, subString1.length(), subString2);
		position = string.find(subString1, position + subString2.length());
	}
	std::cout << "Requested string is: " << string;
}
