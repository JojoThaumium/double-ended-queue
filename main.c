#include <stdio.h>
#include "dqlib.h"

int main() {
	
cell* cellback = newdequeue(5);
cell* cellfront = addfront(7, cellback);
cellback = addback(13, cellback);
printall(cellfront);
cellfront = popfront(cellfront);
cellback = popback(cellback);
	//printf("%d\n", cellback->data);
	//printf("%d\n", cellfront->data);
printall(cellfront);
freedequeue(cellfront);
	
	return 0;
}
