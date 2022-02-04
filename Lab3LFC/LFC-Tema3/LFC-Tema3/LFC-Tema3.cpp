#include "AFD.h"

int main()
{
	AFD afd;
	afd.citire();

	bool conditie = false;
	//afd.verificare(conditie);

	if (conditie)
	{
		std::cout << "\nAvem erori in fisier!";
	}

	else
	{
		afd.afisare();
		uint16_t optiune;

		std::cout << "\nIntroduceti 0 pentru oprire.\nIntroduceti 1 pentru continuare.\n";
		std::cin >> optiune;

		if (optiune)
		{
			do
			{
				std::string cuvant;
				std::cout << "Cuvantul care trebe verificat: ";
				std::cin >> cuvant;

				afd.accepta(cuvant);

				std::cout << "\nIntroduceti 0 pentru oprire.\nIntroduceti 1 pentru continuare.\n";
				std::cin >> optiune;
			} while (optiune);
		}
	}

	return 0;
}
