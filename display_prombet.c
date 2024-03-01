#include "header.h"
/**
 * display_dollar_sign - display problemt
 * Return: non
 */
void display_dollar_sign(void)
{
	char *prombet = "$ ";

	write(STDOUT_FILENO, prombet, 2);
	fflush(stdout);
}
int status = 0;
int errno;
/**
 * check_state - do a the final check on the command
 * @is_cmplte: chekc the command state
 * @argv: argv
 * @cnt: no of commands done
 * @file: filename
 * @env: envirnment
 * Return: void
 */
void check_state(int is_cmplte, char **argv, int cnt, char *file, char **env)
{
	char *pathname = NULL;

	is_cmplte = check_the_slash(argv[0]);
	if (!is_cmplte)
	{
		pathname = compare_and_set_env(env, argv);
		check_if_true(pathname, argv, cnt, file);
		free(pathname);
	}
	else
		check_if_true(argv[0], argv, cnt, file);
	free_grid(argv);
}
/**
 * display_prompet - function
 * @env: envro
 * @envp: envp
 * @arg: arg
 * @count: count
 * Return: void
 */
void display_prompet(char **env, char **envp, char **arg, int count)
{
	char *filename = arg[0], *buff = NULL, **argv = NULL;
	size_t n = 10000;
	int is_compelte = 0, t = 0;

	while (isatty(STDIN_FILENO))
	{

		count++;
		display_dollar_sign();
		t = _getline(&buff, &n, stdin);
		if (t == -1)
		{
			free_grid(env);
			exit(status);
		}
		if (isExit(buff) != 0)
		{
			free_grid(env);
			free(buff);
			exit(status);
		}
		if (strcmp(buff, "\n") == 0 || check_the_spaces(buff) == 0)
		{
			free(buff);
			continue;
		}
		else if ((t > 0) && (buff[t - 1] == '\n'))
			buff[t - 1] = '\0';
		if (strcmp(buff, "env") == 0)
		{
			print_env(envp);
			free(buff);
			continue;
		}
		argv = spilt_string(" ", buff);
		if (argv == NULL)
		{
			perror("invalid pls try again");
			continue;
		}
		check_state(is_compelte, argv, count, filename, env);

		free(buff);
	}
}
/**
 * non_interactive_mode - function
 * @env: envro
 * @arg: envp
 * @envp: arg
 * @count: count
 * Return: void
 */
void non_interactive_mode(char **env, char **arg, char **envp, int count)
{
	char *filename = arg[0], *buff = NULL, **buff2 = NULL, **argv = NULL;
	int is_compelte = 0, i = 0, lsi = 0;
	size_t t = 0, n = 10000;

	t = _getline(&buff, &n, stdin);
	count++;
	if ((int)t == -1 || isExit(buff) != 0 || check_the_spaces(buff) == 0)
	{
		if (status == 2)
			exit_case(count, filename, (buff + 5));
		free_grid(env);
		free(buff);
		exit(status);
	}
	buff[strlen(buff)] = '\0';
	buff2 = spilt_string("\n", buff);
	while (*(buff2 + i) != NULL)
	{

		argv = spilt_string(" ", *(buff2 + i));
		if (argv == NULL)
			perror("invalid pls try again");
		lsi = isExit(*(buff2 + i));

		if (lsi != 0)
		{

			free_grid(env), free_grid(buff2), free_grid(argv), free(buff), exit(status);
		}
		if (strcmp(*(buff2 + i), "env") == 0)
		{
			print_env(envp), free_grid(env), free_grid(buff2), free(buff), exit(status);
		}
		check_state(is_compelte, argv, count, filename, env);
		i++;
	}
	free_grid(env);
	free_grid(buff2);
	free(buff);
}
