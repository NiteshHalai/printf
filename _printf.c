#include "main.h"
#include <math.h>


void print_long(long value) {
   if(value != 0) {
      print_long(value/10);
      new_putchar((value%10) + '0');
   }
}
/**
*returns the length of output
*/
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
	long int printf_d;
	long int printf_u;
	int length;
	unsigned int printf_b;

	i = 0;
	count = 0;

	va_start(ap, format);
	
 /**
 * if null is passed in the function
 */    
	
	if (format == NULL){
	  return(-1);
	    }
	
	while (format[i])
	{
	    if (format[i] != '%'){
			  new_putchar(format[i]);
			  count++;
	    }
      else if (format[i] == '%'){
        i++;	
 /**
 * null byte after %
 */    	      
	 if (format[i] == '\0'){
          return(-1);
          }
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
 /**
 *Prints an integer
 */
        if (format[i] == 'd' || format[i] == 'i'){
          printf_d = va_arg (ap, int);
	  if (printf_d == 0){
            new_putchar('0');}
          else if  (printf_d < 0){
            printf_d = -printf_d;
            new_putchar('-');
            count++;
          }
          print_long(printf_d);
          length =  countlength(printf_d);
          count = count + length;
          }     
 /**
 *prints in binary
 */
if (format[i] == 'b'){ 

          long bin;
          long int rem;
          long int place;
          
          bin = 0;
          rem = 0;
          place = 1;

          printf_b = va_arg (ap, unsigned long int);
	       
  
          while (printf_b) {
            rem = printf_b % 2;
            printf_b = printf_b / 2;
            bin = bin + (rem * place);
            place = place * 10;
          }
              

  	      print_long(bin);
	        length =  countlength(bin);
	        count = count + length + 1;
	       }
	      
 /**
 *Prints an unsigned integer
 */
          if (format[i] == 'u'){
          printf_u = va_arg (ap, int);
	        if (printf_u == 0){
            new_putchar('0');}
          else if  (printf_u < 0){
            printf_u = (4294967296 + printf_u);
          }
          print_long(printf_u);
          length =  countlength(printf_u);
          count = count + length;
          }  
 /**
 *conditional formats end here. None should be ended after this.
 */	      
 
      }
      i++;
	}
	va_end(ap);
	return (count);
}
