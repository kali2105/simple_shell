#include "my_shell.h"

int main(void)
{
		char *full_path = NULL, *copy_path = NULL, *input_buffer = NULL;
		char *search_path = NULL;
		char **args;
		int exit_status = 0;

		signal(SIGINT, SIG_IGN);
		search_path = get_environment_variable("PATH");
		if (search_path == NULL)
			return (-1);
		while (1)
		{
			args = NULL;
			display_prompt();
			input_buffer = read_input();
			if (*input_buffer != '\0')
			{
				args = tokenize_input(input_buffer);
				if (args == NULL)
				{
					free(input_buffer);
					continue;
				}
				full_path = find_full_path(args, search_path, copy_path);
				if (check_builtin_commands(args, input_buffer, exit_status) == 1)
					continue;
				exit_status = fork_and_execute(args, input_buffer, full_path);
			}
			else
				free(input_buffer);
		}
		return (0);
}
