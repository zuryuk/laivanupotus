#include <iostream>
#include <string>
#include <algorithm>
#include <ctime>
#include "windows.h"
#include "printShots.h"
#include "muunnaAmpumiskoord.h"
#include "laivaUpotettu.h"
using namespace std;
void pelaaAI(int poyta[][7], char laukaukset[][7]){

	string koordinaatit;
	int osuma = 0;
	int laiva5 = 0;
	int laiva4 = 0;
	int laiva3 = 0;
	int laiva2 = 0;
	int upposi2 = 0;
	int upposi3 = 0;
	int upposi4 = 0;
	int upposi5 = 0;
	int laukaukset1 = 0;
	int firstShot5 = 0;
	int firstShot4 = 0;
	int firstShot3 = 0;
	int firstShot2 = 0;
	float upotettu5 = 0;
	float upotettu4 = 0;
	float upotettu3 = 0;
	float upotettu2 = 0;
	int hutijakso = 0;
	int hutijaksomax = 0;
	int hudit = 0;
	int osumisjaksomax = 0;

	system("cls");
	while (osuma < 14){
		srand(time(NULL));
		int x = rand() % 6 + 0;
		int y = rand() % 6 + 0;
			cout << "Ammutaan koordinaatteihin " << char(x + 65) << y + 1 << " " <<endl;
			if (poyta[x][y] == (5)) {
				if (hutijakso > hutijaksomax) {
					hutijaksomax = hutijakso;
				}
				hutijakso = 0;
				cout << "Osuma!" << endl;
				laukaukset[x][y] = '*';
				poyta[x][y] = 55;
				firstShot5++;
				osuma++;
				laiva5++;
				if (laiva5 == 5){
					cout << "Laiva upotettu!" << endl;
					laivaUpotettu(laukaukset, poyta, laiva5);
					upposi5 = laukaukset1 + 1;
					upotettu5 = firstShot5;
				}
			}
			if (poyta[x][y] == 4) {
				if (hutijakso > hutijaksomax) {
					hutijaksomax = hutijakso;
				}
				hutijakso = 0;
				cout << "Osuma!" << endl;
				laukaukset[x][y] = '*';
				poyta[x][y] = 44;
				firstShot4++;
				osuma++;
				laiva4++;
				if (laiva4 == 4){
					cout << "Laiva upotettu!" << endl;
					laivaUpotettu(laukaukset, poyta, laiva4);
					upposi4 = laukaukset1 + 1;
					upotettu4 = firstShot4;
				}
			}
			if (poyta[x][y] == 3) {
				if (hutijakso > hutijaksomax) {
					hutijaksomax = hutijakso;
				}
				cout << "Osuma!" << endl;
				laukaukset[x][y] = '*';
				poyta[x][y] = 33;
				firstShot3++;
				osuma++;
				laiva3++;
				if (laiva3 == 3){
					cout << "Laiva upotettu!" << endl;
					laivaUpotettu(laukaukset, poyta, laiva3);
					upposi3 = laukaukset1 + 1;
					upotettu3 = firstShot3;
				}
			}
			if (poyta[x][y] == 2) {
				if (hutijakso > hutijaksomax) {
					hutijaksomax = hutijakso;
				}
				cout << "Osuma!" << endl;
				laukaukset[x][y] = '*';
				poyta[x][y] = 22;
				firstShot2++;
				osuma++;
				laiva2++;
				if (laiva2 == 2){
					cout << "Laiva upotettu!" << endl;
					laivaUpotettu(laukaukset, poyta, laiva2);
					upposi2 = laukaukset1 + 1;
					upotettu2 = firstShot2;
				}
			}
			if (poyta[x][y] == 0){
				cout << "Huti!" << endl;
				poyta[x][y] = 10;
				printShots(laukaukset);
				laukaukset[x][y] = '#';
				hutijakso++;
				hudit++;
				laukaukset1++;
				if (firstShot5 != 0) {
					firstShot5++;
				}
				if (firstShot4 != 0) {
					firstShot4++;
				}
				if (firstShot3 != 0) {
					firstShot3++;
				}
				if (firstShot2 != 0) {
					firstShot2++;
				}
				Sleep(3000);
				system("cls");
				continue;
			}
			if (poyta[x][y] == 10 || poyta[x][y] == 22 || poyta[x][y] == 33 || poyta[x][y] == 44 || poyta[x][y] == 55){
				cout << "Ruutuun on jo ammuttu hölmö robotti!" << endl;
			}
			printShots(laukaukset);
			Sleep(3000);
			system("cls");
			laukaukset1++;
	}
	float osumisjakso5 = upotettu5 / 5;
	float osumisjakso4 = upotettu4 / 4;
	float osumisjakso3 = upotettu3 / 3;
	float osumisjakso2 = upotettu2 / 2;

	cout << "Peli voitettu!";
	cout << "\nLaukauksia ammuttiin " << laukaukset1 << " kappaletta";
	cout << "\nLaukauksista ohi ammuttiin " << hudit << " kappaletta";
	cout << "\nLaivat upposivat seuraavasti: ";
	cout << "\n Viiden pituinen laiva " << upposi5 << " laukauksen jälkeen\n ja " << upotettu5 << " laukauksen jälkeen ensimmäisestä osumasta" << endl;
	cout << "\n Neljän pituinen laiva " << upposi4 << " laukauksen jälkeen\n ja " << upotettu4 << " laukauksen jälkeen ensimmäisestä osumasta" << endl;
	cout << "\n Kolmen pituinen laiva " << upposi3 << " laukauksen jälkeen\n ja " << upotettu3 << " laukauksen jälkeen ensimmäisestä osumasta" << endl;
	cout << "\n Kahden pituinen laiva " << upposi2 << " laukauksen jälkeen\n ja " << upotettu2 << " laukauksen jälkeen ensimmäisestä osumasta" << endl;
	cout << "Pisin hutijakso oli " << hutijaksomax << " paras suhteellinen osumisjakso oli " << fmin(fmin(osumisjakso5, osumisjakso4), fmin(osumisjakso3, osumisjakso2));


}