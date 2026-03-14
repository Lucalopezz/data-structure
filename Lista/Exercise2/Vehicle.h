#define ERROR 0
#define SUCCESS 1

typedef struct vehicle
{
    char model[20];
    char car_plate[8];
} Vehicle;

Vehicle *createVehicle(char model[20], char car_plate[8]);
int getCarPlate(Vehicle *vehicle, char car_plate[8]);
void destroyVehicle(Vehicle *vehicle);
