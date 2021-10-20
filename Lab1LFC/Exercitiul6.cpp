#include "Exercitiul6.h"

void Exercitiul6::Run()
{
	std::string word;
	std::vector<std::string> prefix;

	showPrefixes(word, prefix);
}

void Exercitiul6::showPrefixes(std::string& word, std::vector<std::string>& prefix)
{
	std::cout << "Word input: ";
	//std::cin.ignore();
	std::getline(std::cin, word);

	std::string aux;
	for (int index = 0; index < word.length() - 1; index++)
	{
		aux.push_back(word[index]);
		prefix.push_back(aux);
	}

	for (int index = 0; index < prefix.size(); index++)
		std::cout << prefix[index] << '\n';
}
