/*
** EPITECH PROJECT, 2018
** navy
** File description:
** Aurélien Vandaële <aurelien.vandaele@epitech.eu>
*/

#include "my.h"

int global_i;

void client_connected(int i)
{
	(void) i;
	global_i = 1;
}

void client_connected2(int i)
{
	(void) i;
	global_i = 2;
}
