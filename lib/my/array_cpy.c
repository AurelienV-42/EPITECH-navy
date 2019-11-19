/*
** EPITECH PROJECT, 2018
** Library : array_cpy
** File description:
** Aurélien Vandaële <aurelien.vandaele@epitech.eu>
*/

#include "my.h"

char **array_cpy(char **array_to_cpy)
{
	char **array = malloc(sizeof(char *)
			* (my_strlen_array(array_to_cpy) + 1));

	for (int i = 0; array_to_cpy[i] != NULL; i++)
		array[i] = my_strdup(array_to_cpy[i]);
	array[my_strlen_array(array_to_cpy)] = NULL;
	return (array);
}
