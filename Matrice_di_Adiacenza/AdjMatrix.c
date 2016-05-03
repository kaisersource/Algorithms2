#include<stdio.h>
#include<stdlib.h>

int** creazione(int dim){
	//int **A = calloc(dim*dim,1+sizeof(int*)); malloc ebraica non funzionante
	int **A = calloc(dim,1+sizeof(int*));
	for(int i = 0;i<dim;i++) {
    		A[i] = calloc(dim, sizeof(int));
    	}
    return A;

}

void Output(int **A,int dim){
	for(int i=0;i<dim;i++){
		printf("\n");
		for(int j=0;j<dim;j++)
			printf("%d",A[i][j]);
	}
	printf("\n");
}

void inserimento(int **A,int dim){
				int x,y;
			char answer;
			printf("vuoi inserire un arco?\n");
			scanf(" %c",&answer);
			while(answer=='s'){
				printf("Inserisci il primo valore dell'arco\n");
				scanf("%d",&x);
				printf("Inserisci il secondo valore dell'arco\n");
				scanf("%d",&y);
				if(x==y||x>=dim||y>=dim){
					printf("arco non ammissibile \n");
				}
				else if (A[x][y]==0){
					A[x][y]=1;
					A[y][x]=1;
				}
				else{
					printf("Arco gia esistente\n");
				}
				printf("vuoi inserire un altro arco?\n");
				scanf(" %c",&answer);
			}
}
int mostarkedval(int **A,int dim){//elemento con piu archi. A e' una matrice di adiacenza di soli booleani
	int *Carry = calloc(dim,sizeof(int));//vettore d'appoggio per contare le ocorrenze
	for(int i=0;i<dim;i++){
		for(int j=0;j<dim;j++){
			if(A[i][j]==1)//se l'arco esiste
				Carry[i]++;//incremento.
		}
	}

		int max=Carry[0];//salvo l'elemento di partenza da confrontare
		int maxIndex=0;//indice dell'elemento con piu archi
	for(int i=1;i<dim;i++){
		if(max<Carry[i]){//verifico l'elemento che ha avuto il maggior numero di archi(lo scopro in base all'indice i)
			max=Carry[i];//nuovo massimo
			maxIndex=i;//nuovo indice del massimo
			}
	}
	return (maxIndex);//indice massimo di carry nonche' punto fisso per l'indice i-esimo o j-esimo della matrice A
}

void detectIsolatedNodes(int **A,int dim ){
	//trovare nodi isolati (quindi grado 0)
	int *C= calloc(dim,sizeof(int)); //array accumulatore il cui indice corrisponde al nodo mentre i suoi valori alla presenza di archi

	for(int i=0;i<dim;i++){
		for(int j=0;j<dim;j++){
			if(A[i][j]==0)//se e' un nodo isolato allora
				C[i]++; //incrementa. Intuitivamente il nodo i isolato e' quello la cui C[i]=dim.
		}
	}
		printf("Nodi isolati =>");
	for(int i=0;i<dim;i++){
		if(C[i]==dim)
			printf(" %d",i);//stampo l'indice che equivale al nodo isolato
	}
}
int checkGraphRegularity(int **A,int dim){
		int *C= calloc(dim,sizeof(int));
		for(int i=0;i<dim;i++){
			for(int j=0;j<dim;j++){
				if(A[i][j]==1)//se esiste l'arco
					C[i]++;//incremento il grado
			}
		}
		for(int i=0;i<dim-1;i++){
			if(C[i]!=C[i+1]) //Se sono uguali non entra nella condizione e ritorna 1 (Regolare). Altrimenti 0 (non regolare).
				return 0;
																				
													
		}
		return 1;
}

int main(){
	int **A,**C,dim,maxarkval;

	printf("Insert size of A\n");
	scanf("%d",&dim);
	A = creazione(dim);
	inserimento(A,dim);
	Output(A,dim);
	printf("Elemento con piu archi => %d\n",mostarkedval(A,dim));
	detectIsolatedNodes(A,dim);
	printf("\n");
	printf("Grafo regolare = 1, Irregolare = 0  => %d\n",checkGraphRegularity(A,dim));
}
