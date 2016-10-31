/**@file
 * @author Ben Hylak
 *
 * Funcion prototypes for String operations. 
*/

char* mystrdup(const char* src);
char * myStrnDup(const char * src, size_t n);
char * myStrCat(char* dest, const char* src);
char * myStrnCat(char* dest, const char* src, size_t n);
int myStrLen(const char* src);
char* myStrCpy(char* dest, const char* src);
char * myStrnCpy(char* dest, const char*src, size_t n);
char getRandomChar();
int getRandomInt(int min, int max);
char* getRandomString(int length);
