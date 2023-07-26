#include "shell.h"

/**
 * str_tok - Function to tokenize a string
 * @str: String to be tokenized
 * @delim: Delimeter
 * @num: pointer to the number of tokens tokenized
 * Return: Char **(tokens)
 */
char **str_tok(char *str, const char *delim, int *num)
{
	char **args;
	char *token, *string_cpy;
	int i;

	*num = 0;
	i = 0;

	args = malloc(str_len(str) * sizeof(char *));

	string_cpy = malloc(str_len(str) * sizeof(char *));

	if (args == NULL || string_cpy == NULL)
	{
	perror("Error (malloc)");
	_exit(EXIT_FAILURE);
	}

	str_cpy(string_cpy, str);
	token = tokenise(string_cpy, delim);

	while (token != NULL)
	{
	args[i] = malloc((str_len(token) * sizeof(char *)) + 1);

	if (args[i] == NULL)
	{
	perror("Error (malloc)");
	free(args);
	_exit(EXIT_FAILURE);
	}
	str_cpy(args[i], token);
	(*num)++;
	token = tokenise(NULL, delim);
	i++;
	}
	args[i] = NULL;

	free(string_cpy);
	return (args);
}
