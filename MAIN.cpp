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
	tyhjapoyta(poyta); // Tyhjennet��n pelip�yt� (t�ytet��n nollilla)
	char laukaukset[leveys][pituus];
	memset(laukaukset, ' ', sizeof(char) * 7 * 7); // Nollataan laukaukset
	setlocale(LC_ALL, "finnish");
	int j = 0; // Valitsee mik� ohjelma suoritetaan seuraavaksi
	int i = 0; // Vasta onnistuneessa sy�t�ss� poistutaan while-loopista.
	while (i < 1){
		system("cls"); //Tyhjenn� aikaisempi teksti
		valikko(poyta, laukaukset);
		system("pause");
	}
}