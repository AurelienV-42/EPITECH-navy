/*
** EPITECH PROJECT, 2017
** Library : my_strdup
** File description:
** Aurélien Vandaële <aurelien.vandaele@epitech.eu>
*/

#include "my.h"

char *my_strdup(char const *src)
{
	char *new = NULL;
	int i = my_strlen(src);

	new = malloc(sizeof(char) * (i + 1));
	my_strcpy(new, src);
	return (new);
}
