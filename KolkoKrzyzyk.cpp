// KolkoKrzyzyk.cpp: definiuje punkt wejścia dla aplikacji konsolowej.
//

#include "stdafx.h"
#include "Gra.h"
#include <cstdlib>
#include <iostream>
#include <stdlib.h>
#include <conio.h>

using namespace std;

int main()
{
	system("color 5B");
	int wybor = 0;
	bool playAgain = true;

	while (playAgain) {
		Gra *nowaGra = new Gra('X');
		nowaGra->menu();
		cin >> wybor;
		switch (wybor) {
		case 1: { nowaGra->graczVsGracz(); break; }
		case 2: { nowaGra->graczVsPC(); break; }
		default: break;
			delete nowaGra;
		}

		cout << "\nczy chcialbys zagrac jescze raz? :\n";
		cout << "1.tak \n";
		cout << "0.nie \n wybierz: ";
		cin >> playAgain;
		
		system("cls");
	}
	cout << endl;
	system("pause");
return 0;
}

