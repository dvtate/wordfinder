
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
		// check if word is there
		for (uint16_t i = 0; i < strlen(word); i++)
			if (row - i < 0 || col + i >= cols)
				return false;
			else if (CHAR_AT(game, row - i, col + i) != *(word + i))
				return false;

		// paint word on board
		for (uint16_t i = 0; i < strlen(word); i++)
			CHAR_AT(solutions, row - i, col + i) = true;

		return true;
	}
	bool downRight(const char* word, const uint16_t& row, const uint16_t& col){
		// check if word is there
		for (uint16_t i = 0; i < strlen(word); i++)
			if (row + i >= rows || col + i >= cols)
				return false;
			else if (CHAR_AT(game, row + i, col + i) != *(word + i))
				return false;

		// paint word on board
		for (uint16_t i = 0; i < strlen(word); i++)
			CHAR_AT(solutions, row + i, col + i) = true;

		return true;

	}
	bool upLeft(const char* word, const uint16_t& row, const uint16_t& col){
		// check if word is there
		for (uint16_t i = 0; i < strlen(word); i++)
			if (row - i < 0 || col - i < 0)
				return false;
			else if (CHAR_AT(game, row - i, col - i) != *(word + i))
				return false;

		// paint word on board
		for (uint16_t i = 0; i < strlen(word); i++)
			CHAR_AT(solutions, row - i, col - i) = true;

		return true;
	}
	bool downLeft(const char* word, const uint16_t& row, const uint16_t& col){
		// check if word is there
		for (uint16_t i = 0; i < strlen(word); i++)
			if (row + i >= rows || col - i < 0)
				return false;
			else if (CHAR_AT(game, row + i, col - i) != *(word + i))
				return false;

		// paint word on board
		for (uint16_t i = 0; i < strlen(word); i++)
			CHAR_AT(solutions, row + i, col - i) = true;

		return true;
	}

}

namespace horizontal {
	bool up(const char* word, const uint16_t& row, const uint16_t& col){
		// check if word is there
		for (uint16_t i = 0; i < strlen(word); i++)
			if (row - i < 0)
				return false;
			else if (CHAR_AT(game, row - i, col) != *(word + i))
				return false;

		// paint word on board
		for (uint16_t i = 0; i < strlen(word); i++)
			CHAR_AT(solutions, row - i, col) = true;


		return true;
	}
	bool down(const char* word, const uint16_t& row, const uint16_t& col){
		// check if word is there
		for (uint16_t i = 0; i < strlen(word); i++)
			if (row + i >= rows)
				return false;
			else if (CHAR_AT(game, row + i, col) != *(word + i))
				return false;

		// paint word on board
		for (uint16_t i = 0; i < strlen(word); i++)
			CHAR_AT(solutions, row + i, col) = true;


		return true;
	}
	bool left(const char* word, const uint16_t& row, const uint16_t& col){
		// check if word is there
		for (uint16_t i = 0; i < strlen(word); i++)
			if (col - i < 0)
				return false;
			else if (CHAR_AT(game, row, col - i) != *(word + i))
				return false;

		// paint word on board
		for (uint16_t i = 0; i < strlen(word); i++)
			CHAR_AT(solutions, row, col - i) = true;


		return true;
	}
	bool right(const char* word, const uint16_t& row, const uint16_t& col){
		// check if word is there
		for (uint16_t i = 0; i < strlen(word); i++)
			if (col + i >= cols)
				return false;
			else if (CHAR_AT(game, row, col + i) != *(word + i))
				return false;

		// paint word on board
		for (uint16_t i = 0; i < strlen(word); i++)
			CHAR_AT(solutions, row, col + i) = true;


		return true;
	}

}



void findWords(void){

	char* word = strtok(words, " ,");
	while (word && *word) {

		//std::cout <<"Finding word - \"" <<word <<"\"\n";



		for (uint16_t r = 0; r < rows; r++)
			for (uint16_t c = 0; c < cols; c++) {
				// if the first letter of the word is found
				if (CHAR_AT(game, r, c) == *word) {

					// see if the rest of the word is there
					if (diagonal::upRight(word, r, c))
						goto next_word;
					else if (diagonal::downRight(word, r, c))
						goto next_word;
					else if (diagonal::upLeft(word, r, c))
						goto next_word;
					else if (diagonal::downLeft(word, r, c))
						goto next_word;

					else if (horizontal::up(word, r, c))
						goto next_word;
					else if (horizontal::down(word, r, c))
						goto next_word;
					else if (horizontal::left(word, r, c))
						goto next_word;
					else if (horizontal::right(word, r, c))
						goto next_word;


				}

			}

		printf("\aWarning: couldn\'t find word \"%s\"\n", word);

next_word:
		word = strtok(NULL, " ,");


	}
}

