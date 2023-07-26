#include "shell.h"

/**
 * str_cmp - Function that compares n number of two strings
 * @str1: First string to be compared
 * @str2: Second string to be compared
 * @n: First n strings to be compared
 * Return: Negative, Positive or Zero Integer
 */
int str_cmp(char *str1, char *str2, int n)
{
	int x, diff;

	for (x = 0; x < n; x++)
	{
		diff = str1[x] - str2[x];

		if (diff > 0 || diff < 0)
		return (diff);
	}
	return (0);
}
