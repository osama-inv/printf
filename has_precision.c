#include "main.h"

/**
 * get_precision - Calculates the precision for printing
 * @format: Formatted string in which to print the arguments
 * @i: List of arguments to be printed.
 * @list: list of arguments.
 *
 * Return: Precision.
 */
int get_precision(const char *format, int *i, va_list list)
{
int num = *i + 1;
int prec = 0;
if (format[num] != '.')
return (prec);
for (num += 1; format[num] != '\0'; num++)
{
if (is_digit(format[num]))
{
prec *= 10;
prec += format[num] - '0';
}
else if (format[num] == '*')
{
num++;
prec = va_arg(list, int);
if (prec < 0)
{
// Handle negative precision, maybe set it to a default value
prec = 0;
}
break;
}
else
{
break;
}
}
*i = num - 1;
return (prec);
}
