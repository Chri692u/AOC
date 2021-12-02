#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER 16
#define LOWER_ASCII_LIMIT 48

int partOne(char* path);
int partTwo(char* path);

int main(){
	char* path = "./inputs/2.txt";

	printf("Answer to part one: %d\n", partOne(path));
	printf("Answer to part two: %d\n", partTwo(path));

	return EXIT_SUCCESS;
}

int partOne(char* path){
	//accumulators
	int depth = 0, pos = 0;
	char line[BUFFER];
	char peek, number;
	int lineLength;

	//File pointer
	FILE* file = fopen(path, "r");

	if (!file)
		return EXIT_FAILURE;
	
	while (fgets(line, BUFFER, file)) {
		lineLength = strnlen(line, BUFFER);
		peek = line[0];
		number = line[lineLength-2] - LOWER_ASCII_LIMIT;

		switch(peek){
			case 'u':
				depth -= number;
				break;
			case 'd':
				depth += number;
				break;
			case 'f':
				pos += number;
				break;		
		}
	}
	fclose(file);

	return depth*pos;
}

int partTwo(char* path){
	//accumulators
	int depth = 0, pos = 0, aim = 0;
	char line[BUFFER];
	char peek, number;
	int lineLength;
	
	//File pointer
	FILE* file = fopen(path, "r");

	if (!file)
		return EXIT_FAILURE;
	
	while (fgets(line, BUFFER, file)) {
		lineLength = strnlen(line, BUFFER);
		peek = line[0];
		number = line[lineLength-2] - LOWER_ASCII_LIMIT;

		switch(peek){
			case 'u':
				aim -= number;
				break;
			case 'd':
				aim += number;
				break;
			case 'f':
				pos += number;
				depth += aim * number;
				break;		
		}
	}
	fclose(file);
	return depth*pos;
}
