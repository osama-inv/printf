#include "main.h"
void print_the_buf(char buffer[], int *byts_to_print);
/**
 * _printf - Printf main
 * @format: Formatting.
 * Return: Number of chars on screen.
 */
int _printf(const char *format, ...)
{
char buffer[BUFF_len];
int i, printed = 0, num_of_chars_printed = 0;
int flags, width, precision, size, byts_to_print = 0;
va_list list;
/* check if format is NULL */
if (format == NULL)
return (-1);
va_start(list, format);
/* looping through format*/
for (i = 0; format[i] != '\0' && format; i++)
{
if (format[i] != '%')
{
buffer[byts_to_print++] = format[i];
if (byts_to_print == BUFF_len)
{
print_the_buf(buffer, &byts_to_print);
}
/* print buffer*/
num_of_chars_printed++;
}
else
{
/* case of encountering % */
print_the_buf(buffer, &byts_to_print);
/* picking different things and sps % */
flags = has_flags(format, &i);
width = has_width(format, &i, list);
precision = has_precision(format, &i, list);
size = has_size(format, &i);
++i;
printed = get_def_print(format, &i, list, buffer,
flags, width, precision, size);
if (printed == -1)
{
return (-1);
}
num_of_chars_printed += printed;
}
}
print_the_buf(buffer, &byts_to_print);
va_end(list);
/* return (num_of_chars_printed) */
return (num_of_chars_printed);
}
/**
 * print_the_buf - Prints the contents of the buffer if it exists
 * @buffer: Array of chars
 * @byts_to_print: Index at which to add the next char, represents the length.
 */
void print_the_buf(char buffer[], int *byts_to_print)
{
/* print all */
if (*byts_to_print > 0)
{
write(1, &buffer[0], *byts_to_print);
}
*byts_to_print = 0;
}
