#include "Exercitiul8.h"

void Exercitiul8::Run()
{
	std::vector<std::string> allWords;
	std::string word, usedWord;

	inputData(allWords, word, usedWord);
	hangMan(usedWord);
}

void Exercitiul8::inputData(std::vector<std::string> allWords, std::string& word, std::string& usedWord)
{
	std::ifstream file("words.txt");

	while (std::getline(file, word))
		allWords.push_back(word);

	srand(time(NULL));

	usedWord = allWords[rand() % allWords.size()];

}

void Exercitiul8::hangMan(std::string usedWord)
{
	std::string letter, copy;
	int trys = 6;
	std::regex reg("[a-zA-Z]");


	for (int index = 0; index < usedWord.size(); index++)
	{
		std::cout << "_ ";
	}
	std::cout << '\n';

	copy.resize(usedWord.size());

	while (trys != 0)
	{
		bool correct = false;

		std::cout << "Input a letter, please: ";
		std::cin >> letter;
		std::cout << '\n';

		while (letter.size() != 1 || std::regex_match(letter, reg) == false)
		{
			std::cout << "Invalid: please try again.\n\n";

			std::cout << "Input a letter, please: ";
			std::cin >> letter;
			std::cout << '\n';
		}

		for (int index = 0; index < usedWord.size(); index++)
		{
			if (usedWord[index] == letter[0])
			{
				copy[index] = letter[0];
				correct = true;
			}
		}

		for (int index = 0; index < copy.size(); index++)
		{
			if (copy[index] != NULL)
				std::cout << copy[index] << " ";
			else
				std::cout << "_ ";
		}
		std::cout << "\n\n";

		if (correct == false)
		{
			trys--;
			std::cout << "ERROR: you have " << trys << " guesses left!\n\n";
		}

		if (usedWord.compare(copy) == 0)
		{
			std::cout << "CONGRATULATIONS! YOU WON!\n";
			break;
		}
	}

	if (trys == 0)
		std::cout << "GAME OVER: YOU LOST! Your word was " << usedWord << ".";
}
