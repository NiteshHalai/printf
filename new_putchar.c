#include "main.h"

/**
 * new_putchar- writes the character c to stdout.
 * @c: The character to print
 *
 * Return: On success 1.
 * got from stackoverflow..
 */
int new_putchar(char c)
{
	return (write(1, &c, 1));
}
