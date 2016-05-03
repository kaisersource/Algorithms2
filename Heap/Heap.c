
#include<stdio.h>
void maxheapify(int [],int,int);
void buildmaxheap(int arr[],int n){
	int i;
	for(i=n/2;i>=1;i--)
		maxheapify(arr,i,n);
}

void maxheapify(int arr[],int i,int n){
	int l,r,largest,temp;
	l=2*i;
	r=(2*i)+1;
	if(l<=n&&arr[l]>arr[i])
		largest=l;
	else
		largest=i;
	if(r<=n&&arr[r]>arr[largest])
		largest=r;
	if(largest!=i)
	{
		temp=arr[i];
		arr[i]=arr[largest];
		arr[largest]=temp;
		maxheapify(arr,largest,n);
	}
}
int heapmaximum(int arr[])
	{
	return arr[1];
	}
int heapextractmax(int arr[], int n){
	int max;
	if(n<1){
		printf("\nHeap Underflow");
		return -1;
	}
	else{
		max=arr[1];
		arr[1]=arr[n];
		n=n-1;
	maxheapify(arr,1,n);
	return max;
	}
}
int heapextractelem(int arr[], int k,int n){
	
	int max;
	if(n==1){
		printf("\nHeap Underflow");
		return -1;
	}
	else if(k==n){
			max=arr[k];			
			//arr[k]=arr[n];
			
			//maxheapify(arr,k,n);
			n=n-1;
			return max;
	}
	
	
		return heapextractelem(arr,k,n-1);
		
}

void heapincreasekey(int arr[],int i,int key){
int temp;
	if (key<=arr[i]){
		printf("\nThevalue of key is Less Than Or Equal To Existing Key");
	}
	else{
		arr[i]=key;
		while(i>1&&arr[i/2]<arr[i]){
			temp=arr[i];
			arr[i]=arr[i/2];
			arr[i/2]=temp;
			i=i/2;
		}
	}
}
void maxheapinsert(int arr[],int key,int n){
	arr[n]=-100;
	heapincreasekey(arr,n,key);
	}


					
int main(){
	int i,n,arr[50],scelta,max,key;
	printf("EnterThe Size Of Array ");
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		printf("Enter The Element %d\n",i);
		scanf("%d",&arr[i]);
	}
	buildmaxheap(arr,n);
	printf("\n Enter Your choelta");
	printf("\n1. Heap Maximum");
	printf("\n2. Heap Extract Max");
	printf("\n3. Heap Increase Key");
	printf("\n4. Max Heap Insert");
	printf("\n5. Heap Extract\n element");
	scanf("%d",&scelta);
	switch (scelta){
		case 1:max=heapmaximum(arr);
  			printf("\nMaximum Element= %d",max);
  		break;
		case 2:max=heapextractmax(arr,n);
  			n=n-1;
  			printf("\n Maximum Element Extracted Is= %d",max);
  			printf("\nAfter Extracting Array Is");
  		for(i=1;i<=n;i++)
  			printf("\n%d",arr[i]);
  		break;
		case 3:printf("\nEnterThe Value Of Key ; ");
  			scanf("\n%d",&key);
  			printf("\nEnter The Value Of Index ; ");
  			scanf("%d",&i);
  			heapincreasekey(arr,i,key);
  			printf("\nAfter Increasing Key Array Is");
  		for(i=1;i<=n;i++)
 			printf("\n%d",arr[i]);
 		break;
		case 4:printf("\Enter The Value Of Key ; ");
 		       scanf("%d",&key);
 		       n=n+1;
 		       maxheapinsert(arr,key,n);
 		       printf("\nAfter Inserting Array Is");
		       for(i=1;i<=n;i++)
		       		printf("\n%d",arr[i]);
 		break;
		case 5:
			
			printf("Enter The Position Of key ; ");
			scanf("\n%d",&key);
			max=heapextractelem(arr,key,n);
			maxheapify(arr,key,n);
			n=n-1;
			printf("\n Element Extracted Is= %d",max);
			for(i=1;i<=n;i++)
	  			printf("\n%d",arr[i]);
  		break;
			
	}

}
