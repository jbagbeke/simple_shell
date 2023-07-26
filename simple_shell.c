#include "shell.h"
/**
 * main - Entry point of shell
 * Return: 0 on success
 */
int main(void)
{
	char *command = NULL, **args;
	char *prompt = "$ ";
	size_t buffer_size = 0;
	int *num, i, b;

	num = &b;
	while (true)
	{
	write(STDOUT_FILENO, prompt, 2);

	if (getline(&command, &buffer_size, stdin) == -1)
	{
	put_char('\n');
	break;
	}

	args = str_tok(command, " ", num);
	i = b;
	exe_cve(args, i);

	free(command);
	free(args);
	}
	return (0);
}

