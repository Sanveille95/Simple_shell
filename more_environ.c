#include "shell.h"

/**
 * *_itoa - function to convert integer to array
 * @n: the given number
 * Return: a pointer to the null terminated string
 */
char *_itoa(unsigned int n)
{
	int len = 0, i = 0;
	char *s;

	len = intlen(n);
	s = malloc(len + 1);
	if (!s)
		return (NULL);
	*s = '\0';
	while (n / 10)
	{
		s[i] = (n % 10) + '0';
		n /= 10;
		i++;
	}
	s[i] = (n % 10) + '0';
	array_rev(s, len);
	s[i + 1] = '\0';
	return (s);
}

/**
 * _atoi - function to convert character to integer
 * @c: the given character
 * Return: An integer
 */
int _atoi(char *c)
{
	unsigned int val = 0;
	int sig = 1;

	if (c == NULL)
		return (0);
	while (*c)
	{
		if (*c == '-')
			sig *= (-1);
		else
			val = (val * 10) + (*c - '0');
		c++;
	}
	return (sig * val);
}

/**
 * intlen - function to determine the number of digit int integer
 * @num: the given number
 * Return: the length of the integer
 */
int intlen(int num)
{
	int len = 0;

	while (num != 0)
	{
		len++;
		num /= 10;
	}
	return (len);
}

/**
 * print_error - prints error
 * @data: the data structure pointer
 * Return: positive number (Success), otherwise (Fail)
 */
int print_error(sh_t *data)
{
	char *indx = _itoa(data->index);

	PRINT("sbsh: ");
	PRINT(indx);
	PRINT(": ");
	PRINT(data->args[0]);
	PRINT(": ");
	PRINT(data->error_msg);
	free(indx);
	return (0);
}

/**
 * write_history - function to print errors
 * @data: the data structure pointer
 * Return: positive number (Sucess), otherwise (Fail)
 */
int write_history(sh_t *data __attribute__((unused)))
{
	char *filename = "history";
	char *history_lib = "this is a history library";
	ssize_t fd, wx;
	int len;

	if (!filename)
		return (-1);
	fd = open(filename, O_RDWR | O_APPEND);
	if (fd < 0)
		return (-1);
	if (history_lib)
	{
		while (history_lib[len])
			len++;
		wx = write(fd, history_lib, len);
		if (wx < 0)
			return (-1);
	}
	return (1);
}
