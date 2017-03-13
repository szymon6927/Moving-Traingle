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
void Odcinek::rysuj_podstawe(int x, int y, int wielkosc, char znak)  // funkcja rysuj�ca podstaw� mojego tr�jk�ta
{
	gotoxy(x, y);
	int dlugosc_podst = wielkosc * 2 - 1; // d�ugo�� podstawy zawsze nie parzysta w celu poprawnego narysowania tr�jk�ta i jego wysoko��i kt�ra zawsze dzi�ki temu b�dzie na �rodku odcinka
	for (int i = 0; i<dlugosc_podst; i++)
	if (i % 2 == 0)
		cout << znak;
	else
		cout << " ";
}
//----------------------------------------------------------------
void Odcinek::rysuj_wysokosc(int x, int y, int wielkosc, char znak) // rysowanie wysoko�ci
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
void Figura::rysuj()  //funkcja rysuj�ca ca�y tr�j�t tzm. podstaw�, ramiona i wysko��
{
	system("cls");
	rysuj_podstawe(x, y, wielkosc, znak);
	rysuj_wysokosc(x + wielkosc - 1, y - wielkosc + 1, wielkosc, znak); //wysoko�� od g�rnego wierzcho�ka, schodzca w d�l
	rysuj_ramiona(x + wielkosc - 1, y - wielkosc + 1, wielkosc, znak); //ramiona od g�rnego wierzcho�ka, schodz�ce w d�l
}
//---------------------------------------------------------------------------
void Figura::sprawdz() // funkcja zabezpieczaj�ca przed wyj�ciem figury poza obszar okna konsoli dla standardowego rozmiaru podanego na wyk�adzie tj. 80x25
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
	const int Esq = 27; // deklaracja zmiennej o warto�ci znaku ASCI klawisza ESC pozwalaj�cego na zako�czenie dzia�ania programu
	HideCursor(); // ukrycie kursora w oknie konsoli
	do
	{
		rysuj(); // wywo�anie funkcji rysuj�cej ca�y tr�jkat

		// Switch umo�liwiaj�cy poruszanie figur� strza�kami oraz powiekszanie i zmniejszanie rozmiar�w figury
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

					if (wielkosc <= 4) { //warunek chroni�cy przed zmniejszeniem tr�jk�ta do zbyt ma�ych rozmiar�w
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
					case 72: //strza�ka w g�re
					{
								 y--;
								 break;
					}
					case 80: //strza�ka w d�
					{
								 y++;
								 break;
					}
					case 75: //strza�ka w lewo
					{
								 x--;
								 break;
					}
					case 77: //strza�ka w prawo
					{
								 x++;
								 break;
					}
					}
		}
		}

		sprawdz(); // wywo�anie funkcji zabezpieczaj�cej przed wyj�ciem figury poza rozmiar okna
	} while (klawisz != Esq);
	ShowCursor();
}
//---------------------------------------------------------------------------
void Figura::start_programu(){
	polskie_litery(); //wywo�anie funkcji umo�liwiaj�cej wy�wietlanie polskich znak�w
	gotoxy(22, 12);
	ustaw_kolor(14);
	cout << "Podaj znak z kt�rego chcesz narysowa� figur�" << endl;
	cin >> znak;
	cout << "Naci�nij dowolny klawisz aby rozpocz�� rysowanie figury";
	_getch();
}
//---------------------------------------------------------------------------