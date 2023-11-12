#include "main.h"

/**
 * get_def_print - args depend on  type
 * @fmt: arguments printing.
 * @list: args.
 * @x_id: x_id.
 * @buffer: handle print.
 * @flags: flgs
 * @width: spec
 * @precision: spec
 * @size: spec
 * Return: 2 or 1;
 */
int get_def_print(const char *fmt, int *x_id, va_list list, char buffer[],
	int flags, int width, int precision, int size)
{
	int i, num_of_got_chars = -1;
	int ig_length = 0;
	fmt_t arrofstruct[] = {
		{'c', print_char}, {'s', print_string},
		{'b', print_binary},
		{'i', print_int}, {'d', print_int},
		{'%', print_percent},
		{'u', print_unsigned}, {'o', print_octal},
		{'S', print_non_printable},
		{'X', print_hexa_upper}, {'p', print_pointer},
		{'x', print_hexadecimal},
		{'r', print_reverse}, {'R', print_rot13string}, {'\0', NULL}
	};
	for (i = 0; arrofstruct[i].fmt != '\0'; i++)
		if (fmt[*x_id] == arrofstruct[i].fmt)
        {
            return (arrofstruct[i].fn(list, buffer, flags, width, precision, size));
        }
	if (arrofstruct[i].fmt == '\0')
	{
		if (fmt[*x_id] == '\0')
        {
            return (-1);
        }
		ig_length += write(1, "%%", 1);
		if (fmt[*x_id - 1] == ' ')
			ig_length += write(1, " ", 1);
		else if (width)
		{
			--(*x_id);
			while (fmt[*x_id] != ' ' && fmt[*x_id] != '%')
				--(*x_id);
			if (fmt[*x_id] == ' ')
            {
                --(*x_id);
            }
			return (1);
		}
		ig_length += write(1, &fmt[*x_id], 1);
		return (ig_length);
	}
	return (num_of_got_chars);
}

