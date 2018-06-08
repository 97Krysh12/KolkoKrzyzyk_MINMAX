// KolkoKrzyzyk.cpp: definiuje punkt wejścia dla aplikacji konsolowej.
//

#include "stdafx.h"
#include "Gra.h"
#include <cstdlib>
#include <iostream>

using namespace std;

int main()
{
	Gra g1('X'); /////////DO TESTOW NA RAZIE 'X' TO CZLOWIEK i 'O' TO PC
	while (g1.isMove(g1.getPlansza(), g1.getSize()))
	{
		if (g1.wygrana(g1.getPlansza(), 'X', g1.getSize()) == 10) break;
		if(g1.wygrana(g1.getPlansza(), 'O', g1.getSize()) == -10) break;
		
		g1.ruchCzlowiek(g1.getPlansza(), g1.getSize());
		
		//g1.RuchPC(g1.getPlansza(), g1.getSize());
	}
	cout << endl;
	system("pause");
return 0;
}

