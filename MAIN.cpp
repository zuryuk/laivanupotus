#include <iostream>
#include "tyhjapoyta.h"
#include "tulostapoyta.h"
#include <string>
#include "valikko.h"
using namespace std;
void main()
{
	setlocale(LC_ALL, "finnish");
	const int pituus = 7;
	const int leveys = 7; 
	int* xPtr;
	int* yPtr;
	int x, y;
	xPtr = &x;
	yPtr = &y;
	int poyta[leveys][pituus];
	tyhjapoyta(poyta); // Tyhjennetään pelipöytä (täytetään nollilla)
	char laukaukset[leveys][pituus];
	memset(laukaukset, ' ', sizeof(char) * 7 * 7); // Nollataan laukaukset
	setlocale(LC_ALL, "finnish");
	int j = 0; // Valitsee mikä ohjelma suoritetaan seuraavaksi
	int i = 0; // Vasta onnistuneessa syötössä poistutaan while-loopista.
	while (i < 1){
		system("cls"); //Tyhjennä aikaisempi teksti
		valikko(poyta, laukaukset);
		system("pause");
	}
}