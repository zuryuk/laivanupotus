#include <string>
#include <algorithm>
#include <iostream>
using namespace std;
int muunnaAmpumiskoord(int* xPtr, int* yPtr, std::string z){
		z.erase(std::remove_if(z.begin(), z.end(), isspace)), z.end(); // Poistetaan v�lit
		if (z.size() > 2){
			cout << "Virheellinen sy�tt� yrit� uudelleen." << endl; // Jos koko on silti yli 2 on sy�tt� virheellinen
			return 0;
		}
		int x1 = int(tolower(z.at(0)) - 'a'); // muutetaan sopivaan muotoon 
		int y1 = int(z.at(1) - '1');
		*xPtr = x1; // pointterit osoittaa nyt koordinattien arvoja
		*yPtr = y1;
		return 1;
}