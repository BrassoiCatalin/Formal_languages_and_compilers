#include "Exercitiul1.h"
#include "Exercitiul2.h"
#include "Exercitiul3.h"
#include "Exercitiul4.h"
#include "Exercitiul5.h"
#include "Exercitiul6.h"
#include "Exercitiul7.h"
#include "Exercitiul8.h"

void menu()
{
	std::cout << "Choose number 1 for exercise 1.\n";
	std::cout << "Choose number 2 for exercise 2.\n";
	std::cout << "Choose number 3 for exercise 3.\n";
	std::cout << "Choose number 4 for exercise 4.\n";
	std::cout << "Choose number 5 for exercise 5.\n";
	std::cout << "Choose number 6 for exercise 6.\n";
	std::cout << "Choose number 7 for exercise 7.\n";
	std::cout << "Choose number 8 for exercise 8.\n";
	std::cout << "Choose number 0 for exit.\n\n";
}

void startProgram()
{
	menu();
	int option = -1;

	while (option)
	{
		std::cout << "\nProgram option: ";
		std::cin >> option;
		std::cin.ignore();

		switch (option)
		{
		case 0:
			break;

		case 1:
			Exercitiul1 e1;
			e1.Run();
			std::cout << '\n';
			break;

		case 2:
			Exercitiul2 e2;
			e2.Run();
			std::cout << '\n';
			break;

		case 3:
			Exercitiul3 e3;
			e3.Run();
			std::cout << '\n';
			break;

		case 4:
			Exercitiul4 e4;
			e4.Run();
			std::cout << '\n';
			break;

		case 5:
			Exercitiul5 e5;
			e5.Run();
			std::cout << '\n';
			break;

		case 6:
			Exercitiul6 e6;
			e6.Run();
			std::cout << '\n';
			break;

		case 7:
			Exercitiul7 e7;
			e7.Run();
			std::cout << '\n';
			break;

		case 8:
			Exercitiul8 e8;
			e8.Run();
			std::cout << '\n';
			break;

		default:
			std::cout << "No option is avaliable.\n\n";
		}
	}
}

int main()
{
	startProgram();

	return 0;
}

