#include "header.h"
/**
 * countwords - Count the number of words in
 * a string delimited by a specified character.
 * @str: Pointer to the input string.
 * @d: Pointer to the string containing the delimiter character.
 * Return: The number of words in the input string.
 */
int countwords(char *str, char *d)
{
	int n = 0;
	int i = 0;
	int flag = 0;
	char delim = d[0];

	if (str == NULL)
		return (n);
	while (str[i] != '\0')
	{
		while (str[i] == delim)
		{
			i++;
			flag = 1;
		}
		if (flag == 1)
		{
			n++;
			flag = 0;
		}
		if (str[i] != '\0')
			i++;
	}
	if (str[i - 1] != ' ' && str[i - 2] == ' ')
		n++; 
	if ((i - 2 >= 0) && str[i - 2] == delim && str[i - 2] != '\0')
		n--;
	return (n + 1);
}
/**
 * free_fun - free_uncerssy mallocs
 * @tmp: the main array
 * @i: unitll Is elemnts
 * @tmp2: the command aprt
 * Return: void
*/
void free_fun(char **tmp, int i, char *tmp2)
{
	int j;

	printf("error happend while allocating\n");
	for (j = 0; j < i; j++)
	{
		free(tmp[j]);
		tmp[j] = NULL;
	}
	free(tmp);
	tmp = NULL;
	free(tmp2);
}
/**
 * spilt_string - Splits a string into tokens
 * @delim: Pointer to the string containing the delimiter characters.
 * @str: Pointer to the input string to be split.
 * Return: An array of strings representing
 */
char **spilt_string(char *delim, char *str)
{
	int i = 0;
	int n = countwords(str, delim);
	char *tmp2 = NULL;
	char **tmp = NULL;
	char *tokn = NULL;
	int token_len = 0;

	if (str == NULL)
		return (NULL);
	tmp2 = malloc(strlen(str) + 1);
	if (tmp2 == NULL)
		return (NULL);
	strcpy(tmp2, str);
	tmp2[strlen(str)] = '\0';
	tmp = malloc(sizeof(char *) * (n + 1));
	if (tmp == NULL)
	{
		free(tmp2);
		return (NULL);
	}
	tokn = _strtok(tmp2, delim);
	tokn[strlen(tokn)] = '\0';
	while (tokn != NULL)
	{
		if (tokn != NULL)
			token_len = strlen(tokn);
		tmp[i] = malloc(sizeof(char) * (token_len + 1));
		if (tmp[i] == NULL)
		{
			free_fun(tmp, i, tmp2);
			return (NULL);
		}
		strcpy(tmp[i], tokn);
		tmp[i][token_len] = '\0';
		i++;
		tokn = _strtok(NULL, delim);
	}
	free(tmp2);
	tmp[i] = NULL;
	return (tmp);
}

/**
 * free_grid - Frees the memory allocated
 * for a 2D array of strings.
 * @grid: Pointer to the 2D array of strings.
 */

void free_grid(char **grid)
{
	int count;

	count = 0;
	status = status;
	while (grid[count] != NULL)
	{
		free(grid[count]);
		count++;
	}
	free(grid);
}
