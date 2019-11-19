/*
** EPITECH PROJECT, 2018
** navy
** File description:
** Aurélien Vandaële <aurelien.vandaele@epitech.eu>
*/

#include "my.h"

int global_i;

int count_signals2(void)
{
	int second = 0;

	while (global_i == 2) {
		second++;
		pause();
	}
	return (second);
}

int count_signals1(void)
{
	int first = 0;

	my_putstr("\nwaiting for enemy's attack...\n");
	pause();
	first++;
	while (global_i == 1) {
		first++;
		pause();
	}
	return (first);
}
