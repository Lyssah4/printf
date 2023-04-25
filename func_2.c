#include "main.h"
/**
 * print_percent - prints a percent sign
 * @args: arg list
 * @buf: array
 * @f: Calculates flags
 * @w: get width
 * @prec: Precision specification
 * @size: Size
 * Return: Numbers of chars
 */
int print_percent(va_list args, char buf[],
		int f, int w, int prec, int size)
{
	UNUSED(args);
	UNUSED(buf);
	UNUSED(f);
	UNUSED(w);
	UNUSED(prec);
	UNUSED(size);

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

	UNUSED(buf);
	UNUSED(f);
	UNUSED(w);
	UNUSED(size);
	UNUSED(prec);

	string = va_arg(args, char *);

	if (string == NULL)
		string = "(null)";

	while (string[a])
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
 * print_rot13 - print string in rot13
 * @args: arg list
 * @buf: array
 * @f:  Calculates flags
 * @w: get width.
 * @prec: Precision spec
 * @size: Size
 * Return: Number of chars
 */
int print_rot13(va_list args, char buf[],
		int f, int w, int prec, int size)
{
	unsigned int a, b;
	char rot13[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char ROT13[] = "nopqrstuvwxyzabcdefghijklmNOPQRSTUVWXYZABCDEFGHIJKLM";
	char *c = va_arg(args, char *);
	char string;
	int acc = 0;

	UNUSED(buf);
	UNUSED(f);
	UNUSED(w);
	UNUSED(prec);
	UNUSED(size);

	if (c == NULL)
		c = "(AHYY)";
	for (a = 0; c[a]; a++)
	{
		for (b = 0; rot13[b]; b++)
		{
			if (rot13[b] == c[a])
			{
				string = ROT13[b];
				write(1, &string, 1);
				acc++;
				break;
			}
		}
		if (!rot13[b])
		{
			string = c[a];
			write(1, &string, 1);
			acc++;
		}
	}
	return (acc);
}

/**
 * print_pointer - prints the value of a pointer
 * @args: arg list
 * @buf: array
 * @f:  Calculates flags
 * @w: get width.
 * @prec: Precision spec
 * @size: Size
 * Return: Number of chars
 */
int print_pointer(va_list types, char buf[],
		int f, int w, int prec, int size)
{
	char mt[] = "0123456789abcdef";
	void *addrs = va_arg(types, void *);
	unsigned long address;
	char pd = ' ', ext = 0;
	int pd_st = 1, x = BUFF_SIZE - 2, len = 2;

	UNUSED(w);
	UNUSED(size);
	UNUSED(prec);

	if (addrs == NULL)
		return (write(1, "(nil)", 5));

	buf[BUFF_SIZE - 1] = '\0';
	address = (unsigned long)addrs;

	while (address > 0)
	{
		buf[x--] = mt[address % 16];
		address /= 16;
		len++;
	}
	if ((f & F_ZERO) && !(f & F_MINUS))
		pd = '0';
	if (f & F_PLUS)
		ext = '+', len++;
	else if (f & F_SPACE)
		ext = ' ', len++;

	x++;

	return (write_pointer(buf, x, len, w, f, pd, ext, pd_st));
}
/**
 * print_non_printable - print string
 * @args: arg list
 * @buf: array
 * @f:  Calculates flags
 * @w: get width.
 * @prec: Precision spec
 * @size: Size
 * Return: Number of chars
 */
int print_non_printable(va_list args, char buf[],
		int f, int w, int prec, int size)
{
	char *c = va_arg(args, char *);
	int a, num = 0;

	UNUSED(f);
	UNUSED(w);
	UNUSED(prec);
	UNUSED(size);

	if (c == NULL)
		return (write(1, "(null)", 6));

	for (a = 0; c[a] != '\0'; a++)
	{
		if (is_printable(c[a]))
			buf[a + num] = c[a];
		else
			num += append_hexa_code(c[a], buf, a + num);
	}
	buf[a + num] = '\0';
	return (write(1, buf, a + num));
}
