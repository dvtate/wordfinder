#ifndef WORDFINDER_UTILS_H
#define WORDFINDER_UTILS_H

#include <string.h>
#include <inttypes.h>

extern uint16_t rows, cols;
extern char** game;



#define CHAR_AT(MAT, ROW, COL)\
		*(*((MAT) + (ROW)) + (COL))


// removes the trailing newline character at the end of the string by replacing
// it with a nulll-terminator ('\0')
void deleteNewline(char* str);

void printFileHelper(void);

#endif
