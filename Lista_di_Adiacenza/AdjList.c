
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

typedef struct elem {
    int node;
    struct elem *next;
}elem;

typedef elem *link;


void BuildAdj (link *A, int V) {
    int x, y;
    int xCont = 0, yCont = 0;
    _Bool building = 0, xFound = 0, yFound = 0;
    char choice = 'n';
    
    printf("Another Edge ? (y/n)");
    scanf(" %c", &choice);
    printf("\n");
    if (choice == 'y')
        building = 1;
    
    while (building && xCont != (V*(V-1))/2) {
        printf("Insert an Edge: [][]");
        scanf("%d %d", &x, &y);
        printf("\n");
        if (x>=V || y>=V) {
            printf("\nEdge Exists\n");
        }
        else if (x == y) {
            printf("1 Ark to link just 1 node? U trash. \n");
        }
        else {
	// Verifying x
            if (A[x] == NULL) {
                A[x] = calloc(1, sizeof(elem));
                A[x]->node = y;
                A[x]->next = NULL;
                xCont++;
            }
            else {
                link temp = A[x];
                if (xCont == 1) {
                    if (temp->node == y)
                        xFound = 1;
                }
                while (temp->next != NULL && xFound == 0) {
                    if (temp->node == y) {
                        xFound = 1;
                    }
                    else {
                        temp = temp->next;
                    }
                }
                if (xFound == 0) {
                    temp->next = calloc(1, sizeof(elem));
                    temp->next->node = y;
                    temp->next->next = NULL;
                    xCont++;
                }
            }
// Verifying y
            if (A[y] == NULL) {
                A[y] = calloc(1, sizeof(elem));
                A[y]->node = x;
                A[y]->next = NULL;
                yCont++;
            }
            else {
                link temp = A[y];
                if (yCont == 1) {
                    if (temp->node == x)
                        yFound = 1;
                }
                while (temp->next != NULL && yFound == 0) {
                    if (temp->node == x) {
                        yFound = 1;
                    }
                    else {
                        temp = temp->next;
                    }
                }
                if (yFound == 0) {
                    temp->next = calloc(1, sizeof(elem));
                    temp->next->node = x;
                    temp->next->next = NULL;
                    yCont++;
                }
            }
            if (yFound)
                printf("\nEdge Exists\n");
            xFound = 0, yFound = 0;
        }
        printf("Another Edge ? (y/n)");
        scanf(" %c", &choice);
        printf("\n");
        if (choice == 'n') {
            building = 0;
        }
    }
    printf("Adj list created with success\n");
}

int MaxRankAdj (link *A, int V) {//elemento di rango massimo, sum corrisponde al rango massimo
    int i, sum = 0,ris;//cicle var and counter of arks 
    int *aux = calloc(V, sizeof(int));
    for (i = 0; i<V; i++) {
        link temp = A[i];
        while (temp != NULL) {
            aux[i]++;
            temp = temp->next;
        }
	
    }
    for (i = 0; i<V; i++)
        if (sum <= aux[i]) {
            sum = aux[i];
            ris=i;
        }
    return (ris);
}


void IsolatedCounter (link *A, int V) {
    int i, cont = 0;
 	
    for (int i = 0; i<V; i++) {
        if (A[i] == NULL) 
            cont++;
    }
    if (cont != 0){

        printf("Isolated nodes: %d, which are : ", cont);
	for (i = 0; i<V; i++) {
        if (A[i] == NULL) 
            printf("%d ", i);
            
    	}
    }
    else
        printf("No isolated nodes\n");
}



void RegularAdj (link *A, int V) {
    int i,j, sum = 0, ans, *aux = calloc(V, sizeof(int));
    _Bool regular = 1;
    for (i = 0; i<V; i++) {
        link temp = A[i];
        while (temp != NULL) {
            aux[i]++;
            temp = temp->next;
        }
    }
    
    for (i = 0; i<V-1 && regular; i++)
        if (aux[i] != aux[i+1])
            regular = 0;
    
    if (regular)
        printf("Regular\n");
    else
        printf("Not Regular\n");
}

void dfs (link *A, int num_nodes, int start_node){
    int stack[MAX_SIZE];
    int color[num_nodes+1];
    memset (color, 0, sizeof(color)); // I miss you Formis
    int top = -1;
    stack[top+1] = start_node;
    top++;
    while (top != -1){
        int current = stack[top];
        printf("%d  ",current);
        top--;
        link temp = A[current];
        while (temp != NULL){
            if (color[temp->node] == 0){
                stack[top+1] = temp->node;
                top++;
                color[temp->node] = 1;
            }
            temp = temp->next;
        }
    }

}
void bfs (link *A, int num_nodes, int start_node){
    int queue[MAX_SIZE];
    int color[num_nodes+1];
    memset (color, 0, sizeof (color));
    int front=-1, rear=-1;
    queue[rear+1] = start_node;
    rear++;
	printf("\n");
    while (front != rear){
        front++;
        int current = queue[front];
        printf("%d  ",current);

        link temp = A[current];
        while (temp != NULL)
        {
            if (color[temp->node] == 0)
            {
                queue[rear+1] = temp->node;
                rear++;
                color[temp->node] = 1;
            }
            temp = temp->next;
        }
    }

}  

#define V 20

int main() {
    link *A = calloc (V, sizeof(link));//List's Array creation
    BuildAdj(A, V);
    printf("Max rank: %d\n", MaxRankAdj(A, V));
    IsolatedCounter(A, V);
	printf("\n");
    RegularAdj(A, V);
    dfs(A,V,1);//u choose where to start, jew (default 1)
    bfs(A,V,1);
return 0;
}


