/**@file
 * Header file for StructHelper.c. Contains function prototypes and definition of struct
 */

#ifndef STRUCTHELPER_H
#define STRUCTHELPER_H

#define MAKE_CHAR_LIMIT 8
#define COLOR_CHAR_LIMIT 8

//Car structure definition
typedef struct {
    unsigned int year;
    unsigned int seats;
    unsigned int price;

    char make[MAKE_CHAR_LIMIT];
    char color[COLOR_CHAR_LIMIT];
} Car;

//Function prototypes 
Car* make_car(unsigned int year, unsigned int price, unsigned int seats, char* make, char* color);
Car* make_rand_car();
Car** make_car_array(int n);
Car** copy_car_array(Car** oldCarArr, int count);
Car** copy_car_array_deep(Car** oldCarArr, int count);
void deepCpy();
void printCar(Car* inputCar);
void printCarArr(Car** carArr, int count);
void freeCarArr(Car** carArr, int count);

#endif




