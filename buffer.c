#include "shell.h"

/**
 * bu_ffer - Carries out EOF condition
 * @buffer: Command pointer
 * Return: Void
 */
void bu_ffer(char *buffer)
{
	if (!buffer)
	{
		put_char('\n');
		_exit(EXIT_SUCCESS);
	}

	spa_ces(buffer);
}
