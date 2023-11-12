#include "main.h"

/**
 * has_size - a function that calculates the size used to cast the argument
 *
 * @format: is a formatted string used for the arguments to be printed
 * @i: is a list of arguments that will be printed
 *
 * Return: the precision
*/

int has_size(const char *format, int *i)
{
	int num = *i + 1;
	int s = 0;

	if (format[num] == 'l')
	{
		s = S_LONG;
	}
	else if (format[num] == 'h')
	{
		s = S_SHORT;
	}

	if (s == 0)
	{
		*i = num - 1;
	}
	else
	{
		*i = num;
	}
	return (s);
}
