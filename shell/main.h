#ifndef BETTY_H
#define BETTY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

void exeshell(char **argv);
char *location(char *command);

#endif /* BETTY_H */
