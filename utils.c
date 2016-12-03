#include <stdio.h>
#include "utils.h"


// removes the trailing newline character at the end of the string by replacing
// it with a nulll-terminator ('\0')
inline void deleteNewline(char* str)
{

	// there is probably a more efficient solution...
	for (uint16_t i = 0; i < strlen(str); i++, str++);
	if (*str == '\n')
		*str = '\0';
}

inline void printFileHelper(void)
{
	puts("\n\nExpected the format as followed:\n"
		 " - dimensions as numbers separated by spaces\n"
		 " - the complete puzzle, all letters as though it is being read "
		 "(left-to-right, top-to-bottom)\n - the words to find, "
		 "separated by spaces, ending in a newline.\n\n"
		);
}


//inline void printVersionInfo()
//	{ printf("%s", ver_info_txt); }
