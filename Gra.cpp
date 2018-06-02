#include "stdafx.h"
#include "Gra.h"
#include <iostream>
#include <stdlib.h>
#include <algorithm>

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

void Gra::setIsMaxPlayer(bool isMaxPlayer)
{
	this->isMaxPlayer = isMaxPlayer;
}

bool Gra::getIsMaxPlayer()
{
	return this->isMaxPlayer;
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

int Gra::wygrana(char **plansza, char gracz, int size) // dla gracza 'X' zwraca 10. dla 'O' zwraca -10
{
	bool test = true;
	int i, j;

	// Zmienna przyjmuje true, jeśli zawodnik ma trzy figury
				 // w wierszu, kolumnie lub na przekątnych

				 // Sprawdzamy wiersze

	for (i = 0; i < size; i++) {
		for (j = 0; j < size; j++) {
			if (plansza[i][j] != gracz) { test = false; break; }

			else test = true;
		}
		if (test  == true && gracz == 'X') return 10;
		else if (test == true && gracz == 'O') return -10;
	}

	// Sprawdzamy kolumny  

	for (i = 0; i < size; i++) {
		for (j = 0; j < size; j++) {
			if (plansza[j][i] != gracz) { test = false; break; }
			else test = true;
		}
		if (test == true && gracz == 'X') return 10;
		else if (test == true && gracz == 'O') return -10;

	}

	// Sprawdzamy przekątną lewo-prawo
	for (i = 0; i < size; i++) {
		if (plansza[i][i] != gracz) { test = false; break; }
		else test = true;
	}
	if (test == true && gracz == 'X') return 10;
	else if (test == true && gracz == 'O') return -10;



	// Sprawdzamy przekątną prawo- lewo
	for (i = size - 1; i >= 0; i--) {

		if (plansza[i][i] != gracz) { test = false; break; }
		else test = true;
	}
	if (test == true && gracz == 'X') return 10;
	else if (test == true && gracz == 'O') return -10;
	
	if (!isMove(plansza, size)) return 0;
}

bool Gra::isMove(char ** plansza, int size)
{
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (plansza[i][j] == '-') return true;
		}
	}
	return false;
}

void Gra::makeRuch(char **plansza, int wiersz, int kolumna)
{
	if (!isMove(plansza, size)) return;
	plansza[wiersz][kolumna] = this->gracz;
	int score = wygrana(plansza, this->gracz, size);
	Show(size);
	if ( score == 10) cout << "koniec gry" << endl << "WYGRAl GRACZ X'";
	else if(score == -10) cout << "koniec gry" << endl << "WYGRAl GRACZ O'";
	setLicznik(getLicznik() + 1);
	if (this->licznik == size*size) cout << "koniec gry" << endl << "REMIS!!! '" << this->gracz << "'";
	this->gracz = (this->gracz == 'O') ? 'X' : 'O';
	setGracz(this->gracz);
}

void Gra::ruchCzlowiek(char ** plansza, int size)
{
	int RuchX, RuchY;
	
	cout << "Kolej na ruch gracza " << this->gracz << endl;
	cout << "Podaj wiersz oraz kolumne ruchu (W,K) : ";
	cin >> RuchY >> RuchX;
	//plansza[RuchY][RuchX] = gracz;

	makeRuch(plansza, RuchY, RuchX);
	
	
}

void Gra::Show(int size)
{
	//system("cls");
	for (int i = 0; i < size; i++) {			
		cout << endl;
		for (int j = 0; j < size; j++) { cout << plansza[i][j] << " | "; }
	}
	cout << "\n\n\n";
}

int Gra::minmax(char ** plansza, int depth, char gracz)
{
	//TODO zamien bool wygrana na int wygrana, zeby tu mozna bylo sprawdzac czy koniec gry dla wartosci ruchow +10/-10
	int value = 0;
	int score = wygrana(plansza, gracz, this->size);

	if (score == 10) return score;
	if (score == -10) return score;
	if(score == 0) return score;

	if (gracz == 'X') {
		int bestValue = -100;

		for (int i = 0; i < this->size; i++) {
			for (int j = 0; j < this->size; j++) {
				if (plansza[i][j] == '-') {
					plansza[i][j] = 'X';
					value = minmax(plansza, depth + 1, 'O');
					bestValue = max(bestValue, value);
					plansza[i][j] = '-';
				}
			}
		}
		return bestValue;
	}
	else if (gracz == 'O') {
		int bestValue = 100;

		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++) {
				if (plansza[i][j] == '-') {
					plansza[i][j] = 'O';
					value = minmax(plansza, depth + 1, 'X');
					bestValue = min(bestValue, value);
					plansza[i][j] = '-';
				}
			}
		}
		return bestValue;
	}
}

Pole Gra::RuchPC(char ** plansza, int size)
{
	int bestValue = 1000;
	Pole bestMove;
	bestMove.wiersz = -1;
	bestMove.kolumna = -1;

	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (plansza[i][j] == '-') {
				plansza[i][j] = this->gracz;
				int value = minmax(plansza, 0, 'X');
				plansza[i][j] = '-';
				if (value < bestValue) {
					bestValue = value;
					bestMove.wiersz = i;
					bestMove.kolumna = j;
				}
			}
		}
	}

	makeRuch(plansza, bestMove.wiersz, bestMove.kolumna); //TODO upakowac dwie linie ponizej do funkcji makeRuch
	return bestMove;
}
