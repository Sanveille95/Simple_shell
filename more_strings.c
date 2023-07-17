#include "shell.h"

/**
 * _strcpy - function to copy a string from source to destination
 * @src: the string source
 * @dest: the string destination
 * Return: the pointer to dest
 */
char *_strcpy(char *dest, char *src)
{
	int i;

	for (i = 0; src[i] != '\0'; i++)
	{
		dest[i] = src[i];
	}
	dest[i] = '\0';
	return (dest);
}

/**
 * _isalpha - function to check if the input is a letter
 * @c: the character to be checked
 * Return: 1 if letter, 0 otherwise
 */
int _isalpha(int c)
{
	if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122))
	{
		return (1);
	}
	return (0);
}

/**
 * _strdup - function to dupicate strings
 * @str: the given string
 * Return: pointer to the duplicated string(Sucess), return null pointer(Fail)
 */
char *_strdup(char *str)
{
	char *duplen;

	if (str == NULL)
		return (NULL);

	duplen = malloc(_strlen(str) + 1);
	if (duplen == NULL)
		return (NULL);

	_strcpy(duplen, str);
	return (duplen);
}
