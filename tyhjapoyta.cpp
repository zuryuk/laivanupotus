void tyhjapoyta(int arr[][7]) // funktio luo tyhjän pelipöydän
{
	for (int i = 0; i<7; i++) {
		for (int j = 0; j<7; j++) {
			arr[i][j] = 0;
		}
	}
}