#include "library.h"

/**
 * file_exist- verifies if a file exist.
 * @dir: a directory in string format.
 * @command: a command in string format.
 * Return: 1 if file exist, else 0.
 */
int file_exist(char *dir, char *command)
{
	int fd, i, j;
	char *path = malloc(BUFF_MAX);

	if (dir == NULL || command == NULL || path == NULL)
	{
		free(path);
		return (0);
	}
	for (i = 0; dir[i] != '\0'; i++)
	{
		path[i] = dir[i];
	}
	path[i] = '/';
	i++;
	for (j = 0; command[j] != '\0'; j++)
	{
		path[j + i] = command[j];
	}
	path[j + i] = '\0';
	fd = open(path, O_RDONLY); /*opening file*/
	close(fd); /*closing file*/
	free(path); /*de-allocating malloc*/
	if (fd == -1) /*file not exist, return 0*/
	{
		return (0);
	}
	return (1); /*file exist, return 1*/
}

/**
 * find_file - it finds a file in an array of directories.
 * @paths: $PATH directories array.
 * @params: user input commands.
 * Return: 1 if file was found, else 0.
 */
int find_file(char **paths, char **params)
{
	int i;
	int find;

	if (paths == NULL || params == NULL)
	{
		return (0);
	}
	for (i = 0; paths[i] != NULL; i++)
	{
		if (file_exist(paths[i], params[0]))
		{
			find = 1;
			break;
		}
	}
	return (find);
}

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
