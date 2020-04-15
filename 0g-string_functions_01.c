#include "library.h"

/**
 * empty_line - verifies if buffer is empty.
 *
 *@buff: buffer to be checked.
 *
 * Return: "0" if user press enter without writing a command.
 */
int empty_line(char *buff)
{
	int i = 0;

	while (buff[i] != '\0')
		i++;
	return (i);
}


/**
 * separate_string - it separates an string.
 *
 * @string: it receives a string's memory allocation.
 * @sep: separator.
 * Return: an address of a pointer to char.
 */
char **separate_string(char *string, char *sep)
{
	int count = 0;
	char *token;
	char **params = malloc(BUFF_MAX * sizeof(char *));

	if (params == NULL)
	{
		perror("Unable to allocate params");
		return (NULL);
	}
	token = strtok(string, sep);
	while (token != NULL)
	{
		params[count] = token;
		count++;
		token = strtok(NULL, sep);
	}
	params[count] = NULL;
	return (params);
}

/**
 * _strncpy -  copy array
 *@dest:an array of char
 *@src:an array of char
 *@n:size
 * Return: Always dest.
 */
char *_strncpy(char *dest, char *src, int n)
{
	int concat;
	int use_src = 1;

	for (concat = 0; concat < n; concat++)
	{
		if (src[concat] == '\0')
		{
			use_src = 0;
		}

		if (use_src == 1)
		{
			dest[concat] = src[concat];
		}
		else
		{
			dest[concat] = '\0';
		}
	}
	return (dest);
}

/**
 * _strncat - concatenates two strings with "n" value.
 * @dest: char variables.
 * @src:  char variables.
 * @n: int variable.
 * Return: it returns an address of new concated string.
 */
char *_strncat(char *dest, char *src, int n)
{
	int length;
	int concat;

	for (length = 0; dest[length] != '\0'; length++)
	{
		;
	}
	for (concat = 0; concat < n; concat++)
	{
		dest[length + concat] = src[concat];
		if (src[concat] == '\0')
		{
			break;
		}
	}
	return (dest);
}

/**
 * _strlen - returns the length of a string
 *
 *@s:an array of int
 *
 * Return: the count of characters.
 */
int _strlen(char *s)
{
	int iter;

	for (iter = 0; s[iter] != '\0'; iter++)
	{
		;
	}
	return (iter);
}
