#include <stdlib.h>
#include <stdio.h>
#include <inttypes.h>
#include <ctype.h>
#include <time.h>

#include "utils.h"
#include "find_words.h"
#include "version_info.h"


// this adds windows support (needed since windows isn't postix-compatible)
#include "fuck_windows.h"

uint16_t rows, cols;
char** game, **solutions;
char* words;
size_t words_len = 64;

char silent = 0;

int main(int argc, char** argv){

	FILE* inputFile = stdin;

  	if (argc >= 2) {
	  	if (strcmp(argv[1], "-v") == 0 || strcmp(argv[1], "--version") == 0) {
			printVersionInfo();
		  	return 0;
		} else if (strcmp(argv[1], "-h") == 0 || strcmp(argv[1], "--help") == 0) {
			puts("useage: wordfinder [file|options]\n"
				 "  --help : show this help\n"
				 "  --version : prints the version and lisense info\n"
				 "  [file] : file must contain the dimensions separate by spaces,"
				 " the puzzle, and the words to find separated by spaces, just as"
				 " one would input without the file.\n\n"
			);
		  	return 0;
		}

		inputFile = fopen(argv[1], "r");
		silent = 1;
		
		// file not found
		if (!inputFile) {
			fprintf(stderr, "%s: error, file %s not found.\n", argv[0], argv[1]);
			return 1;
		}
	}

	/// TODO: program must ERROR if the file doesn't contain enough information
	if (!silent) printf("Number of rows: ");
	if (fscanf(inputFile, "%hu", &rows) == EOF) { 	// uint16_t == unsigned short ( "%hu" )
		perror("\aERROR: Malformed input file (missing dimension)");
		printFileHelper();
		return 1;
	}


	if (!silent) printf("Number of cols: ");
	if (fscanf(inputFile, "%hu", &cols) == EOF) {
		perror("\aERROR: Malformed input file (missing dimension)");
		printFileHelper();
		return 1;
	}
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
			if (letter == EOF) {
				perror("\aERROR: Malformed input (incomplete puzzle)\n");
				printFileHelper();
				return 2;
			}

			CHAR_AT(game, r, c) = letter;
			CHAR_AT(solutions, r, c) = 0;
		}
	}

	if (!silent) printf("Enter the words to find (separated by spaces): ");



	
	words = (char*) malloc(words_len); // grown as needed
	// keep checking for input every time they press enter without words
	do 
		// no words to find
		if (getline(&words, &words_len, inputFile) == -1) {
			perror("\aERROR: Malformed input (words not given)\n");
			printFileHelper();
			return 3; // EOF
		}
	while (*words == '\n');

	char* str = words;
	while(*++str != '\0');

	if (*--str == '\n')
		*str = '\0';


	// time how long it takes to solve the puzzle
	clock_t diff, start = clock();
	findWords(); // solve puzzle
	diff = clock() - start;
	
	// give processing time
	long usec = diff * 1000000 / CLOCKS_PER_SEC;
	printf("\nsolved in %ld milliseconds %ld microseconds\n\n", 
	       usec / 1000, usec % 1000);

	// print the board with solutions highlighted in bright-red
	for (uint16_t r = 0; r < rows; r++) {

		for (uint16_t c = 0; c < cols; c++)
			if (CHAR_AT(solutions, r, c))
				// print the solution char in bright-red
				printf("\x1B[31;1m%c\x1B[0m ", CHAR_AT(game, r, c));

			else
				printf("%c ",CHAR_AT(game, r, c));
		
		putc('\n', stdout);
	}

}
