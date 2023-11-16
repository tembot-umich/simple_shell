#include "shell.h"
/**
 * output_number -Print Unsigned Int Putchartr
 * @m: Unisigned Integer
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
