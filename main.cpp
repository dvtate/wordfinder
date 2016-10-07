#include <stdlib.h>
#include <stdio.h>
#include <inttypes.h>
#include <iostream>

#include "utils.hpp"
#include "find_words.hpp"

uint16_t rows, cols;
char** game;
bool** solutions;
char* words;
size_t words_len = 64;

int main(){

	std::cout <<"Number of rows: ";
	std::cin >>rows;
	std::cout <<"Number of cols: ";
	std::cin >>cols;


	game = (char**) malloc(rows * sizeof(char**));
	solutions = (bool**) malloc(rows * sizeof(bool**));

	for (uint16_t r = 0; r < rows; r++) {
		*(game + r) = (char*) malloc(cols * sizeof(char*));
		*(solutions + r) = (bool*) malloc(cols* sizeof(bool*));
		for (uint16_t c = 0; c < cols; c++) {
			char letter;
			do
				letter = getchar();
			while (letter == '\n' || letter == ' ');

			CHAR_AT(game, r, c) = letter;
			CHAR_AT(solutions, r, c) = false;
		}
	}

	/*
	putchar('\n');
	for (uint16_t r = 0; r < rows; r++) {
		putchar('\n');
		for (uint16_t c = 0; c < cols; c++)
			putchar(charAt(game, r, c));
	}*/
	std::cout <<std::endl <<"Enter the words to find (separated by spaces): ";




	words = (char*) malloc(64);
	do
		if (getline(&words, &words_len, stdin) == -1)
			return 2; // EOF
	while (*words == '\n');

	char* str = words;
	while(*++str != '\0');

	if (*--str == '\n')
		*str = '\0';


	findWords();

	// print the board with solutions highlighted in red
	putchar('\n');
	for (uint16_t r = 0; r < rows; r++) {
		putchar('\n');
		for (uint16_t c = 0; c < cols; c++)
			if (CHAR_AT(solutions, r, c) == true)
				// print the solutions in bright red
				printf("\x1B[31;1m%c\x1B[0m ", CHAR_AT(game, r, c));

			else
				printf("%c ",CHAR_AT(game, r, c));
	}


	std::cout <<std::endl;
}
