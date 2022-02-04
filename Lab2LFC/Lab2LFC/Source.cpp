#include "Gramatica.h"

void startProgram(Gramatica gramatica)
{
	gramatica.citire();

	bool verific = true;
	gramatica.verificare(verific);

	if (verific)
	{
		gramatica.afisare();

		bool optiune;
		uint16_t numarCuvinte;

		std::cout << "Introdu optiunea: \n0.Doar cuvantul final.\n1.Afisare pasi pana la generare finala.\n";
		std::cin >> optiune;

		std::cout << "Alege cate cuvinte sa fie generate: ";
		std::cin >> numarCuvinte;

		for (uint16_t index = 0; index < numarCuvinte; index++)
		{
			std::cout << "Cuvantul " << index + 1 << " generat este: ";
			gramatica.generare(optiune);
			std::cout << "\n\n";
		}
	}
	else
		std::cout << "Exista erori in fisier!.\n";
}

int main()
{
	Gramatica gramatica;

	startProgram(gramatica);

	return 0;
}