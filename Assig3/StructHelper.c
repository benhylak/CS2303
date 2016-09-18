/**@file
 * @author Ben Hylak
 * @Contains functions for creating/manipulating Car struct
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "StructHelper.h"
#include "mystring.h"

#define MAX_RAND_YEAR 3000
#define MAX_RAND_SEATS 500
#define MAX_RAND_PRICE 100000

/** Creates car in memory based off of parameters
 *
 * @param year Year of car
 * @param price Price of Car
 * @param seats Number of seats in car
 * @param make Make of Car (GMC, Ford, Chevy, etc.)
 * @param color Color of car
 *
 * @returns pointer to allocated struct
 */

Car* make_car(unsigned int year, unsigned int price, unsigned int seats, char* make, char* color)
{
    Car* newCar = (Car*) malloc(sizeof(Car));

    newCar->year = year; 
    newCar->price = price;
    newCar->seats = seats;
    
    strncpy(newCar->make, make, MAKE_CHAR_LIMIT);
    strncpy(newCar->color, color, COLOR_CHAR_LIMIT);

    return newCar;
} 

/** Creates car struct in memory with randomly initialized fields.
 * 
 * @returns pointer to allocated car
 *
 */
Car* make_rand_car()
{
    Car* newCar = (Car*) malloc(sizeof(Car));

    newCar->year = getRandomInt(0, MAX_RAND_YEAR);
    newCar->price = getRandomInt(0, MAX_RAND_PRICE);
    newCar->seats = getRandomInt(0, MAX_RAND_SEATS);

    char* randMake = getRandomString(MAKE_CHAR_LIMIT);
    char* randColor = getRandomString(COLOR_CHAR_LIMIT);

    strncpy(newCar->make, randMake, 8);
    strncpy(newCar->color, randColor, COLOR_CHAR_LIMIT);

    free(randMake);
    free(randColor);

    return newCar;
}

/**! Creates an array of Car structs of size n
 *
 * Allocates an array for n car structs, each car initialized with random data using make_rand_car
 *
 * @param n Number of structs in array
 * @returns pointer to new array
 */

Car** make_car_array(int n)
{
    Car** newCarArr = malloc(sizeof(Car*) * n);

    for(int i=0; i<n; i++)
    {
        newCarArr[i] = make_rand_car();
    }
    
    return newCarArr;
}

/**Prints car struct
 *
 * @param inputCar Car to print
 */
void printCar(Car* inputCar)
{
    printf("Make: %s\n Year: %d\n Color: %s\n Seats: %d\n Price: $%d\n", 
            inputCar->make, inputCar->year, inputCar->color, inputCar->seats,
            inputCar->price);
}

/*!Print an array of pointers to car structs
 *
 * Print an array of pointers to car structs using the printcar() function. 
 *
 * @param carArr Array of pointers to car structs
 * @param count Count of pointers in array
 */
void printCarArr(Car** carArr, int count)
{
    for(int i=0; i<count; i++)
    {
        printCar(*carArr++); //send print function a pointer to the car and then increment
    }
}

/** Makes a shallow copy of an array of pointers to car structs
 *
 * @param oldCarArr Array of pointers to car structs
 * @param count Count of pointers in array
 * @return address of new array
 */
 
Car** copy_car_array(Car** oldCarArr, int count)
{
    Car** newCarArr = calloc(count, sizeof(Car*));

    for(int i=0; i<count; i++)
    {
        newCarArr[i] = oldCarArr[i];
    }

    return newCarArr;
}

/** Makes a deep copy of an array of pointers to car structs
 *
 * Makes a deep copy by depublicating the structs and then filling a new array with pointers
 * to the new structs
 *
 * @param oldCarArr Array to be deep copied
 * @param count Number of car pointers to be deep copied
 * @return Address of new array
 */
Car** copy_car_array_deep(Car** oldCarArr, int count)
{
    size_t arrMemSize = count * sizeof(Car*); //size in memory is the size of a Car pointer * num of pointers
    Car** newCarArr= (Car**)malloc(arrMemSize);

    memcpy(newCarArr, oldCarArr, arrMemSize);

    return newCarArr;
}

/** Frees an array of pointers to car structs
 *
 * @param oldCarArr Array of pointers to car structs
 * @param count Count of pointers in array
 */
void freeCarArr(Car** oldCarArr, int count)
{
    int freed = 0;

    while(freed<count)
    {
        free(*(oldCarArr++));
        freed++;
    }
}
