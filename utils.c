#include "main.h"
/**
 * converter - converts number and base into string
 * @n: input number
 * @base: input base
 * @lcase: flag for case hexa values need lowercase
 * Return: string
 */
char *converter(unsigned long int n, int base, int lcase)
{
	static char *op;
	static char buf[50];
	char *pointer;

	op = (lcase)
		? "0123456789abcdef"
		: "0123456789ABCDEF";
	pointer = &buf[49];
	*pointer = '\0';

	do {
		*--pointer = op[n % base];
		n /= base;
	} while (n != 0);

	return (ptr);
}
/**
 * is_digit - checks if char is a digit
 * @c: Char to be checked
 *
 * Return: 1 if c is a digit, 0 otherwise
 */
int is_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);

	return (0);
}
/**
 * is_printable - checks if char is printable
 * @c: Char to be checked.
 *
 * Return: 1 success, 0 otherwise
 */
int is_printable(char c)
{
	if (c >= 32 && c < 127)
		return (1);

	return (0);
}
/**
 * convert_size_unsgnd - convert to specified size
 * @num: number to convert
 * @size: type to be converted to
 *
 * Return: converted value of num
 */
long int convert_size_unsgnd(unsigned long int num, int size)
{
	if (size == S_LONG)
		return (num);
	else if (size == S_SHORT)
		return ((unsigned short)num);
	return ((unsigned int)num);
}
/**
 * convert_size_number - convert to specified size
 * @num: number to convert
 * @size: type to be converted to
 *
 * Return: converted value of num
 */
long int convert_size_number(long int num, int size)
{
	if (size == S_LONG)
		return (num);
	else if (size == S_SHORT)
		return ((short)num);

	return ((int)num);
}
