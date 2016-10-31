#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "GeneralNumber.h"

/** Program to demonstrate the GeneralNumber class and its subclasses.
 * @param argc Number of words on the command line.
 * @param argv Arrray of pointers to these words.
 */
int main(int argc, char* argv[]) {

  GeneralLong* g2 = new GeneralLong(2000L);
  char* gs = g2->toString(); // Generate string version.
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

  GeneralRational* g7 = new GeneralRational(500L, -300L);
  gs = g7->toString();

  printf("Original Form: %s\n", gs);

  g7->canonicalize();
  gs = g7->toString();
  printf("Canonical Form: %s\n", gs);

  GeneralRational* g8 = new GeneralRational(501L, -300L);
  gs = g8->toString();

  printf("Original Form: %s\n", gs); 

  g8->canonicalize();
  gs = g8->toString();
  printf("Canonical Form: %s\n", gs);

  GeneralRational* g9 = new GeneralRational(503L, 300L);
  gs = g9->toString();

  printf("Original Form: %s\n", gs); 

  g8->canonicalize();
  gs = g9->toString();
  printf("Canonical Form: %s\n", gs);

  printf("\nTESTING ADDITION: ______________________\n");

  printf("\nConstructed GeneralRational with value of 16/4\n");
  printf("\nConstructed GeneralLong with value of -2\n");
  
  GeneralRational* g10 = new GeneralRational(16L,4L);
  GeneralLong* g11 = new GeneralLong(-2L);

  GeneralRational* g12 = (GeneralRational*)g10->sumWith(g11);

  gs = g12->toString();
  printf("Added GeneralLong to Rational: %s\n", gs);

  GeneralLong* g13 = (GeneralLong*)g11->sumWith(g10);
  gs = g13->toString();
  printf("Added Rational to GeneralLong: %s\n", gs);

  GeneralNumber* parsedRational = GeneralNumber::parse(" [ 300 / 500 ]");
  gs = parsedRational->toString();
  printf("Parsed result of [ 300 / 500 ]: %s\n", gs);

  GeneralNumber* parsedLong = GeneralNumber::parse("5000");
  gs = parsedLong->toString();
  printf("Parsed result of 5000: %s\n", gs);

  GeneralNumber* parsedJunk = GeneralNumber::parse("Junk");

  if(parsedJunk == NULL) printf("Impossible Parse returned NULL (Yay!)\n");
  else printf("Impossible Parse returned %s\n", parsedJunk->toString());

//  printf("Impossible Parse (Should print NULL): %s\n", gs);
  // We don't need the objects any more.
  delete(g2);
  delete(g3);
  delete(g4);
  delete(g5);
  delete(g6);
  delete(g7);
  delete(g8);
  delete(g9);
  delete(g10);
  delete(g11);
  delete(g12);
  delete(g13);
  delete(gs);
}
