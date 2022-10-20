#ifndef PRINT_F
#define PRINT_F

#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>

/*list functions here*/
int _printf(const char *format, ...);
int new_putchar(char);
int countlength(int number);
void print_long(long value);
int print_c(va_list c);


#endif
