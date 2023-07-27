#include "shell.h"

/**
 * bu_ffer - Carries out EOF condition
 * @buffer: Command pointer
 * Return: True if error or false otherwise
 */
bool bu_ffer(char *buffer)
{
	if (!buffer)
	{
		put_char('\n');
		_exit(EXIT_SUCCESS);
	}

	if (*buffer == '\0' || buffer == NULL)
	{
		free(buffer);
		return (true);
	}

	return (false);

}
