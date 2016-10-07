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


	game = (char**) malloc(rows);
	solutions = (bool**) malloc(rows);

	for (uint16_t r = 0; r < rows; r++) {
		*(game + r) = (char*) malloc(cols);
		*(solutions + r) = (bool*) malloc(cols);
		for (uint16_t c = 0; c < cols; c++) {
			char letter;
			do
				letter = getchar();
			while (letter == '\n' || letter == ' ');

			charAt(game, r, c) = letter;
			charAt(solutions, r, c) = false;
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


	findWords();
}
