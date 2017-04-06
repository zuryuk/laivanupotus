#include <iostream>
#include <string>
#include <algorithm>
#include "muunnaAmpumiskoord.h"
#include "tulostapoyta.h"
#include "sallittu.h"
#include "tyhjapoyta.h"
#include "muunnaAmpumiskoord.h"
using namespace std;
void syotalaivat(int poyta[][7]){
	char input;
	bool toimii;
	string inputTmp; 
	tyhjapoyta(poyta);
	string koordinaatit;
	cin.clear();
	for (int i = 2; i <= 5; i++){
		system("cls");
		tulostapoyta(poyta);
		cout << "\nValitse koordinaatit ja laivan suunta\n (P)ohjoinen, (I)tä, (E)telä tai (L)änsi";
		cout << "\nSyötä " << i << " pituisen laivan koordinaatit.\n";
		getline(cin, koordinaatit);  //haetaan koordinaatti stringi
		if (koordinaatit.empty()){
			cout << "Virheellinen syöttö yritä uudelleen." << endl;
			i--;
			cin.clear();  //Tyhjennetään virheellinen cin ettei jää looppaamaan
			continue;
		}
		if (koordinaatit.size() < 2){
			cout << "Virheellinen syöttö yritä uudelleen." << endl;
			i--;
			cin.clear();  //Tyhjennetään virheellinen cin ettei jää looppaamaan
			continue;
		}
		int z = 0;
		int x, y;
		int *xPtr = &x;
		int *yPtr = &y;
		muunnaAmpumiskoord(xPtr, yPtr, koordinaatit);
		if (x > 6 || x < 0 || y > 6 || y < 0){
			cout << "Virheellinen syöttö. Yritä uudelleen." << endl;
			i--;
			system("pause");
			continue;
		}
		cout << "koordinaatit olivat: " << x << ", " << y;
		cout << "Ja suunta";
		getline(cin, inputTmp); // Cin on perseestä käytetään getlineä ja otetaan char ekasta kirjaimesta JOS syöte oli yhden mittainen muuten input = E - > default:
		if (inputTmp.length() > 1){ 
			input = 'E';
		}
		if (inputTmp.empty()){
			input = 'E';
		}
		else {
			input = inputTmp.at(0);
		}
			switch (input){
			case 'P':
			case 'p':
				z = 1;
				toimii = sallittu(x, y, i, z, poyta); // tarkistetaan voidaanko laivaa laittaa tähän
				if (toimii == true){
					for (int j = 0; j < i; j++){
						poyta[x - j][y] = i;
					}
					break;
				}
				else {
					i -= 1;
					continue;
				}
			case 'I':
			case 'i':
				z = 2;
				toimii = sallittu(x, y, i, z, poyta);
				if (toimii == true){
					for (int j = 0; j < i; j++){
						poyta[x][y + j] = i;
					}
					break;
				}
				else {
					i -= 1;
					continue;
				}
			case 'E':
			case 'e':
				z = 3;
				toimii = sallittu(x, y, i, z, poyta);
				if (toimii == true){
					for (int j = 0; j < i; j++){
						poyta[x + j][y] = i;
					}
					break;
				}
				else {
					i -= 1;
					continue;
				}
			case 'l':
			case 'L':
				z =4;
				toimii = sallittu(x, y, i, z, poyta);
				if (toimii == true){
					for (int j = 0; j < i; j++){
						poyta[x][y - j] = i;
					}
					break;
				}
				else {
					i -= 1;
					continue;
				}
			default:
				cout << "Virheellinen syöttö yritä uudelleen";
				cin.clear();
				break;
			}
		}
}