#include "shell.h"

/**
 * main - The main function for code execution
 * @argc: Argument counter
 * @argv: Argument vector
 * Return: An int(0, Success)
 */
int main(int argc, char **argv)
{
	char **args, *buffer, *prompt = "$ ";
	bool is_pipe = false;
	int i, b, a = 1, *num = &b;

	(void)argc;
	while (1 && !is_pipe)
{
	if (isatty(STDIN_FILENO) == 0)
	{
	while ((buffer = get_line(STDIN_FILENO)) != NULL)
	{
		bu_ffer(buffer);

		args = str_tok(buffer, " ", num);
		i = b;
		if (bu_ffer(buffer))
		continue;
		_path(argv, buffer, args, i, a);
		a++;
	}
		is_pipe = true;
	}
	else
	{
		write(STDOUT_FILENO, prompt, 2);
		buffer = get_line(STDIN_FILENO);
		if (bu_ffer(buffer))
		continue;
		args = str_tok(buffer, " ", num);
			i = b;

		_path(argv, buffer, args, i, a);
		a++;
	}
}
	return (0);
}
