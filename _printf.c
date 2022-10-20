#include "main.h"
#include <math.h>


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

/**
 * _printf - Receives the main string and all the necessary parameters to
 * print a formated string
 * @format: A string containing all the desired characters
 * Return: A total count of the characters printed
 */

int _printf(const char *format, ...)

{
	va_list	ap;
	int	i;
	int printf_c;
	const char* printf_s;
	int count;
	int printf_d;
	int length;
	unsigned int printf_b;

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
	      
 /**
 * prints a character
 */    
        if (format[i] == 'c'){
          printf_c = va_arg (ap, int);  
          new_putchar(printf_c);
          count++;
          }
       
 /**
 * prints a string
 */
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
          
	  if (format[i] == 'b'){ 
	        
	        long bin;
		
	         
	       int rem, i;
		  
		  
		i = 1;
		bin = 0;
		printf_b = va_arg (ap, unsigned int);
	        while (printf_b!=0) {
		        rem = printf_b % 2;
		        printf_b /= 2;
   		      bin += rem * i;
		        i *= 10;
		      }
              
  	      print_long(bin);
	        length =  countlength(bin);
	        count = count + length;
	       }
      }
      i++;
	}

	va_end(ap);
	return (count);
}
