#include "main.h"

/**
 * has_precision - a function that calculates the print precision
 *
 * @format: is the  format string used to print the arguments
 * @i: is the arguments list to be printed
 * @list: is a pointer that list the arguments
 *
 * Return: the precision
*/

int has_precision(const char *format, int *i, va_list list)
{
	int prec = -1;
	int num = *i + 1;

	if (format[num] != '.')
	{
		return (prec);
	}
	prec = 0;

	for (num = num + 1; format[num] != '\0'; num++)
	{
		if (is_digit(format[num]))
		{
			prec = prec * 10;
			prec = prec + format[num] - '0';
		}
		else if (format[num] == '*')
		{
			num++;
			prec = va_arg(list, int);
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
