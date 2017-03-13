#ifndef Konsola
#define Konsola
//=============================
#include <iostream>
#include <conio.h>
#include <Windows.h>
#include <locale>
#include <math.h>
//-----------------------------
void polskie_litery();
void gotoxy(int x, int y);
void HideCursor();
void ShowCursor();
void ustaw_kolor(int kolor);
int wherex();
int wherey();
void clreol();
//=============================
#endif
