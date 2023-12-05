#include "shell.h"

/**
 *
 * main - entry point
 *
 * Always retun 0 (success)
 *
 */

int main(void)
{
	char command[128];
	char *args[128];
	const char *file;


	while (true) {
		show_prompt();
		check_commands(command, sizeof(command));
		exe_commands(command, args);
		execvp_in_path(file, args);
	}
	
	return 0;
}
