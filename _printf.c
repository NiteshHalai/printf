#include "main.h"

int _printf(const char *format, ...)

{
	va_list	ap;
	int	i;
	int j;
	int count;

	i = 0;
	count = 0;

	va_start(ap, format);
	while (format[i])
	{
	    if (format[i] != '%'){
			  new_putchar(format[i]);
			  count++;
	      
	    }
			
      else if (format[i] == '%'){
        i++;
        if (format[i] == 'c'){
        j = va_arg (ap, int);  
        new_putchar(j);
        count++;
        }
          
      }
      i++;
	}

	va_end(ap);

	return (count);
}
