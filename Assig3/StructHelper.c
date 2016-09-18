#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAKE_CHAR_LIMIT 8;
#define COLOR_CHAR_LIMIT 8;

typedef struct Car {
    unsigned int year;
    unsigned int seats;
    unsigned double price;
   
    char make[MAKE_CHAR_LIMIT];
    char color[COLOR_CHAR_LIMIT];
}

Car* make_char(int year, double price, int seats, char* make, char* color)
{
    Car* newCar = (Car*) malloc(sizeof(Car));

    newCar->year = year; 
    newCar->price = price;
    newCar->seats = seats;
    
    strncpy(newCar->make, make, MAKE_CHAR_LIMIT);
    strncpy(newCar->color, color, COLOR_CHAR_LIMIT);

    return newCar;
} 

void printCar(Car* inputCar)
{
    printf("Make: %s\n Year: %s\n Color: %s\n Seats: %d\n Price: %.2f\n", 
            inputCar->make, inputCar->year, inputCar->color, inputCar->seats
            inputCar->price);
}
