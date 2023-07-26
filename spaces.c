#include "shell.h"

/**
 * spa_ces - Removes leading and trailing spaces
 * @command: Chars read
 * Return: Void
 */
void spa_ces(char *command)
{
	char *src = command;
	char *dest = command;
	int first_non_space_found = 0;

	while (*src == ' ')
	{
	src++;
	}

	while (*src)
	{
	if (*src != ' ' || first_non_space_found)
	{
	*dest = *src;

	if (*src != ' ')
	{
	first_non_space_found = 1;
	}

	dest++;
	}

	src++;
	}

	while (dest > command && *(dest - 1) == ' ')
	{
	dest--;
	}

	*dest = '\0';
}
