#include <stdbool.h>
struct book  {
	int data;
	struct book* next;
	struct book* prev;
};

struct book *head;// global variable - pointer to head book.
struct book *tail; 
struct book* Getnewbook(int x);
void InsertAtHead(int x);
void InsertAtTail(int x);
void Print();
void PrintbyID(int x);

void deletefrombeginning();
void deletefromend();
bool searchbyID(int x);
bool deletebyID(int x);
