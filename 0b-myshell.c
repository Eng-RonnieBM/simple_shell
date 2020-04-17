#include "library.h"

/**
 * main - main of the code for Simple Shell functions.
 * @argc: argument's counter.
 * @argv: argument's value.
 * @envp: environment variables.
 * Return: Always 0.
 */
int main(int argc, char **argv, char **envp)
{
	int keep_prompt;
	char **paths = fetch_paths(envp);
	(void)argc;

	keep_prompt = 1;
	while (keep_prompt)
	{
		handle_pr(&keep_prompt, paths, envp, argv);
	}
	free(paths);
	return (0);
}
