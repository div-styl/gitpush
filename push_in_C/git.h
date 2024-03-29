#ifndef GIT_H
#define GIT_H
/*Header*/
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#define MAX_COMMANDS 5
#define MAX_INPUT 1024
/*colors*/
#define RED "\033[0;31m"
#define GREEN "\033[0;32m"
#define NC "\033[0m"
#define YELLOW "\033[0;33m"
#define BLUE "\033[0;34m"
#define CYAN "\033[0;36m"
#define MAGENTA "\033[0;35m"
/*dump commands*/
static const char *commands[] = {
  "git add -A",
  "git commit -m",
  "git push origin main",
  "git clean",
  "git status --short",
  "clear",
};
/*prototypes*/
void checkgit(void);
void getInput(char **commit, size_t *commtlen);
void gitcmt(const char *commit_message);
void execute(const char *command);
void push(void);
#endif
