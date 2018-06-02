#pragma once
struct Pole{
	int wiersz;
	int kolumna;
};
struct Gracz {
	char player;
	char PC;
};

class Gra
{
public:
	// Konstruktor i Destruktor
	Gra(int size, char gracz);
	~Gra();

	// Settery
	void setSize(int size);
	void setGracz(char gracz);
	void setLicznik(int licznik);
	void setIsMaxPlayer(bool isMaxPlayer);
	
	// Gettery
	bool getIsMaxPlayer();
	int getLicznik();
	int getSize();
	char getGracz();
	char **getPlansza();

	
	int minmax(char **plansza, int depth, char gracz); // algorytm minimax znajduje optymalny ruch

	Pole RuchPC(char **plansza, int size); // wykorzystuje alg. minmax do znalezienia optymalnego ruchu PC
	void makeRuch(char **plansza, int wiersz, int kolumna); // wpisuje symbol gracza w odpowiednie miejsce na planszy
	void ruchCzlowiek(char **plansza, int size); // umozliwia ruch czlowieka
	void Show(int size); // pokazuje plansze w konsoli

	int wygrana(char **, char gracz, int size); // sprawdza warunki konca gry i zwyciestwa
	bool isMove(char **plansza, int size);

private:
	 int size;
	int licznik; // inkrementowany po kazdym ruchu. kiedy osiagnie wartosc size*size oznacza to zapelnienie planszy
	char **plansza; 
	char gracz; // 'x' lub 'o' 
	bool isMaxPlayer; // przyjmuje wartosc 1 jesli gracz maksymalizujacy. 0 jesli inaczej
};

