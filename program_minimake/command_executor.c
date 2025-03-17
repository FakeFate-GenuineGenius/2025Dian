#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include "rule_parser.h"

void execute_command_for_target(const char *target) {
    for (int i = 0; i < rule_count; i++) {
        if (strcmp(rules[i].target, target) == 0) {
            pid_t pid = fork();
            if (pid == -1) {
                perror("fork");
                exit(1);
            } else if (pid == 0) {
                char *args[MAX_COMMAND_LENGTH / 32];
                char *token = strtok((char *)rules[i].command, " ");
                int arg_count = 0;
                while (token) {
                    args[arg_count++] = token;
                    token = strtok(NULL, " ");
                }
                args[arg_count] = NULL;

                execvp(args[0], args);
                perror("execvp");
                exit(1);
            } else {
                int status;
                waitpid(pid, &status, 0);
                if (!WIFEXITED(status) || WEXITSTATUS(status) != 0) {
                    printf("Command execution failed\n");
                    exit(1);
                }
            }
            break;
        }
    }
}
