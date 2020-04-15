#include "library.h"

/**
 * prompt - start of prompt.
 *
 * Return: No Return.
 */
void prompt(void)
{
	write(STDOUT, "($) ", 4);
}

/**
 * handle_prompt - Function to print the prompt, get the command and execute.
 * @keep_prompt: variable with true value.
 * @paths: array of strings with the op.system's main paths.
 * Return: No Return, free.
 */
void handle_prompt(int *keep_prompt, char **paths)
{
	char *buffer;
	char **params;

	if (isatty(STDIN == 1))
	{
		prompt();
	}
	else
	{
		*keep_prompt = 0;
	}
	buffer = takeInput(keep_prompt);
	if (buffer != NULL)
	{
		params = fill_params(buffer);
		execute_comand(params, paths, keep_prompt);
		free(params);
	}
	free(buffer);
}

/**
 * fill_params - take params from the buffer
 * @buffer: string that the user type
 * Return: params separated by an empty space.
 */
char **fill_params(char *buffer)
{
	if (buffer == NULL)
		return (NULL);
	return (separate_string(buffer, " "));
}
