#include "shell.h"

/**
 * *_realloc - function to reallocate a memory block
 * @ptr: pointer to the previous memory
 * @old_size: the old size
 * @new_size: the new size
 * Return: returns pointer to new memory location
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *result

	if (new_size == old_size)
		return (ptr);

	if (new_size == 0 && ptr)
	{
		free(ptr);
		return (NULL);
	}

	result = malloc(new_size);
	if (result == NULL)
		return (NULL);

	if (ptr == NULL)
	{
		fill_an_array(result, '\0', new_size);
		free(ptr);
	}
	else
	{
		_memcpy(result, ptr, old_size);
		free(ptr);
	}
	return (result);
}

/**
 * _memset - function to fill a memory with constant byte
 * @s: pointer to memory area
 * @n: first n bytes
 * @b: constant byte
 * Return: A pointer to a character
 */
char *_memset(char *s, char b, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
	{
		s[i] = b;
	}
	return (s);
}

/**
 * free_data - function to free data
 * @data: the data structure
 * Return: positive number (Success), otherwise (Fail)
 */
int free_data(sh_t *data)
{
	free(data->line);
	data->line = NULL;
	free(data->args);
	data->args = NULL;
	free(data->cmd);
	data->cmd = NULL;
	free(data->error_msg);
	data->error_msg = NULL;
	return (0);
}

/**
 * _memcpy - function to copy memory area
 * @dest: Destination memory area
 * @src: Source memory area
 * @n: Amount of memory byte
 * Return: A pointer to dest
 */
char *_memcpy(char *dest, char *src, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
	{
		dest[i] = src[i];
	}
	return (dest);
}
