#include "my_shell.h"

/**
 * print_string - A function that prints a string
 * @str: String to print
 */
void print_string(char *str)
{
	int c;

	for (c = 0; str[c] != '\0'; c++)
		print_character(str[c]);
	print_character('\n');
}

/**
 * print_character - A function that prints a character
 * @c: Character to print
 *
 * Return: Return value of the write syscall
 */
int print_character(char c)
{
	return (write(1, &c, 1));
}
