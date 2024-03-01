#include "header.h"
/**
 * check_the_spaces - check if iput is only spaces
 * @buff: buff
 * Return: interger
 */
int check_the_spaces(char *buff)
{
	int i = 0;
	int char_check = 0;

	while (buff[i] != '\0')
	{
		if (buff[i] != ' ' && buff[i] != '\n')
			char_check = 1;
		i++;
	}
	return (char_check);
}
/**
 * check_the_slash - function to check if there's a slash or not
 * @str: the string to be checked
 * Return: integer
 */
int check_the_slash(char *str)
{
	if (str[0] == '/' || str[0] == '.')
		return (1);
	else
		return (0);
	return (0);
}
/**
 * check_if_true- fucntion
 * @pathname: pathname
 * @argv: argv
 * @count: count
 * @filename: filename
 * Return: void
 */
void check_if_true(char *pathname, char **argv, int count, char *filename)
{
	if (pathname != NULL && access(pathname, X_OK) == 0)
		excute_function(argv, pathname);
	else
		printf("%s: %d: %s: not found\n", filename, count, argv[0]), status = 127;
}
/**
 * isExit - function for the exit command
 * @c: the buffer
 * Return: int
 */
int isExit(char *c)
{
	char *exii = NULL;
	int num = 0;
	const char *tmp;

		if (c[strlen(c) - 1] == '\n')
			c[strlen(c) - 1] = '\0';
	exii = "exit";
	if (strncmp(c, exii, 4) == 0)
	{
		if (countwords(c, " ") == 1 || strcmp(exii, c) == 0)
		{
			return (1);
		}
		tmp = c + 5;
		num = atoi(tmp);
		if (num <= 0)
		{
			status = 2;
			return (status);
		}
		return (num);
	}
	return (0);
}
/**
 * exit_case - funciion to print errors
 * @count: counter of the command
 * @filename: filname
 * @val: value of the error
 * Return: integer
*/
int exit_case(int count, char *filename, char *val)
{
	fprintf(stderr, "%s: %d: exit: Illegal number: %s\n", filename, count, val);
	return (2);
}
