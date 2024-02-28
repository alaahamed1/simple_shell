#include "header.h"

char *make_path_arr(char **str)
{
	int i = 0;

	while (str[i] != NULL)
	{
		if (strncmp(str[i], "PATH", 4) == 0)
		{
			char *tmp = str[i] + 5;

			return (tmp);
		}
		i++;
	}
	return (NULL);
}
/**
 * *compare_and_set_env - Searches for the executable
 * file specified in the command
 * argument within the directories listed in the environment
 * variable PATH, and returns the full path of the executable
 * if found and executable, otherwise returns NULL.
 * @env: Pointer to the array of environment variables.
 * @argv: Pointer to the array of command-line arguments,
 *  where the first argument
 * is the executable file name.
 * Return: The full path of the executable
 * if found and executable, otherwise NULL.
 */
char *compare_and_set_env(char **env, char **argv)
{
	int i = 0;
	char *command = malloc(strlen(argv[0]) + 1);
	char *fullpath = NULL;

	if (command == NULL)
		return (NULL);
	command = strcpy(command, argv[0]);
	while (env[i] != NULL)
	{
		fullpath = malloc(strlen(command) + strlen(env[i]) + 2);
		if (fullpath == NULL)
			return (NULL);
		strcpy(fullpath, env[i]);
		if (fullpath[(strlen(fullpath) - 1)] != '/')
			strcat(fullpath, "/");
		strcat(fullpath, command);
		if (access(fullpath, X_OK) == 0)
		{
			free(command);
			return (fullpath);
		}
		i++;
		free(fullpath);
	}
	free(command);
	return (NULL);
}
/**
 * excute_function - Executes a given command
 * @argv: Pointer to the array of command-line arguments,
 * @str: Path to the executable file.
 * @filename: Name of the executable file.
 * Return: 1 upon successful execution,
 */
int excute_function(char **argv, char *str, char *filename)
{
	int id = fork();

	if (id == 0)
	{
		if (execve(str, argv, NULL) == -1)
		{
			printf("%s: No such file or directory", filename);
			exit(1);
		}
		else
			return (1);
	}
	else
	{
		wait(NULL);
	}
	return (1);
}
