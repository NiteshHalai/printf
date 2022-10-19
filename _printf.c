#include "main.h"

int _printf(const char *format, ...)

{
	va_list	ap;
	int	i;
	int j;

	i = 0;

	va_start(ap, format);
	while (format[i])
	{
	    if (format[i] != '%'){
			  putchar(format[i]);
	      
	    }
			
      else if (format[i] == '%'){
        i++;
        if (format[i] == 'c'){
        putchar('H');
        }
          
      }
      i++;
	}
  
	va_end(ap);
	return (0);
}
