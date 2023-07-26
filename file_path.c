#include "shell.h"

/**
 * file_path - Function to check if file exists in PATH
 * @f_stat: Stores info on file if found
 * @name: Name of the file to be checked
 * Return: Full path if found, NULL otherwise
 */
char *file_path(char *name, struct stat *f_stat)
{
	int n, *num, i, b;
	char *full_path;
	bool witness;
	char **paths;
	char *current_path;

	current_path = get_env("PATH");
	num = &b;

	paths = str_tok(current_path, ":", num);
	i = b;
	for (n = 0; n < i; n++)
	{
		full_path = con_cat(3, paths[n], "/", name);

		witness = file_stat(full_path, f_stat);
		if (witness)
		{
		free_arr(paths, i);
		return (full_path);
		}

		free(full_path);
	}

	free_arr(paths, i);
	return (NULL);
}
