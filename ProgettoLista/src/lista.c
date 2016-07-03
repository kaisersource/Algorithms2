/* Doubly Linked List implementation */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include "lista.h"


//Creates a new book and returns pointer to it.
struct book* Getnewbook(int x) {
	struct book* newbook = (struct book*)malloc(sizeof(struct book));
	newbook->data = x;
	newbook->prev = NULL;
	newbook->next = NULL;
	return newbook;
}

//Inserts a book at head of doubly linked list
void InsertAtHead(int x) {
	struct book* newbook = Getnewbook(x);
	if(head == NULL) {
		head =tail= newbook;
		return;
	}
	head->prev = newbook;
	newbook->next = head;
	head = newbook; //nuova testa impostata
}

//Inserts a book at tail of Doubly linked list
void InsertAtTail(int x) {
	struct book* temp = head;
	struct book* newbook = Getnewbook(x);
	if(head == NULL) {
		tail=head = newbook;
		return;
	}
	while(temp->next != NULL) temp = temp->next; //scorri lista
	tail->next = newbook;
	newbook->prev = tail;
	tail=newbook; //nuova coda impostata
}

//Prints all the elements in linked list in forward traversal order
void Print() {
	struct book* temp = head;
	while(temp != NULL) {
		printf("%d ",temp->data);
		temp = temp->next;
	}
	printf("\n");
}

void PrintbyID(int x) {
	struct book* temp = head;
	while(temp != NULL) {
		if(temp->data==x)
			printf("%d ",temp->data);
		temp = temp->next;
	}
	printf("\n");
}



void deletefrombeginning(){
	struct book *temp;
         temp= (struct book*)malloc(sizeof(struct book)) ;
	temp=head;
	if(head==NULL)
		return;
	
	if(head==tail){//unico elemento della lista
		head=tail=NULL;//eliminazione
		free(temp);
		return;
	}
	else{
		(temp->next)->prev=NULL;
		head=temp->next;
		return;
	}
free(temp);

}
void deletefromend(){
	struct book *temp;
	temp= (struct book*)malloc(sizeof(struct book)) ;
	temp=tail;
	if(tail==NULL)
		return;
	if(tail==head){ //unico elemento della lista
		tail=head=NULL; //eliminazione
		free(temp);
		return;
	}else{
	
		(temp->prev)->next=NULL;//faccio puntare il penultimo elemento al nulla, sganciando quindi l'elemento finale
		tail=temp->prev;//coda è l'elemento precedente
		free(temp);
		return;
	}
	
	free(temp);
}


bool deletebyID(int x){
		
	struct book *temp;
	temp=(struct book*)malloc(sizeof(struct book));
	temp=head;
	//ciclo dentro la lista
	while(temp!= NULL){
		//se l'elemento esiste ed 
		if(temp->data==x){
			printf("ciao");
			if(temp==head){
				
				if(head==NULL)
					return 1;
				if(head==tail){ /*if there's just one element  then*/
					head=tail=NULL; //clean this element
					free(temp);
					return 1;
				}
				else{
					(temp->next)->prev=NULL;
					head=temp->next;
					free(temp);
					return 1;
				}
			
			}
		//se l'elemento x sta in coda
		
			if(temp==tail){
				
				if(tail==NULL)
					return 1; 
				if(tail==head){ 
					tail=head=NULL; 
					free(temp);
					return 1; 
				}
				else{
					(temp->prev)->next=NULL;
					tail=temp->prev;
					free(temp);
					return 1; 
				}
	
			
			}	
			//caso elemento centrale
			temp->prev->next=temp->next;
			temp->next->prev=temp->prev;
			free(temp);
			return 1;
		}
			
		//scorri se si trova diverso da x
	temp = temp->next;
		
	}
return 0;
}


bool searchbyID(int x){

	//temp = temp->next;
	struct book *temp;
	temp=(struct book*)malloc(sizeof(struct book));
	temp=head;
	if(head==NULL)
		return 0;

	// cicla nella lista
	while(temp!= NULL) {
        	if(temp->data == x){// se l'elemento c'è
			
            		return 1;//bene 
			free(temp);
		}

	temp = temp->next;//altrimenti vai avanti
	}

return 0;
free(temp);
}
	
