#include "lista_bidirezionale.h"

void createList(PList lista){
    lista->counter = 0;
    lista->head = NULL;
    lista->tail = NULL;
}

void printList(PList lista){
    Node* tmp = lista->head;

    while(tmp != NULL){
        printf(" %d ", tmp->key);
        tmp = tmp->next;
    }
    printf("NULL\n");
}

void insertHead(PList lista, int key){
    // Creazione nodo
    Node* newNode = (Node*)malloc(sizeof(Node));
    if(newNode == NULL) exit(1);
    newNode->key = key;
    newNode->next = lista->head;
    newNode->prec = NULL;

    // Modifiche in head of the list
    if(lista->head == NULL){
        lista->head = newNode;
    }
    else lista->head->prec = newNode;

    // Modifiche in tail of the list
    if(lista->tail == NULL){
        lista->tail = newNode;
    }
     // Incremento del numero di nodi presenti in list
    lista->counter++;
}

