#include "main.h"
#include <math.h>

static int (*check_for_specifiers(const char *format))(va_list)
{
	unsigned int i;
	print_t p[] = {
		{"c", print_c},
		{"b", print_b},
			{NULL, NULL}
	};
for (i = 0; p[i].t != NULL; i++)
	{
		if (*(p[i].t) == *format)
		{
			break;
		}
	}
	return (p[i].f);
}


void print_long(long value) {

   if(value != 0) {
      print_long(value/10);
      new_putchar((value%10) + '0');
      
   }
}

int countlength(int n)
{
  
  int count;
  
  count=0;
  
  do {
    n /= 10;
    ++count;
  } while (n != 0); 
    return (count);
}

int _printf(const char *format, ...)

{
	va_list	ap;
	int	i;
	int printf_c;
	const char* printf_s;
	int count;
	int printf_d;
	int length;

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
          printf_c = va_arg (ap, int);  
          new_putchar(printf_c);
          count++;
          }
        
        if (format[i] == 's'){
          printf_s = va_arg (ap, const char*);
          while(*printf_s) {
            new_putchar(*printf_s++); 
            count++;
          }
          }
          
        if (format[i] == '%'){ 
          new_putchar('%');
          count++;
          }
          
        if (format[i] == 'd' || format[i] == 'i'){
          printf_d = va_arg (ap, int);
          if (printf_d < 0){
            printf_d = -printf_d;
            new_putchar('-');
            count++;
          }
          print_long(printf_d);
          length =  countlength(printf_d);
          count = count + length;
          }
          
      }
      i++;
	}

	va_end(ap);
	return (count);
}
