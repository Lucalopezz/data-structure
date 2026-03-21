#include "Car.h"

#define ERROR 1
#define SUCCESS 0

typedef struct list List;
typedef struct node Node;
List *createLinkedList();
int insertBegin(List *l, Car *car);
int insertEnd(List *l, Car *car);
int insertAfter(List *l, Car *car, Car *existing_car);
Node *search(List *l, Car *car);
int removeCar(List *l, Car *car);

void showList(List *l);
void destroyList(List *l);
