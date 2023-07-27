#include "shell.h"

/**
 * ex_it - Function that handles 'exit' input
 * @buf: String to compare with 'exit'
 * @argv: Null terminated string array
 * @i: Number of tokens
 * Return: Void
 */
void ex_it(char *buf, char **argv, char **args, int a, int i)
{
	char *status_str, *err, str[INIT];
	int exit_status;

	(void)err;
	(void)args;
	(void)a;

	err = "exit: Illegal number";
	if (str_len(buf) > 4)
	{
	status_str = buf + 5;
	str_cpy(str, status_str);
	if (va_lid(status_str))
	{
	exit_status = at_oi(status_str);

	free_arr(argv, i);
	free(buf);
	exit(exit_status);
	}
	else
	{
		free_arr(argv, i);
		free(buf);
		exit(2);
	}
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
 * va_lid - Checks if string is an integer
 * @str: String to be checked
 * Return: true if valid and false otherwise
 */
bool va_lid(char *str)
{
	int i;

	if (str == NULL || *str == '\0')
	{
	return (false);
	}

	i = 0;

	if (str[i] == '+')
	{
	i++;
	}

	if (str[i] < '0' || str[i] > '9')
	{
	return (false);
	}

	while (str[i] != '\0')
	{
	if (str[i] < '0' || str[i] > '9')
	{
	return (false);
	}
	i++;
	}

	return (true);
}


/**
 * built_in - Function that checks env and exit
 * @argv: Null terminated string array
 * @i: Number of tokens
 * @buf: Pointer to command
 * Return: Void
 */
bool built_in(char *buf, char **argv, char **args, int a, int i)
{
	if (str_cmp(argv[0], "exit", 4) == 0)
	{
		ex_it(buf, argv, args, a, i);
	}

	if (str_cmp(argv[0], "env", 3) == 0 || str_cmp(argv[0], "printenv", 8) == 0)
	{
	en_v(argv, i);
	return (true);
	}

	return (false);
}
