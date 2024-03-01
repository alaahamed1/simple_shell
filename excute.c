#include "header.h"
/**
 * make_path_arr - Extracts the value associated with
 * the "PATH" environment variable from an array of strings.
 * @str: Pointer to the array of strings.
 * Return: Pointer to the character array containing
 * the value of the "PATH" environment variable,
 *or NULL if the "PATH" variable is not found.
 */
char *make_path_arr(char **str)
{
	int i = 0;
	char *tmp = NULL;

	if (str == NULL)
		return (NULL);
	while (str[i] != NULL)
	{
		if (strncmp(str[i], "PATH", 4) == 0)
		{
			if (str[i][5] == '\0')
				return (NULL);
			
			tmp = str[i] + 5;
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
 * Return: 1 upon successful execution,
 */
int excute_function(char **argv, char *str)
{
	int id = fork();
	int s;

	if (id == 0)
	{
		execve(str, argv, NULL);
		exit(0);
	}
	else
	{
		wait(&s);
		status = WEXITSTATUS(s);
	}
	return (1);
}
