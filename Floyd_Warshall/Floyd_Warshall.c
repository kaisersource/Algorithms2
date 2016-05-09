
void floyd_warshall() {
	int i, j, k;
	for (i = 1; i <= N; i++)
		for (j = 1; j <= N; j++)
			D[i][j] = W[i][j]; // W[i][i] = 0

	for (k = 1; k <= N; k++)
		for (i = 1; i <= N; i++)
			for (j = 1; j <= N; j++)
				D[i][j] = min(D[i][j], D[i][k] + D[k][j]);
}
