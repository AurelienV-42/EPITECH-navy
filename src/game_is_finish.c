/*
** EPITECH PROJECT, 2018
** navy
** File description:
** Aurélien Vandaële <aurelien.vandaele@epitech.eu>
*/

#include "my.h"

int game_is_finish(char **array)
{
	for (int i = 0; array[i] != NULL; i++)
		for (int nb = 0; array[i][nb] != '\0'; nb++)
			if (array[i][nb] >= '1' && array[i][nb] <= '5')
				return (1);
	return (0);
}