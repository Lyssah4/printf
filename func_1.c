#include "main.h"
/**
 * print_binary - print an unsigned number
 * @args: args list
 * @buf: array
 * @f:  Calculates flags
 * @w: width
 * @prec: Precision spec
 * @size: Size
 * Return: Numbers of char.
 */
int print_binary(va_list args, char buf[],
		int f, int w, int prec, int size)
{
	unsigned int a, b, c, sum;
	unsigned int str[32];
	int acc;

	UNUSED(buf);
	UNUSED(f);
	UNUSED(w);
	UNUSED(prec);
	UNUSED(size);

	a = va_arg(args, unsigned int);
	b = 2147483648;
	str[0] = a / b;
	while (c < 32)
	{
		b /= 2;
		str[c] = (a / b) % 2;
		c++;
	}
	c = 0;
	sum = 0;
	acc = 0;
	while (c < 32)
	{
		sum += str[c];
		if (sum || c == 31)
		{
			char z = '0' + str[c];

			write(1, &z, 1);
			acc++;
		}
		c++;
	}
	return (acc);
}
/**
 * print_int - Print int
 * @args: arg list
 * @buf: array
 * @f:  Calculates flags
 * @w: get width.
 * @prec: Precision spec
 * @size: Size
 * Return: Number of chars
 */
int print_int(va_list args, char buf[],
		int f, int w, int prec, int size)
{
	int a = BUFF_SIZE - 2;
	int neg = 0;
	long int n = va_arg(args, long int);
	unsigned long int num;

	n = convert_size_number(n, size);

	if (n == 0)
	buf[a--] = '0';

	buf[BUFF_SIZE - 1] = '\0';
	num = (unsigned long int)n;

	if (n < 0)
	{
		num = (unsigned long int)((-1) * n);
		neg = 1;
	}

	while (num > 0)
	{
		buf[a--] = (num % 10) + '0';
		num /= 10;
	}
	a++;

	return (write_number(neg, a, buf, f, w, prec, size));
	return (0);
}
/**
 * print_hexa_low - prints in hexadecimal notation
 * @args: args list
 * @buf: array
 * @f:  Calculates flags
 * @w: width
 * @prec: Precision spec
 * @size: Size spec
 * Return: Number of chars printed
 */
int print_hexa_low(va_list args, char buf[],
		int f, int w, int prec, int size)
{
	return (print_hexa(args, "0123456789abcdef", buf,
				f, 'x', w, prec, size));
}
/**
 * print_hexa_big - prints number hexadecimal notation
 * @args: args list
 * @buf: array
 * @f:  Calculates flags
 * @w: width
 * @prec: Precision spec
 * @size: Size spec
 * Return: Number of chars
 */
int print_hexa_big(va_list args, char buf[],
		int f, int w, int prec, int size)
{
	return (print_hexa(args, "0123456789ABCDEF", buf,
				f, 'X', w, prec, size));
	return (0);
}
/**
 * print_hexa - prints a hexadecimal number in lower or upper
 * @args: args list
 * @map_to: Array of values map number
 * @buf: Buffer array to handle print
 * @f:  Calculates active flags
 * @flag_ch: Calculates active flags
 * @w: get width
 * @prec: Precision specification
 * @size: Size spec
 * Return: Number of chars
 */
int print_hexa(va_list args, char map_to[], char buf[],
		int f, char flag_ch, int w, int prec, int size)
{
	int a = BUFF_SIZE - 2;
	unsigned long int n = va_arg(args, unsigned long int);
	unsigned long int init_num = n;

	UNUSED(w);

	n = convert_size_unsgnd(n, size);

	if (n == 0)
		buf[a--] = '0';

	buf[BUFF_SIZE - 1] = '\0';

	while (n > 0)
	{
		buf[a--] = map_to[n % 16];
		n /= 16;
	}

	if (f & F_HASH && init_num != 0)
	{
		buf[a--] = flag_ch;
		buf[a--] = '0';
	}
	a++;
	return (write_unsgnd(0, a, buf, f, w, prec, size));
}
