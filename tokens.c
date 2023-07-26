#include "shell.h"

/**
 * tokenise - Tokenizes strings
 * @buffer: Pointer to string to be tokenized
 * @delim: Delimiter to use
 * Return: A char pointer
 */
char *tokenise(char *buffer, const char *delim)
{
	static char *l_token;
	char *tokens;

	if (buffer != NULL)
	{
		l_token = buffer;
	}

	if (!l_token)
	return (NULL);

	tokens = l_token;

	while (*l_token)
	{
		if (*l_token == *delim)
		{
		*l_token++ = '\0';
		break;
		}
		l_token++;
	}

	if (*l_token == '\0')
	{
		l_token = NULL;
	}

	return (tokens);
}
