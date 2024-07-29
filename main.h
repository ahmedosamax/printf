#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

#define UNUSED(y) (void)(y)
#define BUFFS 1024

/* FLAGS */
#define F_M 1
#define F_P 2
#define F_Z 4
#define F_H 8
#define F_S 16

/* SIZES */
#define S_L 2
#define S_SH 1

/**
 * struct format - Struct define
 * @ft: character.
 * @f: pointer to the function.
 */
typedef struct format
{
	char ft;
	int (*f)(va_list, char[], int, int, int, int);
} fmt;

int _printf(const char *format, ...);
int h_print(const char *ft, int *n,
va_list ptr, char buff[], int fl, int w, int prec, int s);

/****************** functions ******************/

/* Funtions for string and character */
int print_Character(va_list ptr, char buff[],
	int fl, int w, int prec, int s);
int print_String(va_list ptr, char buff[],
	int fl, int w, int prec, int s);
int print_Percentage(va_list ptr, char buff[],
	int fl, int w, int prec, int s);

/* Functions for handling the numbers */
int print_Integar(va_list ptr, char buff[],
	int fl, int w, int prec, int s);
int print_B(va_list ptr, char buff[],
	int fl, int w, int prec, int s);
int print_Nsigned(va_list ptr, char buff[],
	int fl, int w, int prec, int s);
int print_Octall(va_list ptr, char buff[],
	int fl, int w, int prec, int s);
int print_Hexa(va_list ptr, char buff[],
	int fl, int w, int prec, int s);
int print_HEXA(va_list ptr, char buff[],
	int fl, int w, int prec, int s);

int print_hexaa(va_list ptr, char to[],
char buff[], int fl, char fl_ch, int w, int prec, int s);

/* Function for non printable functions */
int print_N_Printed(va_list ptr, char buff[],
	int fl, int w, int prec, int s);

/* Funcion for handling adressess*/
int print_PTR(va_list ptr, char buff[],
	int fl, int w, int prec, int s);

/* Funciotns for  handling advanced specifier */
int get_fl(const char *ft, int *n);
int get_w(const char *ft, int *n, va_list ptr);
int get_prec(const char *ft, int *n, va_list ptr);
int get_s(const char *ft, int *n);

/*Function for reverse print*/
int print_IN_REV(va_list ptr, char buff[],
	int fl, int w, int prec, int s);

/*Function for ROT13 printing*/
int print_ROT13(va_list ptr, char buff[],
	int fl, int w, int prec, int s);

/* write for handlling */
int write_Character(char c, char buff[],
	int fl, int w, int prec, int s);
int write_DIGIT(int is_Positive, int in, char buff[],
	int fl, int w, int prec, int s);
int write_NUMBERS(int in, char buff[], int fl, int w, int prec,
	int L, char pad, char extra_character);
int write_PTR(char buff[], int in, int Length,
	int w, int fl, char pad, char extra_character, int pad_Start);

int write_Unsignd(int is_Negative, int in,
char buff[],
	int fl, int w, int prec, int s);

/****************** UT ******************/
int is_PRINT(char s);
int for_hexa_code(char, char[], int);
int is_number(char);

long int size_of_number(long int num, int s);
long int size_of_unsigned_int(unsigned long int num, int s);
#endif
