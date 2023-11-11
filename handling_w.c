#include "main.h"
/**
 * w_pointer - Outputs a memory address
 * @buffer: Char array for print handling
 * @ix_d: ix_dex where the number starts in the buffer
 * @length: Length of the number
 * @width: Width specifier
 * @flags: Flags specifier
 * @ch_p: Character representing ch_ping
 * @extra_c: Character representing an extra char
 * @ch_p_start: ix_dex where ch_ping should start
 *
 * Return: Number of printed characters
 */
int w_pointer(char buffer[], int ix_d, int length,
	int width, int flags, char ch_p, char extra_c, int ch_p_start)
{
    /*new i*/
	int i;

	if (width > length)
	{
		for (i = 3; i < width - length + 3; i++)
        {
            buffer[i] = ch_p;
        }
		buffer[i] = '\0';
		if (flags & minus_f && ch_p == ' ')/* Asign extra char */
		{
			buffer[--ix_d] = 'x';
			buffer[--ix_d] = '0';
			if (extra_c) /*extra_c*/
            {
                buffer[--ix_d] = extra_c;
            }
			return (write(1, &buffer[ix_d], length) + write(1, &buffer[3], i - 3));
		}
		else if (!(flags & minus_f) && ch_p == ' ')/* extra char */
		{
			buffer[--ix_d] = 'x';
			buffer[--ix_d] = '0';
			if (extra_c)
            {
                buffer[--ix_d] = extra_c;
            }
			return (write(1, &buffer[3], i - 3) + write(1, &buffer[ix_d], length));
		}
		else if (!(flags & minus_f) && ch_p == '0')/* extra char */
		{
			if (extra_c)
            {
                buffer[--ch_p_start] = extra_c;
            }
            /*extra_c*/
			buffer[1] = '0';
			buffer[2] = 'x';
			/*return*/
			return (write(1, &buffer[ch_p_start], i - ch_p_start) +
				write(1, &buffer[ix_d], length - (1 - ch_p_start) - 2));
		}
	}
	buffer[--ix_d] = 'x';
	buffer[--ix_d] = '0';
	if (extra_c)
		buffer[--ix_d] = extra_c;
	return (write(1, &buffer[ix_d], BUFF_len - ix_d - 1));
}
/**
 * hwrite_char - Output a character
 * @c: Character to be printed
 * @buffer: Array for managing print
 * @flags: Calculation of active flags
 * @width: Width of the output
 * @precision: Precision specification
 * @size: Size specifier
 *
 * Return: Number of printed characters
 */

int hwrite_char(char c, char buffer[],
	int flags, int width, int precision, int size)
{ /* hwrite_char(char c, char buffer[],
	int flags, int width, int precision, int size) */
	int i = 0;
	char ch_p = ' ';

	UNUSED(precision);
	UNUSED(size);

	if (flags & zero_f)
		ch_p = '0';

	buffer[i++] = c;
	buffer[i] = '\0';

	if (width > 1)
	{
		buffer[BUFF_len - 1] = '\0';
		for (i = 0; i < width - 1; i++)
			buffer[BUFF_len - i - 2] = ch_p;
        /*width > 1*/
		if (flags & minus_f)
			return (write(1, &buffer[0], 1) +
					write(1, &buffer[BUFF_len - i - 1], width - 1));
		else
			return (write(1, &buffer[BUFF_len - i - 1], width - 1) +
					write(1, &buffer[0], 1));
	}

	return (write(1, &buffer[0], 1));
}
/**
 * write_unsgnd - Outputs an unsigned number
 * @is_negative: ix_dicator for negativity
 * @ix_d: ix_dex where the number starts in the buffer
 * @buffer: Char array for print handling
 * @flags: Flags specifiers
 * @width: Width specifier
 * @precision: Precision specifier
 * @size: Size specifier
 *
 * Return: Number of printed characters
 */
