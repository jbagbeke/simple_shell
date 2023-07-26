#include "shell.h"

/**
 * free_arr - Frees a 2d array memory that was allocated
 * @vector: Vector to be freed
 * @len: Number of strings(tokens) in the vector
 * Return: Void
 */
void free_arr(char **vector, int len)
{
	int i;

	for (i = 0; i < len; i++)
	{
		free(vector[i]);
	}

	free(vector);
}
