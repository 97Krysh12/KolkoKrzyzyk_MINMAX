#pragma once
//struktura przechowuje ruch 
struct Pole{
	int wiersz;
	int kolumna;
};

//nie dokonoczono. Struktura ta miala przechowywac gracza wykonujacego ruch
struct Gracz {
	char player;
	char PC;
};

class Gra
{
public:
	// Konstruktor i Destruktor
	Gra(char gracz);
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

	
	int minmax(char **plansza, int depth, char gracz, int bestValueMax, int bestValueMin); // algorytm minimax z alfa beta cieciami znajduje optymalny ruch
	int wygrana(char **, char gracz, int size); // sprawdza warunki konca gry i zwyciestwa
	Pole RuchPC(char **plansza, int size); // wykorzystuje alg. minmax do znalezienia optymalnego ruchu dla PC
	void makeRuch(char **plansza, int wiersz, int kolumna); // wpisuje symbol gracza w odpowiednie miejsce na planszy
	void ruchCzlowiek(char **plansza, int size); // umozliwia ruch czlowieka
	void Show(int size); // pokazuje plansze w konsoli
	void Ustawienia(); // umozliwia ustawienie wymiaru plaszny oraz ilosci wygrywajacych figur
	void menu(); // wyswietla menu startowe gry 
	void graczVsPC(); // odpowiada za przeprowadzenie rozgrywki gracz vs PC
	void graczVsGracz(); // odpowiada za przeprowadzenie rozgrywki miedzy 2 graczami
	
	bool isMove(char **plansza, int size); // sprawdza czy jest jeszcze jakies wolne pole do wykonania ruchu
	bool isKoniec(char **plansza); // sprawdza czy warunek zwyciestwa zostal spelniony i w takiej sytuacji zwraca komunikat o zwyciescy

private:
	 int size;
	int licznik; // inkrementowany po kazdym ruchu. kiedy osiagnie wartosc size*size oznacza to zapelnienie planszy
	char **plansza; 
	char gracz; // 'x' lub 'o'
	bool isMaxPlayer; // przyjmuje wartosc 1 jesli gracz maksymalizujacy. 0 jesli inaczej
	int zRzedu; 
};

