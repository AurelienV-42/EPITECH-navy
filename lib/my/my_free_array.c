/*
** EPITECH PROJECT, 2018
** Library : my_free_array
** File description:
** Aurélien Vandaële <aurelien.vandaele@epitech.eu>
*/

#include <stdlib.h>

void my_free_array(char **array)
{
	for (int i = 0; array[i] != NULL; i++)
		free(array[i]);
	free(array);
}