int write_unsgnd(int is_negative, int ix_d,
	char buffer[],
	int flags, int width, int precision, int size)
{
	/* write_unsgnd at position i */
	int length = BUFF_len - ix_d - 1, i = 0;
	char ch_p = ' ';

	UNUSED(is_negative);
	UNUSED(size);

	if (precision == 0 && ix_d == BUFF_len - 2 && buffer[ix_d] == '0')
    {
        return (0);
    }
    /*precision > 0 && precision < length*/
	if (precision > 0 && precision < length)
    {
        ch_p = ' ';
    }
	while (precision > length)
	{
		buffer[--ix_d] = '0';
		length++;
	}
	if ((flags & zero_f) && !(flags & minus_f))
		ch_p = '0';
	if (width > length)
	{
		for (i = 0; i < width - length; i++)
        {
            /*precision > 0 && precision < length*/
            buffer[i] = ch_p;
        }
		buffer[i] = '\0';
		if (flags & minus_f) /* Asign extra char*/
		{
			return (write(1, &buffer[ix_d], length) + write(1, &buffer[0], i));
		}
		else /* Asign extra char*/
			return (write(1, &buffer[0], i) + write(1, &buffer[ix_d], length));
	}
	return (write(1, &buffer[ix_d], length));
}
/**
 * write_number - Outputs a number
 * @is_negative: ix_dicator for negativity
 * @ix_d: Character types
 * @buffer: Buffer array for print handling
 * @flags: Calculation of active flags
 * @width: Width of the output
 * @precision: Precision specifier
 * @size: Size specifier
 *
 * Return: Number of printed characters
 */
int write_number(int is_negative, int ix_d, char buffer[],
	int flags, int width, int precision, int size)
{
    /* new vars*/
	int length = BUFF_len - ix_d - 1;
	char ch_p = ' ', extra_ch = 0;

	UNUSED(size);

	if ((flags & zero_f) && !(flags & minus_f))
    {
        ch_p = '0';
    }
	if (is_negative)
    {
        extra_ch = '-';
    }
	else if (flags & plus_f)
    {
        extra_ch = '+';
    }
	else if (flags & space_f)
    {
        extra_ch = ' ';
    }
    /* done*/
	return (write_num(ix_d, buffer, flags, width, precision,
		length, ch_p, extra_ch));
}
/* write_num */
/**
 * write_num - Writes a number using a buffer
 * @ix_d: ix_dex where the number starts in the buffer
 * @buffer: Buffer array for print handling
 * @flags: Flags for formatting
 * @width: Width of the output
 * @prec: Precision specifier
 * @length: Length of the number
 * @ch_p: ch_ping character
 * @extra_c: Extra character
 *
 * Return: Number of printed characters
 */
int write_num(int ix_d, char buffer[],
	int flags, int width, int prec,
	int length, char ch_p, char extra_c)
{
	int i, ch_p_start = 1;
    /* new i */
	if (prec == 0 && ix_d == BUFF_len - 2 && buffer[ix_d] == '0' && width == 0)
    {
        return (0);
    }
	if (prec == 0 && ix_d == BUFF_len - 2 && buffer[ix_d] == '0')
    {
        buffer[ix_d] = ch_p = ' ';
    }
	if (prec > 0 && prec < length)
		ch_p = ' ';
	while (prec > length)
		buffer[--ix_d] = '0', length++;
	if (extra_c != 0)
		length++;
	if (width > length)
	{
		for (i = 1; i < width - length + 1; i++)
			buffer[i] = ch_p;
		buffer[i] = '\0';
		if (flags & minus_f && ch_p == ' ')
		{
			if (extra_c)
				buffer[--ix_d] = extra_c;
			return (write(1, &buffer[ix_d], length) + write(1, &buffer[1], i - 1));
		}
		else if (!(flags & minus_f) && ch_p == ' ')
		{
			if (extra_c)
				buffer[--ix_d] = extra_c;
			return (write(1, &buffer[1], i - 1) + write(1, &buffer[ix_d], length));
		}
		else if (!(flags & minus_f) && ch_p == '0')
		{
			if (extra_c)
				buffer[--ch_p_start] = extra_c;
			return (write(1, &buffer[ch_p_start], i - ch_p_start) +
				write(1, &buffer[ix_d], length - (1 - ch_p_start)));
		}
	}
	if (extra_c)
		buffer[--ix_d] = extra_c;
	return (write(1, &buffer[ix_d], length));
}
