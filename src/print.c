/*
** EPITECH PROJECT, 2018
** navy
** File description:
** Aurélien Vandaële <aurelien.vandaele@epitech.eu>
*/

#include "my.h"

void print(char **array)
{
	int nb = 0;

	my_putstr(" |A B C D E F G H\n");
	my_putstr("-+---------------\n");
	for (int i = 1; i <= 8; i++) {
		my_putnbr(i);
		my_putchar('|');
		my_putstr(array[nb]);
		my_putchar('\n');
		nb++;
	}
}

void print_tab(char **array, char **array1)
{
	my_putstr("\nmy positions:\n");
	print(array);
	my_putstr("\nenemy's positions:\n");
	print(array1);
}