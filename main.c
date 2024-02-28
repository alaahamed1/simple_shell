#include"header.h"
/**
 * main - main function
 * @ac: not essitial
 * @arg: name file + other things
 * @envp: environment
 * Return: 0
*/
int main(int ac, char **arg, char **envp)
{
	char *en = NULL;
	char **env = NULL;
	int count = 0;

	(void)ac;
	en = make_path_arr(envp);

	env = spilt_string(":", en);


	if (isatty(STDIN_FILENO))
		display_prompet(env, envp, arg, count);
	else
		non_interactive_mode(env, arg, envp, count);

	return (0);
}
