#include "library.h"

/**
 * print_error - prints an error in STDERR stream.
 * @argv: argument values.
 * @params: input commands.
 * @msg: text message to show.
 * Return: nothing.
 */
void print_error(char **argv, char **params, char *msg)
{
	int i, j, k, l;
	char *program = argv[0];
	char *cmd = params[0];
	char *ptr = malloc(BUFF_MAX);
	char *s1 = ": 1: ";

	if (ptr == NULL)
	{
		write(STDOUT, "Error", 5);
		return;
	}
	for (i = 0; program[i] != '\0'; i++)
	{
		ptr[i] = program[i];
	}
	for (j = 0; s1[j] != '\0'; j++)
	{
		ptr[j + i] = s1[j];
	}
	for (k = 0; cmd[k] != '\0'; k++)
	{
		ptr[k + j + i] = cmd[k];
	}
	ptr[k + j + i] = ':';
	k++;
	ptr[k + j + i] = ' ';
	k++;
	for (l = 0; msg[l] != '\0'; l++)
	{
		ptr[l + k + j + i] = msg[l];
	}
	ptr[l + k + j + i] = '\0';
	write(STDERR, ptr, bytes_str(ptr));
	free(ptr);
	NEW_LINE;
}

/**
 * bytes_str - it counts the bytes of a string.
 * @str: string to be checked.
 * Return: number of bytes.
 */
int bytes_str(char *str)
{
	int i;

	if (str == NULL)
	{
		return (0);
	}
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}
