extern char **environ;  // Access the current environment variables

void exe_command(const char *command) {
    pid_t pid = fork();

    if (pid == -1) {
        perror("forking error");
        exit(EXIT_FAILURE);
    } else if (pid == 0) {
        // Parsing
        char *args[128];
        int argnum = 0;
        char *token = strtok((char *)command, " ");
        
        while (token != NULL) {
            args[argnum++] = token;
            token = strtok(NULL, " ");
        }

        args[argnum] = NULL;

        // Creating an array of environment variables
        char *env[] = { "PATH=/bin:/usr/bin", NULL };  // Example environment variables

        // Executing with execve
        if (execve(args[0], args, env) == -1) {
            perror("execve error");
            exit(EXIT_FAILURE);
        }
    } else {
        wait(NULL);
    }
}}
