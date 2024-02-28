#include"header.h"
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
	if (str[0] == '/')
		return (1);
	else
		return (0);
	return (0);
}
/**
 * check_if_true- fucntion
 * @pathname: pathname
 * @argv: argv
 * @filename: filename
 * Return: void
*/
void check_if_true(char *pathname, char **argv, char *filename)
{
	if (pathname != NULL && access(pathname, X_OK) == 0)
		excute_function(argv, pathname, filename);
	else
		printf("%s: No such file or directory\n", filename);
}
/**
 * isExit - function for the exit command
 * @c: the buffer
 * Return: int
*/
int isExit(char *c)
{
	char *exii = NULL;

	if (c[strlen(c) - 1] == '\n')
		c[strlen(c) - 1] = '\0';
	exii = "exit";
	if (strcmp(c, exii) == 0)
		return (1);
	else
		return (0);
}
