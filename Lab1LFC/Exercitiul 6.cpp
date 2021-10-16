#include <iostream>
#include <string>
#include <vector>

void showPrefixes(std::string& word, std::vector<std::string>& prefix)
{
	std::cout << "Word input: ";
	std::getline(std::cin, word);

	std::string aux;
	for (int index = 0; index < word.length() - 1; index++)
	{
		//aux.resize(index + 1);
		aux.push_back(word[index]);
		prefix.push_back(aux);
	}

	for (int index = 0; index < prefix.size(); index++)
		std::cout << prefix[index] << '\n';
}

int main()
{
	std::string word;
	std::vector<std::string> prefix;

	showPrefixes(word, prefix);

	return 0;
}