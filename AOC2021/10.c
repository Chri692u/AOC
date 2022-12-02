/*
TODO:
	fix errors, den giver penalty for expected ikke found.
	find et fix til incomplete lines
	done?
*/
#define PAREN 3
#define BRACKET 57
#define CURLY 1197
#define ANGLE 25137

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Aux. functions*/
void parseLine();
void exprs();
int match(char matchCh);
int errorValues(char symbol);

/*Globals used for recursive descend*/
int lookAhead = 0;
int error = 0;
int isFirstError = 1;
char* line = NULL;
char current;

int main(){
	/*Read line by line*/
	FILE* fp;
	size_t len = 0;
	ssize_t read;

	fp = fopen("./inputs/10.txt", "r");
	if (fp == NULL)
	        exit(EXIT_FAILURE);

	/*Parse line by line*/
	while ((read = getline(&line, &len, fp)) != -1) {
		parseLine();
		isFirstError = 1;
		lookAhead = 0;
	}
	printf("error: %d\n", error);

	fclose(fp);
	if (line)
        	free(line);

	return EXIT_SUCCESS;
}

void parseLine(){
	current = line[lookAhead];
	exprs();
}

/*Recursive descend*/
void exprs(){
	if ( match('(') ) {
		exprs();
		if (match(')')){
			exprs();	
		} else if (isFirstError && (current != '\n')) {
		 	isFirstError = 0;			
			printf("expected: ), found: %c\n", current);
			error += errorValues(current);
		}

	} else if ( match('[') ) {
		exprs();
		if (match(']')){
			exprs();
		} else if (isFirstError && (current != '\n')) {
			isFirstError = 0;			
			printf("expected: ], found: %c\n", current);
			error += errorValues(current);
		}

	} else if ( match('{')) {
		exprs();
		if (match('}')){
			exprs();	
		} else if (isFirstError && (current != '\n')) {
			isFirstError = 0;			
			printf("expected: }, found: %c\n", current);
			error += errorValues(current);
		}

	} else if (match('<')){
		exprs();
		if (match('>')){
			exprs();	
		} else if (isFirstError && (current != '\n')) {
			isFirstError = 0;			
			printf("expected: >, found: .%c.\n", current);
			error += errorValues(current);
		}
	}
}
/*error value lookup*/
int errorValues(char symbol){
	switch(symbol){
		case ')':
			return PAREN;
		case ']':
			return BRACKET;
		case '}':
			return CURLY;
		case '>':
			return ANGLE;
	}
}
/* if current char == expected char*/
int match(char matchCh){
	if (matchCh == current){
		lookAhead++;
		current = line[lookAhead];
		return 1;
	} else {
		return 0;
	}
}
