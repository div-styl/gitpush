#ifndef git_H
#define git_H
/*Header*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#define MAX_COMMANDS 10
/*prototypes*/
void executeCommand(const char *command);
void freeCommandsAndInputs(char **commands, int numCommands, char *input, char* commit);
char* getInput(void);
void githuberror(void);
#endif
