#include <stdio.h>
#include <stdlib.h>
#include "List.h"

int main()
{
    List *l = createList();
    Vehicle *v1 = createVehicle("Fiat", "ABC1234");
    Vehicle *v2 = createVehicle("GM", "XYZ5678");
    Vehicle *v3 = createVehicle("Ford", "DEF9012");

    insert(l, *v1, 0);
    insert(l, *v2, 1);
    insert(l, *v3, 2);

    printList(l);

    removeByCarPlate(l, "XYZ5678");

    printf("\nAfter removing by car plate:\n");
    printList(l);

    destroyVehicle(v1);
    destroyVehicle(v2);
    destroyVehicle(v3);
    free(l);
    return 0;
}