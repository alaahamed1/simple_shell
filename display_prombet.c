#include"header.h"
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
	char *filename = arg[0];
	char *buff = NULL;
	size_t t = 0;
	size_t n = 10000;
	int is_compelte = 0;
	char **argv = NULL;

	while (isatty(STDIN_FILENO))
	{
		count++;
		display_dollar_sign();
		t = _getline(&buff, &n, stdin);
		if (strcmp(buff, "\n") == 0 || check_the_spaces(buff) == 0)
		{
			free(buff);
			continue;
		}
		else if ((int)t == -1 || isExit(buff) == 1)
		{
			free_grid(env);
			free(buff);
			exit(0);
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
	char *filename = arg[0];
	char *buff = NULL;
	char **buff2 = NULL;
	int is_compelte = 0;
	int i = 0;
	size_t t = 0;
	size_t n = 10000;
	char **argv = NULL;

	count++;
	t = _getline(&buff, &n, stdin);
	if ((int)t == -1 || isExit(buff) == 1 || check_the_spaces(buff) == 0)
	{
		free_grid(env);
		free(buff);
		exit(0);
	}
	buff[strlen(buff)] = '\0';
	buff2 = spilt_string("\n", buff);
	while (*(buff2 + i) != NULL)
	{
		if (strcmp(*(buff2 + i), "env") == 0)
		{
			print_env(envp);
			free_grid(env);
			free(buff2);
			free(buff);
			exit(0);
		}

		argv = spilt_string(" ", *(buff2 + i));
		if (argv == NULL)
			perror("invalid pls try again");
		check_state(is_compelte, argv, count, filename, env);
		i++;
	}
	free_grid(env);
	free_grid(buff2);
	free(buff);
}
