#include <stdlib.h>
#include <stdio.h>
#include <inttypes.h>
#include <ctype.h>
#include <time.h>

#include "utils.h"
#include "find_words.h"


// this adds windows support (needed since windows isn't postix-compatible)
#include "fuck_windows.h"

uint16_t rows, cols;
char** game, **solutions;
char* words;
size_t words_len = 64;

char silent = 0;

int main(int argc, char** argv){

	FILE* inputFile = stdin;

  	if (argc == 2) {
		inputFile = fopen(argv[1], "r");
		silent = 1;
	}

	if (!silent) printf("Number of rows: ");
	fscanf(inputFile, "%hu", &rows); // uint16_t == unsigned short ( "%hu" )

	if (!silent) printf("Number of cols: ");
	fscanf(inputFile, "%hu", &cols);

	if (!silent) puts("\n\nEnter the puzzle (spaces and newlines ignored):\n");

	game = (char**) malloc(rows * sizeof(char*));
	solutions = (char**) malloc(rows * sizeof(char*));

	for (uint16_t r = 0; r < rows; r++) {
		*(game + r) = (char*) malloc(cols);
		*(solutions + r) = (char*) malloc(cols);
		for (uint16_t c = 0; c < cols; c++) {
			char letter;
			do
				letter = fgetc(inputFile);
			while (letter == '\n' || isspace(letter));

			CHAR_AT(game, r, c) = letter;
			CHAR_AT(solutions, r, c) = 0;
		}
	}

	if (!silent) printf("Enter the words to find (separated by spaces): ");




	words = (char*) malloc(64);
	do
		if (getline(&words, &words_len, inputFile) == -1)
			return 2; // EOF
	while (*words == '\n');

	char* str = words;
	while(*++str != '\0');

	if (*--str == '\n')
		*str = '\0';


	// time how long it takes to solve the puzzle
	clock_t diff, start = clock();
	findWords();
	diff = clock() - start;

	int msec = diff * 1000000 / CLOCKS_PER_SEC;

	printf("\nsolved in %d milliseconds %d microseconds", msec/1000, msec%1000);

	// print the board with solutions highlighted in bright-red
	putc('\n', stdout);
	for (uint16_t r = 0; r < rows; r++) {
		putc('\n', stdout);

		for (uint16_t c = 0; c < cols; c++)

			if (CHAR_AT(solutions, r, c))
				// print the solutions in bright-red
				printf("\x1B[31;1m%c\x1B[0m ", CHAR_AT(game, r, c));

			else
				printf("%c ",CHAR_AT(game, r, c));
	}

	// terminating newlines are nice
	putc('\n', stdout);

}
