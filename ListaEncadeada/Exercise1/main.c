#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"

int main()
{
    List *l = createLinkedList();

    Car *car1 = createCar("Model 1", "ABC-1234", 2020);
    Car *car2 = createCar("Model 2", "DEF-5678", 2021);
    Car *car3 = createCar("Model 3", "GHI-9012", 2022);

    insertBegin(l, car1);
    insertEnd(l, car2);
    insertAfter(l, car3, car1);

    showList(l);

    removeCar(l, car2);

    printf("After removing car2:\n");
    showList(l);

    destroyList(l);
    return 0;
}