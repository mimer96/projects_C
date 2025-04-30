#include "lista_bidirezionale.h"

// Creazione di una nuova lista vuota
void createList(PList lista){
    lista->counter = 0;
    lista->head = NULL;
    lista->tail = NULL;
}

// Stampa in console i nodi della lista
void printList(PList lista){
    Node* tmp = lista->head;
    while(tmp != NULL){
        printf(" %d ", tmp->key);
        tmp = tmp->next;
    }
    printf("NULL\n");
}

// Inserisce un nuovo nodo in testa alla lista
void insertHead(PList lista, int key){

    // Controllo se lista esiste
    if(lista == NULL) exit(1);

    // Creazione nodo
    Node* newNode = (Node*)malloc(sizeof(Node));
    if(newNode == NULL) exit(1);
    newNode->key = key;
    newNode->prec = NULL;
    newNode->next = NULL;

    // Aggiunta nuovo nodo in testa alla lista
    if(lista->counter == 0){
        lista->head = newNode;
        lista->tail = newNode;
    }
    else{
        lista->head->prec = newNode;
        newNode->next = lista->head;
        lista->head = newNode;
    }

     // Incremento del numero di nodi presenti in lista
    lista->counter++;
}

// Inserisce un nuovo nodo in coda alla lista
void insertTail(PList lista, int key){

    // Controllo se lista esiste
    if(lista == NULL) exit(1);

    // Creazione nodo
    Node* newNode = (Node*)malloc(sizeof(Node));
    if(newNode == NULL) exit(1);
    newNode->key = key;
    newNode->next = NULL;
    newNode->prec = NULL;

    // Aggiunta nuovo nodo in coda alla lista
    if(lista->counter == 0){
        lista->head = newNode;
        lista->tail = newNode;
    }
    else{
        lista->tail->next = newNode;
        newNode->prec = lista->tail;
        lista->tail = newNode;
    }

     // Incremento del numero di nodi presenti in lista
    lista->counter++;
}

// Inserisce un nuovo nodo in posizione x
void insertInPosition(PList lista, int key, int position){

    // Controllo se lista esiste
    if(lista == NULL) exit(1);

    // Verifica della position
    if(position < 1) exit(1);

    // Creazione nodo
    Node* newNode = (Node*)malloc(sizeof(Node));
    if(newNode == NULL) exit(1);
    newNode->key = key;
    newNode->next = NULL;
    newNode->prec = NULL;

    // Aggiunta nuovo nodo in position della lista
    if(lista->counter == 0){
        lista->head = newNode;
        lista->tail = newNode;
    }
    if(position == 1) insertHead(lista, key);
    if(position >= lista->counter) insertTail(lista, key);
    if(position > 1 && position < lista->counter){
        int counter = 1;
        for(Node* tmp = lista->head; tmp != lista->tail; tmp = tmp->next){
            if(counter == position){
                newNode->next = tmp;
                newNode->prec = tmp->prec;
                tmp->prec->next = newNode;
                tmp->prec = newNode;
                lista->counter++;
            }
            counter++;
        }
    }
}
