// KolkoKrzyzyk.cpp: definiuje punkt wejścia dla aplikacji konsolowej.
//

#include "stdafx.h"
#include "Gra.h"
#include <cstdlib>
#include <iostream>

using namespace std;

int main()
{
	Gra g1(3,'X');
	while (g1.getLicznik() != pow(g1.getSize(),2)) 
	{
		g1.ruch(g1.getPlansza(), g1.getGracz(), g1.getSize());
	}
	system("pause");
return 0;
}

