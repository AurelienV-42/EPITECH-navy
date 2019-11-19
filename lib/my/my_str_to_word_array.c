/*
** EPITECH PROJECT, 2018
** Library : my_str_to_word_array
** File description:
** Aurélien Vandaële <aurelien.vandaele@epitech.eu>
*/

#include <stdlib.h>

static int ct(char const *str, char symbol)
{
	static int i = 0;
	int nb = 0;

	while (str[i] != '\0') {
		i++;
		nb++;
		if (str[i] == symbol)
			return (nb);
	}
	return (--nb);
}

static char **malloc_it(char const *str, char symbol)
{
	int len_columns = 0;
	char **array_result;
	int nb = 0;
	int i = 0;
	int len_columns2 = 0;

	for (int i = 0; str[i]; i++) {
		if (str[i] == symbol)
			len_columns++;
	}
	len_columns++;
	len_columns2 = len_columns;
	array_result = malloc(sizeof(char *) * (len_columns + 1));
	for (len_columns = len_columns; len_columns != 0; len_columns--, nb++) {
		i = ct(str, symbol);
		array_result[nb] = malloc(sizeof(char) * (i + 2));
	}
	array_result[len_columns2] = NULL;
	return (array_result);
}

char **my_str_to_word_array(char const *str, char symbol)
{
	char **array_result = malloc_it(str, symbol);
	int nb = 0;
	int n = 0;
	int a = 0;

	if (array_result == NULL)
		return (NULL);
	for (int i = 0; str[i] != '\0'; i++, nb++) {
		if (str[i] == symbol) {
			array_result[n][nb] = '\0';
			n++;
			i++;
			nb = 0;
		}
		array_result[n][nb] = str[i];
		a = nb;
	}
	array_result[n][++a] = '\0';
	array_result[++n] = NULL;
	return (array_result);
}
