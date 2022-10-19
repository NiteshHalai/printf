#include "main.h"

int _printf(const char *format, ...)

{
	va_list	ap;
	int i;

	i = 0;

	va_start(ap, format);
	while (format[i])
	{
	    if (format[i] != '%'){
			  new_putchar(format[i]);
	      
	    }
			
      else if (format[i] == '%'){
        i++;
        if (format[i] == 'c'){
        new_putchar('H');
        }
          
      }
      i++;
	}
  
	va_end(ap);
	return (0);
}
