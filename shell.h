#ifndef SHELL_H
#define SHELL_H

/**
 * header files
 */

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

/**
 *Functions
 * */

void show_prompt(void);
void check_commands(char *command, size_t size);
void exe_commands(const char *command);



#endif /* SHELL_H */
