#include "shell.h"

/**
 * *_getenv - function to get the path
 * @path_name: a pointer to the struct of data
 * Return: a positive number on success, otherwise (Fail)
 */
char *_getenv(char *path_name)
{
	char **env_cur, *env_ptr, *name_ptr;

	env_cur = environ;
	while (*env_cur)
	{
		env_ptr = *env_cur;
		name_ptr = path_name;
		while (*env_ptr == *name_ptr)
		{
			if (*env_ptr == '=')
				break;
			env_ptr++;
			name_ptr++;
		}
		if ((*env_ptr == '=') && (*name_ptr == '\0'))
			return (env_ptr + 1);
		env_cur++;
	}
	return (NULL);
}

/**
 * signal_handler - function to handle the process interrept signal
 * @sign: the signal identifier
 * Return: void
 */
void signal_handler(int sign)
{
	if (sign == SIGINT)
	{
		PRINT("\n");
		PRINT(PROMPT);
	}
}

/**
 * fill_an_array - function to fill an array with elements
 * @arr: the given array
 * @elm: the given element
 * @len: the length of the array
 * Return: pointer to filled array
 */
void *fill_an_array(void *arr, int elm, unsigned int len)
{
	char *p = arr;
	unsigned int i = 0;

	while (i < len)
	{
		*p = elm;
		p++;
		i++;
	}
	return (arr);
}

/**
 * array_rev - function to reverse array
 * @arr: the given array
 * @len: the array length
 * Return: void
 */
void array_rev(char *arr, int len)
{
	int i;
	char tmp;

	for (i = 0; i < (len / 2); i++)
	{
		tmp = arr[i];
		arr[i] = arr[(len - 1) - i];
		arr[(len - 1) - i] = tmp;
	}
}

/**
 * index_cmd - function is an indexed command
 * @data: a pointer to the data structure
 * Return: void
 */
void index_cmd(sh_t *data)
{
	data->index += 1;
}
