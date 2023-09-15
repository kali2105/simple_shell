#include "main.h"

void exeshell(char **argv)
{
    char *command = NULL, *actual_command = NULL;

    if (argv)
    {
        /* gets command */
        command = argv[0];

	/*generate the path */
	actual_command = location(command);

        /* execute the command */
        if (execve(actual_command, argv, NULL) == -1)
        {
            perror("ERROR:");
        }
    }
}
