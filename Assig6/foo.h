 // Just some arbitrary class

class Foo {
public:
  Foo();
  Foo(int i, double x);
  char* toString();

private:
  int i; // just some data
  double x;
  static const int MAX_TOSTRING = 50; // Maximum length of string version
};
