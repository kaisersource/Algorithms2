#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void Initialize_S_S (int n, int s, int *d, int *pi){
    int v;
    for (v=0; v<n; v++){
        d[v]=1000*n;
        pi[v]=n;
        }
    d[s] = 0;
    }

void Relax(int u, int v, int *w, int n, int *d, int *pi){
    if(d[v]> d[u]+ w[u+n*v]){
        d[v] = d[u]+ w[u+n*v];
        pi[v]=u;
        }
    }

int Bellman_ford (int *w, int s, int *d, int *pi, int n){
    int i, u, v, ris=1;
    Initialize_S_S(n,s,d,pi);
    for (i = 1; i<n; i++){
        for (u=0; u<n; u++){
            for (v=0; v<n; v++){
                Relax(u,v,w,n,d,pi);
            }
        }
    }
    for(u=0;u<n;u++){
        for(v=0;v<n;v++){
            if(d[v] > d[u]+w[u+n*v])
                ris =0;

        }
    }

    return ris;
}
