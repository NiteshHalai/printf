#include "main.h"
#include <stdlib.h>

int print_c(va_list c)
{
	char ch = (char)va_arg(c, int);

	new_putchar(ch);
	return (1);
}
