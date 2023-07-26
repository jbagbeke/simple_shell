#include "shell.h"

/**
 * str_len - Function to determine length of a string
 * @str: String's length to be determined
 * Return: Count(int)
 */
int str_len(char *str)
{
	int count = 0;

	while (str[count] != '\0')
	{
	count++;
	}
	return (count);
}


/**
 * str_cpy - function to copy string to destination
 * @dest: destination of string
 * @src: Source of string
 * Return: Void
 */
void str_cpy(char *dest, char *src)
{
	int i = 0;

	while (src[i] != '\0')
	{
	dest[i] = src[i];
	i++;
	}
	dest[i] = '\0';
}
