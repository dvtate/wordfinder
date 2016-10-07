#ifndef FIND_WORDS_HPP
#define FIND_WORDS_HPP

#include <string.h>

extern uint16_t rows, cols;
extern char** game;
extern bool** solutions;
extern char* words;
extern size_t words_len;

namespace diagonal {
	bool upRight(const char* word, const uint16_t& row, const uint16_t& col);
	bool downRight(const char* word, const uint16_t& row, const uint16_t& col);
	bool upLeft(const char* word, const uint16_t& row, const uint16_t& col);
	bool downLeft(const char* word, const uint16_t& row, const uint16_t& col);
};

namespace horizontal {
	bool up(const char* word, const uint16_t& row, const uint16_t& col);
	bool down(const char* word, const uint16_t& row, const uint16_t& col);
	bool left(const char* word, const uint16_t& row, const uint16_t& col);
	bool right(const char* word, const uint16_t& row, const uint16_t& col);
};


void findWords(void){

	char* word = strtok(words, " ");
	for (;;) {
		if (word == NULL)
			return;

		std::cout <<"Finding word - \"" <<word <<"\"\n";







		word = strtok(NULL, " ");


	}
}

#endif

