#include "AFN.h"

int main()
{
	AFN afn;
	afn.citire();

	bool conditie;
	afn.verificare(conditie);

	if (!conditie)
	{
		std::cout << "Avem erori in fisier!\n";
	}

	else
	{
		afn.afisare();

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

				int raspuns = afn.accepta(cuvant, afn.getStareInitiala());
				switch (raspuns)
				{
				case 1:
				case -1:
					std::cout << "Neacceptat\n";
					break;

				case 0:
					std::cout << "Acceptat\n";
					break;

				case 2:
					std::cout << "\nCuvantul nu este bun! Reintroduceti alt cuvant!\n";
					break;

				default:
					break;

				}

				std::cout << "\nIntroduceti 0 pentru oprire.\nIntroduceti 1 pentru continuare.\n";
				std::cin >> optiune;

			} while (optiune);
		}

	}

	return 0;
}