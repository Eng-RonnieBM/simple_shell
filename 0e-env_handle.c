#include "library.h"

/**
 * fetch_paths - function that execute the params typed by user.
 *
 * @envp: environment variables.
 * Return: string's memory allocation with all path's separated from ":".
 */
char **fetch_paths(char **envp)
{
	char *path_string = _getenv(envp, "PATH=/");

	return (separate_string(path_string, ":"));
}

/**
 * _getenv - it returns PATH's memory location.
 *
 * @envp: environment variables.
 * @name: String to be finded in the env.locations ("PATH=").
 * Return: string's memory allocation of "PATH=".
 */
char *_getenv(char **envp, char *name)
{
	int i = 0;

	while (envp[i] != NULL)
	{
		if (_strstr(envp[i], name))
		{
			return (_strchr(envp[i], '=') + 1);
		}
		i++;
	}
	return (NULL);
}
