#define MAX_LINE_LEN 100

typedef enum{false, true} bool;
typedef enum{SUCCESS=0, FAILURE=1} status;


/*
 * readString - reads a line from a file given by
 * fileName and returns it as a c-string.  The line
 * return is removed from the string.
 * 
 * fileName is c-string representing the file to read.
 * 
 */
char* readString(char* fileName);

/*
 * mysteryExplode - takes a string of characters and explodes it
 * as follows:
 * 
 * A non-empty string such as "Code" is turned into "CCoCodCode".
 *
 *   Return a new string similar to the string given above.
 *
 *  Example:
 *   mysteryExplosion("Code") --> "CCoCodCode"
 *   mysteryExplosion("abc") --> "aababc"
 *   mysteryExplosion(":)") --> "::)"
 * 
 */
char* mysteryExplode(const char* str);
