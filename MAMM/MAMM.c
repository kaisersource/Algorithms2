#include<stdio.h>
#include<stdlib.h>

void extend_s_p(int *D,int *w, int n){
	int *D1;
	int i,j,k;
	D1=calloc(n*n,sizeof(int));
	for(i=0;i<n;i++)
		for(j=0;j<n;j++){
			D1[i+n*j]=1000*n;
			for(k=0;k<n;k++)
				if(w[k+n*j]!=1000*n)
					if((D[i+k*n]+w[k+n*j])<(D1[i+n*j]))
						D1[i+n*j]=(D[i+k*n]+w[k+n*j]);
			}
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			D[i+n*j]=D1[i+n*j];

}

void slow_ap_sp(int *D,int *W,int n){
	int i,j,m;
	for(i=0;i<m;i++)
		for(j=0;j<n;j++)
			D[i+n*j]=W[i+n*j];
	for(m=2;m<n;m++)
		extend_s_p(D,W,n);
}

void Faster_AP_SP(int *D,int *W, int n){
	int i,j,m;
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			D[i+n*j]=W[i+n*j];
			m=1;
			while(n-1>m){
				extend_s_p(D,D,n);
				m=2*m;
			}
}
