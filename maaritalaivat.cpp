#include <iostream>
using namespace std;
void maaritalaivat(int poyta[7][7]){
	cout << "Seuraavaksi syötetään laivojen koordinaatit." << endl;
	cout << "Ilmoita ensiksi laivan aloitus koordinaatti esimerkiksi B1" << endl; 
	cout << "Seuraavaksi ilmoita laivan suunta (P)ohjoinen, (L)änsi, (E)telä tai (I)tä ilmansuunnan ensimmäisellä kirjaimella." << endl;
	cout << "Aloitetaan. Syötä viiden pituisen laivan aloitus koordinaatit" << endl;
	int k1;
	int s1;
	cin >> k1;
	cout << "\nSyötä nyt viiden pituisen laivan suunta." << endl;
	cin >> s1;

	cout << "\nSyötä seuraavaksi neljän pituisen laivan aloitus koordinaatit" << endl;
	int k2;
	int s2;
	cin >> k2;
	cout << "\nSyötä nyt neljän pituisen laivan suunta." << endl;
	cin >> s2;

	cout << "\nSyötä seuraavaksi kolmen pituisen laivan aloitus koordinaatit" << endl;
	int k3;
	int s3;
	cin >> k3;
	cout << "\nSyötä nyt kolmen pituisen laivan suunta." << endl;
	cin >> s3;

	cout << "\nSyötä seuraavaksi kahden pituisen laivan aloitus koordinaatit" << endl;
	int k4;
	int s4;
	cin >> k4;
	cout << "\nSyötä nyt kahden pituisen laivan suunta." << endl;
	cin >> s4;

	
}