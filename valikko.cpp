#include "syotalaivat.h"
#include "pelaa.h"
#include "pelaaAI.h"
#include "arvolaivat.h"
#include <iostream>
#include <string>
#include "laillinenValinta.h"
using namespace std;
void valikko(int arr[][7], char arr2[][7]){
	cout << "Laivanupotuspeli" << endl;
	cout << "================" << endl;
	cout << "\nValinnat:" << endl;
	cout << "1) Syötä laivat\n2) Pelaa\n3) Arvo laivojen sijainnit\n4) Ampumisen simulointi \nL) Lopeta" << endl;
	cout << "\nValintasi: ";
	string sallitut = "123lL";
	bool sallittu;
	char input;
	string input1;
	getline(cin, input1); // Cin on perseestä käytetään getlineä ja otetaan char ekasta kirjaimesta JOS syöte oli yhden mittainen muuten input = E - > default:
	if (input1.length() > 1){
		input = 'E';
	}
	if (input1.empty()){
		input = 'E';
	}
	else {
		input = input1.at(0);
	}

		switch (input) { // Switch-case valikolla valitaan haluttu toiminto
		case '1':
			syotalaivat(arr);
			break;
		case '2':
			for (int i = 0; i < 7; i++){ // Tarkistetaan, etät laivat on syötetty
				for (int j = 0; j < 7; j++){
					if (arr[i][j] != 0){
						pelaa(arr, arr2);
					}
				}
			}
			cout << "Syötä laivat ensin." << endl;
			break;
		case '3':
			arvolaivat(arr);
			break;
		case '4':
			pelaaAI(arr, arr2);
		case 'l':
		case 'L':
			cout << "Kiitos pelaamisesta \nPress any key to continue..." << endl;
			exit(EXIT_SUCCESS);
		default:
			cout << "Virheellinen syöttö yritä uudelleen" << endl;
			break;
		}
}