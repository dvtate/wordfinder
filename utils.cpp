#ifndef WORDFINDER_UTILS_HPP
#define WORDFINDER_UTILS_HPP


#include <inttypes.h>
#include <string.h>

#include "utils.hpp"

void deleteNewline(char* str){
	for (uint16_t i = 0; i < strlen(str); i++, str++);
	if (*str == '\n')
		*str = '\0';
}


#endif
