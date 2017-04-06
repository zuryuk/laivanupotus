#include <iostream>
void printShots(char taulukko[7][7]){
	std::cout << "   1  2  3  4  5  6  7" << std::endl << "   ___________________ \n" << std::endl; // Kolumnien numerointi
	for (int i = 0; i < 7; i++) {
		char rivi = 'A';
		std::cout << static_cast <char> (rivi + i) << "|"; // Rivien nimeäminen 
		for (int j = 0; j < 7; j++) {
			std::cout << " " << taulukko[i][j] << " ";
		}

		std::cout << "|" << static_cast <char> (rivi + i) << std::endl; // Rivien nimeäminen oikealla puolella
	}
	std::cout << "   ___________________\n" << std::endl;
	std::cout << "   1  2  3  4  5  6  7\n" << std::endl; // Kolumnien numerointi alhaalla
}