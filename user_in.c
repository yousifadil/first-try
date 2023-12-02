#include "shell.h"

/**
* getting user input function
*/

void check_commands(char *command, size_t size) 
{
	if (fgets(command, size, stdin) == NULL) 
	{
		if (feof(stdin))
		{
			printf("\n");
			exit(EXIT_SUCCESS);
		}
		else 
		{
			printf("input error");
			exit(EXIT_FAILURE);
		}
	}

	/*remove newline*/

	command[strcspn(command, "\n")] = '\0';
}
