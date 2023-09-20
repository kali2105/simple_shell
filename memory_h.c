/**
 * fill_memory - A function that fills memory with a constant byte
 * @s: Character array to fill
 * @byte: Constant byte to fill with
 * @n: How many bytes to fill
 *
 * Return: Pointer to the character array
 */
char *fill_memory(char *s, char byte, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
		s[i] = byte;
	return (s);
}
