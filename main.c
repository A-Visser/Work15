#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

char ** parse_args(char * line) {
	char ** args = malloc(5 * sizeof(char *));
	
	int index = 0;
	while(line) {
		char * arg = strsep(&line, " ");
		args[index] = arg;
		index++;
	}
	return args;
}

int main() {
	printf("Input Command: \n");

	char command[100];
	fgets(command, 100, stdin);
	*strchr(command, '\n') = 0;

	char ** args = parse_args(command);
	execvp(args[0], args);
}
