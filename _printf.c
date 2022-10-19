#include "main.h"

void print_long(long value) {

   if(value != 0) {
      print_long(value/10);
      new_putchar((value%10) + '0');
      
   }
}

int countlength(int number)
{
    static int count = 0;
    if (number > 0)
    {
        count++;
        number /= 10;
        countlength(number);
    }
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

