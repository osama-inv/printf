#include "main.h"

/**
 * has_flags - used to find active flags
 *
 * @format: is the format string used to print the arguments
 * @str: is the struct of the parameters
 *
 * Return: flags if valid
*/

int has_flags(const char *format, int *str)
{
	int n, len;
	int flgs = 0;

	/*for -,+,0,#,' '*/
	const char ch[] = {'-', '+', '0', '#', ' ', '\0'};
	const int arr[] = {minus_f, plus_f, zero_f, hash_f, space_f, null_f};

	for (len = *str + 1; format[len] != '\0'; len++)
	{
		for (n = 0; ch[n] != '\0'; n++)
		{
			if (format[len] == ch[n])
			{
				flgs |= arr[n];
				break;
			}
		}
		if (ch[n] == 0)
			break;
	}
	*str = len - 1;
	return (flgs);
}
