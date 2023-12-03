#include "shell.h"

/**
 * Handle PATH :
 */


void execvp_in_path(const char *file, char *args[])
{
    char *path = getenv("PATH");
    char *path_copy = strdup(path);
    char *dir = strtok(path_copy, ":");

    while (dir != NULL)
    {
        char *path_command = malloc(strlen(dir) + strlen(file) + 2); /* note: +2 for / and null terminator */
        sprintf(path_command, "%s/%s", dir, file);

        execvp(path_command, args);

        free(path_command);
        dir = strtok(NULL, ":");
    }

    perror("execvp error");
    free(path_copy);
    exit(EXIT_FAILURE);
}
