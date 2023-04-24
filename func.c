#include "main.h"

/**
 * print_char - prints a char
 * @args: List a of arguments
 * @buf: array
 * @f:  Calculates active flags
 * @w: Width
 * @prec: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int print_char(va_list args, char buf[],
		int f, int w, int prec, int size)
{
	char c = va_arg(args, int);

	return (handle_write_char(c, buf, f, w, prec, size));
}

/**
 * print_string - prints a char
 * @args: List a of arguments
 * @buf: array
 * @f:  Calculates active flags
 * @w: Width
 * @prec: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int print_string(va_list args, char buf[],
			int f, int w, int prec, int size)
{
	char *string = va_arg(args, char *);
	int a, len;

	UNUSED(buf);
	UNUSED(f);
	UNUSED(w);
	UNUSED(prec);
	UNUSED(size);

	if (string == NULL)
	{
		string = "(null)";
		if (prec >= 6)
			string = " ";
	}
	for (len = 0; string[len] != '\0'; len++)
		;

	if (prec >= 0 && prec < len)
		len = prec;

	if (w > len)
	{
		if (f & F_MINUS)
		{
			write(1, &string[0], len);
			for (a = w - len; a > 0; a--)
				write(1, " ", 1);
			return (w);
		}
		else
		{
			for (a = w - len; a > 0; a--)
				write(1, " ", 1);
			write(1, &string[0], len);
			return (w);
		}
	}
	return (write(1, string, len));
}
/**
 * print_unsigned - prints a char
 * @args: List a of arguments
 * @buf: array
 * @f:  Calculates active flags
 * @w: Width
 * @prec: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */

int print_unsigned(va_list args, char buf[],
		int f, int w, int prec, int size)
{
	int a = BUFF_SIZE - 2;
	unsigned long int n = va_arg(args, unsigned long int);

	num = convert_size_unsgnd(n, size);

	if (num == 0)
	buf[a--] = '0';

	buf[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buf[a--] = (num % 10) + '0';
		num /= 10;
	}
	i++;

	return (write_unsgnd(0, a, buf, f, w, prec, size));
}

/**
 * print_octal - prints a char
 * @args: List a of arguments
 * @buf: array
 * @f:  Calculates active flags
 * @w: Width
 * @prec: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int print_octal(va_list args, char buf[],
		int f, int w, int prec, int size)
{
	int a = BUFF_SIZE - 2;
	unsigned long int n = va_arg(args, unsigned long int);
	unsigned long int init_n = n;

	(void)w;

	n = convert_size_unsgnd(n, size);

	if (n == 0)
		buffer[a--] = '0';

	buf[BUFF_SIZE - 1] = '\0';

	while (n > 0)
	{
		buf[a--] = (n % 8) + '0';
		n /= 8;
	}
	if (f & F_HASH && init_n != 0)
		buf[a--] = '0';

	a++;

	return (write_unsgnd(0, a, buf, f, w, prec, size));
}
