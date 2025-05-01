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

    // Verifica esattezza dell'input position
    if(position < 1 || position > lista->counter + 1) exit(1);

    // Se position in testa
    if(position == 1){
        insertHead(lista, key);
        return;
    }

    // Se position in coda
    if(position == lista->counter + 1){
        insertTail(lista, key);
        return;
    }

    // Ricerca del nodo in position nella lista
    Node* tmp = lista->head;
    for(int i = 1; i < position - 1; i++)
        tmp = tmp->next;

    // Creazione nodo
    Node* newNode = (Node*)malloc(sizeof(Node));
    if(newNode == NULL) exit(1);
    newNode->key = key;
    newNode->next = NULL;
    newNode->prec = NULL;

    // Immissione del nuovo nodo nella lista
    newNode->next = tmp->next;
    newNode->prec = tmp;
    tmp->next->prec = newNode;
    tmp->next = newNode;
    lista->counter++;
}

// Elimina un nodo in testa
void deleteHead(PList lista){

    // Controllo se lista esiste
    if(lista == NULL) exit(1);

    // Elimina il nodo in testa
    if(lista->counter == 1){
        free(lista->head);
        lista->head = lista->tail = NULL;
    }
    else{
        Node* tmp = lista->head->next;
        tmp->prec = NULL;
        free(lista->head);
        lista->head = tmp;
    }
    lista->counter--;
}

//Elimina nodo in coda
void deleteTail(PList lista){

    // Controllo se lista esiste
    if(lista == NULL) exit(1);

    // Elimina il nodo in coda
    if(lista->counter == 1){
        free(lista->tail);
        lista->head = lista->tail = NULL;
    }
    else{
        Node* tmp = lista->tail->prec;
        tmp->next = NULL;
        free(lista->tail);
        lista->tail = tmp;
    }
    lista->counter--;
}

// Elimina nodo in position
void deleteInPosition(PList lista, int position){

    // Controllo se lista esiste
    if(lista == NULL) exit(1);

    // Verifica della position
    if(position < 1) exit(1);

    if(position == 1){
        deleteHead(lista);
        return;
    }

    if(position == lista->counter){
        deleteTail(lista);
        return;
    }

    Node* tmp = lista->head;
    for(int i = 1; i < position; i++)
        tmp = tmp->next;

    tmp->prec->next = tmp->next;
    tmp->next->prec = tmp->prec;
    free(tmp);

    lista->counter--;
}
