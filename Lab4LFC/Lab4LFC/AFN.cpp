#include "AFN.h"

#include <queue>

void AFN::citire()
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
		std::string first, second, third;
		fis >> first >> second >> third;

		m_delta[first].push_back(std::make_pair(second, third));
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

void AFN::afisare()
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

	//int count = 0;
	std::cout << "Functia de tranzitie: \n";
	for (auto iterator : m_delta)
	{
		for (int index = 0; index < iterator.second.size(); index++)
		{
			std::cout << iterator.first << " " << iterator.second[index].first << " " << iterator.second[index].second << '\n';
		}
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

void AFN::verificare(bool& conditie)
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
	for (auto iterator : m_delta)
	{
		conditie = false;
		for (int index1 = 0; index1 < m_stari.size(); index1++)
		{
			if (iterator.first == m_stari[index1])
			{
				conditie = true;
				break;
			}
		}
		if (!conditie)
		{
			std::cout << "O tranzitie contine un element care nu se afla in multimea de stari: coloana 1.\n";
			return;
		}
	}

	for (auto iterator : m_delta)
	{
		for (int index = 0; index < iterator.second.size(); index++)
		{
			if (m_sigma.find(iterator.second[index].first) == std::string::npos)
			{
				conditie = false;
				break;
			}
		}
		if (!conditie)
		{
			std::cout << "O tranzitie contine un element care nu se afla in multimea de stari: coloana 2.\n";
			return;
		}
	}

	std::vector<std::string> temp;
	for (auto iterator : m_delta)
	{
		for (int index = 0; index < iterator.second.size(); index++)
		{
			temp.push_back(iterator.second[index].second);
		}
	}

	for (int index = 0; index < temp.size(); index++)
	{
		if (temp[index] == "-")
		{
			temp.erase(temp.begin() + index);
			index--;
		}
	}

	std::sort(temp.begin(), temp.end());

	for (int index = 0; index < m_stari.size(); index++)
	{
		while (temp.size() != 0 && temp[0] == m_stari[index] )
			temp.erase(temp.begin());
	}

	if (temp.size() != 0)
	{
		std::cout << "O tranzitie contine un element care nu se afla in multimea de stari: coloana 3.\n";
		conditie = false;
		return;
	}
}

int AFN::accepta(std::string cuvant, std::string stare)
{
	for (int index = 0; index < cuvant.size(); index++)
	{
		if (m_sigma.find(cuvant[index]) == std::string::npos)
		{
			return 2;
		}
	}

	if (cuvant == "")
	{
		for (int index = 0; index < m_finale.size(); index++)
		{
			if (stare == m_finale[index])
				return 0;
		}
		return 1;
	}

	bool conditieFinala = false;

	for (auto iterator : m_delta)
	{
		for (int index = 0; index < iterator.second.size(); index++)
		{
			std::queue<std::string> stariCurente;

			if (iterator.first == stare && iterator.second[index].first.front() == cuvant.front())
			{
				for (int index2 = 0; index2 < iterator.second.size(); index2++)
				{
					if (iterator.second[index2].first.front() == cuvant.front())
					{
						stariCurente.push(iterator.second[index2].second);
					}
				}
			}

			if (!stariCurente.empty())
			{
				if (stariCurente.front() == "-")
					return -1;

				std::string temp = cuvant;
				temp.erase(0, 1);
				bool conditie;

				while (!stariCurente.empty())
				{
					conditie = accepta(temp, stariCurente.front());
					stariCurente.pop();
				}

				if (conditie == false)
				{
					return 0;
				}

				if (conditie == true)
				{
					conditieFinala = true;
				}
			}
		}
	}

	if (conditieFinala == true)
	{
		return 1;
	}
	return -1;
}

std::string AFN::getStareInitiala()
{
	return m_stareInit;
}
