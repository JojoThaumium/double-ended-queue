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

//Erstellt eine neue Zelle...
cell* newdequeue(int content)
{
 cell* temp = calloc(1,sizeof(cell));
 temp->data = content;
 return temp;
};
//...und hängt sie vorne an eine DEQueue an
cell* addfront(int content, cell* anchor)
{
 cell* temp = newdequeue(content);
 temp->next = anchor;
 anchor->prev = temp;
 return temp;
};
//...und hängt sie hinten an eine DEQueue an
cell* addback(int content, cell* anchor)
{
 cell* temp = newdequeue(content);
 temp->prev = anchor;
 anchor->next = temp;
 return temp;
};
//löscht die forderste Zelle (die man der Funktion gibt), gibt die neue forderste Zelle zurück 
cell* popfront (cell* anchor)
{
 cell* temp = anchor->next;
 free(anchor);
 temp->prev = 0;
 return temp;
}
//löscht die hinterste Zelle (die man der Funktion gibt), gibt die neue hinterste Zelle zurück 
cell* popback (cell* anchor)
{
 cell* temp = anchor->prev;
 free(anchor);
 temp->next = 0;
 return temp;
}
//Gibt alle Daten aus
void printall(cell* anchor)
{ 
 cell* temp1 = anchor;
 cell* temp2;
 do 
 {
  temp2 = temp1->next;

  printf("%d\n", temp1->data);

  temp1=temp2;
 }
 while (temp1 != NULL);
  

};
///löscht alle Zellen
void freedequeue(cell* zelle)
{ 
 cell* temp1 = zelle;
 cell* temp2;
 do 
 {
  temp2 = temp1->next;

  free(temp1);

  temp1=temp2;
 }
 while (temp1 != NULL);
  

};


