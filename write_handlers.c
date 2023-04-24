#include "main.h"

/**
 * handle_write_char - prints a string
 * @c: char types.
 * @buffer: Buffer aray to handle print
 * @flags: Calculates active flags.
 * @width: get width.
 * @precision: precision specifier
 * @size: Size specifier
 *
 * Return: Number of chars printed
 */
int handle_write_char(char c, char buffer[],
		int flags, int width, int precision, int size)
{
	int i = 0;
	char padd = ' ';

	UNUSED(precision);
	UNUSED(size);

	if (flags & F_ZERO)
		padd = '0';

	buffer[i++] = c;
	buffer[i] = '\0';

	if (width > 1)
	{
		buffer[BUFF_SIZE - 1] = '\0';
		for (i = 0; i < width - 1; i++)
			buffer[BUFF_SIZE - i - 2] = padd;

		if (flags & F_MINUS)
			return (write(1, &buffer[0], 1) +
					write(1, &buffer[BUFF_SIZE - i - 1], width - 1));
		else
			return (write(1, &buffer[BUFF_SIZE - i - 1], width - 1) +
					write(1, &buffer[0], 1));
	}
	return (write(1, &buffer[0], 1));
}
/**
 * write_number - Prints a string
 * @is_negative: List of arguments
 * @ind: char types.
 * @buffer: Buffer array to handle print
 * @flags: Calculate active flags
 * @width: get width.
 * @precision: precision specifier
 * @size: Size specifier
 * Return: Number of chars printed.
 */
int write_number(int is_negative, int ind, char buffer[],
		int flags, int width, int precision, int size)
{
	int length = BUFF_SIZE - ind - 1;
	char padd = ' ', extra_ch = 0;

	UNUSED(size);

	if ((flags & F_ZERO) && !(flags & F_MINUS))
		padd = '0';
	if (is_negative)
		extra_ch = '-';
	else if (flags & F_PLUS)
		extra_ch = '+';
	else if (flags & F_SPACE)
		extra_ch = ' ';

	return (write_num(ind, buffer, flags, width, precision,
				length, padd, extra_ch));
}
/**
 * write_num - Write a number using a buffer
 * @x: Index at which the number starts on the buffer
 * @buf: Buffer
 * @f: Flags
 * @w: width
 * @prec: Precisiom specifier
 * @l: Number length
 * @pd: Pading char
 * @extra_c: Extra char
 * Return: Number if printed chars
 */
int write_num(int x, char buf[], int f, int w, int prec,
		int l, char pd, char extra_c)
{
	int i, pd_st = 1;

	if (prec == 0 && x == BUFF_SIZE - 2 && buf[x] == '0' && w == 0)
		return (0);
	if (prec == 0 && x == BUFF_SIZE - 2 && buf[x] == '0')
		buf[x] = pd = ' ';
	if (prec > 0 && prec < l)
		pd = ' ';
	while (prec > l)
		buf[--x] = '0', l++;
	if (extra_c != 0)
		l++;
	if (w > l)
	{
		for (i = 1; i < w - l + 1; i++)
			buf[i] = pd;
		buf[i] = '\0';
		if (f & F_MINUS && pd == ' ')
		{
			if (extra_c)
				buf[--x] = extra_c;
			return (write(1, &buf[x], l) + write(1, &buf[1], i - 1));
		}
		else if (!(f & F_MINUS) && pd == ' ')
		{
			if (extra_c)
				buf[--x] = extra_c;
			return (write(1, &buf[1], i - 1) + write(1, &buf[x], l));
		}
		else if (!(f & F_MINUS) && pd == '0')
		{
			if (extra_c)
				buf[--pd_st] = extra_c;
			return (write(1, &buf[pd_st], i - pd_st) +
				write(1, &buf[x], len - (1 - pd_st)));
		}
	}
	if (extra_c)
		buf[--x] = extra_c;
	return (write(1, &buf[x], len));
}
/**
 * write_unsgnd - Writes an unsigned number
 * @is_negative: Number indicating if the num is negative
 * @ind: Index at which the number starts in the buffer
 * @buffer: Array of chars
 * @flags: Flags specifiers
 * @width: Width specifier
 * @precision: Precision specifier
 * @size: Size sprecifier
 * Return:Number of written chars.
 */
int write_unsgnd(int is_negative, int ind,
	char buffer[],
	int flags, int width, int precision, int size)
{
	int length = BUFF_SIZE - ind - 1, i = 0;
	char padd = ' ';

	UNUSED(is_negative);
	UNUSED(size);

	if (precision == 0 && ind == BUFF_SIZE - 2 && buffer[ind] == '0')
		return (0);

	if (precision > 0 && precision < length)
		padd = ' ';

	while (precision > length)
	{
		buffer[--ind] = '0';
		length++;
	}
	if ((flags & F_ZERO) && !(flags & F_MINUS))
		padd = '0';
	if (width > length)
	{
		for (i = 0; i < width - length; i++)
			buffer[i] = padd;

		buffer[i] = '\0';

		if (flags & F_MINUS)
		{
			return (write(1, &buffer[ind], length) + write(1,
	&buffer[0], i));
		}
		else
		{
			return (write(1, &buffer[0], i) + write(1, &buffer[ind], length));
		}
	}
	return (write(1, &buffer[ind], length));
}
/**
 * write_pointer - Write a memory address
 * @buf: Arrays of chars
 * @ind: Index at which the number starts in the buffer
 * @len: Length of number:
 * @w: Width specifier
 * @f: Flags specifier
 * @pd: Char representing the padding
 * @extra_c: Char representing extra char
 * @pd_st: Index at which padding should start
 * Return: Number of written chars
 */
int write_pointer(char buf[], int ind, int len,
		int w, int f, char pd, char extra_c, int pd_st)
{
	int i;

	if (w > len)
	{
		for (i = 3; i < w - len + 3; i++)
			buf[i] = pd;
		buf[i] = '\0';
		if (f & F_MINUS && pd == ' ')
		{
			buf[--ind] = 'x';
			buf[--ind] = '0';
			if (extra_c)
				buf[--ind] = extra_c;
			return (write(1, &buf[ind], len) + write(1,
						&buf[3], i - 3));
		}
		else if (!(f & F_MINUS) && pd == ' ')
		{
			buf[--ind] = 'x';
			buf[--ind] = '0';
			if (extra_c)
				buf[--ind] = extra_c;
			return (write(1, &buf[3], i - 3) + write(1,
&buf[ind], len));
		}
		else if (!(f & F_MINUS) && pd == '0')
		{
			if (extra_c)
				buf[--pd_st] = extra_c;
			buf[1] = '0';
			buf[2] = 'x';
			return (write(1, &buf[pd_st], i - pd_st) +
				write(1, &buf[ind], len - (1 - pd_st) - 2));
		}
	}
	buf[--ind] = 'x';
	buf[--ind] = '0';
	if (extra_c)
		buf[--ind] = extra_c;
	return (write(1, &buf[ind], BUFF_SIZE - ind - 1));
}
