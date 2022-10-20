#include "main.h"
#include <stdlib.h>

int print_c(va_list c)
{
	char ch = (char)va_arg(c, int);

	new_putchar(ch);
	return (1);
}

/**
* print_b - takes an unsigned int and prints it in binary notation
 * @b: unsigned in to print
 *
 * Return: number of digits printed
 */
int print_b(va_list b)
{
	unsigned int n, m, i, sum;
	unsigned int a[32];
	int count;

	n = va_arg(b, unsigned int);
	m = 2147483648; /* (2 ^ 31) */
	a[0] = n / m;
	for (i = 1; i < 32; i++)
	{
		m /= 2;
		a[i] = (n / m) % 2;
	}
	for (i = 0, sum = 0, count = 0; i < 32; i++)
	{
		sum += a[i];
		if (sum || i == 31)
		{
			new_putchar('0' + a[i]);
			count++;
		}
	}
	return (count);
}

