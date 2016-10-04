
// Maximum number of digits in a long integer, including possible sign
// Not necessarily portable -- this works for 64-bit longs.
#define MAX_DIGITS_IN_LONG (20)

long GCD(long A, long B);

// Class "prototypes" to solve the forward reference problem:
class GeneralNumber;
class GeneralLong;
class GeneralRational;
/***************************************/

// The parent class:

class GeneralNumber {
 public:
  virtual char* toString() const = 0;
  char* foo() const; // Not a virtual function!
  virtual GeneralLong* toGeneralLong() const = 0;
  virtual GeneralRational* toGeneralRational() const = 0;
  virtual GeneralNumber* sumWith(GeneralNumber* num) = 0;

  static GeneralNumber* parse(const char* s);
};
/***************************************/

// Define the various subclasses:

class GeneralLong: public GeneralNumber {
 public:
  GeneralLong();
  GeneralLong(long value);
  char* toString() const;
  char* foo() const; // Not a virtual function!
  GeneralLong* toGeneralLong() const;
  GeneralRational* toGeneralRational() const;
  
  long getValue();   
  GeneralNumber* sumWith(GeneralNumber* num);
  
 private:
  long value; // This holds the value of the number.
};

class GeneralRational: public GeneralNumber {
 public:
  GeneralRational();
  GeneralRational(long top, long bottom);
  char* toString() const;
  char* foo() const; // Not a virtual function!
  GeneralLong* toGeneralLong() const;
  GeneralRational* toGeneralRational() const;
  void canonicalize();
  
  long getTop();
  long getBottom();

  GeneralNumber* sumWith(GeneralNumber* num);
 private:
  long top; // This holds the top (numerator)
  long bottom; // This holds the bottom (denominator)
};
