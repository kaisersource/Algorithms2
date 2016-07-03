#include<stdio.h>
#include<stdlib.h>

void merge(int a[],int b[],int c[], int m, int n){
	int i=0,j=0,k=0;
	while(i<m && j<n){
		if(a[i]<b[j])
			c[k++]=a[i++];
		else
			c[k++]=b[j++];		
	}
	//svuotiamo i vettori d'appoggio se ci fosse disparita' di rango tra di essi
	while (i<m)
		c[k++]=a[i++];
	while(j<n)
		c[k++]=b[j++];
}

void mergesort(int k[],int n){
	int j,t,m,*w;
	w=calloc(n,sizeof(int));
	for(t=1;t<n;t*=2){
		for(j=0;j<n-t;j+=2*t)
			merge(k+j,k+j+t,w+j,t,t);
		for(j=0;j<n;j++)
			k[j]=w[j];
	}
	free(w);
}	
int main(){
	int k[]={4,5,3,7,6,4,3,5,10,55,34,54,76,54,56,90};
	int n=16;
	
	mergesort(k,n);
	for(int i=0;i<n;i++)
		printf("%d\n",k[i]);
	
return 0;

}
