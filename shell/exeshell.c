#include "main.h"

void exeshell(char **argv)
{
    char *command = NULL;

    if (argv)
    {
        /* gets command */
        command = argv[0];

        /* execute the command */
        if (execve(command, argv, NULL) == -1)
        {
            perror("ERROR:");
        }
    }
}
