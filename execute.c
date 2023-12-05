#include "shell.h"


/**
 * exe_commands - executes and tokenizes the commands
 * @command: input command
 * @args: array to store parsed arguments
 */
void exe_commands(const char *command, char *args[])
{
	pid_t pid = fork();

	if (pid == -1)
	{
		perror("forking error\n");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		/* Parsing */
		int argnum = 0;
		char *token = strtok((char *)command, " ");

		while (token != NULL)
		{
			args[argnum++] = token;
			token = strtok(NULL, " ");
		}

		args[argnum] = NULL;

		/* Checks if the command is exit */
		if (strcmp(args[0], "exit") == 0)
			exit(EXIT_SUCCESS);

		/* Checks if the command is env */
		if (strcmp(args[0], "env") == 0)
		{
			/* environment variables */
			char **env = environ;

			while (*env != NULL)
			{
				printf("%s\n", *env);
				env++;
			}
			exit(EXIT_SUCCESS);
		}

		/* PATH */
		char *path = getenv("PATH");
		char *path_copy = strdup(path);

		if (path_copy == NULL)
		{
			perror("strdup error\n");
			exit(EXIT_FAILURE);
		}
		char *path_token = strtok(path_copy, ":");

		while (path_token != NULL)
		{
			char full_path[256];

			snprintf(full_path, sizeof(full_path), "%s/%s", path_token, args[0]);

			/* Check if the command exists */
			if (access(full_path, X_OK) == 0)
			{
				if (execve(full_path, args, environ) == -1)
				{
					perror("execve error\n");
					free(path_copy);
					exit(EXIT_FAILURE);
				}
			}
			path_token = strtok(NULL, ":");
		}
		/* if the commands does not exist */
		fprintf(stderr, "Command not found: %s\n", args[0]);
		free(path_copy);
		exit(EXIT_FAILURE);
	}
	else
	{
		wait(NULL);
	}
}
