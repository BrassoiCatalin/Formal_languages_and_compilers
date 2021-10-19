#include "Exercitiul1.h"
#include "Exercitiul2.h"
#include "Exercitiul3.h"
#include "Exercitiul4.h"
#include "Exercitiul5.h"
#include "Exercitiul6.h"
#include "Exercitiul7.h"
#include "Exercitiul8.h"

void startProgram()//ce se intampla in acest switch??
{
	int option;

	std::cout << "Program option: ";
	std::cin >> option;

	switch (option)
	{
	case 1:
		Exercitiul1 e1;
		e1.Run();
		break;

	case 2:
		Exercitiul2 e2;
		e2.Run();
		break;

	case 3:
		Exercitiul3 e3;
		e3.Run();
		break;

	case 4:
		Exercitiul4 e4;
		e4.Run();
		break;

	case 5:
		Exercitiul5 e5;
		e5.Run();
		break;

	case 6:
		Exercitiul6 e6;
		e6.Run();
		break;

	case 7:
		Exercitiul7 e7;
		e7.Run();
		break;

	case 8:
		Exercitiul8 e8;
		e8.Run();
		break;

	default:
		std::cout << "No option is avaliable.";
	}

}

int main()
{
	//startProgram();
	Exercitiul1 e1;
	Exercitiul2 e2;
	Exercitiul3 e3;
	Exercitiul4 e4;
	Exercitiul5 e5;
	Exercitiul6 e6;
	Exercitiul7 e7;
	Exercitiul8 e8;
	e7.Run();
	return 0;
}