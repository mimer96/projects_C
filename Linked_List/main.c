#include <stdio.h>
#include <stdlib.h>
#include "lista_bidirezionale.h"

int main()
{
    LinkedList t;
    createList(&t);
    insertHead(&t, 5);
    insertTail(&t, 8);
    insertInPosition(&t, 9, 1);
    deleteInPosition(&t, 2);
    deleteInPosition(&t, 2);
    printList(&t);
}
