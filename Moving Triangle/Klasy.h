#ifndef Klasy
#define Klasy

using namespace std;

//----------------------------------------------------------------
class Punkt
{
protected:
	int x, y;
	int wielkosc;
	char znak;
	void Rysuj_punkt();
public:
	Punkt(int _x, int _y, char _znak, int _wielkosc) : x(_x), y(_y), znak(_znak), wielkosc(_wielkosc)
	{
	}
	~Punkt() { cout << "\n\nLikwiduje obiekt klasy Punkt\n"; };
};
//----------------------------------------------------------------
class Odcinek : public Punkt
{
protected:
	void rysuj_podstawe(int x, int y, int wielkosc, char znak);
	void rysuj_wysokosc(int x, int y, int wielkosc, char znak);
	void rysuj_ramiona(int x, int y, int wielkosc, char znak);
public:
	Odcinek(int _x, int _y, char _znak, int _wielkosc) :Punkt(_x, _y, _znak, _wielkosc)
	{
	}
	~Odcinek() { cout << "\n\nLikwiduje obiekt klasy Odcinek\n"; };
};
//----------------------------------------------------------------
class Figura : public Odcinek
{
public:
	unsigned char klawisz;
	void rysuj();
	void sprawdz();
	void start_programu();
	void inicjuj();
	Figura(int _x, int _y, char _znak, int _wielkosc) : Odcinek(_x, _y, _znak, _wielkosc)
	{
	}
	~Figura() { cout << "\n\nLikwiduje obiekt klasy Figura\n"; };
};
//---------------------------------------------------------------------------
#endif