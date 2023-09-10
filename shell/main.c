#include "main.h"

int main(int ac, char **argv)
{
    char *prompt = "(shell) $ ";
    char *linep = NULL;
    char *linep_copy = NULL;
    size_t t = 0;
    ssize_t tchars;
    const char *del = " \n";
    int num_of_tokens = 0;
    char *token;
    int j;

    /* void variables */
    (void)ac;

    /* the infinite loop */
    while (1)
    {
        printf("%s", prompt);
        tchars = getline(&linep, &t, stdin);
        
        /* the getline failed? && it reached the end && the user ended it */
        if (tchars == -1)
        {
            printf("Exiting.....\n");
            return (-1);
        }

        /* allocating the space we need for the copy of linep */
        linep_copy = malloc(sizeof(char) * (tchars + 1));
        if (linep_copy == NULL)
        {
            perror("tsh: memory error");
            return (-1);
        }
        
        /* making the linep-copy */
        strcpy(linep_copy, linep);

        /**** breaking the linep into array of chars ****/
        
        /* the total number of tokens */
        token = strtok(linep, del);

        while (token != NULL)
        {
            num_of_tokens++;
            token = strtok(NULL, del);
        }
        num_of_tokens++;

        /* allocate space for the array of strings */
        argv = malloc(sizeof(char *) * (num_of_tokens + 1));

        /* storing each token in the argv array */
        token = strtok(linep_copy, del);

        for (j = 0; token != NULL; j++)
        {
            argv[j] = malloc(sizeof(char) * (strlen(token) + 1));
            strcpy(argv[j], token);
            token = strtok(NULL, del);
        }
        argv[j] = NULL;

        /* executing the commands */
        exeshell(argv);
    }

    /* free the allocated memory */
    free(linep);
    free(linep_copy);
    return (0);
}
