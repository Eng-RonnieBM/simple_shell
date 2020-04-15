#include "library.h"

/**
 * execute_comand - function that execute the params typed by user.
 *
 * @params: string to be read and execute.
 * @paths: array of strings with op. system's main paths.
 * @keep_prompt: var to keep iterating
 * Return: No Return.
 */
void execute_comand(char **params, char **paths, int *keep_prompt)
{
	char *comand;
	pid_t child_pid;
	int status;

	if (*params == NULL)
	{
		return;
	}

	comand = (char *)malloc(BUFF_MAX * sizeof(char));

	child_pid = fork();
	if (child_pid == -1)
	{
		perror("Error:");
		*keep_prompt = 0;
		return;
	}
	if (child_pid == 0)
	{
		_strncpy(comand, params[0], _strlen(params[0]));
		attach_path(comand, paths);
		if (execve(comand, params, NULL) == -1)
		{
			perror("Error:");
		}
		*keep_prompt = 0;
	}
	else /* parent process*/
	{
		wait(&status);
	}
	free(comand);
}

/**
 * attach_path - function that attachs path and command.
 *
 * @command: user's command typed.
 * @paths: array of strings with op. system's main paths.
 * Return: No Return.
 */
void attach_path(char *command, char **paths)
{
	int index, cmd_file_d;
	char *cmd_with_path;

	if (paths == NULL)
	{
		return;
	}

	cmd_with_path = (char *)malloc(BUFF_MAX * sizeof(char));

	for (index = 0; paths[index] != NULL; index++)
	{
		_strncpy(cmd_with_path, paths[index], _strlen(paths[index]));
		_strncat(cmd_with_path, "/", 1);
		_strncat(cmd_with_path, command, _strlen(command));
		cmd_file_d = open(cmd_with_path, O_RDONLY);
		if (cmd_file_d > 0)
		{
			_strncpy(command, cmd_with_path, _strlen(cmd_with_path));
			free(cmd_with_path);
			close(cmd_file_d);
			return;
		}
		strClear(cmd_with_path, BUFF_MAX);
	}
	free(cmd_with_path);
}
