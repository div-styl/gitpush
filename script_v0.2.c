#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COMMANDS 3

void executeCommand(const char *command)
{
    int result = system(command);
    if (result != 0)
    {
        printf("Error executing command: %s\n", command);
        exit(1);
    }
}

char* getInput()
{
    char* input = NULL;
    size_t size = 0;
    
    printf("Enter the commit name (or leave empty for 'update'): ");
    getline(&input, &size, stdin); /*get the input using getline which allocate and free*/
    
    /*Remove trailing newline character*/
    input[strcspn(input, "\n")] = '\0';
    
    return input;
}

// int argExist(const char* arg, const int argc, const char* argv) {
//     for (int i = 0; i < argc - 1; ++i) {
//         if (strcmp (argv[i], arg) == 0) {
//             return 1;
//         }
//     }
//     return 0;
// }

int main(int argc, char* argv[])
{
    char input[100];
    if (system("git > /dev/null 2>&1" ) == 127) {
        printf("Git is not dectected");
        exit(127);
    }
    if (system("git status > /dev/null 2>&1") == 128) {
        printf("Git repository not dectected, use git init to create a git repository");
        exit(128);
    }
    const char *commands[MAX_COMMANDS] =
    {
        "git add -A -f",
        "git commit -m 'updated'",
        "git push",
        //"clear"
    };

    

    int numCommands = sizeof(commands) / sizeof(commands[0]);

    for (int i = 0; i < numCommands; i++)
  {
        if (i == 1)
    {
            char* input = getInput();
            if (strlen(input) > 0) /*check if the user provide the commit name*/
            {
                char* command = malloc(strlen(input) + strlen("git commit -m ''") + 1);
                sprintf(command, "git commit -m '%s'", input);
                commands[i] = command;
                free(input);
            }
    }
        executeCommand(commands[i]);
  }

    return 0;
}

