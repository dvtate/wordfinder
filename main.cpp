#include <stdlib.h>
#include <stdio.h>
#include <wchar.h>
#include <inttypes.h>
#include <iostream>


#include "utils.hpp"

uint16_t rows, cols;

char** game;
char* words;
size_t words_len = 64;

int main(){

	std::cout <<"Number of rows: ";
	std::cin >>rows;
	std::cout <<"Number of cols: ";
	std::cin >>cols;


	game = (char**) malloc(rows);

	for (uint16_t r = 0; r < rows; r++) {
		*(game + r) = (char*) malloc(cols);
		for (uint16_t c = 0; c < cols; c++) {
			char letter;
			do
				letter = getchar();
			while (letter == '\n' || letter == ' ');

			charAt(game, r, c) = letter;
		}
	}


	putchar('\n');
	for (uint16_t r = 0; r < rows; r++) {
		putchar('\n');
		for (uint16_t c = 0; c < cols; c++)
			putchar(charAt(game, r, c));
	}
	std::cout <<std::endl <<"Enter the words to find (separated by spaces):";




	char* words = (char*) malloc(64);
	getline();
		if (getline(&words, &words_len, stdin) == -1)
			return; // EOF


}
