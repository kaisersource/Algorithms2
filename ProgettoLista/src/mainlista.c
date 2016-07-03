#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include "lista.h"

int main() {
	int add;
	char scelta;
	printf("|->-<->-<->-<->-<->-<->-<->-<->-<->-<->-<-|\n");
	printf("|---------Salve. Cosa vuoi fare?----------|\n");
	printf("| 	a- Inserimento in testa	   	  |\n");
	printf("| 	b- Inserimento in coda            |\n");
	printf("| 	c- Eliminazione in testa          |\n");
	printf("| 	d- Eliminazione in coda           |\n");
	printf("| 	e- Eliminazione per ID            |\n");
	printf("| 	f- Ricerca di un elemento per ID  |\n");
	printf("| 	g- Output della lista             |\n");
	printf("| 	h- Output della lista per ID      |\n");
	printf("| 	q- Uscire dal programma           |\n");
	printf("|->-<->-<->-<->-<->-<->-<->-<->-<->-<->-<-|\n");
	printf("\n");
	do{

	scanf("%c",&scelta);
		switch(scelta){
			case 'a':
				printf("\nInserisci l'elemento in testa...\n");
				scanf("%d",&add);
				InsertAtHead(add);
				printf("...aggiunta in corso...");
				printf("\n...aggiunto. Che vuoi fare ?");
				sleep(2);
			break;
			case 'b':
				printf("\nInserisci l'elemento in coda\n");
				scanf("%d",&add);
				printf("...aggiunta in corso...");
				InsertAtTail(add);
				printf("\n...aggiunto. Che vuoi fare ?");
				sleep(2);

			break;
			case 'c':

				printf("\n...Eliminazione in corso...");
				deletefrombeginning();
				printf("\n...Elemento eliminato. Che vuoi fare ?");
				sleep(2);
			break;
			case 'd':
  				printf("\n...Eliminazione in corso...");
				deletefromend();
				printf("\n...Elemento eliminato. Che vuoi fare ?");
				sleep(2);
			break;
			case 'e':
				printf("\nQuale elemento vuoi eliminare?");
				scanf("%d",&add);
				printf("...Eliminazione in corso...");
				deletebyID(add);
				printf("\n...Elemento eliminato. Che vuoi fare ?");
				sleep(2);
			break;
			case 'f':
				printf("\nQuale elemento vuoi verificare?");
				scanf("%d",&add);
				printf("...Verifica in corso...");
				if(searchbyID(add)==1){
					printf("\n...L'elemento esiste. Che vuoi fare ?");
					sleep(2);
				}
				else{
					printf("\n...L'elemento non esiste. Che vuoi fare ?");
					sleep(2);
				}
			break;
			case 'g':
				printf("\n...Output in corso...\n");
				sleep(2);
				Print();
				printf("...Output eseguito. Che vuoi fare?");





			break;
			case 'h':
				printf("Inserisci ID per visualizzare l'elemento");
				scanf("%d",&add);
				PrintbyID(add);
				printf("...Output eseguito. Che vuoi fare?");
				sleep(2);
			break;
		}
	}while(scelta!='q');
	printf("...");
	printf("Alla prossima!\n");
	sleep(2);
	
	
	
return 0;
}
/*
int main() {

	//printf("Inserimento in testa: ");InsertAtHead(2); Print();
	//printf("Inserimento in testa: ");InsertAtTail(2); Print();
	//printf("Inserimento in testa: ");InsertAtHead(2); Print();
	printf("Inserimento in coda: ");InsertAtTail(4); Print();
	printf("Inserimento in testa: ");InsertAtHead(6); Print();
	//printf("Inserimento in coda: ");InsertAtTail(8); Print();
	printf("Eliminazione in coda: ");deletefromend();Print();
	//printf("Eliminazione in testa: ");deletefrombeginning();Print();

	printf("Valore di Restituzione della ricerca per ID: %d\n", searchbyID(4));
	printf("Inserimento in coda: ");InsertAtTail(3); Print();
	printf("Eliminazione per ID: %d -- Lista dopo eliminazione: \n", deletebyID(2)); Print();
	printf("Output per ID : ");PrintbyID(2);

return 0;}*/
