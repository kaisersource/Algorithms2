#include<stdio.h>
#include<stdlib.h>

struct elem{
	data d;
	struct elem *next;
}
typedef struct elem LINK;

struct coda{
int cnt;
elem *testa;
elem *fondo;
};
typedef struct coda coda;

void sostituisci (LINK head){
	if(head!=NULL){
		if(head->data=='a')
			head->data='b';
		sostituisci(head->next)
		
	}
		

void aggiungi(LINK head){
	Link p;
	if(head!=NULL){
		if(head->data=='a'){
			p=head->next;
			head->next=malloc(sizeof(Elemento));
			head->next->data='b';
			head->next->next=p;
			aggiungi(p);
		}
		else
			aggiungi(head->next);
	}
}
		


void inizializzazione(code *q){
	
	q->cnt=0;
	q->testa=NULL;
	q->fondo=NULL;
}

void inserisci(dato i,coda *q){
	elem *p;
	p=malloc(sizeof(elem));
	p->d=i;
	p->next=NULL;
	if(q->cnt!=0){
		q->fondo->next=p;
		q=fondo=p;
	}
	else{
		q->head=p;
		q->fondo=p;
	}
}

void stampa(){
	while(q!=NULL){
		printf("%c",q->head);
		q=q->next;
	}
}
