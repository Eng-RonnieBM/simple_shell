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
 * @keep_pr: variable with true value.
 * @paths: array of strings with the op.system's main paths.
 * @envp: environment variables.
 * @argc: (argc) argument counter.
 * @argv: (argv) argument values.
 * Return: No Return, free.
 */
void handle_pr(int *keep_pr, char **paths, char **envp, int argc, char **argv)
{
	char *buffer;
	char **params;
	int find = 0; /*modif 1.0*/
	(void)argc;   /*modif 1.0*/

	if (isatty(STDIN == 1))
	{
		prompt();
	}
	buffer = takeInput(keep_pr, envp);
	if (buffer != NULL)
	{
		params = fill_params(buffer);
		find = find_file(paths, params);/*modif 1.0*/
		if (find == 1) /*modif 1.0*/
		{
			execute_comand(params, paths, keep_pr);
			free(params);
		}
		else /*modif 1.0*/
			print_error(argv, params, "not found");/*modif 1.0*/
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
	return (separate_string(buffer, " \t\n"));
}
