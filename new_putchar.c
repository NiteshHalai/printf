#include "main.h"
#include <unistd.h>

/**
 * new_putchar- writes the character c to stdout.
 * @c: The character to print
 *
 * Return: On success 1.
 * got from stackoverflow..
 */
int _putchar(char c)
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
