/** mystring.h
 * @author Mike Ciaraldi
 * My own versions of some of the C-style string functions
*/

char* mystrdup(const char* src);
char * myStrnDup(const char * src, size_t n);
char * myStrCat(char* dest, const char* src);
char * myStrnCat(char* dest, const char* src, size_t n);
int myStrLen(const char* src);
char* myStrCpy(char* dest, const char* src);
char * myStrnCpy(char* dest, const char*src, size_t n);
