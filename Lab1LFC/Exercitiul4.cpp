#include "Exercitiul4.h"

void Exercitiul4::Run()
{

	std::string string;

	dataInput(string);
	wordCount(string);
}

void Exercitiul4::dataInput(std::string& string)
{
	std::cout << "Input string: ";
	std::getline(std::cin, string);
}

void Exercitiul4::wordCount(std::string string)
{
	std::string copy = string, space = " ";
	std::regex letter("[a-zA-Z]+");

	for (int index = 0; index < copy.length(); index++)
	{
		std::string tempString1;
		tempString1.push_back(copy[index]);

		if (!std::regex_match(tempString1, letter) || index == copy.length() - 1)
		{
			bool condition = false;

			for (int index1 = 0; index1 < index; index1++)
			{
				std::string tempString;
				tempString.push_back(copy[index1]);

				if (std::regex_match(tempString, letter)) {
					condition = true;
					std::cout << copy[index1];
				}
			}

			for (int index1 = 0; index1 < index + 1; index1++)
			{
				copy.erase(0, 1);
			}

			if (condition)
				std::cout << '\n';
			index = 0;
		}
	}

}
