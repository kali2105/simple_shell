#include "my_shell.h"

/**
 * display_prompt - A function that dispalys a shell prompt
 *
 * Return: 0 on success
 */
int display_prompt(void)
{
	char *prompt = "$ ";
	ssize_t write_count = 0;

	if (isatty(STDIN_FILENO) == 1)
	{
		write_count = write(STDOUT_FILENO, prompt, 2);
		if (write_count == -1)
			exit(0);
	}
	return (0);
}

/**
 * read_input - A fct that eads input from stdin and stores it in a buffer
 *
 * Return: A pointer to the input buffer
 */
char *read_input(void)
{
	ssize_t read_count = 0;
	size_t n = 0;
	char *input_buffer = NULL;
	int i = 0;

	read_count = getline(&input_buffer, &n, stdin);
	if (read_count == -1)
	{
		free(input_buffer);
		if (isatty(STDIN_FILENO) != 0)
			write(STDOUT_FILENO, "\n", 1);
		exit(0);
	}
	if (input_buffer[read_count - 1] == '\n' || input_buffer[read_count - 1] == '\t')
		input_buffer[read_count - 1] = '\0';
	for (i = 0; input_buffer[i]; i++)
	{
		if (input_buffer[i] == '#' && input_buffer[i - 1] == ' ')
		{
			input_buffer[i] = '\0';
			break;
		}
	}
	return (input_buffer);
}

/**
 * find_full_path - A function that finds the executable to call using execve
 * @args: Pointer to an array of user strings
 * @PATH: Pointer to the PATH string
 * @copy: Pointer to a copy of the PATH string
 *
 * Return: A pointer to the string to call execve on
 */
char *find_full_path(char **args, char *PATH, char *copy)
{
	char *token, *executable = NULL, *concatenated_str = NULL;
	static char tmp[256];
	int PATH_count = 0, executable_flag = 0, z = 0, token_len = 0;
	struct stat h;

	copy = NULL;
	copy = duplicate_string(PATH);
	PATH_count = split_path(copy);
	token = strtok(copy, ": =");
	while (token != NULL)
	{
		concatenated_str = concatenate_strings(tmp, args, token);
		if (stat(concatenated_str, &h) == 0)
		{
			executable = concatenated_str;
			executable_flag = 1;
			break;
		}
		if (z < PATH_count - 2)
		{
			token_len = string_length(token);
			if (token[token_len + 1] == ':')
			{
				if (stat(args[0], &h) == 0)
				{
					executable = args[0];
					executable_flag = 1;
					break;
				}
			}
		}
		z++;
		token = strtok(NULL, ":");
	}
	if (executable_flag == 0)
		executable = args[0];
	free(copy);
	return (executable);
}

/**
 * check_builtin_commands - A fct checks if the first user string is a built-in command
 * @args: Pointer to an array of user strings
 * @input_buffer: Pointer to the user input string
 * @exit_status: Exit status of execve
 *
 * Return: 1 if the user string is equal to "env" or 0 otherwise
 */
int check_builtin_commands(char **args, char *input_buffer, int exit_status)
{
	int i;

	if (compare_strings(args[0], "env") == 0)
	{
		display_environment();
		for (i = 0; args[i]; i++)
			free(args[i]);
		free(args);
		free(input_buffer);
		return (1);
	}
	else if (compare_strings(args[0], "exit") == 0)
	{
		for (i = 0; args[i]; i++)
			free(args[i]);
		free(args);
		free(input_buffer);
		exit(exit_status);
	}
	else
		return (0);
}

/**
 * fork_and_execute - A fct creates a child process to execute the user command
 * @args: Pointer to an array of user strings
 * @input_buffer: Pointer to the user input string
 * @executable: Pointer to the executable string
 *
 * Return: 0 on success
 */
int fork_and_execute(char **args, char *input_buffer, char *executable)
{
	int i, status, result, exit_status = 0;
	pid_t pid;

	pid = fork();
	if (pid == -1)
	{
		perror("Error");
		exit(1);
	}
	if (pid == 0)
	{
		result = execve(executable, args, environ);
		if (result == -1)
		{
			perror(args[0]);
			for (i = 0; args[i]; i++)
				free(args[i]);
			free(args);
			free(input_buffer);
			exit(127);
		}
	}
	wait(&status);
	if (WIFEXITED(status))
	{
		exit_status = WEXITSTATUS(status);
	}
	for (i = 0; args[i]; i++)
		free(args[i]);
	free(args);
	free(input_buffer);
	return (exit_status);
}
