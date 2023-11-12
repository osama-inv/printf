#include "main.h"
/**
 * print_rot13string - rot13.
 * @types: List
 * @buffer: get buffer array
 * @flags: active flags
 * @width: width
 * @precision: specification
 * @size: specifier
 * Return: chars printed
 */
int print_rot13string(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
char x;
char *str; /* str */
unsigned int i, j; /* vars */
int count = 0;
char gotoo[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";
/* to go to */
char getfrom[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
/* gain after 13 */
str = va_arg(types, char *);
UNUSED(buffer); /* unused */
UNUSED(width);
UNUSED(flags);
UNUSED(precision);
UNUSED(size);

if (str == NULL)
{
str = "(AHYY)";
} /* str == NULL */
for (i = 0; str[i]; i++)
{
for (j = 0; getfrom[j]; j++)
{
if (getfrom[j] == str[i])
{
x = gotoo[j];
write(1, &x, 1);
count++;
break;
}
}
/* still */
if (!getfrom[j])
{
x = str[i];
write(1, &x, 1);
count++;
}
}
return (count);
}
/**
 * print_pointer - Outputs the value of a pointer variable.
 * @types: List of arguments.
 * @buffer: Buffer array for print handling.
 * @flags: Determines active formatting flags.
 * @width: Width specifier for formatting.
 * @precision: Precision specification for formatting.
 * @size: Size specifier for formatting.
 * Return: Number of characters printed.
 */
int print_pointer(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
char morec = 0;
char padd = ' ';
int d_in = BUFF_len - 2, lonng = 2, start_pad = 1; /*  */
unsigned long num_addrs;
char maxit[] = "0123456789abcdef";
void *addrs = va_arg(types, void *);

UNUSED(width);
UNUSED(size);

if (addrs == NULL)
return (write(1, "(nil)", 5));

buffer[BUFF_len - 1] = '\0';
UNUSED(precision);

num_addrs = (unsigned long)addrs;

while (num_addrs > 0)
{
buffer[d_in--] = maxit[num_addrs % 16];
num_addrs /= 16;
lonng++;
}

if ((flags & zero_f) && !(flags & minus_f))
padd = '0';
if (flags & plus_f)
morec = '+', lonng++;
else if (flags & space_f)
morec = ' ', lonng++;

d_in++;

/*return (write(1, &buffer[i], BUFF_len - i - 1));*/
return (w_pointer(buffer, d_in, lonng,
width, flags, padd, morec, start_pad));
}
/**
 * print_reverse - rev string.
 * @types: Lista of arguments
 * @buffer: handle print
 * @flags: active flags
 * @width: get width
 * @precision: spec
 * @size: spec
 * Return: num chars printed
 */
int print_reverse(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
int i, count = 0;
char *str;
UNUSED(width);
UNUSED(buffer);
UNUSED(flags);
UNUSED(size);

str = va_arg(types, char *);

if (str == NULL)
{
UNUSED(precision);
str = ")Null(";
}
for (i = 0; str[i]; i++)
;

for (i = i - 1; i >= 0; i--)
{
char z = str[i];

write(1, &z, 1);
count++;
}
return (count);
}
/**
 * print_non_printable - Outputs hexadecimal ASCII
 * codes of non-printable characters
 * @types: List of arguments
 * @buffer: Buffer array for print handling
 * @flags: Calculates active flags
 * @width: Width specifier
 * @precision: Precision specifier
 * @size: Size specifier
 *
 * Return: Number of characters printed
 */
int print_non_printable(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
int i = 0, set_off = 0;
char *str = va_arg(types, char *);
UNUSED(flags);
UNUSED(width);
UNUSED(precision);
UNUSED(size);
if (str == NULL)
{
return (write(1, "(null)", 6));
}
while (str[i] != '\0')
{
if (is_printable(str[i]))
{
buffer[i + set_off] = str[i];
}
else
{
set_off += append_hexa_code(str[i], buffer, i + set_off);
}
i++;
}
buffer[set_off + i] = '\0';
return (write(1, buffer, i + set_off));
}
