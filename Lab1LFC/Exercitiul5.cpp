#include "Exercitiul5.h"

void Exercitiul5::Run()
{
	int vectorLenght;
	std::vector<std::string> stringVector;

	sortingProgram(vectorLenght, stringVector);

}

void Exercitiul5::sortingProgram(int& vectorLenght, std::vector<std::string>& stringVector)
{
	std::string word;

	std::cout << "Number of words: ";
	std::cin >> vectorLenght;
	std::cin.ignore();

	std::cout << "Your words: ";
	for (int index = 0; index < vectorLenght; index++)
	{
		std::cin >> word;
		std::cin.ignore();
		stringVector.push_back(word);
	}

	std::sort(stringVector.begin(), stringVector.end());

	for (int index = 0; index < vectorLenght; index++)
	{
		std::cout << stringVector[index] << '\n';
	}
}
