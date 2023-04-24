#include "main.h"
#include <unistd.h>

/**
 * _putchar - prints char
 * @c: char
 *
 * Return: 1 (success), -1 error
 */
int _putchar(char c)
{
	static char word[1024];
	static int a;

	if (c == -1 || a >= 1024)
	{
		write(1, &word, a);
		a = 0;
	}
	if (c != -1)
	{
		word[a] = c;
		a++;
	}
	return (1);
}
/**
 * _puts - prints a string
 * @str: pointer to the string
 *
 * Return: number of chars
 */
int _puts(char *str)
{
	register int a;

	while (str[a] != '\0')
	{
		_putchar(str[a]);
		a++;
	}
	return (a);
}
/**
 * append_hexa_code - append ascci in hexadecimal to buffer
 * @buf: array
 * @a: index at which to start appending.
 * @asc: ascii CODE
 * Return: Always 3
 */
int append_hexa_code(char asc, char buf[], int a)
{
	char mt[] = "0123456789ABCDEF";

	if (asc < 0)
		asc *= -1;

	buf[a++] = '\\';
	buf[a++] = 'x';
	buf[a++] = mt[asc / 16];
	buf[a] = mt[asc % 16];

	return (3);
}
