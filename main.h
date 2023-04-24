#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

#define UNUSED(x) (void)(x)
#define BUFF_SIZE 1024

#define F_MINUS 1
#define F_PLUS 2
#define F_ZERO 4
#define F_HASH 8
#define F_SPACE 16
#define S_LONG 2
#define S_SHORT 1
/**
 * struct flags - flag finder
 * @pl: flag for '+'
 * @sp: flag for ' '
 * @hash: flag for '#'
 */
typedef struct flags
{
	int pl, sp, hash;
} flag_check;

/**
 * struct printh - prints the right func
 * @c: format sppec
 * @f: pointer to the right func
 */
typedef struct printh
{
	char c;
	int (*f)(va_list args, flag_check *p)
} ph;

/**
 * struct fmt - struct operation
 * @fmt: format
 * @f: function associated
 */
struct fmt
{
	char fmt;
	int (*f)(va_list, char[], int, int, int, int)
};
/**
 * typedef struct fmt fmt_t - struct operation
 * @fmt: format
 * @fm_t: func associated
 */
typedef struct fmt fmt_t;

int _printf(const char *format, ...);
int handle_print(const char *fmt, int *i,
va_list list, char buffer[], int flags, int width, int precision, int size);

int print_char(va_list args, flag_check *p);
int print_string(va_list args, flag_check *p);


int print_percent(va_list args, flag_check *p);
int print_reverse(va_list types, char buffer[],
		int flags, int width, int precision, int size);
int print_rot13string(va_list args, flag_check *p);
int print_non_printable(va_list args, flag_check *p);
int print_pointer(va_list args, flag_check *p);


int print_int(va_list args, char buf[],
		int f, int w, int prec, int size);
int print_binary(va_list args, char buf[],
		int f, int w, int prec, int size);
int print_unsigned(va_list args, flag_check *p);
int print_octal(va_list args, flag_check *p);
int print_hexa_low(va_list args, char buf[],
		int f, int w, int prec, int size);
int print_hexa_big(va_list args, char buf[],
		int f, int w, int prec, int size);
int print_hexa(va_list args, char map_to[],
		char buf[], int f, char flag_ch,
		int w, int prec, int size);


int get_flags(const char *format, int *i);
int get_width(const char *format, int *i, va_list list);
int get_precision(const char *format, int *i, va_list list);
int get_size(const char *format, int *i);


int handle_write_char(char c, char buffer[],
			int flags, int width, int precision, int size);
int write_number(int is_positive, int ind, char buffer[],
			int flags, int width, int precision, int size);
int write_num(int ind, char bff[], int flags, int width, int precision,
			int length, char padd, char extra_c);
int write_pointer(char buffer[], int ind, int length,
		int width, int flags, char padd, char extra_c, int padd_start);
int write_unsgnd(int is_negative, int ind,
		char buffer[], int flags, int width, int precision, int size);


int is_printable(char c);
int append_hexa_code(char, char[], int);
char *converter(unsigned long int n, int base, int lcase);
int is_digit(char c);
long int convert_size_number(long int num, int size);
long int convert_size_unsgnd(unsigned long int num, int size);

int _putchar(char c);
int _puts(char *str);

#endif
