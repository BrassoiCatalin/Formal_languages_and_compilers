#include "AFD.h"

void AFD::citire()
{
	std::ifstream fis("text.txt");
	int dim;

	fis >> dim;
	for (int index = 0; index < dim; index++)
	{
		std::string element;
		fis >> element;
		m_stari.push_back(element);
	}

	fis >> m_sigma;

	fis >> dim;
	for (int index = 0; index < dim; index++)
	{
		std::string inceput;
		std::string mijloc;
		std::string final;
		fis >> inceput >> mijloc >> final;

		//m_delta.push_back(std::tuple<std::string, std::string, std::string>(inceput, mijloc, final));
		inceput.append(mijloc);

		m_delta2[inceput] = final;
	}

	fis >> m_stareInit;

	fis >> dim;
	for (int index = 0; index < dim; index++)
	{
		std::string final;
		fis >> final;
		m_finale.push_back(final);
	}
}

void AFD::afisare()
{
	std::cout << "Multimea starilor: \n{";
	for (int index = 0; index < m_stari.size(); index++)
	{
		if (index != 0)
			std::cout << ", " << m_stari[index];
		else
			std::cout << m_stari[index];
	}
	std::cout << "}\n\n";

	std::cout << "Alfabetul de intrare: \n{";
	std::cout << m_sigma;
	std::cout << "}\n\n";

	std::cout << "Functia de tranzitie: \n";
	/*for (int index = 0; index < m_delta.size(); index++)
	{
		std::cout << std::get<0>(m_delta[index]) << " ";
		std::cout << std::get<1>(m_delta[index]) << " ";
		std::cout << std::get<2>(m_delta[index]) << " ";
		std::cout << '\n';
	}*/

	for (const std::pair<std::string, std::string> it : m_delta2)
	{
		std::cout << it.first << " " << it.second << '\n';
	}

	std::cout << '\n';

	std::cout << "Starea initiala: \n" << m_stareInit << "\n\n";

	std::cout << "Starile finale: \n{";
	for (int index = 0; index < m_finale.size(); index++)
	{
		if (index != 0)
			std::cout << ", " << m_finale[index];
		else
			std::cout << m_finale[index];
	}
	std::cout << "}\n\n";

}

void AFD::verificare(bool& conditie)
{
	conditie = false;
	for (int index = 0; index < m_stari.size(); index++)
	{
		if (m_stari[index] == m_stareInit)
		{
			conditie = true;
			break;
		}
	}

	if (!conditie)
	{
		std::cout << "Starea initiala nu se gaseste in multimea de stari!\n";
		return;
	}

	conditie = false;

	for (int index2 = 0; index2 < m_finale.size(); index2++)
	{
		for (int index = 0; index < m_stari.size(); index++)
		{
			if (m_stari[index] == m_finale[index2])
			{
				conditie = true;
				break;
			}
		}
	}

	if (!conditie)
		std::cout << "O stare finala nu se gaseste in multimea de stari!\n";

	conditie = false;

	for (int index = 0; index < m_delta.size(); index++)
	{
		conditie = false;
		for (int index1 = 0; index1 < m_stari.size(); index1++)
		{
			if (std::get<0>(m_delta[index]) == m_stari[index1])
			{
				conditie = true;
				break;
			}
		}
		if (!conditie)
		{
			std::cout << "O tranzitie contine un element care nu se afla in multimea de stari, din coloana 1.";
			return;
		}
	}

	conditie = false;

	for (int index = 0; index < m_delta.size(); index++)
	{
		conditie = false;
		for (int index1 = 0; index1 < m_stari.size(); index1++)
		{
			if (std::get<2>(m_delta[index]) == m_stari[index1] || std::get<2>(m_delta[index]) == "-")
			{
				conditie = true;
				break;
			}
		}
		if (!conditie)
		{
			std::cout << "O tranzitie contine un element care nu se afla in multimea de stari, din coloana 2.";
			return;
		}
	}

	conditie = false;

	for (int index = 0; index < m_delta.size(); index++)
	{
		conditie = false;
		for (int index1 = 0; index1 < m_sigma.size(); index1++)
		{
			if (std::get<1>(m_delta[index]).find(m_sigma[index1]) != std::string::npos)
			{
				conditie = true;
				break;
			}
		}
		if (!conditie)
		{
			std::cout << "O tranzitie contine un element care nu se afla in sigma.";
			return;
		}
	}
}

void AFD::accepta(std::string cuvant)
{
	for (int index = 0; index < cuvant.size(); index++)
	{
		if (m_sigma.find(cuvant[index]) == std::string::npos)
		{
			std::cout << "Cuvantul nu e bun! Incercati din nou.\n";
			return;
		}
	}

	int16_t stare = -2;
	std::string stareCurenta = m_stareInit;

	std::queue<std::string> cuvantCoada;
	for (int index = 0; index < cuvant.size(); index++)
	{
		std::string litera{ cuvant[index] };
		cuvantCoada.push(litera);
	}

	while (cuvant.length() != 0/*cuvantCoada.size()*/)
	{
		//for (int index1 = 0; index1 < m_delta.size(); index1++)
		//{
		//	if (std::get<0>(m_delta[index1]) == stareCurenta && std::get<1>(m_delta[index1]) == cuvantCoada.front())
		//	{
		//		stareCurenta = std::get<2>(m_delta[index1]);

		//		if (stareCurenta == "-")
		//		{
		//			stare = -1;
		//			break;//blocaj
		//		}

		//		cuvantCoada.pop();

		//		if (cuvantCoada.empty())
		//			break;
		//	}
		//}

		for (const auto& iterator : m_delta2)
		{
			if (iterator.first.back() == cuvant[0] && iterator.first.find(stareCurenta) != std::string::npos)
			{
				stareCurenta = iterator.second;

				if (stareCurenta == "-")
				{
					stare = -1;
					break;//blocaj
				}

				cuvant.erase(0, 1);

				if (cuvant.length() == 0)
					break;
			}
		}

		if (stare == -1)
		{
			break;
		}
	}

	if (stare != -1)
	{
		stare = 0;//neacceptat

		for (int index = 0; index < m_finale.size(); index++)
		{
			if (stareCurenta == m_finale[index])
			{
				stare = 1;
				break;//acceptat
			}
		}
	}

	switch (stare)
	{
	case -1:
		std::cout << "\nBlocaj!\n";
		break;

	case 0:
		std::cout << "\nNeacceptat!\n";
		break;

	case 1:
		std::cout << "\nAcceptat!\n";
		break;
	}

}
//verifica data viitoare