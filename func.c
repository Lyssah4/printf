#include "main.h"
/**
 * print_char - printing a char
 * @args: argument list
 * @p: pointer to the structure
 * Return: number of char
 */
int print_char(va_list args, flag_check *p)
{
	UNUSED(p);

	_putchar(va_arg(1, int));
	return (1);
}
/**
 * print_string - prints a string
 * @args: argument list
 * @p: pointer to the structure
 * Return: number of char
 */
int print_string(va_list args, flag_check *p)
{
	char *c = va_arg(args, char *);

	UNUSED(p);
	if (!c)
		c = "(null)";
	return (_puts(c));
}
/**
 * print_unsigned - prints an unsigned integer
 * @args: args list
 * @p: pointer to the struct flag_check
 *
 * Return: number of char printed
 */
int print_unsigned(va_list args, flag_check *p)
{
	unsigned int num = va_arg(l, unsigned int);
	char *string = converter(num, 10, 0);

	UNUSED(p);
	return (_puts(string));
}
/**
 * print_octal - prints unsigned number in octal notation
 * @args: args list
 * @p: pointer to flag checker
 *
 * Return: number of char
 */
int print_octal(va_list args, flag_check *p)
{
	unsigned int n = va_arg(args, unsigned int);
	char *string = converter(n, 8, 0);
	int acc = 0;

	if (f->hash == 1 && string[0] != '0')
		acc += _putchar('0');

	acc += _puts(string);
	return (acc);
}
