#include<stdio.h>
#include<stdlib.h>

void Johnson (int *W,int n){
  int u,v,ans;
  int *W1;//pesi dell'arco G'
  int *d1,*pi1,*W2,*d,*pi,*pi2;
  W1=calloc((n+1)*(n+1),sizeof(int));
  d1=calloc((n+1),sizeof(int));
  pi1=calloc((n+1),sizeof(int));
  W2=calloc((n*n),sizeof(int));
  d=calloc((n),sizeof(int));
  pi=calloc((n),sizeof(int));
  //riempimento W1
  for(u=0;u<n;u++)
    for(v=0;v<n;v++)
      W1[n+(n+1)*v]=W[n+n*v];
  for(v=0;v<n;v++)
    W1[v+(n+1)*n]=1000*n;
  ans=Bellman_Ford(W1,n,d1,pi2,n+1);//n+1 e' la dimensione, n invece e' il nodo sorgente
  if(ans==0){
    printf("il grafo contiene cicli negativi\n");
    return ans;
  }
  else{
    for(u=0;u<n;u++)
      if(W[u+n*v]==n*1000)
        W2[u+n*v]=d[u]-d[v];
      else
        W2[u+n*v]=1000*n;

  for(u=0;u<n;u++){
    Dijkstra(W2,u,d,pi,n);
    for(v=0;v<n;v++){
      d[u+n*v]=d[v]+d1[v]-d[u];
      pi[n+n*v]=pi[v];
    }
  }//for
 }//else
return ans;
}//chiusura programma
