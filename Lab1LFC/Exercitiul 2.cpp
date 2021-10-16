#include <iostream>
#include <regex>

void inputData(std::string& number)
{
	std::cout << "String input: ";
	std::getline(std::cin, number);
}

void searchNumber(std::string number)
{
	std::regex natural("[0]|([1-9]+[0-9]*)?");
	std::regex ints("([+]|[-])?[1-9]+[0-9]*?");
	std::regex floats("(\\+|-)?(0[.][0-9]*)|(0[.][0-9]*[E][+-]?[0-9]*)|([1-9]+[0-9]*[.][0-9]*)|([1-9]+[0-9]*[.][0-9]*[E][+-]?[0-9]*)");

	if (std::regex_match(number, natural))
		std::cout << "Number " << number << " is a natural number.";
	else if (std::regex_match(number, ints))
		std::cout << "Number " << number << " is a whole number.";
	else if (std::regex_match(number, floats))
		std::cout << "Number " << number << " is a real number.";
	else std::cout << number << " is not a number.";
}

int main()
{
	std::string number;

	inputData(number);
	searchNumber(number);

	return 0;
}