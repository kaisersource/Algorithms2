#include<stdio.h>

int push(int t,int *a,int n){
	if((a[0]+1)==n)
		return 0;
	else{
		a[0]++;
		a[a[0]]=t;
		return 1;
	}
}

int pop(int *t,int *a, int n){
	if(a[0]==0)
		return 0;
	else{
		*t=a[a[0]];
		a[0]--;
		return 1;

	}

}

int main(){
	int n,c,a[10],t,z,k,tot;
	a[0]=0;
	printf("inserisci il numero di cifre da tastiera ");
	scanf("%d",&n);//numero di cifre da tastiera

	for(int i=1;i<=n;i++){
		printf("inserisci cifra\n");
		scanf("%d",&t);
		push(t,a,10); 
	}
	k=1;
	t=1;
	tot=0;
	while(k==1)
	{
		k=pop(&c,a,10);// estrai in coda
		if(k==1){
			tot+=t*c;  //se immettessi 1 , 2 , 5 allora estraggo 5 e lo moltiplico per 1, poi 2 e lo moltiplico per 10, e 1 *100 e print
	
			t*=10;	

	
		}


	}
printf("il totale e' %d\n",tot);
return 0;
}
