#include "main.h"

int _printf(const char *format, ...)

{
	va_list	ap;
	int	i;
	int printf_c;
	const char* printf_s;
	int count;

	i = 0;
	count = 0;

	va_start(ap, format);
	while (format[i])
	{
	    if (format[i] != '%'){
			  putchar(format[i]);
			  count++;
	      
	    }
			
      else if (format[i] == '%'){
        i++;
        if (format[i] == 'c'){
          printf_c = va_arg (ap, int);  
          putchar(printf_c);
          count++;
          }
        
        if (format[i] == 's'){
          printf_s = va_arg (ap, const char*);
          while(*printf_s) {
            putchar(*printf_s++); 
            count++;
          }
          }
        
      
          
      }
      i++;
	}
