#include "stdafx.h"
#include "Gra.h"
#include <iostream>
#include <stdlib.h>

using namespace std;

Gra::Gra(int size, char gracz)
{
	setSize(size);
	setGracz(gracz);
	setLicznik(0);
	this->plansza = new char*[size];

	for (int i = 0; i < size; i++)
	{
		plansza[i] = new char[size];

	}

	for (int i = 0; i < size; i++)  // Rysuje pusta plansze
	{
		cout << endl;
		for (int j = 0; j < size; j++) {
			plansza[i][j] = '-';
			cout << plansza[i][j] << " | ";
		}
	}
}

Gra::~Gra()
{
	delete plansza; 
}

void Gra::setSize(int size)
{	
	this->size = size;
}

void Gra::setGracz(char gracz)
{
	this->gracz = gracz;
}

void Gra::setLicznik(int licznik)
{
	this->licznik = licznik;
}

int Gra::getLicznik()
{
	return this->licznik;
}

int Gra::getSize()
{
	return this->size;
}

char Gra::getGracz()
{
	return this->gracz;
}

char ** Gra::getPlansza()
{
	return this->plansza;
}

bool Gra::wygrana(char **plansza, char gracz, int size)
{
	bool test = false;
	int i, j;

	// Zmienna przyjmuje true, jeœli zawodnik ma trzy figury
				 // w wierszu, kolumnie lub na przek¹tnych

				 // Sprawdzamy wiersze

	for (i = 0; i < size; i++) {
		for (j = 0; j < size; j++) {
			if (plansza[i][j] != gracz) { test = false; break; }

			else test = true;
		}
		if (test) return 1;
	}

	// Sprawdzamy kolumny  

	for (i = 0; i < size; i++) {
		for (j = 0; j < size; j++) {
			if (plansza[j][i] != gracz) { test = false; break; }
			else test = true;
		}
		if (test) return 1;

	}

	// Sprawdzamy przek¹tn¹ lewo-prawo
	for (i = 0; i < size; i++) {
		if (plansza[i][i] != gracz) { test = false; break; }
		else test = true;
	}
	if (test) return 1;



	// Sprawdzamy przek¹tn¹ prawo- lewo
	for (i = size - 1; i >= 0; i--) {

		if (plansza[i][i] != gracz) { test = false; break; }
		else test = true;
	}
	if (test) return 1;

	return 0;
}

void Gra::ruch(char ** plansza, char gracz, int size)
{
	int RuchX, RuchY, licznik;
	gracz = (gracz == 'X') ? 'O' : 'X';
	setGracz(gracz);
	cout << "Kolej na ruch gracza " << gracz << endl;
	cout << "Podaj wiersz oraz kolumne ruchu (W,K) : ";
	cin >> RuchY >> RuchX;
	plansza[RuchY][RuchX] = gracz;
	if (wygrana(plansza, gracz, size) == 1) cout << "koniec gry" << endl << "WYGRAl GRACZ '" << gracz << "'";
	setLicznik(getLicznik()+1);
	Show(size);
	
}

void Gra::Show(int size)
{
	system("cls");
	for (int i = 0; i < size; i++) {			
		cout << endl;
		for (int j = 0; j < size; j++) { cout << plansza[i][j] << " | "; }
	}

}
