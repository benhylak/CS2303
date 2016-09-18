#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "StructHelper.h"
#include "mystring.h"
#include "time.h"

int main()
{
    srand((int)time(NULL)); //seed random generator with time

    Car* myCar = make_car(2002, 2380, 5, "GMC", "Blue"); //create car

    printCar(myCar); //print car

    Car* randomCar = make_rand_car();

    printCar(randomCar);

    Car** carArr = make_car_array(2);
    printCarArr(carArr, 2);

    Car** carArr2 = copy_car_array(carArr, 2);
    printCarArr(carArr, 2);

    Car** carArrNew = make_car_array(3);

    Car** carArrDeepCpy = copy_car_array_deep(carArrNew, 3);

    printCarArr(carArrNew, 3);
    printCarArr(carArrDeepCpy, 3);

    return 0; //success
}
