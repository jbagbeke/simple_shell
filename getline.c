#include "shell.h"

/**
 * get_line - Function to read chars
 * @fd: File descriptor
 * Return: Pointer to chars read
 */
char *get_line(int fd)
{
	char *buffer, *t_buffer, ch;
	int b_size = INIT, i = 0;
	ssize_t bytes;

	buffer = malloc(INIT);
	if (!buffer)
	return (NULL);

	while ((bytes = read(fd, &ch, 1)) > 0)
{
	if (ch == '\n')
	{
		buffer[i++] = '\0';
		break;
	}
	buffer[i++] = ch;

	if (i == b_size - 1)
	{
		b_size *= 2;
		t_buffer = malloc(b_size);

	if (!t_buffer)
	{
		free(buffer);
		return (NULL);
	}
		get_one(buffer, t_buffer, i);
	}
}
	if (bytes == -1 || (bytes == 0 && i == 0))
	{
		free(buffer);
		return (NULL);
	}
	return (buffer);
}

/**
 * get_one - Function to copy strings from one char * to another
 * @buffer: First char *
 * @t_buffer: Second char *
 * @i: Number of chars read
 * Return: Void
 */
void get_one(char *buffer, char *t_buffer, int i)
{
	int j;

	for (j = 0; j < i; j++)
	{
		t_buffer[j] = buffer[j];
	}

	free(buffer);
	buffer = t_buffer;
}
