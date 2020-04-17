#include "library.h"

/**
 * strClear - initializes a string with "0".
 * @string: it receives a string's memory allocation.
 * @len: lenght of the string passed.
 * Return: Nothing (void).
 */
void strClear(char *string, int len)
{
	int i;

	if (string == NULL)
	{
		return;
	}
	for (i = 0; i < len; i++)
	{
		string[i] = 0;
	}
}

/**
 * _strstr - a function that locates a substring.
 * @haystack: pointer to main string.
 * @needle: pointer to substring.
 *
 * Return: a pointer to the beginning of the located substring.
 */
char *_strstr(char *haystack, char *needle)
{
	while (*haystack != '\0')
	{
		char *start = haystack;
		char *match = needle;

		while (*match == *haystack && *match != '\0' && *haystack != '\0')
		{
			haystack++;
			match++;
		}
		if (*match == '\0')
		{
			return (start);
		}
		haystack = start + 1;
	}
	return (NULL);
}

/**
 * _strchr - it returns an address of first character match.
 * @s: char pointer variable.
 * @c: char to find.
 *
 * Return: an address.
 */
char *_strchr(char *s, char c)
{
	int i = 0;

	while (*(s + i))
	{
		if (*(s + i) == c)
			return (s + i);
		i++;
	}

	if (c == '\0')
		return (s + i);
	return (NULL);
}

/**
 * call_envp - call all the enviroments variables
 * @envp: environment variables.
 * Return: cero.
 */
char call_envp(char **envp)
{
	int count_env;

	for (count_env = 0; envp[count_env] != NULL; count_env++)
	{
		write(STDOUT_FILENO, envp[count_env], _strlen(envp[count_env]));
		write(STDOUT_FILENO, "\n", 1);
	}
	return (0);
}
