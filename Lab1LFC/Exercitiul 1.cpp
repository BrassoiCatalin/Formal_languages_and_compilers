#include <iostream>
#include <string>

void inputData(std::string& string, std::string& character)
{
	std::cout << "Type your string: ";
	std::getline(std::cin, string);

	std::cout << "Type your character: ";
	std::cin >> character;
}

void characterSearch(std::string& string, std::string& character)
{
	int solution = 0;

	for (int index = 0; index < string.length(); index++)
	{
		if (character[0] == string[index])
			solution++;
	}
	std::cout << "Your solution is " << solution << ".\n";
}

int main()
{
	std::string string, character;

	inputData(string, character);

	characterSearch(string, character);

	return 0;
}
//am interpretat problema in felul urmator: a este un caracter diferit de A