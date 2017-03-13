#include "stdafx.h"
#include "Konsola.h"
#include "Klasy.h"

using namespace std;

void Punkt::Rysuj_punkt()
{
	gotoxy(x, y);
	cout << znak;
}
//----------------------------------------------------------------
void Odcinek::rysuj_podstawe(int x, int y, int wielkosc, char znak)  // funkcja rysuj¹ca podstawê mojego trójk¹ta
{
	gotoxy(x, y);
	int dlugosc_podst = wielkosc * 2 - 1; // d³ugoœæ podstawy zawsze nie parzysta w celu poprawnego narysowania trójk¹ta i jego wysokoœæi która zawsze dziêki temu bêdzie na œrodku odcinka
	for (int i = 0; i<dlugosc_podst; i++)
	if (i % 2 == 0)
		cout << znak;
	else
		cout << " ";
}
//----------------------------------------------------------------
void Odcinek::rysuj_wysokosc(int x, int y, int wielkosc, char znak) // rysowanie wysokoœci
{
	for (int i = 0; i<wielkosc; i++)
	{
		gotoxy(x, y + i);
		cout << znak;
	}
}
//----------------------------------------------------------------
void Odcinek::rysuj_ramiona(int x, int y, int wielkosc, char znak) // rysowanie ramion
{
	//lewe ramie
	for (int i = 0; i<wielkosc; i++)
	{
		gotoxy(x - i, y + i);
		cout << znak;
	}

	//prawe ramie
	for (int i = 0; i<wielkosc; i++)
	{
		gotoxy(x + i, y + i);
		cout << znak;
	}
}
//----------------------------------------------------------------
void Figura::rysuj()  //funkcja rysuj¹ca ca³y trój¹t tzm. podstawê, ramiona i wyskoœæ
{
	system("cls");
	rysuj_podstawe(x, y, wielkosc, znak);
	rysuj_wysokosc(x + wielkosc - 1, y - wielkosc + 1, wielkosc, znak); //wysokoœæ od górnego wierzcho³ka, schodzca w dól
	rysuj_ramiona(x + wielkosc - 1, y - wielkosc + 1, wielkosc, znak); //ramiona od górnego wierzcho³ka, schodz¹ce w dól
}
//---------------------------------------------------------------------------
void Figura::sprawdz() // funkcja zabezpieczaj¹ca przed wyjœciem figury poza obszar okna konsoli dla standardowego rozmiaru podanego na wyk³adzie tj. 80x25
{
	if (wielkosc < 1)
		wielkosc = 1;
	else if (wielkosc > 25)
		wielkosc = 25;

	if (y < wielkosc - 1)
		y++;
	else if (y > 24)
		y = 24;

	if (x < 0)
		x = 0;
	else if (x + wielkosc * 2 > 81)
		x = 81 - wielkosc * 2;
}
//---------------------------------------------------------------------------
void Figura::inicjuj()
{
	const int Esq = 27; // deklaracja zmiennej o wartoœci znaku ASCI klawisza ESC pozwalaj¹cego na zakoñczenie dzia³ania programu
	HideCursor(); // ukrycie kursora w oknie konsoli
	do
	{
		rysuj(); // wywo³anie funkcji rysuj¹cej ca³y trójkat

		// Switch umo¿liwiaj¹cy poruszanie figur¹ strza³kami oraz powiekszanie i zmniejszanie rozmiarów figury
		klawisz = _getch();
		switch (klawisz)
		{
		case '+':
		{
					wielkosc++;
					break;
		}
		case '-':
		{

					if (wielkosc <= 4) { //warunek chroni¹cy przed zmniejszeniem trójk¹ta do zbyt ma³ych rozmiarów
						wielkosc = 4;
					}
					else {
						wielkosc--;
					}
					break;
		}
		case Esq:
		{
					break;
		}     // wyjscie
		case 224:
		{
					klawisz = _getch();
					switch (klawisz)
					{
					case 72: //strza³ka w góre
					{
								 y--;
								 break;
					}
					case 80: //strza³ka w dó³
					{
								 y++;
								 break;
					}
					case 75: //strza³ka w lewo
					{
								 x--;
								 break;
					}
					case 77: //strza³ka w prawo
					{
								 x++;
								 break;
					}
					}
		}
		}

		sprawdz(); // wywo³anie funkcji zabezpieczaj¹cej przed wyjœciem figury poza rozmiar okna
	} while (klawisz != Esq);
	ShowCursor();
}
//---------------------------------------------------------------------------
void Figura::start_programu(){
	polskie_litery(); //wywo³anie funkcji umo¿liwiaj¹cej wyœwietlanie polskich znaków
	gotoxy(22, 12);
	ustaw_kolor(14);
	cout << "Podaj znak z którego chcesz narysowaæ figurê" << endl;
	cin >> znak;
	cout << "Naciœnij dowolny klawisz aby rozpocz¹æ rysowanie figury";
	_getch();
}
//---------------------------------------------------------------------------