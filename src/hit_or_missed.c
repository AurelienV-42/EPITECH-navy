/*
** EPITECH PROJECT, 2018
** navy
** File description:
** Aurélien Vandaële <aurelien.vandaele@epitech.eu>
*/

#include "my.h"

int hit_or_missed(char **array, int first, int scd, int pid)
{
	int hit = 0;

	first--;
	scd--;
	my_putchar('A' + first);
	my_putchar('1' + scd);
	my_putstr(":  ");
	if (array[scd][first * 2] >= '1' && array[scd][first * 2] <= '5') {
		hit = 1;
		my_putstr("hit\n");
		kill(pid, SIGUSR1);
	} else {
		my_putstr("missed\n");
		kill(pid, SIGUSR2);
	}
	return (hit);
}
