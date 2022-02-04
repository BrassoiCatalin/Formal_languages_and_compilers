#include "Gramatica.h"

Gramatica::Gramatica()
{
	/*empty*/
}

void Gramatica::citire()
{
	std::ifstream fin("Gramatica.txt");
	fin >> m_VN;
	fin >> m_VT;
	fin >> m_S;

	while (!fin.eof())
	{
		std::string temp;

		fin >> temp;
		m_P.productiiStanga.push_back(temp);

		fin >> temp;
		m_P.productiiDreapta.push_back(temp);
	}
	fin.close();
}

void Gramatica::verificare(bool& conditie)
{
	for (uint16_t index = 0; index < m_VN.length(); index++)//pentru intersectie intre terminale si neterminale
	{
		if (m_VT.find(m_VN[index]) != std::string::npos)
		{
			std::cout << "Conditia 1: s-a gasit o eroare la neterminale / terminale.\n\n";
			conditie = 0;
			return;
		}
	}


	if (m_VN.find("S") == std::string::npos)//S sa existe in neterminale
	{
		std::cout << "Conditia 2: S nu este in neterminale. \n\n";
		conditie = 0;
		return;
	}


	for (uint16_t index1 = 0; index1 < m_P.productiiStanga.size(); index1++)//in stanga productiilor sa se afle cel putin un neterminal
	{
		for (uint16_t index2 = 0; index2 < m_VN.length(); index2++)
		{
			if (m_P.productiiStanga[index1].find(m_VN[index2]) != std::string::npos)
			{
				break;
			}
			else
			{
				if (index2 == m_VN.length() - 1)
				{
					std::cout << "Conditia 3: s-a gasit o productie ce nu contine un neterminal.\n\n" << m_P.productiiStanga[index1] << '\n';
					conditie = 0;
					return;
				}
			}
		}
	}


	std::string temp;//sa nu existe in productii simboluri care nu se regasesc in terminale sau neterminale
	for (uint16_t index1 = 0; index1 < m_P.productiiStanga.size(); index1++)
	{
		std::string temp1 = m_P.productiiStanga[index1];
		for (uint16_t index2 = 0; index2 < temp1.length(); index2++)
		{
			temp.push_back(temp1[index2]);
		}

		temp1 = m_P.productiiDreapta[index1];
		for (uint16_t index2 = 0; index2 < temp1.length(); index2++)
		{
			temp.push_back(temp1[index2]);
		}
	}
	for (uint16_t index2 = 0; index2 < temp.length(); index2++)
	{
		if (m_VN.find(temp[index2]) == std::string::npos)
		{
			if (m_VT.find(temp[index2]) == std::string::npos)
			{
				std::cout << "Conditia 4: s-au gasit elemente ce nu apartin de VT sau VN.\n\n";
				conditie = 0;
				return;
			}
		}
	}

	bool verificareStart = false;
	for (uint16_t index = 0; index < m_P.productiiStanga.size(); index++)//sa existe cel putin o productie care in stanga sa aiba S
	{
		if (m_P.productiiStanga[index].find(m_S) != std::string::npos)
		{
			if (m_P.productiiStanga[index].size() == 1)
			{
				if(m_P.productiiStanga[index] == m_S)
				{
					return;
				}
			}
			
		}
	}
	if(!verificareStart)
	{
		conditie = 0;
		std::cout << "Conditia 5: nu exista nici macar o productie care in stanga sa aiba doar S.\n";
		return;
	}
}

void Gramatica::afisare()
{
	std::cout << "VN: ";
	for (uint16_t index = 0; index < m_VN.length(); index++)
	{
		if (index < m_VN.length() - 1)
			std::cout << m_VN[index] << ", ";
		else
			std::cout << m_VN[index] << ";";
	}
	std::cout << std::endl;


	std::cout << "VT: ";
	for (uint16_t index = 0; index < m_VT.length(); index++)
	{
		if (index < m_VT.length() - 1)
			std::cout << m_VT[index] << ", ";
		else
			std::cout << m_VT[index] << ";";
	}
	std::cout << std::endl;


	std::cout << "S: " << m_S << "\n\n";


	std::cout << "Productii: \n";
	for (uint16_t index = 0; index < m_P.productiiStanga.size(); index++)
	{
		//if (index < m_P.productiiStanga.size())
		std::cout << m_P.productiiStanga[index] << " => " << m_P.productiiDreapta[index] << '\n';
	}
	std::cout << '\n';

}

void Gramatica::generare(bool optiune)
{
	if (optiune == true)
	{
		std::cout << m_S;
		bool conditie = 1;

		while (conditie)
		{
			conditie = 1;
			std::vector<std::string> tempProductiiStanga, tempProductiiDreapta;

			for (uint16_t index = 0; index < m_P.productiiStanga.size(); index++)
			{
				if (m_S.find(m_P.productiiStanga[index]) != std::string::npos)
				{
					tempProductiiStanga.push_back(m_P.productiiStanga[index]);

					if (m_P.productiiDreapta[index] == "$")
						tempProductiiDreapta.push_back("");
					else
						tempProductiiDreapta.push_back(m_P.productiiDreapta[index]);
				}
			}

			if (tempProductiiStanga.size() == 0)
			{
				for (uint16_t index = 0; index < m_S.length(); index++)
				{
					if (m_VN.find(m_S[index]) != std::string::npos)
					{
						std::cout << "\nEroare, cuvantul este format si din neterminale.";
						break;
					}
				}

				m_S = 'S';
				return;
			}

			else
				std::cout << "=>";

			std::random_device randomDevice;
			std::mt19937 generator(randomDevice());
			std::uniform_int_distribution<std::mt19937::result_type> index(0, tempProductiiStanga.size() - 1);

			uint16_t rand = index(generator);
			uint16_t pos = m_S.find(tempProductiiStanga[rand]);

			m_S.replace(pos, tempProductiiStanga[rand].length(), tempProductiiDreapta[rand]);
			std::cout << m_S;
		}
	}
	else
	{
		std::cout << m_S;
		bool conditie = 1;

		while (conditie)
		{
			conditie = 1;
			std::vector<std::string> tempProductiiStanga, tempProductiiDreapta;

			for (uint16_t index = 0; index < m_P.productiiStanga.size(); index++)
			{
				if (m_S.find(m_P.productiiStanga[index]) != std::string::npos)
				{
					tempProductiiStanga.push_back(m_P.productiiStanga[index]);

					if (m_P.productiiDreapta[index] == "$")
						tempProductiiDreapta.push_back("");
					else
						tempProductiiDreapta.push_back(m_P.productiiDreapta[index]);
				}
			}
			if (tempProductiiStanga.size() == 0)
			{
				for (uint16_t index = 0; index < m_S.length(); index++)
					if (m_VN.find(m_S[index]) != std::string::npos)//verifica daca m_S e format si din neterminale
					{
						std::cout << "Eroare, cuvantul este format si din neterminale.";
						break;
					}
				std::cout << "=>" << m_S;
				m_S = 'S';
				return;
			}
			std::random_device randomDevice;
			std::mt19937 generator(randomDevice());
			std::uniform_int_distribution<std::mt19937::result_type> index(0, tempProductiiStanga.size() - 1);

			uint16_t rand = index(generator);
			uint16_t pos = m_S.find(tempProductiiStanga[rand]);

			m_S.replace(pos, tempProductiiStanga[rand].length(), tempProductiiDreapta[rand]);

		}

	}
}
