#include "Exercitiul7.h"

void Exercitiul7::Run()
{
	std::vector<std::string> stringVector;
	std::string subString;

	inputData(stringVector, subString);
	generateVector(stringVector, subString);
}

void Exercitiul7::inputData(std::vector<std::string>& stringVector, std::string& subString)
{
	int dimension;
	std::string word;

	std::cout << "Vector dimension: ";
	std::cin >> dimension;

	for (int index = 0; index < dimension; index++)
	{
		std::cin >> word;
		stringVector.push_back(word);
	}

	std::cout << "Your substring is: ";
	std::cin >> subString;

}

void Exercitiul7::generateVector(std::vector<std::string> stringVector, std::string subString)
{
	std::vector<std::string> resultVector;

	for (int index = 0; index < stringVector.size(); index++)
	{
		if (stringVector[index].find(subString) != std::string::npos)
			resultVector.push_back(stringVector[index]);
	}

	std::cout << "Your result: \n";
	for (int index = 0; index < resultVector.size(); index++)
		std::cout << resultVector[index] << " ";
}
