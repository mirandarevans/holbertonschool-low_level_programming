#include "holberton.h"

/**
 * print_binary - prints an int in binary
 * @n: number to be printed
 */
void print_binary(unsigned long int n)
{
	unsigned long int count = 1;

	while (count * 2 <= n)
		count *= 2;

	while (count > 0)
	{
		if ((count & n) > 0)
			write(1, "1", 1);
		else
			write(1, "0", 1);

		count = count >> 1;
	}
}