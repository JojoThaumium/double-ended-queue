#include <stdio.h>
#include "dqlib.h"

int main() {

header* dqheader = newdequeueheader();

addfront(dqheader, 5);
addfront(dqheader, 6);
popback(dqheader);
addfront(dqheader, 8);
printf("Aktuelles vorderes Integer:%d\n", dqheader->first->data);
printf("Aktuelles hinteres Integer:%d\n", dqheader->last->data);
int i= dqheader->first->data;
int j= dqheader->last->data;
addback(dqheader, i);
i= i+j;
popfront(dqheader);
addfront(dqheader, i);

printf("Die double-ended Queue umfasst momentan %d Einträge.\n", dqheader->size);
printall(dqheader);
printf("Aktuelles vorderes Integer:%d\n", dqheader->first->data);
printf("Aktuelles hinteres Integer:%d\n", dqheader->last->data);
freedequeue(dqheader);

return 0;
}
