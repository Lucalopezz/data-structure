#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "List.h"

#define MAX 100

struct list
{
    Vehicle vehicles[MAX];
    int size;
};

List *createList()
{
    List *l = (List *)malloc(sizeof(List));
    l->size = 0;
    return l;
}

int isListFull(List *l)
{
    return l->size == MAX;
}
int isListEmpty(List *l)
{
    return l->size == 0;
}

int insert(List *l, Vehicle v, int pos)
{
    if (isListFull(l))
    {
        return ERROR;
    }
    if (pos < 0 || pos > l->size)
    {
        return ERROR;
    }
    // Shift elements to the right
    for (int i = l->size; i > pos; i--)
    {
        l->vehicles[i] = l->vehicles[i - 1];
    }
    l->vehicles[pos] = v;
    l->size++;
    return SUCCESS;
}
int removeCar(List *l, int pos)
{
    if (isListEmpty(l))
    {
        return ERROR;
    }
    // Position need to be < than size
    // 0 1 2 -> size 3, so will input in the 3 pos not remove
    if (pos < 0 || pos >= l->size)
    {
        return ERROR;
    }
    for (int i = pos; i < l->size - 1; i++)
    {
        l->vehicles[i] = l->vehicles[i + 1];
    }
    l->size--;
    return SUCCESS;
}

int removeByCarPlate(List *l, char *car_plate)
{
    if (isListEmpty(l))
    {
        return ERROR;
    }
    int pos;

    for (int i = 0; i < l->size; i++)
    {
        char car_plate_search[8];
        getCarPlate(&l->vehicles[i], car_plate_search);
        if (strcmp(car_plate, car_plate_search) == 0)
        {
            removeCar(l, i);
            return SUCCESS;
        }
    }
    return ERROR;
}

void printList(List *l)
{
    for (int i = 0; i < l->size; i++)
    {
        char car_plate[8];
        getCarPlate(&l->vehicles[i], car_plate);
        printf("Model: %s, Car Plate: %s\n", l->vehicles[i].model, car_plate);
    }
}