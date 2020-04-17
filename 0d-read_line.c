#include "library.h"

/**
 * takeInput - function to take user input params.
 *
 * @keep_prompt: it takes the keep_prompt address from main.
 * @envp: environment variables.
 * Return: buffer.
 */
char *takeInput(int *keep_prompt, char **envp)
{
	size_t buffer_size;
	char *buffer = NULL;
	int char_count;

	char_count = getline(&buffer, &buffer_size, stdin);
	if (char_count == EOF)
	{
		free(buffer);
		*keep_prompt = 0;
		if (isatty(STDIN == 1))
		{
			write(2, "\n", 1);
		}
		return (NULL);
	}
	if (_strstr(buffer, "exit"))
	{
		free(buffer);
		*keep_prompt = 0;
		return (NULL);
	}
	if (_strstr(buffer, "env"))
	{
		free(buffer);
		call_envp(envp);
		return (NULL);
	}
	if (buffer[char_count - 1] == '\n')
	{
		buffer[char_count - 1] = '\0';
		--char_count;
	}
	if (empty_line(buffer) == 1)
	{
		free(buffer);
	}
	return (buffer);
}
