#ifndef LISTA_BIDIREZIONALE_H
#define LISTA_BIDIREZIONALE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definizione della struttura nodo
typedef struct node{
    int key;
    struct node *prec;
    struct node *next;
}Node;

// Definizione della struttura lista
typedef struct linked_list{
    int counter;
    Node *head;
    Node *tail;
}LinkedList;

// Tipo per il puntatore alla lista
typedef LinkedList* PList;


// Operations


void createList(PList lista);
void insertHead(PList lista, int key);
void insertTail(PList lista, int key);
void insertInPosition(PList lista, int key);
void deleteHead(PList lista, int key);
void deleteTail(PList lista, int key);
void deleteInPosition(PList lista, int key);
void printList(PList lista);
void deleteList(PList lista);

#endif // LISTA_BIDIREZIONALE
