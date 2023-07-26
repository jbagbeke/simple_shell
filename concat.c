#include "shell.h"

/**
 * con_cat - Function to concatenate strings
 * @len: Number of strings to concatenate
 * Return: Char * to the concatenated string
 */
char *con_cat(int len, ...)
{
	va_list args;
	size_t t_len;
	char *str, *result;
	size_t c_index;
	int i;

	va_start(args, len);

	t_len = 0;

	for (i = 0; i < len; i++)
	{
	str = va_arg(args, char *);

	t_len += str_len(str);
	}

	result = malloc(t_len + 1);

	if (result == NULL)
	{
	perror("Error (malloc)");
	exit(EXIT_FAILURE);
	}

	c_index = 0;
	va_start(args, len);
	for (i = 0; i < len; i++)
	{
	str = va_arg(args, char *);

	str_cpy(result + c_index, str);
	c_index += str_len(str);
	}
	result[c_index] = '\0';

	va_end(args);
	return (result);
}
