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

	while (true) {
		show_prompt();
		check_commands(command, sizeof(command));
		exe_commands(command, args);
	}
	
	return 0;
}
