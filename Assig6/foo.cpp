#include <stdio.h>
#include <string.h>
#include "foo.h"

using namespace std;

/** Default constructor for Foo 
 */
Foo::Foo() {
  i = 0;
  x = 0.0;
}

/** Constructor for Foo 
 * @param x Just some data
 * @param x 
 */
Foo::Foo(int i, double x) {
  this->i = i;
  this->x = x;
}

/** Generates printable representation of the object.
 * @return Freshly-allocated C-style string
 */
char* Foo::toString() {
  char s[Foo::MAX_TOSTRING]; // Temporary place to build the string
  sprintf(s, "i = %d, x = %f", i, x);

  return strdup(s); // Allocate and return a copy.
}
