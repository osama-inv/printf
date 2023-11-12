#include "main.h"

/**
 * has_width - a function that calculates the width for printing
 *
 * @format: is a formatted string that is used to print the arguments
 * @i: is the arguments list to be printed
 * @list: is a list of the arguments
 *
 * Return: the width
*/

int has_width(const char *format, int *i, va_list list)
{
	int num = *i + 1;
	int wid = 0;

	for (; format[num] != '\0'; num++)
	{
		if (is_digit(format[num]))
		{
			wid = wid * 10;
			wid =  wid + format[num] - '0';
		}
		else if (format[num] == '*')
		{
			num++;
			wid = va_arg(list, int);
			break;
		}
		else
		{
			break;
		}
	}
	*i = num - 1;
	return (wid);
}
