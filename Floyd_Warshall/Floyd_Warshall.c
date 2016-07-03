
void Floyd_Farshall(int *D, int *pi,int n) {//D e' la matdelle distanze, pi la matr dei predecessori, W i pesi degli archi, n dim delle mat
	int i, j, k,*w;
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++){
			D[i+j*n] = w[i+j*n]; // W[i][i] = 0 procedura tramite array : D[i+n*j]=w[i+n*j];
			if((i==j)||(w[i+n*j]==1000*n))
				pi[i+n*j]=n;
			else
				pi[i+n*j]=i;
		}

	for (k = 0; k < n; k++)
		for (i = 0; i < n; i++)
			for (j = 0; j < n; j++)
			if((D[i+k*n]!=n*1000)&&(D[k+n*j]!=n*1000))
				if(D[i+n*j]>D[i+k*n]+D[k+n*j]){
					D[i+n*j]=D[i+k*n]+D[k+n*j];
					pi[i+n*j]=pi[k+n*j];
				}

}
//costo spaziale: O(n^3) dove n= |V| e' la cardinalita' dei vertici
