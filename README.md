Title: ALX Low-Level Programming Project - Custom Printf Implementation

Project Overview:
Under the ALX Low Level Programming curriculum, the project involves creating a custom printf function in C. The goal is to write a function named _printf that outputs to stdout based on a format string, specifying the conversion of subsequent arguments using variable-length argument facilities.

Function Prototype:

c
Copy code
int _printf(const char *format, ...);
Return Value:
Upon successful execution, _printf returns the number of characters printed (excluding the null byte used to terminate output to strings). If an output error occurs, the function returns -1.

Format String:
The format string is a constant character string with directives. Ordinary characters (except %) are copied unchanged to the output stream, while conversion specifications, introduced by %, fetch zero or more subsequent arguments.

General Requirements:

Compilation will be on Ubuntu 20.04 LTS using gcc with specific options.
All files should end with a new line.
Each file should contain no more than 5 functions.
Global variables are not allowed.
Function prototypes must be included in the header file named holberton.h.
Header files should be include guarded.
Authorized Functions and Macros:

write (man 2 write)
malloc (man 3 malloc)
free (man 3 free)
va_start (man 3 va_start)
va_end (man 3 va_end)
va_copy (man 3 va_copy)
va_arg (man 3 va_arg)
Compilation Command:

bash
Copy code
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 test/main.c *.c -o print
Authors:

iAmG-r00t 👾
Michael Ndula @Michaelndula 👨‍💻
Tasks Overview:

Implement the basic conversion specifiers: c, s, %
Handle additional conversion specifiers: d, i
Create a man page for the custom printf function.
