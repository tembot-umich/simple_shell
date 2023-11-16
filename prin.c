#include "shell.h"
/**
 * output_number -Print Unsigned Int Putchartr
 * @m: Unisigned Integer
 * This function prints an unsigned integer using
 * the _putchartr function.
 * It recursively breaks down the integer into its
 * individual digits and prints them.
 * Return: Void
 */
void output_number(unsigned int m)
{
	unsigned int x = m;

	if ((x / 10) > 0)
		output_number(x / 10);

	_putchartr(x % 10 + '0');
}
/**
 * output_number_in -Print Number Putchar
 * mn:Integer
 * This function prints an integer using the _putchar function.
 * If the integer is negative, it prints a minus sign
 * and then handles the absolute value.
 * It recursively breaks down the absolute value into
 * its individual digits and prints them.
 * Return: void
 */
void output_number_in(int m)
{
	unsigned int x = m;

	if (m < 0)
	{
		_putchartr('-');
		x = -x;
	}
	if ((x / 10) > 0)
		output_number(x / 10);

	_putchartr(x % 10 + '0');
}
