#include <iostream>
#include <string>
#include <algorithm>
#include "printShots.h"
#include "muunnaAmpumiskoord.h"
#include "laivaUpotettu.h"
#include "tulostapoyta.h"
#include "valikko.h"
using namespace std;
void pelaa(int poyta[][7], char laukaukset[][7]){

	string koordinaatit;
	int osuma = 0;
	int laiva5 = 0; // Laivojen elämät
	int laiva4 = 0;
	int laiva3 = 0;
	int laiva2 = 0;
	int upposi2 = 0; // Millä vuorolla laivat uppoavat
	int upposi3 = 0;
	int upposi4 = 0;
	int upposi5 = 0;
	int laukaukset1 = 0; // Laukauksien lukumäärä
	int firstShot5 = 0; // Milloin laivaan osuu ensimmäinen laukaus
	int firstShot4 = 0;
	int firstShot3 = 0;
	int firstShot2 = 0;
	float upotettu5 = 0; // Kauanko ensimmäisestä osumasta kului uppoamiseen
	float upotettu4 = 0;
	float upotettu3 = 0;
	float upotettu2 = 0;
	int i = 0; //Apumuuttuja tarkistaa onko käyttäjän syöte virheellinen
	int j = 0; //Apumuuttuja tarkistaa missä järjestyksessä laivat upposivat
	int uppoaminen[5]; // Uppoamisjärjestys tallennetaan taulukkoon
	int hutijakso = 0; // Hutijakso muuttuja
	int hutijaksomax = 0; // Pisin hutijakso
	int hudit = 0; // Hutien määrä
	int osumisjaksomax = 0; // Pisin osumisputki
	cin.clear(); // Koska aikaisemmin on käytetty cin >> tarvitaan tätä riviä, että getline toimii
	while (osuma < 14){
		cout << "Anna laukauksen koordinaatit ";
		int x, y;
		int *xPtr = &x;
		int *yPtr = &y;
		getline(cin, koordinaatit);
		if (koordinaatit.empty()){
			cout << "Virheellinen syöttö yritä uudelleen." << endl;
			cin.clear();  //Tyhjennetään virheellinen cin ettei jää looppaamaan
			continue;
		}
		if (koordinaatit.at(0) == 'p' || koordinaatit.at(0) == 'P'){
			valikko(poyta, laukaukset);
		}
		if (koordinaatit.size() < 2){
			cout << "Virheellinen syöttö yritä uudelleen." << endl;
			cin.clear();  //Tyhjennetään virheellinen cin ettei jää looppaamaan
			continue;
		}
		i = muunnaAmpumiskoord(xPtr, yPtr, koordinaatit);
		if (i = 0) {
			cout << "Virheellinen syöttö yritä uudelleen." << endl;
			continue;
		}
		if (x == -5 || y == 15){ // \@ ajettuna läpi muunnaAmpumiskoord ohjelmasta (sallii myös välit)
			cout << "Laivat ovat pelilaudalla seuraavanlaisesti: " << endl;
			tulostapoyta(poyta);
			continue;
		}
		if (x > 7 || x < 0 || y > 7 || y < 0){
			cout << "Virheellinen syöttö yritä uudelleen." << endl;
			continue;
		}
		if (poyta[x][y] == (5)) {
			if (hutijakso > hutijaksomax) {
				hutijaksomax = hutijakso;
			}
			hutijakso = 0;
			system("cls");
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
				uppoaminen[j] = 5;
				j++;
			}
		}
		if (poyta[x][y] == 4) {
			if (hutijakso > hutijaksomax) {
				hutijaksomax = hutijakso;
			}
			hutijakso = 0;
			system("cls");
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
				uppoaminen[j] = 4;
				j++;
			}
		}
		if (poyta[x][y] == 3) {
			if (hutijakso > hutijaksomax) {
				hutijaksomax = hutijakso;
			}
			system("cls");
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
				uppoaminen[j] = 3;
				j++;
			}
		}
		if (poyta[x][y] == 2) {
			if (hutijakso > hutijaksomax) {
				hutijaksomax = hutijakso;
			}
			system("cls");
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
				uppoaminen[j] = 2;
				j++;
			}
		}
		if (poyta[x][y] == 0){
			system("cls");
			cout << "Huti!" << endl;
			laukaukset[x][y] = '#';
			printShots(laukaukset);
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
			continue;
		}
		printShots(laukaukset);
		laukaukset1++;
	}
	float osumisjakso5 = upotettu5 / 5;
	float osumisjakso4 = upotettu4 / 4;
	float osumisjakso3 = upotettu3 / 3;
	float osumisjakso2 = upotettu2 / 2;
	poyta[7][7] = { 0 }; // Nollataan pöytä
	cout << "Peli voitettu!";
	cout << "\nLaukauksia ammuttiin " << laukaukset1 << " kappaletta"; // Tulostetaan statistiikat
	cout << "\nLaukauksista ohi ammuttiin " << hudit << " kappaletta";
	cout << "\nLaivat upposivat seuraavasti: ";
	cout << "\n Viiden pituinen laiva " << upposi5 << " laukauksen jälkeen\n ja " << upotettu5 << " laukauksen jälkeen ensimmäisestä osumasta" << endl;
	cout << "\n Neljän pituinen laiva " << upposi4 << " laukauksen jälkeen\n ja " << upotettu4 << " laukauksen jälkeen ensimmäisestä osumasta" << endl;
	cout << "\n Kolmen pituinen laiva " << upposi3 << " laukauksen jälkeen\n ja " << upotettu3 << " laukauksen jälkeen ensimmäisestä osumasta" << endl;
	cout << "\n Kahden pituinen laiva " << upposi2 << " laukauksen jälkeen\n ja " << upotettu2 << " laukauksen jälkeen ensimmäisestä osumasta" << endl;
	cout << "Pisin hutijakso oli " << hutijaksomax << " paras suhteellinen osumisjakso oli " << fmin(fmin(osumisjakso5, osumisjakso4), fmin(osumisjakso3, osumisjakso2));
	cout << "\nLaivat upposivat järjestyksessä: ";
		for (int o = 0; o < 4; o++){
			cout << uppoaminen[o] << "-pituinen laiva" << endl;
		}

}