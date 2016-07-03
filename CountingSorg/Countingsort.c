#include <stdio.h>
#include <stdlib.h>


int main(){
	printf("Array disordinato ");
	int a[10]={3,2,1,3,4};
	 int range=50,n=5,i,j;
	int count[50]={0};


	printf("Array disordinato");
	for(i=0;i<n;i++){
		count[a[i]]=count[a[i]]+1;
	
}

	for(i=0;i<=range;i++){
		for(j=1;j<=count[i];j++){
			
			printf("%d",i);
		}
		
	}
	
return 0;
}
