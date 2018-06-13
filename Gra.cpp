#include "stdafx.h"
#include "Gra.h"
#include <iostream>
#include <stdlib.h>
#include <algorithm>

using namespace std;

Gra::Gra(char gracz)
{
	Ustawienia();
	setGracz(gracz);
	setLicznik(0);
	this->plansza = new char*[size];

	for (int i = 0; i < size; i++)
	{
		plansza[i] = new char[size];

	}
	
	cout << "    ";
	for (int a = 0; a < size; a++) {
		cout << a << ".   ";
	}
	for (int i = 0; i < size; i++)  // Rysuje pusta plansze
	{
		
		
		
		cout << endl;
		cout << i << ". ";
		for (int j = 0; j < size; j++) {
			plansza[i][j] = '-';
			cout << "|" << plansza[i][j] << " | " ;
		}
		
	}
}

Gra::~Gra()
{
	for (int i = 0; i < size; i++)
	{
		delete plansza[i];

	}
	delete []plansza; 
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
	int licznik_K = 0, licznik_W = 0;
	int i = 0, j = 0;

	// Zmienna przyjmuje true, jeśli zawodnik ma wybrana ilosc  figur
    // w wierszu, kolumnie lub na przekątnych


	 // Sprawdzamy wiersze
	while (i != size || j != size) {
		for (i = licznik_W; i < zRzedu + licznik_W; i++) {

			for (j = licznik_K; j < zRzedu + licznik_K; j++) {

				if (plansza[i][j] != gracz) { j = zRzedu + licznik_K; test = false; break; }

				else test = true;
			}
			


			if (test == true && gracz == 'X') return 10;
			else if (test == true && gracz == 'O') return -10;
		}
		licznik_W++;
		if (i == size) {
			licznik_W = 0;
			licznik_K++;
		}

	}
	licznik_K = 0;
	licznik_W = 0;
	i = 0;
	j = 0;

	// Sprawdzamy kolumny  
	while (i != size || j != size) {
		for (i = 0; i < size; i++) { 

			for (j = licznik_K; j < zRzedu + licznik_K; j++) { 
				if (plansza[j][i] != gracz) { j = zRzedu + licznik_K;  test = false; break; } 
				else test = true;
			}
			if (test == true && gracz == 'X') return 10;
			else if (test == true && gracz == 'O') return -10;

		}

		licznik_K++;
	}



	licznik_K = 0;
	licznik_W = 0;
	i = 0;
	j = 0;

	// Sprawdzamy przekątną lewo-prawo
	while (i != size || j != size) {
		j = licznik_W;
		for (i = licznik_K; i < zRzedu + licznik_K; i++) {

			if (plansza[j][i] != gracz) { i = zRzedu + licznik_K; j = licznik_W + zRzedu; test = false; break; }
			else test = true;
			j++;

		}
		if (test == true && gracz == 'X') return 10;
		else if (test == true && gracz == 'O') return -10;

		licznik_K++;
		if (i == size) {
			licznik_W++;
			licznik_K = 0;
		}

	}
	licznik_K = 0;
	licznik_W = 0;
	i = 0;
	j = 0;

	// Sprawdzamy przekątną prawo- lewo
	while (i != -1 || j != size) {
		j = licznik_W;
		for (i = size - 1 - licznik_K; i > size - 1 - licznik_K - zRzedu; i--) {
			 
			if (plansza[j][i] != gracz) { i = size - 1 - licznik_K - zRzedu; j = licznik_W + zRzedu ; test = false; break; }
			else test = true;
			j++;
		}
		if (test == true && gracz == 'X') return 10;
		else if (test == true && gracz == 'O') return -10;

		licznik_K++;
		if (i == -1) {
			licznik_W++;
			licznik_K = 0;
		}
		
	}
	if (!isMove(plansza, size)) return 0;
	else if (gracz == 'X') return 5;
	else return -5;
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
	setLicznik(getLicznik() + 1);
	if(isKoniec(plansza)) return;
	this->gracz = (this->gracz == 'O') ? 'X' : 'O';
}

void Gra::ruchCzlowiek(char ** plansza, int size)
{
	int RuchX, RuchY;
	
	
	do {
		cout << "Kolej na ruch gracza " << this->gracz << endl;
		cout << "Podaj wiersz oraz kolumne ruchu (W,K) : ";
		do {
			cin >> RuchY >> RuchX;
			if (RuchY > size - 1 || RuchX > size - 1) cout << "Pole wpisane niepoprawnie. Sprobuje ponownie \n";
			else break;
		} while (true);
		
		
		if (plansza[RuchY][RuchX] != '-') cout << "Pole juz Zajete. Sprobuj ponownie \n";
	} while (plansza[RuchY][RuchX] != '-');
	

	

	makeRuch(plansza, RuchY, RuchX);
	
	
}

void Gra::Show(int size)
{
	system("cls");
	cout << "    ";
	for (int a = 0; a < size; a++) {
		cout << a << ".   ";

	}
	for (int i = 0; i < size; i++) {			
		cout << endl;
		cout << i << ". ";

		for (int j = 0; j < size; j++) { cout << "|" << plansza[i][j] << " | "; }
	}
	cout << "\n\n\n";
}

