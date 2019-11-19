/*
** EPITECH PROJECT, 2018
** Library : my_strlen_array
** File description:
** Aurélien Vandaële <aurelien.vandaele@epitech.eu>
*/

#include "my.h"

int my_strlen_array(char **array)
{
	int i;

	for (i = 0; array[i] != NULL; i++);
	return (i);
}
