#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "GeneralNumber.h"

/** Program to demonstrate the GeneralNumber class and its subclasses.
 * @param argc Number of words on the command line.
 * @param argv Arrray of pointers to these words.
 */
int main(int argc, char* argv[]) {

  GeneralNumber* g1 = new GeneralNumber();
  char* gs = g1->toString(); // Generate string version.
  printf("%s\n", gs); 
  // We don't need the string any more.
  free(gs);
  gs = g1->foo(); // Test non-virtual function
  printf("%s\n", gs); 
  free(gs);

  GeneralLong* g2 = new GeneralLong(2000L);
  gs = g2->toString(); // Generate string version.
  printf("%s\n", gs); 
  free(gs);
  gs = g2->foo(); // Test non-virtual function
  printf("%s\n", gs); 
  free(gs);

  GeneralNumber* g3 = new GeneralLong(5000L);
  gs = g3->toString(); // Generate string version.
  printf("%s\n", gs); 
  free(gs);
  gs = g3->foo(); // Test non-virtual function
  printf("%s\n", gs); 
  free(gs);

  GeneralNumber* g4 = new GeneralRational(4000L, 3000L);
  gs = g4->toString(); // Generate string version.
  printf("%s\n", gs); 
  free(gs);
  gs = g4->foo(); // Test non-virtual function
  printf("%s\n", gs); 
  free(gs);

  // Now for some conversions!

  GeneralNumber* g5 = g2->toGeneralRational();
  gs = g5->toString(); // Generate string version.
  printf("%s\n", gs); 
  free(gs);

  GeneralNumber* g6 = g4->toGeneralLong();
  gs = g6->toString(); // Generate string version.
  printf("%s\n", gs); 
  free(gs);

  // We don't need the objects any more.
  delete(g1);
  delete(g2);
  delete(g3);
  delete(g4);
}
