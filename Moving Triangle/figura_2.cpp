/*Tre�� zadania: 

Napisz program rysowania za pomoc� znaku ASCI poni�szej figury.
Program powinien umo�liwi�: 
- wybo�r znaku kodu ASCII;
- wczytanie pocz�tkowych rozmiar�w figury;
- przesuwanie figury klawiszami strza�ek;
- powi�kszanie oraz zmniejszanie rozmar�w figury za pomoc� klawiszy + i -;
- ograniczenie przesuwania i rozmiar�w figury do obszaru ekranu;
(rysunek tr�jk�ta)
       * 
      ***
     * * *
    *  *  *
   *   *   *
  *    *    * 
 *     *     * 
*      *      *
****************
UWAGA: Punkt zaczepienia znajduje si� w lewym dolnym naro�niku ekranu.
Zmiana rozmiar�w powinna odbywa� si� wzgl�dem punktu zaczepienia figury.

Autor i wykonanie: Szymon Miks PG ETI studia niestacjonarne I rok, I semestr, grupa 1
przedmiot: Praktyka Programowania
wyk�adowaca: dr in�. Olga Chore�                                             */
/* ------------------------------------------------------------------*/
#include "stdafx.h"
#include "Konsola.h" // wczytanie pliku nag��wkowego 
#include "Klasy.h" // wczytanie pliku nag��wkowego z klasami

using namespace std;

//Deklaracje funkcji---------------------------------------------------------
void tresc_zadania();
void wybor_start();
int wczytanie_kontrola_rozmiar_figury();
//---------------------------------------------------------------------------
int main()
{
	tresc_zadania();
	wybor_start();
	return 0;
}
//---------------------------------------------------------------------------

//Funkcje poza klas�
void tresc_zadania(){
	polskie_litery();
	gotoxy(0, 1);
	ustaw_kolor(12); //Tre�� zadania na ekranie powitalnym
	cout << "Tre�� zadania: " << endl
		<< "Napisz program rysowania za pomoc� znaku ASCI poni�szej figury" << endl
		<< "z zastosowaniem klas (tr�jk�t z wysoko�ci�)." << endl
		<< "// Ca�o�� tre�ci zadnaia w kodzie programu" << endl
		<< "Numer zadnia: 5." << endl
		<< endl;
	ustaw_kolor(15);
	cout << "Instrukcja obs�ugi programu: " << endl
		<< "1. Poruszanie figur� nast�puje za pomoc� naci�ni�cia klawiszy strza�ek" << endl
		<< "2. Powi�kszanie oraz zmniejszenie figury nast�puje za pomoc�" << endl
		<< "naci�ni�cia klawisza + i -" << endl
		<< "3. Program dzia�a dla standardowego rozmiaru konsoli 80x25" << endl
		<< "4. Aby zako�czy� dzia�anie programu naci�nij klawisz ESC" << endl
		<< endl;
	ustaw_kolor(11);
}
//---------------------------------------------------------------------------
void wybor_start(){ //Funkcja rozpoczynaj�ca program

	// Opcje wykonania programu
	char wybor;
	int rozmiar;
		ustaw_kolor(14);
		do {
			cout << "Wybierz opcj� wykonania programu: " << endl; //Menu do wybrania opcji uruchomienia programu
			cout << "1. Stw�rz figur� o predefiniowanych rozmiarach" << endl;
			cout << "2. Stw�rz figur� o w�asnych rozmiarach" << endl;
			cout << "3. Koniec programu" << endl;
			cout << "Wybor: " << endl;
			cin >> wybor;
			if (wybor == '1') {
				system("cls");
				Figura F(0, 24, ' ', 11); //Tworzy nowy obieky klasy figura z podanymi danymi
				F.start_programu();
				F.inicjuj();
				F.~Figura();
			}
			//---------------------------------------------------------------------------
			if (wybor == '2') {
				cout << "Podaj rozmiar figury (4-25): ";
				rozmiar = wczytanie_kontrola_rozmiar_figury();
				system("cls");
				Figura F(0, 24, ' ', rozmiar); //Tworzy nowy obieky klasy figura z danymi podanymi przez u�ytkownika
				F.start_programu();
				F.inicjuj();
				F.~Figura();
			}
			if (wybor == '3') {
				cout << endl
					<< "Ko�czenie dzia�ania pracy programu ..." << endl;
				cout << "Naci�ni�cie dowolnego klawisza spowoduje zamkni�cie programu";
				_getch();
				exit(0);
			}
		} while (wybor != '1' || wybor != '2' || wybor != '3');
		
}
//---------------------------------------------------------------------------
int wczytanie_kontrola_rozmiar_figury()
{
	int rozmiar, x, y;
	bool err;

	x = wherex();
	y = wherey();
	do
	{
		err = false;
		gotoxy(x, y);
		clreol();
		cin >> rozmiar;

		if (!cin.good())  // Zabezpieczenie przed wprowadzeniem niewlasciwego znaku
		{
			err = true;
			cin.clear();
			cin.ignore(80, '\n');
		}
	} while (rozmiar < 4 || rozmiar > 25 || err);
	return rozmiar;
}
//---------------------------------------------------------------------------
//Koniec funkcji poza klasami
