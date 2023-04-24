#include "main.h"
/**
 * print_percent - prints a percent sign
 * @args: arg list
 * @p: pointer to the struct
 * Return: number of char printed
 */
int print_percent(va_list args, flags_t *p)
{
	UNUSED(p);
	UNUSED(f);
	return (_putchar('%'));
}
/**
 * print_reverse - prints reverse string.
 * @args: arg list
 * @buf: array
 * @f: Calculates flags
 * @w: get width
 * @prec: Precision specification
 * @size: Size
 * Return: Numbers of chars
 */

int print_reverse(va_list args, char buf[],
		int f, int w, int prec, int size)
{
	int a;
	char *string;

	UNUSEDbuf;
	UNUSED(f);
	UNUSED(w);
	UNUSED(size);
	UNUSED(prec);

	str = va_arg(args, char *);

	if (string == NULL)
		string = "(null)";

	while (str[a])
		a++;
	a = a - 1;
	while (a >= 0)
	{
		_putchar(string[a]);
		a--;
	}
	return (a);
}
/**
 * print_rot13 - prints a string in rot13
 * @args: arg list
 * @p: pointer to the struct
 *
 * Return: length of the printed string
 */
int print_rot13(va_list args, flags_check *p)
{
	int a, b;
	char rot13[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char ROT13[] = "nopqrstuvwxyzabcdefghijklmNOPQRSTUVWXYZABCDEFGHIJKLM";
	char *c = va_arg(args, char *);

	UNUSED(p);
	while (c[b])
	{
		if (c[b] < 'A' || (c[b] > 'Z' && c[b] < 'a') || c[b] > 'z')
			_putchar(c[b]);

		else
		{
			while (a <= 52)
			{
				if (c[b] == rot13[a])
					_putchar(ROT13[a]);
				a++;
			}
		}
		b++;
	}
	return (b);
}
/**
 * print_pointer - prints the value of a pointer
 * @args: arg list
 * @p: pointer to the flag_check structure
 *
 * Return: Number of chars printed.
 */
int print_pointer(va_list args, flag_check *p)
{
	char *string;
	unsigned long *address = va_arg(types, unsigned long int *);

	UNUSED(p);

	if (address == NULL)
		return (_puts("(nill)"));

	string = converter(p, 16, 1);

	num += _puts("0x");
	num += _puts(string);

	return (num);
}
/**
 * print_non_printable - prints Non printable characters
 * @args: args list
 * @p: pointer to the flag checker structure
 *
 * Return: Number of chars printed
 */
int print_non_printable(va_list args, flag_check *p)
{
	int num = 0, a;
	char *r;
	char *c = va_arg(args, char *);

	UNUSED(p);
	if (!s)
		return (_puts("(null)"));

	while (c[a])
	{
		if (c[a] > 0 && (c[a] < 32 || c[a] >= 127))
		{
			_puts("\\x");
			num += 2;
			r = converter(c[a], 16, 0);
			if (!r[1])
				num += _putchar('0');

			num += _puts(r);
		}
		else
			num += _putchar(c[a]);
		a++;
	}
	return (num);
}
