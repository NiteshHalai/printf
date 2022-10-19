#include "main.h"

int _printf(const char *format, ...)

{
	va_list	ap;
	int		i;

	i = 0;

	va_start(ap, format);
	while (format[i])
	{
		if (format[i] != '%')
			new_putchar(format[i]);
    
		i++;
	}
  
	va_end(ap);
	return (0);
}
