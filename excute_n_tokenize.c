#include "shell.h"

/**
 * executes and tokenizes the commands
 */

void exe_commands(const char *command)
{
        pid_t pidd = fork();

        if (pidd == -1)
        {
                perror("forking error. \n");
                exit(EXIT_FAILURE);
        }
        else if (pidd == 0)
        {
                /*parsing*/
                char *args[128];
                int argnum = 0;
                char *token = strtok((char *)command, " ");
                while (token != NULL)
                {
                        args[argnum++] = token;
                        token = strtok(NULL, " ");
                }

                args[argnum] = NULL;

                /*executing*/

                if (execvp(args[0], args) == -1)
                {
                        perror("executing error \n");
                        exit(EXIT_FAILURE);
                }

        }

        else
        {
                wait(NULL);
        }
}
