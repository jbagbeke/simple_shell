#include "shell.h"

/**
 * put_char - Writes char to stdout
 * @ch: Char to be written
 * Return: An int
 */
int put_char(char ch)
{
	return (write(1, &ch, 1));
}
