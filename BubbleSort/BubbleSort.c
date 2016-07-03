#include<stdio.h>
#include<stdlib.h>

void bubble_sort (int a[],int n){
int aux;
	if(n>0){
		for(int j=0;j<n-1;j++){
			if(a[j]>a[j+1]){
				aux=a[j];
				a[j]=a[j+1];
				a[j+1]=aux;
			}
			
		}
		return bubble_sort(a,n-1);
	}
	else return;
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
	bubble_sort(A,dim);
	printf("\n");
	for(int i=0;i<dim;i++)
		printf("%d ",A[i]);

}
