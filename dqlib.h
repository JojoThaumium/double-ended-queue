#include <stdio.h>
#include <stdlib.h>
typedef struct cell
{
 //Platz für Daten
 int data;
 //Verkettungen
 void* prev;
 void* next;
} cell;

typedef struct header
{
 //Platz für Daten
 unsigned int size;
 //Verkettungen
 cell* last;
 cell* first;
} header;

//Initialisierung des Headers

header* newdequeueheader()
{
 header* temp = calloc(1,sizeof(header));
 if(temp == NULL)
 {
  printf("Error while allocating the header.\n");
  exit(1);
 }
 return temp;
}
///löscht alle Zellen und den Header
void freedequeue(header* anchor)
{ 
 if(anchor->size)
 {
  cell* todelete;

  for (int i=anchor->size; i>0; i--)
  {
   todelete = anchor->first;
   anchor->first = anchor->first->next;
   free(todelete); 
  }
 } 
  free(anchor);
};

//Erstellt eine neue Zelle...
cell* newcell(int content)
{
 cell* temp = calloc(1,sizeof(cell));
 if(temp == NULL)
 {
  printf("Error while allocating a cell.\n");
  return NULL;
 }
 else
 {
  temp->data = content;
  return temp;
 }
};
//...und hängt sie vorne an eine DEQueue an
int addfront(header* anchor, int content)
{

 cell* temp = newcell(content);
 if(temp==NULL)
 {
  freedequeue(anchor);
  exit(1);
 }
 if(anchor->size)
 {
  temp->next = anchor->first;
  anchor->first->prev = temp;
 }
 else
 {
  anchor->last =temp;
 }
 anchor->first = temp;
 anchor->size++;
 return 0;
};
//...und hängt sie hinten an eine DEQueue an
int addback(header* anchor, int content)
{
 cell* temp = newcell(content);
 if(temp==NULL)
 {
  freedequeue(anchor);
  exit(1);
 }
 if(anchor->size)
 {
 temp->prev = anchor->last;
 anchor->last->next = temp;
 }
 else
 {
  anchor->first = temp;
 }
 anchor->last = temp;
 anchor->size++;
 return 0;
};
//löscht die forderste Zelle (die man der Funktion gibt), gibt die neue forderste Zelle zurück 
int popfront (header* anchor)
{
 if(anchor->size)
 {
  cell* temp = anchor->first->next;
  free(anchor->first);
  anchor->first = temp;
  anchor->size--;
  if(anchor->size)
  {
   temp->prev = NULL;
  }
  else
  {
   anchor->last = NULL;
  }
  return 0;
 }
 else
 {
  return 1;
 }
}
//löscht die hinterste Zelle (die man der Funktion gibt), gibt die neue hinterste Zelle zurück 
int popback (header* anchor)
{
 if(anchor->size)
 {
  cell* temp = anchor->last->prev;
  free(anchor->last);

  anchor->last = temp;
  anchor->size--;
  if(anchor->size)
  {
   temp->next = NULL;
  }
  else
  {
   anchor->first = NULL;
  }
  return 0;
 }
 else
 {
  return 1;
 }
}
//Gibt alle Daten aus

void printall(header* anchor)
{ 
 cell* temp1 = anchor->first;
 cell* temp2;
 do 
 {
  temp2 = temp1->next;

  printf("%d\n", temp1->data);

  temp1=temp2;
 }
 while (temp1 != NULL);
  

};


