#include <iostream>
#include <ctime>
#include "sallittu.h"
#include "tyhjapoyta.h"
using namespace std;
void arvolaivat(int poyta[][7]){
	srand(time(NULL));
	tyhjapoyta(poyta);
	for (int i = 2; i <= 5; i++){
		bool toimii;
		int x = rand() % 6 + 0; // X - koordinaattien arvonta
		int y = rand() % 6 + 0; // Y - koordinaattien arvonta
		int z = rand() % 2 + 1; // Suunnan arvonta
		switch (z){
		case 1:
			toimii = sallittu(x, y, i, z, poyta);
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
		case 2:
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
		default:
			cout << "error"; // EI pitäisi tapahtua
			break;
		}
	}
}