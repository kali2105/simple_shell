#include "my_shell.h"

/**
 * tokenize_input - Creates an array of tokens based on user input
 * @input_buffer: Pointer to user input string
 *
 * Return: Pointer to an array of user input tokens
 */
char **tokenize_input(char *input_buffer)
{
	char *token;
	int i = 0, word_count = 0;
	char *delimiter = " \n";
	char **args;

	word_count = count_words(input_buffer);
	if (!word_count)
		return (NULL);
	args = malloc((word_count + 1) * sizeof(char *));
	if (args == NULL)
		exit(1);
	token = strtok(input_buffer, delimiter);
	while (token != NULL)
	{
		args[i] = duplicate_string(token);
		token = strtok(NULL, delimiter);
		i++;
	}
	args[i] = NULL;
	return (args);
}

/**
 * split_path - A function that counts the number of PATH members
 * @path: Pointer to the PATH string
 *
 * Return: Number of PATH members
 */
int split_path(char *path)
{
	int i;
	int search_flag = 1;
	int word_count = 0;

	for (i = 0; path[i]; i++)
	{
		if (path[i] != ':' && search_flag == 1)
		{
			word_count += 1;
			search_flag = 0;
		}
		if (path[i + 1] == ':')
		{
			search_flag = 1;
		}
	}
	return (word_count);
}

/**
 * compare_path_strings - A function finds value p in comparing PATH and enviro
 * @s1: Pointer to the PATH string
 * @s2: Pointer to the environ string with the actual value
 *
 * Return: 0 on success
 */
int compare_path_strings(const char *s1, const char *s2)
{
	int i;

	for (i = 0; s2[i] != '='; i++)
	{
		if (s1[i] != s2[i])
			return (-1);
	}
	return (0);
}

/**
 * concatenate_strings - A function concatenates user string with string and /
 * @tmp: Static array to store concatenated string
 * @args: Pointer to an array of user strings
 * @token: Pointer to PATH token
 *
 * Return: Return a pointer to the concatenated string
 */
char *concatenate_strings(char *tmp, char **args, char *token)
{
	int len = 0;

	fill_memory(tmp, 0, 256);
	len = string_length(token) + string_length(args[0]) + 2;
	string_concat(tmp, token);
	string_concat(tmp, "/");
	string_concat(tmp, args[0]);
	tmp[len - 1] = '\0';
	return (tmp);
}
