#include"header.h"
/**
 * print_env - print environment function
 * @envp: the envior to be printed
 * Return: void
*/
void print_env(char **envp)
{
	int i = 0;

	while (envp[i] != NULL)
	{
		printf("%s\n", envp[i]);
		i++;
	}
}
/**
 * _getline - get_line custimized function
 * @line_ptr: pointer the the buffer to store read data
 * @n: size of the data being read
 * @stream: place where would the data be read from
 * Return: void
*/
int _getline(char **line_ptr, size_t *n, FILE *stream)
{
	size_t numberofchars = 0;
	int r = 0;
	char *tmp = malloc(sizeof(char) * (*n));

	if (tmp == NULL)
		return (-1);
	r = read(fileno(stream), tmp, *n);
	if (r == 0)
	{
		free(tmp);
		return (-1);
	}
	tmp[r] = '\0';
	while (tmp[numberofchars] != '\0')
		numberofchars++;
	if (*n < numberofchars)
		return (-1);
	if (numberofchars < 120)
		*n = 120;
	else if (numberofchars >= 120 && numberofchars < 240)
		*n = 240;
	else if (numberofchars >= 240)
		*n = numberofchars + 1;
	*line_ptr = malloc(sizeof(char) * (numberofchars + 1));
	strcpy(*line_ptr, tmp);
	free(tmp);
	return (numberofchars);
}
/**
 * _strtok - get_line custimized function
 * @str: pointer the the buffer to store read data
 * @delim: size of the data being read
 * Return: void
 */
char *_strtok(char *str, char *delim)
{
	return(strtok(str, delim));
}
