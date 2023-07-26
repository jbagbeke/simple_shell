#include "shell.h"

/**
 * exe_cve - Function to execute command
 * @argv: Null terminated string array
 * @i: Number of tokens
 * Return: Void
 */
void exe_cve(char **argv, int i)
{
	const char *exist = argv[0];

	if (argv == NULL)
	{
	errno = EINVAL;
	_exit(EXIT_FAILURE);
	}

	if (access(exist, X_OK) != 0)
	{
	perror("Error (execve)");
	_exit(EXIT_FAILURE);
	}

	exe(argv, i);
}

/**
 * exe - Function to execute a command
 * @argv: Pointer to a pointer of Null terminated array of strings
 * @i: Number of tokens
 * Return: Void
 */
void exe(char **argv, int i)
{
	int stat;

	pid_t cpid = fork();

	if (cpid == -1)
	{
		perror("Error (fork)");
		free_arr(argv, i);
		_exit(EXIT_FAILURE);
	}
	else if (cpid == 0)
	{
		execve(argv[0], argv, environ);
		perror("Error (execve)");
		free_arr(argv, i);
		_exit(EXIT_FAILURE);
	}
	else
	{
	pid_t ppid = waitpid(cpid, &stat, 0);

	if (ppid == -1)
	{
		perror("Error (Parent Process)");
		free_arr(argv, i);
		_exit(EXIT_FAILURE);
	}
	}
}