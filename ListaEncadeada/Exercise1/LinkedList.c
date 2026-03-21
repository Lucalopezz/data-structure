#include <stdlib.h>
#include <stdio.h>
#include "LinkedList.h"

struct node
{
    Car *car;
    struct node *prox;
};


struct list
{
    Node *begin;
    Node *end;
};

List *createLinkedList()
{
    List *l = (List *)malloc(sizeof(List));
    if (l)
    {
        l->begin = NULL;
        l->end = NULL;
    }
    return l;
}
int isListEmpty(List *l)
{
    return l->begin == NULL;
}

int insertBegin(List *l, Car *car)
{
    Node *n = (Node *)malloc(sizeof(Node));
    if (n == NULL)
        return ERROR;

    int wasEmpty = isListEmpty(l);
    n->car = car;
    // Here begin is null
    n->prox = l->begin;
    // And here begin is this first node
    l->begin = n;

    // In case the list is total empty
    if (wasEmpty)
    {
        l->end = n;
    }

    return SUCCESS;
}
int insertEnd(List *l, Car *car)
{
    Node *n = (Node *)malloc(sizeof(Node));
    if (n == NULL)
        return ERROR;

    n->car = car;
    n->prox = NULL;

    // If the list is empty, the end is the first node
    if (isListEmpty(l))
        l->begin = n;
    else // If the list is not empty, the end is the new node
        l->end->prox = n;
    // And the end is the new node
    l->end = n;

    return SUCCESS;
}

int insertAfter(List *l, Car *car, Car *existing_car)
{
    Node *aux = search(l, existing_car);
    if (aux == NULL)
        return ERROR;

    Node *n = (Node *)malloc(sizeof(Node));
    if (n == NULL)
        return ERROR;

    // Add the car in the node
    n->car = car;
    //      5
    //       \
    // 1 2 3 4
    // Update the new node prox with the aux prox address
    n->prox = aux->prox;
    //       5
    //      /
    // 1 2 3 4
    // Update the aux prox with the new node
    aux->prox = n;

    if (aux == l->end)
        l->end = n;

    return SUCCESS;
}
Node *search(List *l, Car *car)
{
    Node *searchedCar = l->begin;
    while (searchedCar != NULL && searchedCar->car != car)
    {
        searchedCar = searchedCar->prox;
    }
    return searchedCar;
}
int removeCar(List *l, Car *car)
{
    if (isListEmpty(l))
        return ERROR;

    // Aux1 is the node that will be removed, and aux2 is the previous node of aux1
    Node *aux1 = l->begin;
    Node *aux2 = NULL;

    while (aux1 != NULL && aux1->car != car)
    {
        aux2 = aux1;
        aux1 = aux1->prox;
    }
    if (aux1 == NULL) // does not find the searched car
        return ERROR;

    // If the car is in the beginning of the list, the begin is the next node
    if (aux1 == l->begin)
    {
        l->begin = l->begin->prox;
        // If the list is empty after removing the car, the end is also NULL
        if (l->begin == NULL)
            l->end = NULL;
    }
    // If the car is in the end of the list,
    // the previous node prox is NULL and the end is the previous node
    else if (aux1 == l->end)
    {
        aux2->prox = NULL;
        l->end = aux2;
    }
    // If the car is in the middle of the list, the previous node prox is the next node
    else
    {
        aux2->prox = aux1->prox;
    }
    free(aux1);
    return SUCCESS;
}

void showList(List *l)
{
    if (isListEmpty(l))
        printf("List is empty");
    else
    {
        Node *aux = l->begin;
        while (aux != NULL)
        {
            showCar(aux->car);
            aux = aux->prox;
        }
    }
}
void destroyList(List *l)
{
    if (l == NULL)
        return;

    Node *aux = l->begin;
    while (aux != NULL)
    {
        Node *temp = aux;
        aux = aux->prox;
        destroyCar(temp->car);
        free(temp);
    }
    free(l);
}
