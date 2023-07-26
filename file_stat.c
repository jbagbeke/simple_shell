#include "shell.h"

/**
 * file_stat - Function to check status if file using the stat function
 * @path: The name of the path
 * @f_stat: Struct that stored file statistics
 * Return: true if found, false otherwise
 */
bool file_stat(char *path, struct stat *f_stat)
{
	int stat_info;

	stat_info = stat(path, f_stat);

	if (stat_info == 0)
	{
		return (true);
	}
	else
	{
		return (false);
	}
}
