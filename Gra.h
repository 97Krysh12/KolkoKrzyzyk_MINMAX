#pragma once
class Gra
{
public:
	Gra(int size, char gracz);
	~Gra();
	void setSize(int size);
	void setGracz(char gracz);
	void setLicznik(int licznik);

	int getLicznik();
	int getSize();
	char getGracz();
	char **getPlansza();
	void ruch(char **plansza, char gracz, int size);
	void Show(int size);

	bool wygrana(char **, char gracz, int size);
	

private:
	int size;
	int licznik;
	char **plansza;
	char gracz;
};

