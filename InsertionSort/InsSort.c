#include <stdio.h>
#include<stdlib.h>



void insertion_sort(int a[],int n){
	int i,j,aux;
	for(i=1;i<n;i++){
		aux = a[i];
		j=i-1;
		while((j>=0)&&(a[j]>aux)){
			a[j+1]=a[j];
			j--;
		}
		a[j+1]=aux;
	}
	

}


int main(){
	int dim;
	printf("inserisci la dimensione dell'array\n");
	scanf("%d",&dim);
	int *A=(int*)malloc(dim*sizeof(int));
	for(int i=0;i<dim;i++){
		printf("Inserisci gli elementi:\n");
		scanf("%d",&A[i]);
	}
	insertion_sort(A,dim);
	printf("\n");
	for(int i=0;i<dim;i++)
		printf("%d\n",A[i]);

}
