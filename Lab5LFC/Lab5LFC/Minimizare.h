#pragma once
#include <iostream>
#include "AFD.h"

class Minimizare
{
private:
	std::vector<std::vector<int>> m_tabel;
	

public:
	void minimizare(AFD& automat);
};

