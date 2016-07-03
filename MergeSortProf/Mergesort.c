#include <stdio.h>
#include <stdlib.h>
void merge (int a[], int b[], int c[], int m, int n) {
	
	int i = 0, j = 0, k = 0;
	
	while (i < m && j < n) {
		if (a[i] < b[j])
			c[k++] = a[i++];
		else
			c[k++] = b[j++];
	}
	
	while (i < m)
		c[k++] = a[i++];
	while (j < n)
		c[k++] = b[j++];
}
void stampa(int a[],int n){
	int i;
	for(i=0;i<n;i++)
		printf("%d ",a[i]);
}
	
int main () {
	int m, n, i;
	int *a, *b, *c;
	
	printf ("Inserisci la lunghezza del primo vettore \n");
	scanf ("%d", &m);
	a = calloc (m, sizeof(int));
	
	printf ("Inserisci la lunghezza del secondo \n");
	scanf ("%d", &n);
	b = calloc (n, sizeof(int));
	
	printf ("Inserisci il primo vettore \n");
	for (i = 0; i < m; i++) {
		printf ("Inserisci l'elemento in posizione %d \n", i);
		scanf ("%d", &a[i]);
		if (i != 0)
			while (a[i] < a[i-1]) {
				printf ("Errore! Vettore non ordinato, inserisci nuovamentel'elemento");
				scanf ("%d", &a[i]);
			}
	}
	
	printf ("Inserisci il secondo vettore \n");
	for (i = 0; i < n; i++) {
		printf ("Inserisci l'elemento in posizione %d \n", i);
		scanf ("%d", &b[i]);
		if (i != 0)
			while (b[i] < b[i-1]) {
				printf ("Errore! Vettore non ordinato, inserisci nuovamentel'elemento");
				scanf ("%d", &b[i]);
			}
	}
	
	c = calloc(n + m, sizeof(int));
	merge (a, b, c, m, n);
	stampa(c,n+m);
}
