
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <inttypes.h>

#include "find_words.hpp"



extern uint16_t rows, cols;
extern char** game;
extern bool** solutions;
extern char* words;
extern size_t words_len;

// These will get defined later... I'm too sleepy...
namespace diagonal {
	bool upRight(const char* word, const uint16_t& row, const uint16_t& col){

	}
	bool downRight(const char* word, const uint16_t& row, const uint16_t& col){

	}
	bool upLeft(const char* word, const uint16_t& row, const uint16_t& col){

	}
	bool downLeft(const char* word, const uint16_t& row, const uint16_t& col){

	}

};

namespace horizontal {
	bool up(const char* word, const uint16_t& row, const uint16_t& col){

	}
	bool down(const char* word, const uint16_t& row, const uint16_t& col){

	}
	bool left(const char* word, const uint16_t& row, const uint16_t& col){

	}
	bool right(const char* word, const uint16_t& row, const uint16_t& col){

	}

};

