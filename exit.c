#include "shell.h"

/**
 * ex_it - Function that handles 'exit' input
 * @buf: String to compare with 'exit'
 * @argv: Null terminated string array
 * @i: Number of tokens
 * Return: Void
 */
void ex_it(char *buf, char **argv, int i)
{
	char *status, *error, exit_str[12];
	int exit_status, j;

	if (str_len(buf) > 4)
	{
	status = buf + 5;
	for (j = 0; j < str_len(status); j++)
	{
	if (status[j] < '0' || status[j] > '9')
	{
	error = "Error: Invalid exit status argument\n";
	write(STDOUT_FILENO, error, str_len(error));
	free_arr(argv, i);
	free(buf);
	_exit(EXIT_FAILURE);
	}
	}
	exit_status = at_oi(status);
	free_arr(argv, i);
	free(buf);

	it_oa(exit_status, exit_str);

	_exit(exit_status);
	}
	else
	{
	free_arr(argv, i);
	free(buf);
	_exit(0);
	}
}


/**
 *en_v - Function to print environment variables
 *@argv: Null terminated string array
 *@i: Number of tokens
 *Return: Void
 */
void en_v(char **argv, int i)
{
	char **env = environ;

	while (*env)
	{
	write_str(*env);
	put_char('\n');
	env++;
	}
	free_arr(argv, i);
}

/**
 * write_str - Writes string to stdout
 * @str: String to be written to stdout
 * Return: Void
 */
void write_str(char *str)
{
	size_t len;

	len = str_len(str);
	write(STDOUT_FILENO, str, len);
}


/**
 * built_in - Function that checks env and exit
 * @argv: Null terminated string array
 * @i: Number of tokens
 * @buf: Pointer to command
 * Return: Void
 */
bool built_in(char *buf, char **argv, int i)
{
	if (str_cmp(argv[0], "exit", 4) == 0)
	{
		ex_it(buf, argv, i);
	}

	if (str_cmp(argv[0], "env", 3) == 0 || str_cmp(argv[0], "printenv", 8) == 0)
	{
	en_v(argv, i);
	return (true);
	}

	return (false);
}
