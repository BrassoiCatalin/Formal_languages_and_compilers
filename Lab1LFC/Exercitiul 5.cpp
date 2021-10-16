#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

void sortingProgram(int& vectorLenght, std::vector<std::string>& stringVector)
{
	std::string word;

	std::cout << "Number of words: ";
	std::cin >> vectorLenght;

	std::cout << "Your words: ";
	for (int index = 0; index < vectorLenght; index++)
	{
		std::cin >> word;
		stringVector.push_back(word);
	}

	std::sort(stringVector.begin(), stringVector.end());

	for (int index = 0; index < vectorLenght; index++)
	{
		std::cout << stringVector[index] << '\n';
	}
}

int main()
{
	int vectorLenght;
	std::vector<std::string> stringVector;

	sortingProgram(vectorLenght, stringVector);

	return 0;
}