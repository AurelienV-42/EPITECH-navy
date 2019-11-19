/*
** EPITECH PROJECT, 2018
** change_array_hit
** File description:
** Thomas Meurice
*/

#include "my.h"

int print_array_hit(char *str)
{
	int i = 0;

	pause();
	my_putstr(str);
	my_putstr(": ");
	if (global_i == 1) {
		my_putstr("hit\n");
		i = 1;
	} else {
		my_putstr("missed\n");
		i = 0;
	}
	free(str);
	return (i);
}

void change_array_hit(char **array, int hit, int columns, int lines)
{
	columns--;
	lines--;
	if (hit == 1) {
		array[lines][columns * 2] = 'x';
	} else {
		array[lines][columns * 2] = 'o';
	}
}
