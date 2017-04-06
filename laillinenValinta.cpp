#include <string>
#include <iostream>
#include <algorithm>
bool laillinenValinta(char a, std::string b){
	for (int i = 0; i < b.length(); i++){
	if (b.at(i) == a)
	{
		std::cout << "Sallittu";
		return true;
	}
	else  {
		return false;
		std::cout << "Ei sallittu";
	}
	}
}