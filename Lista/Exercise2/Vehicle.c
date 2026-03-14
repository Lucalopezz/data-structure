#include <stdlib.h>
#include <string.h>
#include "Vehicle.h"


Vehicle *createVehicle(char model[20], char car_plate[8])
{
    Vehicle *vehicle = (Vehicle *)malloc(sizeof(Vehicle));
    strcpy(vehicle->model, model);
    strcpy(vehicle->car_plate, car_plate);
    return vehicle;
}
int getCarPlate(Vehicle *vehicle, char car_plate[8])
{
    if (vehicle != NULL)
    {
        strcpy(car_plate, vehicle->car_plate);
        return SUCCESS;
    }
    return ERROR;
}
void destroyVehicle(Vehicle *vehicle)
{
    if (vehicle != NULL)
    {

        free(vehicle);
    }
}