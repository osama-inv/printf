#ifndef MAIN_H
#define MAIN_H
/* libs */
#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
/* minus_f plus_f ... */
#define minus_f 1
#define plus_f 2
#define zero_f 4
#define hash_f 8
#define space_f 16
#define null_f 0
/* setting UNUSED to void*/
#define BUFF_len 1024
#define UNUSED(x) (void)(x)
/* SIZES */
#define short_s 1
#define long_s 2

/**
 * struct fmt - fmt fn
 *
 * @fmt: fmt.
 * @fn: fn
 */
struct fmt
{
	char fmt;
	int (*fn)(va_list, char[], int, int, int, int);
};
/* typedef */
/**
 * typedef struct fmt fmt_t - fmt fn
 *
 * @fmt: fmt.
 * @fm_t: fm_t
 */
typedef struct fmt fmt_t;

int _printf(const char *format, ...);
int get_def_print(const char *fmt, int *ind,
va_list list, char buffer[], int flags, int width, int precision, int size);
/* see defs */
/* print chars and strings */
int print_percent(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_char(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_string(va_list types, char buffer[],
	int flags, int width, int precision, int size);

/* print_int to print_hexa_upper*/
int print_int(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_binary(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_hexa_upper(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_hexadecimal(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_unsigned(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_octal(va_list types, char buffer[],
	int flags, int width, int precision, int size);

int print_hexa(va_list types, char map_to[],
char buffer[], int flags, char flag_ch, int width, int precision, int size);

/* print_non_printable */
int print_non_printable(va_list types, char buffer[],
	int flags, int width, int precision, int size);

/* print_pointer */
int print_pointer(va_list types, char buffer[],
	int flags, int width, int precision, int size);
/* has_flags .. has_size*/
int has_precision(const char *format, int *i, va_list list);
int has_flags(const char *format, int *str);
int has_width(const char *format, int *i, va_list list);
int has_size(const char *format, int *i);
/* Functions*/
int print_reverse(va_list types, char buffer[],
	int flags, int width, int precision, int size);
/* Functions*/
int print_rot13string(va_list types, char buffer[],
	int flags, int width, int precision, int size);
/* hwrite_char w_pointer */
int hwrite_char(char c, char buffer[],
	int flags, int width, int precision, int size);
int write_number(int is_positive, int ix_d, char buffer[],
	int flags, int width, int precision, int size);
int write_num(int ix_d, char bff[], int flags, int width, int precision,
	int length, char ch_p, char extra_c);
int w_pointer(char buffer[], int ix_d, int length,
	int width, int flags, char ch_p, char extra_c, int padd_start);

int write_unsgnd(int is_negative, int ix_d,
char buffer[],
	int flags, int width, int precision, int size);

int is_printable(char);
int append_hexa_code(char, char[], int);
int is_digit(char);

long int convert_size_number(long int num, int size);
long int convert_size_unsgnd(unsigned long int num, int size);
/****** done ***********/
#endif /* MAIN_H */

