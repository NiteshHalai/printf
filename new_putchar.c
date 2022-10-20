#include "main.h"

/**
 * new_putchar- writes the character c to stdout.
 * @c: The character to print
 *
 * Return: On success 1.
 * got from stackoverflow.. and some random dude's code
 */
int new_putchar(char c)
{
	static char buf[1024];
	static int i;

	if (c == -1 || i >= 1024)
	{
		write(1, &buf, i);
		i = 0;
	}
	if (c != -1)
	{
		buf[i] = c;
		i++;
	}
	return (1);
}
