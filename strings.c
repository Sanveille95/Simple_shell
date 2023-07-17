#include "shell.h"

/**
 * _strcat - function to concatenate two string in a path form
 * @dest: the first given destination
 * @src: the second given source
 * Return: (Success) to new string. (Fail) otherwise
 */
char *_strcat(char *dest, char *src)
{
	int len1, len2, i = 0, j = 0;
	char *result;

	len1 = _strlen(dest);
	len2 = _strlen(src);
	result = malloc((len1 + len2 + 2) * sizeof(char));
	if (!result)
		return (NULL);
	*result = '\0';
	while (dest[j])
		result[i++] = dest[j++];
	result[i++] = '/';
	j = 0;
	while (src[j])
		result[i++] = src[j++];
	result[i] = '\0';
	return (result);
}

/**
 * _strlen - function to find the length of a given string
 * @str: the given string
 * Return: (Success) the length of the string, (Fail) negative value
 */
int _strlen(char *str)
{
	int len;

	for (len = 0; str[len]; len++)
		;
	return (len);
}

/**
 * _strcmp - function to compare two strings
 * @s1: the first given string
 * @s2: the second given string
 * Return: (Success) a positive number, (Fail) a negative number
 */
int _strcmp(char *s1, char *s2)
{
	int cmp = 0;
	int i;

	if (s1 == NULL || s2 == NULL)
		return (1);
	for (i = 0; s1[i]; i++)
	{
		if (s1[i] != s2[i])
		{
			cmp = s1[i] - s2[i];
			break;
		}
		else
			continue;
	}
	return (cmp);
}

/**
 * *_strchr - function to locate a character in a given string
 * @str: the given string
 * @c: the given string
 * Return: pointer to first occurence of c(Success), return null pointer(Fail)
 */
char *_strchr(char *str, char c)
{
	char *ptr;

	if (str == NULL)
		return (NULL);
	for (ptr = str; *ptr; ptr++)
		if (*ptr == c)
			return (ptr);
	return (NULL);
}
