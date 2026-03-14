#define ERROR 0
#define SUCCESS 1
#include "Vehicle.h"

typedef struct list List;

List *createList();
int insert(List *l, Vehicle v, int pos);
int removeCar(List *l, int pos);
int removeByCarPlate(List *l, char *car_plate);

void printList(List *l);