bool sallittu(int x, int y, int i, int z, int poyta[][7]){
	if (z == 1){
		for (int j = 0; j < i; j++){
			if ((x - j) >= 0 && poyta[x - j][y] == 0) {
			}
			else {
				return false;
			}
		}
		return true;
	}
	if (z == 2){
		for (int j = 0; j < i; j++){
			if ((y + j) <= 6 && poyta[x][y+j] == 0) {
			}
			else {
				return false;
			}
		}
		return true;
	}
	if (z == 4){
		for (int j = 0; j < i; j++){
			if ((y - j) >= 0 && poyta[x][y - j] == 0) {
			}
			else {
				return false;
			}
		}
		return true;
	}
	if (z == 3){
		for (int j = 0; j < i; j++){
			if ((x + j) >= 0 && poyta[x + j][y] == 0) {
			}
			else {
				return false;
			}
		}
		return true;
	}
	else{
		return false;
	}
}