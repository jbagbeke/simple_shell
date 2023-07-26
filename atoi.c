#include "shell.h"

/**
 * at_oi - Function to convert string to integer
 * @str: String to be converted
 * Return: Integer equivalent of string
 */
int at_oi(char *str)
{
	int result = 0;
	int sign = 1;
	int i = 0;

	while (str[i] == ' ' || str[i] == '\t')
	{
	i++;
	}

	if (str[i] == '+' || str[i] == '-')
	{
	sign = (str[i] == '-') ? -1 : 1;
	i++;
	}

	while (str[i] >= '0' && str[i] <= '9')
	{
	result = result * 10 + (str[i] - '0');
	i++;
	}

	return (sign * result);
}