void Gra::Ustawienia()
{
	int wymiar, zRzedu;
	cout << "Podaj wymiar planszy: ";
	cin >> wymiar;
	cout << "ile znakow z rzedu wygrywa: ";
	cin >> zRzedu;
	this->size = wymiar;
	this->zRzedu = zRzedu;
}

void Gra::menu()
{
	cout << "\n KOLKO I KRZYZYK \n";
	cout << "1. gracz vs gracz \n";
	cout << "2. gracz vs PC \n";
}

void Gra::graczVsPC()
{
	cout << "KTO ZACZYNA ? \n";
	cout << "1.gracz \n";
	cout << "2. PC \n";
	cout << "wybierz : ";
	int wybor = 0;
	cin >> wybor;
	switch (wybor) {
	case 1: {
		Show(size);
		while (isMove(plansza, size))
		{
			if (!isMove(plansza, size)) break;
			if (wygrana(plansza, 'X', size) == 10) break;
			if (wygrana(plansza, 'O', size) == -10) break;

			ruchCzlowiek(plansza, size);
			RuchPC(plansza, size);
		}
		break;
	}
	case 2: {
		while (isMove(plansza, size))
		{
			RuchPC(plansza, size);

			if (!isMove(plansza, size)) break;
			if (wygrana(plansza, 'X', size) == 10) break;
			if (wygrana(plansza, 'O', size) == -10) break;

			ruchCzlowiek(plansza, size);
		}
		break;
	}
	default: break;
	}
}
	

void Gra::graczVsGracz()
{
	Show(size);
	while (isMove(plansza, size))
	{
		if (wygrana(plansza, 'X', size) == 10) break;
		if (wygrana(plansza, 'O', size) == -10) break;

		ruchCzlowiek(plansza, size);
	}
}

int Gra::minmax(char ** plansza, int depth, char gracz, int alfa, int beta)
{
	
	int value = 0;
	int score = wygrana(plansza, gracz, this->size);

	if (score == 10) return score - depth;
	if (score == -10) return score + depth;

	if (gracz == 'X' && score == 0) return score + depth;
	if (gracz == 'O' && score == 0) return score - depth;

	if (gracz == 'X' && size > 3 && depth == 5) return score ; 
	if (gracz == 'O' && size > 3 && depth == 5) return score;
	
	 //if maximizer
	if (gracz == 'X') {
		
		for (int i = 0; i < this->size; i++) {
			for (int j = 0; j < this->size; j++) {
				if (plansza[i][j] == '-') {
					plansza[i][j] = 'X';
					value = minmax(plansza, depth + 1, 'O', alfa, beta);
					if(value > alfa) alfa = value;
					plansza[i][j] = '-';
					if (alfa >= beta) return alfa;
				}
				
			}
			if (alfa >= beta) return alfa;
		}
		return alfa;
	}
	// if minimizer
	else if (gracz == 'O') {
		
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++) {
				if (plansza[i][j] == '-') {
					plansza[i][j] = 'O';
					value = minmax(plansza, depth + 1, 'X', alfa, beta);
					if (value < beta) beta = value;
					plansza[i][j] = '-';
					
				}
				
			}
			if (alfa >= beta) return beta;
		}
		return beta;
	}
}

bool Gra::isKoniec(char ** plansza)
{
	int score = wygrana(plansza, this->gracz, size);
	Show(size);
	if (score == 10) { cout << "koniec gry" << endl << "WYGRAl GRACZ 'X'"; return 1; }
	else if (score == -10) { cout << "koniec gry" << endl << "WYGRAl GRACZ 'O'"; return 1; }
	else if (this->licznik == size * size) cout << "koniec gry" << endl << "REMIS!!! ";
	else return 0;
}

Pole Gra::RuchPC(char ** plansza, int size)
{
	int bestValue = 10000;
	
	Pole bestMove;
	bestMove.wiersz = -1;
	bestMove.kolumna = -1;
	if (gracz == 'O') {
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++) {
				if (plansza[i][j] == '-') {
					plansza[i][j] = gracz;
					int value = minmax(plansza, 0, 'X', -1000, 1000);
					plansza[i][j] = '-';
					if (value < bestValue) {
						bestValue = value;
						bestMove.wiersz = i;
						bestMove.kolumna = j;
					}
				}
			}
		}
	}
	bestValue = -10000;
	 if (gracz == 'X') {
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++) {
				if (plansza[i][j] == '-') {
					plansza[i][j] = gracz;
					int value = minmax(plansza, 0, 'O', -1000, 1000);
					plansza[i][j] = '-';
					if (value > bestValue) {
						bestValue = value;
						bestMove.wiersz = i;
						bestMove.kolumna = j;
					}
				}
			}
		}
	}
	makeRuch(plansza, bestMove.wiersz, bestMove.kolumna); 
	return bestMove;
}
