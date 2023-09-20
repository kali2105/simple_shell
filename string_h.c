#include "my_shell.h"

/**
 * duplicate_string - A function that duplicates a string
 * @str: Pointer to the string to duplicate
 *
 * Return: Pointer to the duplicated string
 */
char *duplicate_string(char *str)
{
		int i;
		char *dest_str;

		if (str == NULL)
			return (NULL);
		for (i = 0; str[i] != '\0'; i++)
			;
		dest_str = malloc(sizeof(char) * (i + 1));
		if (dest_str == NULL)
			return (NULL);
		for (i = 0; str[i] != '\0'; i++)
		{
			dest_str[i] = str[i];
		}
		dest_str[i] = '\0';
		return (dest_str);
}

/**
 * count_words - A function that counts the number of words in a string
 * @str: Pointer to the string to count
 *
 * Return: Number of words in the string
 */
int count_words(char *str)
{
	int i;
	int search_flag = 1;
	int word_count = 0;

	for (i = 0; str[i]; i++)
	{
		if (str[i] != ' ' && search_flag == 1)
		{
			word_count += 1;
			search_flag = 0;
		}
		if (str[i + 1] == ' ')
			search_flag = 1;
	}
	return (word_count);
}

/**
 * compare_strings - A function that compares two strings
 * @s1: First string to compare
 * @s2: Second string to compare
 *
 * Return: Integer value representing the comparison result
 */
int compare_strings(const char *s1, const char *s2)
{
	while ((*s1 != '\0' && *s2 != '\0') && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	if (*s1 == *s2)
		return (0);
	else
		return (*s1 - *s2);
}

/**
 * string_concat - Concatenates two strings
 * @dest: Destination string
 * @src: Source string to concatenate
 *
 * Return: Pointer to the concatenated string
 */
char *string_concat(char *dest, char *src)
{
	int i;
	int j;

	for (i = 0; dest[i] != '\0'; i++)
		;
	for (j = 0; src[j] != '\0'; j++, i++)
		dest[i] = src[j];
	dest[i] = '\0';
	return (dest);
}

/**
 * string_length - Returns the length of a string
 * @s: Character array
 *
 * Return: Length of the string
 */
int string_length(char *s)
{
	int i;

	for (i = 0; s[i]; i++)
		;
	return (i);
}
