void laivaUpotettu(char arr[][7], int arr2[][7], int laiva){
	for (int i = 0; i < 7; i++){
		for (int j = 0; j < 7; j++){
			if (arr2[i][j] == laiva * 11){
				arr[i][j] = '?';
			}
		}
	}
}