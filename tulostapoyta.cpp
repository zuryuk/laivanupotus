#include <iostream>
void tulostapoyta(int arr[7][7]){ // Funktio tulostaa pöydän ascii-taiteella
	std::cout << "   1  2  3  4  5  6  7" << std::endl << "   ___________________ \n" << std::endl; // Kolumnien numerointi
	for (int i = 0; i < 7; i++) {
		char rivi = 'A';
		std::cout << static_cast <char> (rivi + i) << "|"; // Rivien nimeäminen 
		for (int j = 0; j < 7; j++) {
			if (arr[i][j] == 0)
			{
				std::cout << " ~ "; //Vettä ei laukauksia
			}
			if (arr[i][j] == 2 || arr[i][j] == 22)
			{
				std::cout << " 2 "; //2 Pituinen laiva 
			}
			if (arr[i][j] == 3 || arr[i][j] == 33)
			{
				std::cout << " 3 "; //3 Pituinen laiva
			}
			if (arr[i][j] == 4 || arr[i][j] == 44)
			{
				std::cout << " 4 "; //4 Pituinen laiva
			}
			if (arr[i][j] == 5 || arr[i][j] == 55)
			{
				std::cout << " 5 "; //5 Pituinen laiva
			}
		}
		std::cout << "|" << static_cast <char> (rivi + i) << std::endl; // Rivien nimeäminen oikealla puolella
	}
	std::cout << "   ___________________\n" << std::endl;
	std::cout << "   1  2  3  4  5  6  7\n" << std::endl; // Kolumnien numerointi alhaalla
}