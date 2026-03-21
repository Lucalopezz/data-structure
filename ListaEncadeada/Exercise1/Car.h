typedef struct car Car;

Car *createCar(char *model, char *car_plate, int year);
void showCar(Car *c);
void destroyCar(Car *c);
