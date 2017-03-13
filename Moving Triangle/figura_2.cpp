/*Treœæ zadania: 

Napisz program rysowania za pomoc¹ znaku ASCI poni¿szej figury.
Program powinien umo¿liwiæ: 
- wyboór znaku kodu ASCII;
- wczytanie pocz¹tkowych rozmiarów figury;
- przesuwanie figury klawiszami strza³ek;
- powiêkszanie oraz zmniejszanie rozmarów figury za pomoc¹ klawiszy + i -;
- ograniczenie przesuwania i rozmiarów figury do obszaru ekranu;
(rysunek trójk¹ta)
       * 
      ***
     * * *
    *  *  *
   *   *   *
  *    *    * 
 *     *     * 
*      *      *
****************
UWAGA: Punkt zaczepienia znajduje siê w lewym dolnym naro¿niku ekranu.
Zmiana rozmiarów powinna odbywaæ siê wzglêdem punktu zaczepienia figury.

Autor i wykonanie: Szymon Miks PG ETI studia niestacjonarne I rok, I semestr, grupa 1
przedmiot: Praktyka Programowania
wyk³adowaca: dr in¿. Olga Choreñ                                             */
/* ------------------------------------------------------------------*/
#include "stdafx.h"
#include "Konsola.h" // wczytanie pliku nag³ówkowego 
#include "Klasy.h" // wczytanie pliku nag³ówkowego z klasami

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

//Funkcje poza klas¹
void tresc_zadania(){
	polskie_litery();
	gotoxy(0, 1);
	ustaw_kolor(12); //Treœæ zadania na ekranie powitalnym
	cout << "Treœæ zadania: " << endl
		<< "Napisz program rysowania za pomoc¹ znaku ASCI poni¿szej figury" << endl
		<< "z zastosowaniem klas (trójk¹t z wysokoœci¹)." << endl
		<< "// Ca³oœæ treœci zadnaia w kodzie programu" << endl
		<< "Numer zadnia: 5." << endl
		<< endl;
	ustaw_kolor(15);
	cout << "Instrukcja obs³ugi programu: " << endl
		<< "1. Poruszanie figur¹ nastêpuje za pomoc¹ naciœniêcia klawiszy strza³ek" << endl
		<< "2. Powiêkszanie oraz zmniejszenie figury nastêpuje za pomoc¹" << endl
		<< "naciœniêcia klawisza + i -" << endl
		<< "3. Program dzia³a dla standardowego rozmiaru konsoli 80x25" << endl
		<< "4. Aby zakoñczyæ dzia³anie programu naciœnij klawisz ESC" << endl
		<< endl;
	ustaw_kolor(11);
}
//---------------------------------------------------------------------------
void wybor_start(){ //Funkcja rozpoczynaj¹ca program

	// Opcje wykonania programu
	char wybor;
	int rozmiar;
		ustaw_kolor(14);
		do {
			cout << "Wybierz opcjê wykonania programu: " << endl; //Menu do wybrania opcji uruchomienia programu
			cout << "1. Stwórz figurê o predefiniowanych rozmiarach" << endl;
			cout << "2. Stwórz figurê o w³asnych rozmiarach" << endl;
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
				Figura F(0, 24, ' ', rozmiar); //Tworzy nowy obieky klasy figura z danymi podanymi przez u¿ytkownika
				F.start_programu();
				F.inicjuj();
				F.~Figura();
			}
			if (wybor == '3') {
				cout << endl
					<< "Koñczenie dzia³ania pracy programu ..." << endl;
				cout << "Naciœniêcie dowolnego klawisza spowoduje zamkniêcie programu";
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
