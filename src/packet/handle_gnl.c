/*
** EPITECH PROJECT, 2018
** navy
** File description:
** Aurélien Vandaële <aurelien.vandaele@epitech.eu>
*/

#include "my.h"

int handle_gnl(char *str)
{
	if (str[0] < 'A' || str[0] > 'H' || str[1] < '1' || str[1] > '8'
	|| my_strlen(str) != 2) {
		my_putstr("wrong position");
		return (1);
	}
	return (0);
}
