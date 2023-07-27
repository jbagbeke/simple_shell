#include "shell.h"

/**
 * _path -Checks the existence of a command
 * @argv: char ** to name of program
 * @buffer: Char * to command
 * @args: Null terminated string array pointer
 * @i: NUmber of tokens
 * @a: Random number used for loop
 * Return: Void
 */
void _path(char **argv, char *buffer, char **args, int i, int a)
{
	char *f_path, *buff;
	int j;
	struct stat f_stat;

	buff = "not found";
	for (j = 0; j < 1; j++)
	{
	if (built_in(buffer, args, i))
	{
		free(buffer);
		continue;
	}

	if (!file_stat(args[0], &f_stat))
	{
	f_path = file_path(args[0], &f_stat);

	if (f_path == NULL)
	{
	pr_f(STDERR_FILENO, "%s: %d: %s: %s\n", argv[0], a, args[0], buff);
		free(buffer);
		free_arr(args, i);
		continue;
	}
	else
	{
		free(args[0]);
		args[0] = f_path;
	}
	}
		exe_cve(args, buffer, i);
		free_arr(args, i);
		free(buffer);
	}
}
