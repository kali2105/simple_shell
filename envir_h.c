#include "my_shell.h"

/**
 * get_environment_variable - A function that gets a specific envir vrb value
 * @name: Pointer to the name of the environment vrb
 * vrb = variable
 * Return: Pointer to the value of the environment vrb or NULL if not found
 */
char *get_environment_variable(const char *name)
{
	int i, result;

	for (i = 0; environ[i]; i++)
	{
		result = compare_path_strings(name, environ[i]);
		if (result == 0)
		{
			return (environ[i]);
		}
	}
	return (NULL);
}

/**
 * display_environment - A function that prints the environment vrbs
 *
 * Return: 0 on success
 */
int display_environment(void)
{
	int i;

	for (i = 0; environ[i]; i++)
		print_string(environ[i]);
	return (0);
}
