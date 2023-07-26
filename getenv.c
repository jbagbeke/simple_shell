#include "shell.h"

/**
 * get_env - Function to obtain the 'PATH' key value
 * @env_key: Key to search for
 * Return: Pointer to the value of 'PATH' or NULL
*/
char *get_env(char *env_key)
{
	char **ptr = environ;
	int i;
	int len;

	len = str_len(env_key);

	for (i = 0; ptr[i] != NULL; i++)
	{
	if (str_cmp(ptr[i], env_key, len) == 0 && ptr[i][len] == '=')
	{
		return (&ptr[i][len + 1]);
	}
	}
	return (NULL);
}
