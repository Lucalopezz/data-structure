#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "Car.h"

struct car
{
    char model[50];
    char car_plate[20];
    int year;
};

Car *createCar(char *model, char *car_plate, int year)
{
    Car *c = (Car *)malloc(sizeof(Car));
    if (c != NULL)
    {
        strcpy(c->model, model);
        strcpy(c->car_plate, car_plate);
        c->year = year;
    }
    return c;
}
void showCar(Car *c){
    printf("Car model: %s\n", c->model);
    printf("Car plate: %s\n", c->car_plate);
    printf("Car year: %d\n", c->year);
    printf("\n");
}
void destroyCar(Car *c){
    free(c);
}
