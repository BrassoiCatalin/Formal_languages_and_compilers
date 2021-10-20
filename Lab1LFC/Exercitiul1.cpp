#include "Exercitiul1.h"

void Exercitiul1::Run()
{
	std::string string, character;

	inputData(string, character);

	characterSearch(string, character);

}

void Exercitiul1::inputData(std::string& string, std::string& character)
{
	std::cout << "Type your string: ";
	//std::cin.ignore();
	std::getline(std::cin, string);

	std::cout << "Type your character: ";
	std::cin >> character;
	std::cin.ignore();

}

void Exercitiul1::characterSearch(std::string& string, std::string& character)
{
	int solution = 0;

	for (int index = 0; index < string.length(); index++)
	{
		if (character[0] == string[index])
			solution++;
	}
	std::cout << "Your solution is " << solution << ".\n";
}
